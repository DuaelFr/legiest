<?php

/**
 * @file
 * Handles file licenses and file license logs
 */


// -----------------------------------------------------------------------
// Definitions

/**
 * Implements hook_commerce_file_license_state_info().
 */
function commerce_file_commerce_file_license_state_info() {
  $states = array();

  $states['denied'] = array(
    'name' => 'denied',
    'title' => t('Denied'),
    'description' => t('Licenses in this state cannot be accessed by the owner.'),
    'weight' => -10,
    'default_status' => 'revoked',
  );
  $states['allowed'] = array(
    'name' => 'allowed',
    'title' => t('Allowed'),
    'description' => t('Licenses in this state can be accessed by the owner.'),
    'weight' => 0,
    'default_status' => 'active',
  );
  return $states;
}

/**
 * Implements hook_commerce_file_license_status_info().
 */
function commerce_file_commerce_file_license_status_info() {
  $statuses = array();

  $statuses['pending'] = array(
    'name' => 'pending',
    'title' => t('Pending'),
    'state' => 'denied',
    'weight' => -1,
    'default' => TRUE,
  );
  $statuses['active'] = array(
    'name' => 'active',
    'title' => t('Active'),
    'state' => 'allowed',
    'weight' => 0,
  );
  /** @todo: remove 'canceled' now that 'revoked' is added ?? **************/
  $statuses['canceled'] = array(
    'name' => 'canceled',
    'title' => t('Canceled'),
    'state' => 'denied',
    'weight' => 1,
  );
  $statuses['revoked'] = array(
    'name' => 'revoked',
    'title' => t('Revoked'),
    'state' => 'denied',
    'weight' => 2,
  );

  return $statuses;
}


// -----------------------------------------------------------------------
// File License API

/**
 * Create a commerce_file_license
 */
function commerce_file_license_create($values = array()) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_ENTITY_NAME)->create($values);
}

/**
 * Save a commerce_file_license
 *
 * @param $entity
 *   An entity object - OR - an array of values
 */
function commerce_file_license_save($entity) {
  if (is_array($entity)) {
    return entity_get_controller(COMMERCE_FILE_LICENSE_ENTITY_NAME)->create($entity)->save();
  }

  return entity_get_controller(COMMERCE_FILE_LICENSE_ENTITY_NAME)->save($entity);
}

/**
 * Delete a single commerce_file_license.
 *
 * @param $id
 *   The uniform identifier of the entity to delete.
 *
 * @return
 *   FALSE, if there were no information how to delete the entity.
 */
function commerce_file_license_delete($id) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_ENTITY_NAME)->delete(array($id));
}

/**
 * Delete multiple commerce_file_license.
 *
 * @param $ids
 *   An array of uniform identifiers of the entities to delete.
 * @return
 *   FALSE if the given entity type isn't compatible to the CRUD API.
 */
function commerce_file_license_delete_multiple($ids) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_ENTITY_NAME)->delete($ids);
}

/**
 * Load a single commerce_file_license
 *
 * @param $id
 *   A single entity ID.
 * @return
 *   An entity object.
 */
function commerce_file_license_load($id = NULL) {
  if (empty($id)) {
    return FALSE;
  }

  $entity = commerce_file_license_load_multiple(array($id));
  return $entity ? reset($entity) : FALSE;
}

/**
 * Load multiple commerce_file_licenses based on certain conditions.
 *
 * @param $ids
 *   An array of entity IDs.
 * @return
 *   An array of entity objects, indexed by id.
 */
function commerce_file_license_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  if (empty($ids) && empty($conditions)) {
    return array();
  }
  return entity_load(COMMERCE_FILE_LICENSE_ENTITY_NAME, $ids, $conditions, $reset);
}

/**
 * Return wrapper object for a given license
 */
function commerce_file_license_wrapper($entity) {
  return entity_metadata_wrapper(COMMERCE_FILE_LICENSE_ENTITY_NAME, $entity);
}

/**
 * Load all licenses for given account
 *
 * @param $account
 *   A user object.
 * @return
 *   An array of entity objects, indexed by id.
 */
function commerce_file_license_user_licenses($account = NULL) {
  global $user;
  $licenses = array();

  if (!isset($account)) {
    $account = $user;
  }
  if (isset($account->uid)) {
    $licenses = commerce_file_license_load_multiple(FALSE, array('uid' => $account->uid));
  }

  return $licenses;
}

/**
 * Return all license ids for specified files
 *
 * @param $fids
 *   An array of file fids
 * @param $line_item_ids
 *   An array of line_item_ids
 * @param $account
 *   A user object of the license owner
 * @return
 *   An array of license ids
 */
function _commerce_file_license_query($fids = array(), $line_item_ids = array(), $account = NULL) {
  $entity_ids = array();
  $entity_type = COMMERCE_FILE_LICENSE_ENTITY_NAME;
  $is_filtered = FALSE;

  // initialize query
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', $entity_type, '=');

  if (!empty($account)) {
    // kick anonymous or bad object
    if (empty($account->uid)) {
      return array();
    }
    $query->propertyCondition('uid', $account->uid, '=');
    $is_filtered = TRUE;
  }

  // add file fid condition
  if (!empty($fids)) {
    // determine if there are any file field types on licenses entities
    $file_fields = commerce_info_fields(COMMERCE_FILE_FIELD_TYPE, $entity_type);
    if (!empty($file_fields)) {
      foreach ($file_fields as $field_name => $field_info) {
        $query->fieldCondition($field_name, 'fid', $fids, 'IN');
      }
      $is_filtered = TRUE;
    }
  }

  // add line item id condition
  if (!empty($line_item_ids)) {
    // determine if there are any file field types on licenses entities
    $line_fields = commerce_info_fields('commerce_line_item_reference', $entity_type);
    if (!empty($line_fields)) {
      foreach ($line_fields as $field_name => $field_info) {
        $query->fieldCondition($field_name, 'line_item_id', $line_item_ids, 'IN');
      }
      $is_filtered = TRUE;
    }
  }

  // perform query
  if ($is_filtered) {
    $result = $query->execute();
    if (!empty($result)) {
      $entity_ids = array_keys($result[$entity_type]);
    }
  }

  return $entity_ids;
}

/**
 * Return all licenses for specified files
 *
 * @param $fids
 *   An array of file fids
 * @param $account
 *   A user object of the license owner
 *   - if empty all licenses for $fids is returned
 * @return
 *   An array of license entities
 */
function commerce_file_license_load_by_property($fids = array(), $line_item_ids = array(), $account = NULL) {
  $ids = _commerce_file_license_query($fids, $line_item_ids, $account);
  return !empty($ids) ? commerce_file_license_load_multiple($ids) : array();
}

/**
 * Load all 'allowed' licenses for given account
 *
 * @param $account
 *   A user object.
 * @return
 *   An array of entity objects, indexed by id.
 */
function commerce_file_license_user_allowed_licenses($account = NULL) {
  global $user;
  $licenses = array();

  if (!isset($account)) {
    $account = $user;
  }
  if (isset($account->uid)) {
    $allowed_statuses = commerce_file_license_statuses(array('state' => 'allowed'));
    $licenses = commerce_file_license_load_multiple(FALSE, array('uid' => $account->uid, 'status' => $allowed_statuses));
  }

  return $licenses;
}

/**
 * Generate an array for rendering the given commerce_file_license.
 *
 * @param $entity_type
 *   The type of the entity.
 * @param $entity
 *   An entity object.
 * @param $view_mode
 *   A view mode as used by this entity type, e.g. 'full', 'teaser'...
 * @param $langcode
 *   (optional) A language code to use for rendering. Defaults to the global
 *   content language of the current request.
 * @return
 *   The renderable array.
 */
function commerce_file_license_build_content($entity, $view_mode = 'full', $langcode = NULL) {
  return entity_build_content(COMMERCE_FILE_LICENSE_ENTITY_NAME, $entity, $view_mode, $langcode);
}

/**
 * Callback for getting properties.
 * @see commerce_file_entity_property_info()
 */
function commerce_file_license_property_getter($entity, array $options, $name) {
  try {
    return $entity->$name;
  }
  catch (Exception $e) {
    return NULL;
  }
}

/**
 * Callback for setting properties.
 * @see commerce_file_entity_property_info()
 */
function commerce_file_license_property_setter($entity, $name, $value) {
  try {
   $entity->$name = $value;
  }
  catch (Exception $e) {
    // pass
  }
}


// -----------------------------------------------------------------------
// Status / State Handling

/**
 * Returns an array of all the license states keyed by name.
 *
 * License states can only be defined by modules. When this function is first
 * called, it will load all the states as defined by
 * hook_commerce_file_license_state_info(). The final array will be cached
 * for subsequent calls.
 *
 * @param $conditions
 *   An array of conditions to filter the returned list by; for example, if you
 *     specify 'state' => 'cart' in the array, then only order states in the
 *     cart state would be included.
 *
 * @return
 *   The array of state objects, keyed by state name.
 */
function commerce_file_license_states() {
  // First check the static cache for an order states array.
  $states = &drupal_static(__FUNCTION__);

  // If it did not exist, fetch the states now.
  if (!isset($states)) {
    $states = module_invoke_all('commerce_file_license_state_info');

    // Give other modules a chance to alter the order states.
    drupal_alter('commerce_file_license_state_info', $states);

    uasort($states, 'drupal_sort_weight');
  }

  return $states;
}

/**
 * Returns an order state object.
 *
 * @param $name
 *   The machine readable name string of the state to return.
 *
 * @return
 *   The fully loaded state object or FALSE if not found.
 */
function commerce_file_license_state_load($name) {
  $states = commerce_file_license_states();

  if (isset($states[$name])) {
    return $states[$name];
  }

  return FALSE;
}

/**
 * Returns the human readable title of any or all order states.
 *
 * @param $name
 *   Optional parameter specifying the name of the order state whose title
 *     should be return.
 *
 * @return
 *   Either an array of all order state titles keyed by name or a string
 *     containing the human readable title for the specified state. If a state
 *     is specified that does not exist, this function returns FALSE.
 */
function commerce_file_license_state_get_title($name = NULL) {
  $states = commerce_file_license_states();

  // Return a state title if specified and it exists.
  if (!empty($name)) {
    if (isset($states[$name])) {
      return $states[$name]['title'];
    }
    else {
      // Return FALSE if it does not exist.
      return FALSE;
    }
  }

  // Otherwise turn the array values into the status title only.
  foreach ($states as $key => $value) {
    $states[$key] = $value['title'];
  }

  return $states;
}

/**
 * Wraps commerce_file_license_state_get_title() for use by the Entity module.
 */
function commerce_file_license_state_options_list() {
  return commerce_file_license_state_get_title();
}


/**
 * Returns an array of some or all of the order statuses keyed by name.
 *
 * Order statuses can only be defined by modules but may have settings
 * overridden that are stored in the database (weight and status). When this
 * function is first called, it will load all the statuses as defined by
 * hook_commerce_file_license_status_info() and update them based on the data in the
 * database. The final array will be cached for subsequent calls.
 *
 * @param $conditions
 *   An array of conditions to filter the returned list by; for example, if you
 *     specify 'state' => 'cart' in the array, then only order statuses in the
 *     cart state would be included.
 *
 * @return
 *   The array of order status objects, keyed by status name.
 */
function commerce_file_license_statuses($conditions = array()) {
  // First check the static cache for an order statuses array.
  $statuses = &drupal_static(__FUNCTION__);

  // If it did not exist, fetch the statuses now.
  if (!isset($statuses)) {
    $statuses = module_invoke_all('commerce_file_license_status_info');

    // Merge in defaults.
    foreach ($statuses as $name => &$status) {
      $defaults = array(
        'weight' => 0,
        'enabled' => TRUE,
      );
      $status += $defaults;
    }
    unset($status);

    // Give other modules a chance to alter the order statuses.
    drupal_alter('commerce_file_license_status_info', $statuses);

    uasort($statuses, 'drupal_sort_weight');
  }

  // Apply conditions to the returned statuses if specified.
  if (!empty($conditions)) {
    $matching_statuses = array();

    foreach ($statuses as $name => $status) {
      // Check the status against the conditions array to determine whether to
      // add it to the return array or not.
      $valid = TRUE;

      foreach ($conditions as $property => $value) {
        // If the current value for the specified property on the pane does not
        // match the filter value...
        if (!isset($status[$property]) || $status[$property] != $value) {
          // Do not add it to the temporary array.
          $valid = FALSE;
        }
      }

      if ($valid) {
        $matching_statuses[$name] = $status;
      }
    }

    return $matching_statuses;
  }

  return $statuses;
}

/**
 * Returns an order status object.
 *
 * @param $name
 *   The machine readable name string of the status to return.
 *
 * @return
 *   The fully loaded status object or FALSE if not found.
 */
function commerce_file_license_status_load($name) {
  $statuses = commerce_file_license_statuses();

  if (isset($statuses[$name])) {
    return $statuses[$name];
  }

  return FALSE;
}

/**
 * Returns the human readable title of any or all order statuses.
 *
 * @param $name
 *   Optional parameter specifying the name of the order status whose title
 *     to return.
 *
 * @return
 *   Either an array of all order status titles keyed by the status_id or a
 *     string containing the human readable title for the specified status. If a
 *     status is specified that does not exist, this function returns FALSE.
 */
function commerce_file_license_status_get_title($name = NULL) {
  $statuses = commerce_file_license_statuses();

  // Return a status title if specified and it exists.
  if (!empty($name)) {
    if (isset($statuses[$name])) {
      return $statuses[$name]['title'];
    }
    else {
      // Return FALSE if it does not exist.
      return FALSE;
    }
  }

  // Otherwise turn the array values into the status title only.
  foreach ($statuses as $key => $value) {
    $statuses[$key] = $value['title'];
  }

  return $statuses;
}

/**
 * Return default status with highest weight
 */
function commerce_file_license_status_default($property = NULL) {
  $default = &drupal_static(__FUNCTION__);
  if (!isset($default)) {
    $default = array();
    if ($defaults = commerce_file_license_statuses(array('default' => TRUE))) {
      $default = reset($defaults);
    }
  }

  if (isset($property)) {
    return isset($default[$property]) ? $default[$property] : NULL;
  }

  return $default;
}


/**
 * Wraps commerce_file_license_status_get_title() for use by the Entity module.
 */
function commerce_file_license_status_options_list() {
  return commerce_file_license_status_get_title();
}

/**
 * Updates the status of a license to the specified status.
 *
 * @param $entity
 *   The fully loaded license object to update.
 * @param $name
 *   The machine readable name string of the status to update to.
 * @param $skip_save
 *   TRUE to skip saving the order after updating the status; used when the
 *     order would be saved elsewhere after the update.
 *
 * @return
 *   The updated order.
 */
function commerce_file_license_status_update($entity, $name, $skip_save = FALSE) {
  // Do not update the status if the order is already at it.
  if ($entity->status != $name) {
    try {
      $entity->status = $name;
      if (!$skip_save) {
        $entity->save();
      }
    }
    catch (Exception $e) {

    }
  }

  return $entity;
}


// -----------------------------------------------------------------------
// Type Handling

/**
 * Set default fields for license types
 */
function commerce_file_license_configure_types($type = COMMERCE_FILE_LICENSE_ENTITY_NAME) {

  // If a field type we know should exist isn't found, clear the Field cache.
  if (!field_info_field_types('commerce_line_item_reference')) {
    field_cache_clear();
  }

  // entity info
  $entity_type = COMMERCE_FILE_LICENSE_ENTITY_NAME;
  $bundle = $type;
  $field_names = _commerce_file_get_field_names();

  // File reference
  _commerce_file_create_file_instance($field_names['license_file'], $entity_type, $bundle, 'Licensed file', 10, 1, TRUE);

  // Line item references
/** @todo make this a custom line item reference to allow admins to add lines to a license - ie. a non line item manager widget ********/
  _commerce_file_create_instance('commerce_line_item_reference', $field_names['license_line_items'], $entity_type, $bundle, array(
      'field' => array(
        'cardinality' => FIELD_CARDINALITY_UNLIMITED,
        'locked' => TRUE,
      ),
      'instance' => array(
        'label' => 'Line item references',
        'widget' => array(
          'type' => 'commerce_line_item_manager',
          'weight' => -10,
        ),
        'display' => array(
          'default' => array(
            'label' => 'above',
            'type' => 'commerce_line_item_reference_view',
            'weight' => 10,
          ),
        ),
      ),
  ));
}

/**
 * Returns the human readable name of any or all entity types.
 *
 * @param $type
 *   Optional parameter specifying the type whose name to return.
 *
 * @return
 *   Either an array of all entity type names keyed by the machine name or a
 *     string containing the human readable name for the specified type. If a
 *     type is specified that does not exist, this function returns FALSE.
 */
function commerce_file_license_type_get_name($type = NULL) {
  $names = array();

  $entity = entity_get_info(COMMERCE_FILE_LICENSE_ENTITY_NAME);

  foreach ($entity['bundles'] as $key => $value) {
    $names[$key] = $value['label'];
  }

  if (empty($type)) {
    return $names;
  }

  if (empty($names[$type])) {
    return check_plain($type);
  }
  else {
    return $names[$type];
  }
}

/**
 * Wraps commerce_file_license_type_get_name() for the Entity module.
 */
function commerce_file_license_type_options_list() {
  return commerce_file_license_type_get_name();
}


// -----------------------------------------------------------------------
// File License Access Control

/**
 * Checks license access for various operations.
 *
 * @param $op
 *   The operation being performed. One of 'view', 'update', 'create' or 'delete'.
 * @param $entity
 *   Entity to check access for or for the create operation the
 *   entity type. If nothing is given access permissions for all entities are returned.
 * @param $account
 *   The user to check for. Leave it to NULL to check for the current user.
 *
 * @return TRUE or FALSE
 */
function commerce_file_license_access($op, $entity, $account = NULL) {
  global $user;
  $entity_type = COMMERCE_FILE_LICENSE_ENTITY_NAME;

  if (!isset($account)) {
    $account = $user;
  }

  // kick anonymous
  if (empty($account->uid)) {
    return FALSE;
  }

  // always allow admins
  if (user_access(COMMERCE_FILE_ADMIN_PERM, $account) || user_access('administer ' . $entity_type, $account)) {
    return TRUE;
  }

  // check access based on operation
  switch ($op) {
    case 'view':
      // if valid license and user has access
      if (user_access('access any ' . $entity_type, $account) || (isset($entity) && isset($entity->uid) && $account->uid == $entity->uid)) {
        return TRUE;
      }
      break;

    case 'create':
      if (user_access('create ' . $entity_type, $account)) {
        return TRUE;
      }
      break;

    case 'update':
    case 'delete':
      if (user_access('edit any ' . $entity_type, $account)) {
        return TRUE;
      }
      break;
  }

  // DENY by default
  return FALSE;
}

/**
 * Retrieve all licenses currently being downloaded
 */
function _commerce_file_license_get_request_licenses($license = NULL) {
  return _commerce_file_license_set_request_license($license);
}

/**
 * Set a license as currently being downloaded
 */
function _commerce_file_license_set_request_license($license) {
  $requests = &drupal_static(__FUNCTION__);
  if (!isset($requests)) {
    $requests = array();
  }
  if (isset($license)) {
    $requests[$license->license_id] = clone $license;
  }

  return $requests;
}


// -----------------------------------------------------------------------
// File License Order handling

/**
 * Issue licenses for files in an order
 */
function commerce_file_license_issue_by_order($order, $updated_license_status = 'pending') {
  // kick anonymous
  if (empty($order->uid)) {
    return array();
  }

  $account = user_load($order->uid);
  if (empty($account->uid)) {
    return array();
  }

  // wrap order and check for any line items
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  if (empty($order_wrapper->commerce_line_items)) {
    return array();
  }

  // issue licenses for each line item
  foreach ($order_wrapper->commerce_line_items as $delta => $line_item_wrapper) {
    commerce_file_license_issue_by_line_item($line_item_wrapper->value(), $order, $updated_license_status);
  }
}

/**
 * Issue licenses for files in a line item
 *
 * @param $line_item
 *   A line item object
 * @param $order
 *   An order object [optional]
 */
function commerce_file_license_issue_by_line_item($line_item, $order = NULL, $updated_license_status = 'pending') {
  $processed = &drupal_static(__FUNCTION__, array());
  $line_item_id = $line_item->line_item_id;

  // exit if we issued this already
  if (empty($line_item->line_item_id) || isset($processed[$line_item_id])) {
    return;
  }

  $line_item_field_name = _commerce_file_get_field_names('line_item_files');
  $license_entity_type = COMMERCE_FILE_LICENSE_ENTITY_NAME;
  $license_info = _commerce_file_collate_license_info();

  // wrap the line
  $line_item_wrapper = entity_metadata_wrapper('commerce_line_item', $line_item);
  $line_item_wrapper = _commerce_file_clean_line_item_wrapper($line_item_wrapper);

  // exit if no files on this line item
  if (empty($line_item_wrapper->{$line_item_field_name})) {
    return;
  }

  // resolve order needed to determine order owner
  if (empty($order)) {
    // attempt to load order off of line item
    $order = commerce_order_load($line_item->order_id);
    if (empty($order)) {
      return;
    }
  }

  // wrap order and determine if owner exists
  $order_wrapper = entity_metadata_wrapper('commerce_order', $order);
  if (empty($order_wrapper->owner)) {
    return;
  }

  // get owner account
  $account = $order_wrapper->owner->value();
  if (empty($account)) {
    return;
  }

  // mark as processed
  $processed[$line_item_id] = TRUE;

  // get existing licenses for this line item and account
  $existing_licenses = commerce_file_license_load_by_property(array(), array($line_item_id), $account);

  // set base values for new licenses
  $new_license_base_values = array('uid' => $account->uid, 'status' => $updated_license_status);

  // set base values for new files attached to licenses
  // - set to empty value since limits propogate from line item ref
  $new_file_base_values = array('data' => array());
  foreach ($license_info as $k => $info) {
    if (isset($info['property info']['zero_value'])) {
      $new_file_base_values['data'][$k] = $info['property info']['zero_value'];
    }
  }

  // create licenses based on line item file field items
  foreach ($line_item_wrapper->{$line_item_field_name} as $field_item) {
    $field_value = $field_item->value();
    $fid = $field_value['fid'];

    // Find any existing license
    if (!empty($existing_licenses)) {
      foreach ($existing_licenses as $existing_license) {
        if (!empty($existing_license->file) && $existing_license->file['fid'] == $fid) {
          // only update first found
          if ($existing_license->status != $updated_license_status) {
            $existing_license->status = $updated_license_status;

            // override state if account cannot view
            if (!$existing_license->access('view', $account)) {
              $existing_license->deny();
            }

            $existing_license->save();
          }

          // break out of $existing_licenses loop
          break 2;
        }
      }
    }

    // if no existing license, create a new license ...
    $license_new = commerce_file_license_create($new_license_base_values);

    // merge data for new file
    $field_value_new = $field_value;
    $field_value_new['data'] = $new_file_base_values['data'];
    if (isset($field_value['data'])) {
      $field_value_new['data'] += $field_value['data'];
    }

    // set new file for license
    $license_new->file = $field_value_new;

    // override state if account cannot view
    if (!$license_new->access('view', $account)) {
      $license_new->deny();
    }

    // attempt to link the line item
    $license_new->link_line_item($line_item_id);

    // save the license
    $license_new->save();

    // update existing licenses
    $existing_licenses[$license_new->internalIdentifier()] = $license_new;

  } // /line item field items
}

/**
 * Update the state of licenses for files in an order
 */
function commerce_file_license_order_update_state($order, $updated_state = 'denied') {
  $line_items = field_get_items('commerce_order', $order, 'commerce_line_items');
  if (empty($line_items)) {
    return;
  }

  // revoke line items for the order
  foreach ($line_items as $delta => $field_item) {
    // try to avoid any locking issues
    try {
      $line_item = commerce_line_item_load($field_item['line_item_id']);
      if (!empty($line_item)) {
        commerce_file_license_line_item_update_state($line_item, $order, $updated_state);
      }
    }
    catch (Exception $e) {
    }
  }
}

/**
 * Update the state of licenses for files on a line item
 *
 * @param $line_item
 *   A line item object
 */
function commerce_file_license_line_item_update_state($line_item, $order = NULL, $updated_state = 'denied') {
  // exit if we issued this already
  if (empty($line_item->line_item_id)) {
    return;
  }

  // get the line item owner
  $account = commerce_file_line_item_owner($line_item, $order);
  if (empty($account)) {
    return;
  }

  // get existing licenses for this line item and account
  $existing_licenses = commerce_file_license_load_by_property(array(), array($line_item->line_item_id), $account);

  // deny all licenses for this line item and account
  foreach ($existing_licenses as $license) {
    $license->set_state($updated_state)->save();
  }
}

/**
 * Update the status of licenses for files in an order
 */
function commerce_file_license_order_update_status($order, $updated_status = 'pending') {
  $line_items = field_get_items('commerce_order', $order, 'commerce_line_items');
  if (empty($line_items)) {
    return;
  }

  // revoke line items for the order
  foreach ($line_items as $delta => $field_item) {
    // try to avoid any locking issues
    try {
      $line_item = commerce_line_item_load($field_item['line_item_id']);
      if (!empty($line_item)) {
        commerce_file_license_line_item_update_status($line_item, $order, $updated_status);
      }
    }
    catch (Exception $e) {
    }
  }
}

/**
 * Update the state of licenses for files on a line item
 *
 * @param $line_item
 *   A line item object
 */
function commerce_file_license_line_item_update_status($line_item, $order = NULL, $updated_status = 'pending') {
  // exit if we issued this already
  if (empty($line_item->line_item_id)) {
    return;
  }

  // get the line item owner
  $account = commerce_file_line_item_owner($line_item, $order);
  if (empty($account)) {
    return;
  }

  // get existing licenses for this line item and account
  $existing_licenses = commerce_file_license_load_by_property(array(), array($line_item->line_item_id), $account);

  // deny all licenses for this line item and account
  foreach ($existing_licenses as $license) {
    $license->set_status($updated_status)->save();
  }
}

/**
 * Deletes any references to the given line item on a commerce file license.
 * @ref commerce_line_item_delete_references()
 */
function _commerce_file_license_line_item_delete_references($line_item) {
  $processed = &drupal_static(__FUNCTION__, array());

  if (empty($line_item->line_item_id) || isset($processed[$line_item->line_item_id])) {
    return;
  }

  // mark as processed
  $processed[$line_item->line_item_id] = TRUE;

  // keep track of updated entities
  $updated = array();

  // Check the data in every line item reference field.
  foreach (commerce_info_fields('commerce_line_item_reference', COMMERCE_FILE_LICENSE_ENTITY_NAME) as $field_name => $field) {
    // Query for any entity referencing the deleted line item in this field.
    $query = new EntityFieldQuery();
    $query->fieldCondition($field_name, 'line_item_id', $line_item->line_item_id, '=');
    $result = $query->execute();

    // If results were returned...
    if (!empty($result)) {
      // Loop over results for each type of entity returned.
      foreach ($result as $entity_type => $data) {
        // Load the entities of the current type.
        $entities = entity_load($entity_type, array_keys($data));

        // Loop over each entity and remove the reference to the deleted line item.
        foreach ($entities as $entity_id => $entity) {
          commerce_entity_reference_delete($entity, $field_name, 'line_item_id', $line_item->line_item_id);
          entity_save($entity_type, $entity);
          $updated[] = $entity_id;
        }
      }
    }
  }

  return $updated;
}


// -----------------------------------------------------------------------
// File License Log API

/**
 * Create a commerce_file_license_log
 */
function commerce_file_license_log_create($values = array()) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME)->create($values);
}

/**
 * Save a commerce_file_license_log
 */
function commerce_file_license_log_save($values = array()) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME)->create($values)->save();
}

/**
 * Delete a single commerce_file_license_log.
 *
 * @param $id
 *   The uniform identifier of the entity to delete.
 *
 * @return
 *   FALSE, if there were no information how to delete the entity.
 */
function commerce_file_license_log_delete($id) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME)->delete(array($id));
}

/**
 * Delete multiple commerce_file_license_logs.
 *
 * @param $ids
 *   An array of uniform identifiers of the entities to delete.
 * @return
 *   FALSE if the given entity type isn't compatible to the CRUD API.
 */
function commerce_file_license_log_delete_multiple($ids) {
  return entity_get_controller(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME)->delete($ids);
}

/**
 * Load a single commerce_file_license
 *
 * @param $id
 *   A single entity ID.
 * @return
 *   An entity object.
 */
function commerce_file_license_log_load($id = NULL) {
  if (empty($id)) {
    return FALSE;
  }

  $entity = commerce_file_license_log_load_multiple(array($id));
  return $entity ? reset($entity) : FALSE;
}

/**
 * Load multiple commerce_file_license_logs based on certain conditions.
 *
 * @param $ids
 *   An array of entity IDs.
 * @return
 *   An array of entity objects, indexed by id.
 */
function commerce_file_license_log_load_multiple($ids = array(), $conditions = array(), $reset = FALSE) {
  if (empty($ids) && empty($conditions)) {
    return array();
  }
  return entity_load(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME , $ids, $conditions, $reset);
}

/**
 * Return wrapper object for a given license
 */
function commerce_file_license_log_wrapper($entity) {
  return entity_metadata_wrapper(COMMERCE_FILE_LICENSE_LOG_ENTITY_NAME, $entity);
}
