<?php

/**
 * Implements hook_rules_condition_info().
 */
function commerce_physical_rules_condition_info() {

  $conditions = array();

  $conditions['commerce_physical_rules_order_is_under_weight_limit'] = array(
    'label' => t("Order's total weight is under a chosen limit"),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'limit' => array(
        'type' => 'decimal',
        'label' => t('Weight limit'),
      ),
      'unit' => array(
        'type' => 'text',
        'label' => t('Weight unit'),
        'options list' => 'physical_weight_unit_options',
        'restriction' => 'input',
        'default value' => 'kg',
      ),
    ),
    'group' => t('Commerce Physical'),
  );

  $conditions['commerce_physical_rules_order_maximum_dimension_is_under_size'] = array(
    'label' => t("The maximum dimension of any product in the order is under a certain size"),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
      'limit' => array(
        'type' => 'decimal',
        'label' => t('Size limit'),
      ),
      'unit' => array(
        'type' => 'text',
        'label' => t('Dimension unit'),
        'options list' => 'physical_dimension_unit_options',
        'restriction' => 'input',
        'default value' => 'cm',
      ),
    ),
    'group' => t('Commerce Physical'),
  );

  $conditions['commerce_physical_rules_order_is_shippable'] = array(
    'label' => t("The order contains shippable products"),
    'parameter' => array(
      'commerce_order' => array(
        'type' => 'commerce_order',
        'label' => t('Order'),
      ),
    ),
    'group' => t('Commerce Physical'),
  );

  return $conditions;
}

/**
 * Rules condition: checks to see if the maximum dimension of any product in the
 * order is under a certain size
 */
function commerce_physical_rules_order_maximum_dimension_is_under_size($order, $limit, $unit) {

  $max_dimension = 0;

  $dimension_keys = array(
    'length',
    'width',
    'height',
  );

  // Get the dimensions of every product in the order
  foreach (commerce_physical_order_dimensions($order, $unit) as $dimension) {

    // Check each of length / width / height
    foreach ($dimension_keys as $dimension_key) {

      // If this dimension's bigger than the current max, it's the new max.
      if ($dimension[$dimension_key] > $max_dimension) {
        $max_dimension = $dimension[$dimension_key];
      }
    }
  }

  return $max_dimension <= $limit;
}

/**
 * Rules condition: checks to see if the given order's total weight is under a
 * certain limit.
 */
function commerce_physical_rules_order_is_under_weight_limit($order, $limit, $unit) {

  $order_weight = commerce_physical_order_weight($order, $unit);

  return $order_weight['weight'] <= $limit;
}

/**
 * Rules condition: check if the order contains shippable products.
 */
function commerce_physical_rules_order_is_shippable($order) {
  return commerce_physical_order_shippable($order);
}
