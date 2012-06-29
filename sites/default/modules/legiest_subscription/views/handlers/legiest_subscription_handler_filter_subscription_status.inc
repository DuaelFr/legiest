<?php

/**
 * @file
 * Filter handler for a subscription status.
 */

/**
 * Filter by subscription status
 */
class legiest_subscription_handler_filter_subscription_status extends views_handler_filter_in_operator {
  function get_value_options() {
    if (!isset($this->value_options)) {
      $this->value_title = t('Status');
      $this->value_options = legiest_subscription_status_options_list();
    }
  }
}
