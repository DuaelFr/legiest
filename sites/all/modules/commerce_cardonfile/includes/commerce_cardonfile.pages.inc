<?php

/**
 * @file
 * User page callbacks and forms for Commerce Card on File.
 */


/**
 * Displays the card data overview for the "Stored payment methods" account tab.
 */
function commerce_cardonfile_overview($account) {
  // Load the specified account's stored card data.
  $stored_cards = commerce_cardonfile_data_load_multiple($account->uid);

  $header = array(
    t('Payment method'),
    t('Operations'),
  );

  // Build a table rows array of stored card data.
  $rows = array();

  foreach ($stored_cards as $card_id => $card_data) {
    // Build the operation links for the current card.
    $links = menu_contextual_links('commerce-card-data', 'user/' . $account->uid . '/stored-payment-methods', array($card_id));

    // Add the card's row to the table's rows array.
    $rows[] = array(
      theme('card_data_overview', array('card_data' => $card_data)),
      theme('links', array('links' => $links, 'attributes' => array('class' => 'commerce-card-data links inline operations'))),
    );
  }

  // Add an empty message in case the tab got rendered without stored cards.
  if (empty($rows)) {
    $rows[] = array(array('data' => t('You do not have any stored payment methods.'), 'colspan' => 2));
  }

  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Displays the form for updating cardonfile data.
 *
 * @param $card_data
 *   The data array representing a card on file.
 */
function commerce_cardonfile_update($card_data) {
  // Set the title of the page.
  drupal_set_title(t('Update your credit card data'));
  return drupal_get_form('commerce_cardonfile_update_form', $card_data);
}

/**
 * Builds the form for updating cardonfile data.
 *
 * @param $card_data
 *   The data array representing a card on file.
 */
function commerce_cardonfile_update_form($form, &$form_state, $card_data) {
  // Load the credit card helper functions from the Payment module.
  module_load_include('inc', 'commerce_payment', 'includes/commerce_payment.credit_card');

  $form['card_data'] = array(
    '#type' => 'value',
    '#value' => $card_data,
  );

  $defaults = array(
    'owner' => $card_data['card_name'],
    'number' => t('(Last 4): @number', array('@number' => $card_data['card_number'])),
    'exp_month' => $card_data['card_exp_month'],
    'exp_year' => $card_data['card_exp_year'],
  );

  $form += commerce_payment_credit_card_form(array('owner' => TRUE), $defaults);
  $form['credit_card']['number']['#description'] = t('Leaving this field alone will leave the current card number unchanged.');

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update card data'),
    '#suffix' => l(t('Cancel'), 'user/' . $card_data['uid'] . '/stored-payment-methods'),
  );

  return $form;
}

/**
 * Form validate handler: update stored card data.
 */
function commerce_cardonfile_update_form_validate($form, &$form_state) {
  // Ensure non-default values are valid numbers.
  if ($form_state['values']['credit_card']['number'] != $form['credit_card']['number']['#default_value']) {
    if (!commerce_payment_validate_credit_card_number($form_state['values']['credit_card']['number'])) {
      form_set_error('credit_card][number', t('The credit card number you entered is invalid.'));
    }
  }

  // Ensure the expiration date is not being updated to a past date.
  $exp_valid = commerce_payment_validate_credit_card_exp_date($form_state['values']['credit_card']['exp_month'], $form_state['values']['credit_card']['exp_year']);

  if ($exp_valid !== TRUE) {
    form_set_error('credit_card][exp_' . $exp_valid, t('You have specified an expired credit card.'));
  }
}

/**
 * Form submit handler: update stored card data.
 */
function commerce_cardonfile_update_form_submit($form, &$form_state) {
  // Update the card data with items from the form.
  $card_data = $form_state['values']['card_data'];
  $card_data['card_name'] = $form_state['values']['credit_card']['owner'];

  // Only update the last 4 if we were given a new valid credit card number.
  if ($form_state['values']['credit_card']['number'] != $form['credit_card']['number']['#default_value']) {
    $card_data['card_number'] = substr($form_state['values']['credit_card']['number'], -4);
  }

  $card_data['card_exp_month'] = $form_state['values']['credit_card']['exp_month'];
  $card_data['card_exp_year'] = $form_state['values']['credit_card']['exp_year'];

  // Invoke the payment method's card update callback.
  $payment_method = commerce_payment_method_instance_load($card_data['instance_id']);
  $callback = $payment_method['cardonfile']['update callback'];

  if (function_exists($callback)) {
    if (!$callback($form, $form_state, $payment_method, $card_data)) {
      // Display a message if we failed to communicate properly with the payment
      // gateway in the Card on File update callback.
      drupal_set_message(t('We encountered an error attempting to update your card data. Please try again and contact us if this error persists.'), 'error');
      $form_state['rebuild'] = TRUE;
      return;
    }
  }

  commerce_cardonfile_data_save($card_data);

  drupal_set_message(t('The stored card data has been updated.'));

  // Redirect to the payment methods tab if the user has other stored payment.
  $stored_cards = commerce_cardonfile_data_load_multiple($card_data['uid']);

  if (!empty($stored_cards)) {
    $form_state['redirect'] = 'user/' . $card_data['uid'] . '/stored-payment-methods';
  }
  else {
    $form_state['redirect'] = 'user/' . $card_data['uid'];
  }
}

/**
 * Builds the form for deleting cardonfile data.
 *
 * @param $card_data
 *   The data array representing a card on file.
 */
function commerce_cardonfile_delete_form($form, &$form_state, $card_data) {
  $form['card_data'] = array(
    '#type' => 'value',
    '#value' => $card_data,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete this card data?'),
    'user/' . $card_data['uid'] . '/stored-payment-methods',
    theme('card_data_overview', array('card_data' => $card_data)),
    t('Delete')
  );
}

/**
 * Form submit handler: delete stored card data.
 */
function commerce_cardonfile_delete_form_submit($form, &$form_state) {
  $card_data = $form_state['values']['card_data'];

  // Invoke the payment method's card delete callback.
  $payment_method = commerce_payment_method_instance_load($card_data['instance_id']);
  $callback = $payment_method['cardonfile']['delete callback'];

  if (function_exists($callback)) {
    if (!$callback($form, $form_state, $payment_method, $card_data)) {
      // Display a message if we failed to communicate properly with the payment
      // gateway in the Card on File delete callback.
      drupal_set_message(t('We encountered an error attempting to delete your card data. Please try again and contact us if this error persists.'), 'error');
      $form_state['redirect'] = 'user/' . $card_data['uid'] . '/stored-payment-methods';
      return;
    }
  }

  // Disable the card data but retain the record.
  $card_data['status'] = 0;
  commerce_cardonfile_data_save($card_data);

  drupal_set_message(t('The stored card data has been deleted.'));

  // Redirect to the payment methods tab if the user has other stored payment.
  $stored_cards = commerce_cardonfile_data_load_multiple($card_data['uid']);

  if (!empty($stored_cards)) {
    $form_state['redirect'] = 'user/' . $card_data['uid'] . '/stored-payment-methods';
  }
  else {
    $form_state['redirect'] = 'user/' . $card_data['uid'];
  }
}
