<?php

class LegiestSubscriptionEntityController extends EntityAPIController {
  /**
   * Implements EntityAPIControllerInterface::create().
   */
  public function create(array $values = array()) {
    // merge in defaults
    $values += array(
      'is_new' => empty($values[$this->idKey]),
    );

    // call create
    return parent::create($values);
  }

  /**
   * Implements EntityAPIControllerInterface::save()
   *
   * @param $entity
   *   The full entity object to save.
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   *
   * @return
   *   The saved entity object.
   */
  public function save($entity, DatabaseTransaction $transaction = NULL) {
    $transaction = isset($transaction) ? $transaction : db_transaction();

    // determine is_new
    $is_new = TRUE;
    if (!empty($entity->{$this->idKey})) {
      // if have an id, always update
      unset($entity->is_new);
      $is_new = FALSE;
    }
    elseif (isset($entity->is_new)) {
      // let entity tell us if we're new
      $is_new = $entity->is_new;
    }
    else {
      // default to new
      $is_new = TRUE;
      $entity->is_new = TRUE;
    }

    try {
      $entity->changed = REQUEST_TIME;
      if ($is_new) {
        // Set properties for new entities
        if (!isset($entity->created) || empty($entity->created)) {
          $entity->created = REQUEST_TIME;
        }
      }

      // clone for save so that we dont alter entity object to the serialized arrays
      $clone = clone($entity);
      $return = parent::save($clone, $transaction);

      // alter actual entity after successful save
      if ($return) {
        unset($entity->is_new);
        unset($entity->original);

        // add id
        if ($is_new) {
          $entity->{$this->idKey} = $clone->{$this->idKey};
        }
      }

      return $return;
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }
  }

  /**
   * Implements EntityAPIControllerInterface::delete().
   * Deletes multiple entities by ID.
   *
   * @param $ids
   *   An array of entity IDs to delete.
   *
   * @param $transaction
   *   Optionally a DatabaseTransaction object to use. Allows overrides to pass
   *   in their transaction object.
   */
  public function delete($ids, DatabaseTransaction $transaction = NULL) {
    if (empty($ids)) {
      return TRUE;
    }

    // load entities
    $entities = $this->load($ids);
    if (empty($entities)) {
      return TRUE;
    }

    // initialize transaction db
    $transaction = isset($transaction) ? $transaction : db_transaction();

    // delete licenses
    try {
      parent::delete($ids, $transaction);
    }
    catch (Exception $e) {
      $transaction->rollback();
      watchdog_exception($this->entityType, $e);
      throw $e;
    }

    return TRUE;
  }

  /**
   * Access callback
   */
  public function access($op = 'view', $entity = NULL, $account = NULL) {
    return entity_access($op, $this->entityType, $entity, $account);
  }

}
