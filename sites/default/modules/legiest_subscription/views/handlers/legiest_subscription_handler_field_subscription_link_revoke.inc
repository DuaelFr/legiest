<?php

/**
 * @file
 * Field handler for a subscription edit link.
 */

/**
 * Field handler to present a subscription edit link.
 */
class legiest_subscription_handler_field_subscription_link_revoke extends legiest_subscription_handler_field_subscription_link {
  function render($values) {
    $entity_id = $this->get_value($values, 'subscription_id');

    if (!empty($entity_id)) {
      $entity = legiest_subscription_load($entity_id);

      if ($entity->access('create') && ($uri = $entity->uri())) {
        $text = !empty($this->options['text']) ? $this->options['text'] : t('clone');
        return l($text, $uri['path'] . '/revoke', array('query' => drupal_get_destination()) + $uri);
      }
    }
  }
}
