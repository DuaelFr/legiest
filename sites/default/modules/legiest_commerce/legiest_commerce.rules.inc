<?php
/**
 * @file
 * legiest_commerce rules
 */

/**
 * Implements hook_rules_condition_info().
 */
function legiest_commerce_rules_condition_info() {
  return array(
    'legiest_commerce_rules_condition_is_shippable' => array(
      'label' => t('Order needs shipping'),
      'parameter' => array(
        'commerce_order' => array(
          'type' => 'commerce_order',
          'label' => t('Order'),
          'description' => t('The order whose line items should be checked for the shippable products.'),
        ),
      ),
      'group' => t('Commerce Shipping'),
    ),
    'legiest_commerce_rules_condition_user_special' => array(
      'label' => t('User is special'),
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('The user who may be special (ie have the "use special order states" permission).'),
        ),
      ),
      'group' => t('User'),
    ),
  );
}

/**
 * Rules condition 'rules_condition_is_shippable' execution callback.
 */
function legiest_commerce_rules_condition_is_shippable($order) {
  $shippable = FALSE;

  // If we actually received a valid order...
  if (!empty($order)) {
    $order_wrapper = entity_metadata_wrapper('commerce_order', $order);

    // Populate the array of the quantities of the products on the order.
    foreach ($order_wrapper->commerce_line_items as $delta => $line_item_wrapper) {
      if (in_array($line_item_wrapper->type->value(), commerce_product_line_item_types())) {
        $line_item_type = $line_item_wrapper->commerce_product->type->value();
        if ($line_item_type == 'product_standard') {
          $shippable = TRUE;
          break;
        }
      }
    }
  }

  return $shippable;
}

/**
 * Rules condition 'legiest_commerce_rules_condition_user_special' execution callback.
 */
function legiest_commerce_rules_condition_user_special($user) {
  return user_access('use special order states', $user);
}
