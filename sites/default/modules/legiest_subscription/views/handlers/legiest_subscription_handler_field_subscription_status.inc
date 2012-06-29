<?php

/**
 * @file
 * Field handler for a subscription status.
 */

/**
 * Field handler to translate a subscription status into its readable form.
 */
class legiest_subscription_handler_field_subscription_status extends legiest_subscription_handler_field_subscription {
  function render($values) {
    $name = $this->get_value($values);
    $title = legiest_subscription_status_get_title($name);

    // Only attempt to render a valid subscription status.
    if (!empty($title) && !is_array($title)) {
      return $this->render_link($this->sanitize_value($title), $values);
    }
  }
}
