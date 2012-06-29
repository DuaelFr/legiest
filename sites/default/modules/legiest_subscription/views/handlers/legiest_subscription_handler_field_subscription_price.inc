<?php

/**
 * @file
 * Field handler for a subscription price.
 */

/**
 * Field handler to translate a subscription price into its readable form.
 */
class legiest_subscription_handler_field_subscription_price extends views_handler_field {
  function render($values) {
    $product = $values->_field_data['commerce_product_legiest_subscription_product_id']['entity'];
    $price = commerce_product_calculate_sell_price($product);
    $price2 = commerce_price_component_add($price, 'vat', commerce_tax_rate_load('tva_standard'), FALSE);
dsm($price);
dsm($price2);
    $unit_price = $values->field_commerce_price[0]['raw']['amount'];
    $qty        = $values->legiest_subscription_duration;
    $price      = $unit_price * $qty;

    return $price . ' €';
  }

  /**
   * Called to add the field to a query.
   */
  function query() {
  }
  
}
