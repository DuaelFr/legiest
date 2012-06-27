<?php

/**
 * @file
 * The controller for the subscription entity containing the CRUD operations.
 */

/**
 * The controller class for subscriptions contains methods for the subscription CRUD
 * operations. The load method is inherited from the default controller.
 */
class CommerceSubscriptionRecurranceEntityController extends DrupalDefaultEntityController {

  /**
   * Create a default subscription.
   *
   * @return
   *   A subscription object with all default fields initialized.
   */
  public function create() {
    return (object) array(
      'subscription_recurrance_id' => NULL,
      'subscription_id' => NULL,
      'type' => 1,
      'sequence' => 1,
      'payment' => NULL,
    );
  }

  /**
   * Saves a subscription.
   *
   * @param $subscription
   *   The full subscription object to save.
   *
   * @return
   *   The saved subscription object.
   */
  public function save($subscription) {
    $transaction = db_transaction();

    try {
      $subscription->changed = REQUEST_TIME;

      // Give modules the opportunity to prepare field data for saving.;
      rules_invoke_all('commerce_subscription_recurrance_presave', $subscription);
      field_attach_presave('commerce_subscription_recurrance', $subscription);

      // If this is a new subscription...
      if ((isset($subscription->is_new) && $subscription->is_new) || empty($subscription->subscription_id)) {
        // Set the creation timestamp if not set.
        if (!isset($subscription->created) || empty($subscription->created)) {
          $subscription->created = REQUEST_TIME;
        }

        // Save the new subscription and fields.
        drupal_write_record('commerce_subscription_recurrance', $subscription);
        field_attach_insert('commerce_subscription_recurrance', $subscription);

        $op = 'insert';
      }
      else {
        // Invoke presave to let modules react before the save.
        // rules_invoke_all('commerce_subscription_recurrance_presave', $subscription);
        // Save the updated subscription and fields.
        drupal_write_record('commerce_subscription_recurrance', $subscription, 'subscription_id');
        field_attach_update('commerce_subscription_recurrance', $subscription);

        $op = 'update';
      }

      // Keep product here, as subscriptions are products, really... Maybe?
      // module_invoke_all('commerce_product_' . $op, $subscription);
      // module_invoke_all('entity_' . $op, $subscription, 'commerce_product');

      // rules_invoke_event('commerce_subscription_recurrance_' . $op, $subscription);

      // Ignore slave server temporarily to give time for the
      // saved subscription to be propagated to the slave.
      db_ignore_slave();

      return $subscription;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception('commerce_subscription_recurrance', $e);
      throw $e;
    }
  }

  /**
   * Unserializes the data property of loaded subscriptions.
   */
  /* - Not required, no serialised data.
  public function attachLoad(&$queried_subscriptions, $revision_id = FALSE) {
    foreach ($queried_subscriptions as $subscription_id => &$subscription) {
      $subscription->data = unserialize($subscription->data);
    }

    // Call the default attachLoad() method. This will add fields and call
    // hook_commerce_subscription_recurrance_load().
    parent::attachLoad($queried_subscriptions, $revision_id);
  }
  */

  /**
   * Deletes multiple subscriptions by ID.
   *
   * @param $subscription_ids
   *   An array of subscription IDs to delete.
   *
   * @return
   *   TRUE on success, FALSE otherwise.
   */
  public function delete($subscription_ids) {
    if (!empty($subscription_ids)) {
      $subscriptions = $this->load($subscription_ids, array());

      // Ensure the subscriptions can actually be deleted.
      foreach ((array) $subscriptions as $subscription_id => $subscription) {
        if (in_array(FALSE, module_invoke_all('commerce_subscription_recurrance_can_delete', $subscription))) {
          unset($subscriptions[$subscription_id]);
        }
      }

      // If none of the specified subscriptions can be deleted, return FALSE.
      if (empty($subscriptions)) {
        return FALSE;
      }

      $transaction = db_transaction();

      try {
        db_delete('commerce_subscription_recurrance')
          ->condition('subscription_id', $subscription_ids, 'IN')
          ->execute();

        foreach ($subscriptions as $subscription_id => $subscription) {
          module_invoke_all('commerce_subscription_recurrance_delete', $subscription);
          field_attach_delete('commerce_subscription_recurrance', $subscription);
          rules_invoke_event('commerce_subscription_recurrance_delete', $subscription);
        }

        // Ignore slave server temporarily to give time for the
        // saved subscription to be propagated to the slave.
        db_ignore_slave();
      }
      catch (Exception $e) {
        $transaction->rollback();
        watchdog_exception('commerce_subscription_recurrance', $e);
        throw $e;
      }

      // Clear the page and block and subscription_load_multiple caches.
      cache_clear_all();
      $this->resetCache();
    }

    return TRUE;
  }
}
