<?php

/**
 * @file
 * Page callbacks and form callbacks for user addressbook pages.
 */

/**
 * Page callback for creating a customer profile of a given type.
 */
function commerce_addressbook_profile_create($account, $profile_type) {
  $profile = commerce_customer_profile_new($profile_type, $account->uid);
  module_load_include('inc', 'commerce_customer', 'includes/commerce_customer_profile.forms');
  return drupal_get_form('commerce_addressbook_customer_profile_form', $profile);
}

/**
 * Page callback for editing a customer profile.
 */
function commerce_addressbook_profile_options_edit($account, $customer_profile) {
  // Add the breadcrumb for the form's location.
  commerce_addressbook_set_breadcrumb($account, $customer_profile->type);

  // If the profile is referenced by an order, make sure it gets duplicated.
  $profile = clone($customer_profile);
  if (!commerce_customer_profile_can_delete($customer_profile)) {
    $profile->previous_id = $profile->profile_id;
    unset($profile->profile_id);
    unset($profile->revision_id);
    $profile->is_new = TRUE;
  }
  module_load_include('inc', 'commerce_customer', 'includes/commerce_customer_profile.forms');
  return drupal_get_form('commerce_addressbook_customer_profile_options_edit', $profile);
}

/**
 * Submit handler for commerce_addressbook_customer_profile_options_edit form.
 */
function commerce_addressbook_customer_profile_options_edit_submit($form, &$form_state) {
  list($profile) = $form_state['build_info']['args'];

  // The profile has been duplicated.
  // Disable the previous one to prevent it from showing up in listings.
  if (!empty($profile->previous_id)) {
    $old_profile = commerce_customer_profile_load($profile->previous_id);
    $old_profile->status = 0;
    commerce_customer_profile_save($old_profile);

    // If the old profile was the default, then we need to set the new one
    // as the default.
    $default_profile_id = commerce_addressbook_get_default_profile_id($profile->uid, $profile->type);
    if ($old_profile->profile_id == $default_profile_id) {
      commerce_addressbook_set_default_profile($profile);
    }
  }

  $form_state['redirect'] = 'user/' . $profile->uid . '/addressbook/' . $profile->type;
}

/**
 * Page callback for deleting a customer profile.
 *
 * @see confirm_form()
 * @see commerce_addressbook_profile_options_delete_form_submit()
 */
function commerce_addressbook_profile_options_delete_form($form, $form_state, $account, $customer_profile) {
  // Add the breadcrumb for the form's location.
  commerce_addressbook_set_breadcrumb($account, $customer_profile->type);

  $form_state['profile'] = $customer_profile;

  $content = entity_view('commerce_customer_profile', array($customer_profile->profile_id => $customer_profile));

  $form = confirm_form($form,
    t('Are you sure you want to delete this address?'),
    'user/' . $customer_profile->uid . '/addressbook/' . $customer_profile->type,
    drupal_render($content) . '<p>' . t('Deleting this address cannot be undone.') . '</p>',
    t('Delete'),
    t('Cancel'),
    'confirm'
  );

  return $form;
}

/**
 * Submit handler for commerce_addressbook_profile_options_delete_form.
 *
 * Deletes the customer profile if possible (when it's not referenced by any
 * orders), disables it otherwise.
 */
function commerce_addressbook_profile_options_delete_form_submit($form, &$form_state) {
  $customer_profile = $form_state['profile'];
  if (commerce_customer_profile_can_delete($customer_profile)) {
    commerce_customer_profile_delete($customer_profile->profile_id);
  }
  else {
    $customer_profile->status = 0;
    commerce_customer_profile_save($customer_profile);
  }
  $form_state['redirect'] = 'user/' . $customer_profile->uid . '/addressbook/' . $customer_profile->type;
}

/**
 * Page callback for setting a customer profile as default.
 * Used for both ajax and non-ajax delivery of the customer profile updates.
 */
function commerce_addressbook_profile_options_default($account, $customer_profile, $type = 'ajax') {
  commerce_addressbook_set_default_profile($customer_profile);
  if ($type == 'ajax') {
    $commands = array();
    $commands[] = ajax_command_replace('#commerce-addressbook-' . $customer_profile->type . '-default', '<div id="commerce-addressbook-' . $customer_profile->type . '-default">' . views_embed_view('commerce_addressbook_defaults', 'default', $account->uid, $customer_profile->type) . '</div>');
    $commands[] = ajax_command_replace('#commerce-addressbook-' . $customer_profile->type . '-list', '<div id="commerce-addressbook-' . $customer_profile->type . '-list">' . views_embed_view('commerce_addressbook', 'default', $account->uid, $customer_profile->type) . '</div>');
    ajax_deliver(array('#type' => 'ajax', '#commands' => $commands));
  }
  else {
    drupal_goto('user/' . $account->uid . '/addressbook/' . $customer_profile->type);
  }
}

/**
 * Page callback for listing customer profiles of a certain type.
 *
 * Embeds a view that shows the current default profile, and a view that shows
 * all other profiles of the same type.
 */
function commerce_addressbook_profile_page($account, $profile_type) {
  $output = '';
  $output .= '<div id="commerce-addressbook-' . $profile_type . '-default">' . views_embed_view('commerce_addressbook_defaults', 'default', $account->uid, $profile_type) . '</div>';
  $output .= '<div id="commerce-addressbook-' . $profile_type . '-list">' . views_embed_view('commerce_addressbook', 'default', $account->uid, $profile_type) . '</div>';
  return $output;
}

/**
 * Sets the breadcrumb for address book forms.
 *
 * @param $account
 *   The user object.
 * @param $profile_type
 *   The machine-readable name of the customer profile type
 */
function commerce_addressbook_set_breadcrumb($account, $profile_type) {
  $type_name = commerce_customer_profile_type_get_name($profile_type);
  $breadcrumb = array(
    l(t('Home'), '<front>'),
    l($account->name, 'user/' . $account->uid),
    l(t('Address Book'), 'user/' . $account->uid . '/addressbook'),
    l($type_name, 'user/' . $account->uid . '/addressbook/' . $profile_type),
  );

  drupal_set_breadcrumb($breadcrumb);
}
