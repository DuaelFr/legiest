<?php

/**
 * @file
 * Field handler for a subscription duration.
 */

/**
 * Field handler to translate a subscription duration into its readable form.
 */
class legiest_subscription_handler_field_subscription_duration extends legiest_subscription_handler_field_subscription {
  function render($values) {
    $count = $this->get_value($values);
    $title = format_plural($count, '1 month', '@count months');

    // Only attempt to render a valid subscription duration.
    if (!empty($title) && !is_array($title)) {
      return $this->render_link($this->sanitize_value($title), $values);
    }
  }
}
