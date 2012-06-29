<?php

/**
 * @file
 * Field handler for a subscription delete link.
 */

/**
 * Field handler to present a subscription delete link.
 */
class legiest_subscription_handler_field_subscription_link_delete extends legiest_subscription_handler_field_subscription_link {
  function render($values) {
    $entity_id = $this->get_value($values, 'subscription_id');

    if (!empty($entity_id)) {
      $entity = legiest_subscription_load($entity_id);

      if ($entity->access('delete') && ($uri = $entity->uri())) {
        $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
        return l($text, $uri['path'] . '/delete', array('query' => drupal_get_destination()) + $uri);
      }
    }
  }
}
