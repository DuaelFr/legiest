<?php

/**
 * @file
 * Coupon..
 *
 * This file contains...
 */

class CommerceCoupon extends Entity {
  public $is_active = TRUE;
  public $type;
  
  public function __construct($values = array()) {
    // Allow passing in the type entity.
    if (isset($values['type']) && is_object($values['type'])) {
      $values['type'] = $values['type']->type;
    }
    parent::__construct($values, 'commerce_coupon');
  }
  public function save() {
    if (!isset($this->created) || empty($this->created)) {
      $this->created = REQUEST_TIME;
    }
    $this->changed = REQUEST_TIME;
    
    // Generate a code if no is set:
    $coupon_wrapper = entity_metadata_wrapper('commerce_coupon', $this);
    $code = $coupon_wrapper->commerce_coupon_code->value();
    if (!isset($code) || empty($code)) {
      $coupon_wrapper->commerce_coupon_code = commerce_coupon_generate_coupon_code();
    }
    return parent::save();
  }
}

