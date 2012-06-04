<?php

/**
 * @file
 * Hooks provided by the Commerce File module.
 */

/**
 * Defines states for use in grouping license statuses together to form a
 * simple state machine.
 *
 * A state is a particular phase in the life-cycle of a entity that is
 * comprised of one or more statuses. In that regard, a state acts like a
 * container for statuses with a default status per state. This is useful for
 * categorizing and advancing from one state to the next without needing to
 * know the particular status an entity will end up in.
 *
 * The Commerce File module defines several states in its own implementation of
 * this hook, commerce_file_commerce_file_license_state_info():
 * - Denied: licenses that cannot be accessed by the owner
 * - Allowed: licenses that can be accessed by the owner
 *
 * The state array structure is as follows:
 * - name: machine-name identifying the state using lowercase alphanumeric
 *   characters, -, and _
 * - title: the translatable title of the state, used in administrative
 *   interfaces
 * - description: a translatable description of the types of entities that would
 *   be in this state
 * - weight: integer weight of the state used for sorting lists of states;
 *   defaults to 0
 * - default_status: name of the default status for this state
 *
 * @return
 *   An array of state arrays keyed by name.
 */
function hook_commerce_file_license_state_info() {
  $states = array();

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
 * Allows modules to alter the license state definitions of other modules.
 *
 * @param $states
 *   An array of states defined by enabled modules.
 *
 * @see hook_commerce_file_license_state_info()
 */
function hook_commerce_file_license_state_info_alter(&$states) {
  $states['allowed']['weight'] = 9;
}

/**
 * Defines statuses for use in managing licenses.
 *
 * An status is a single step in the life-cycle of a license that
 * administrators can use to know at a glance what has occurred to the license
 * already and/or what the next step in processing the license will be.
 *
 * The Commerce File module defines several statuses in its own implementation of
 * this hook, commerce_file_commerce_file_license_status_info():
 * - Pending: in the Denied state; used for licenses that have been created
 *   but are awaiting some type of approval
 * - Active: default status of the Allowed state; used to indicate the license
 *   can be accessed by the owner. Currently the only Allowed status.
 * - Canceled: additional status for the Denied state; used to indicate
 *   licenses where the owner's access has been canceled.
 * - Revoked: default status of the Denied state; used for licenses where the
 *   owner's access has been revoked.
 *
 * The status array structure is as follows:
 * - name: machine-name identifying the status using lowercase
 *   alphanumeric characters, -, and _
 * - title: the translatable title of the status, used in administrative
 *   interfaces
 * - state: the name of the state the status belongs to
 * - weight: integer weight of the status used for sorting lists of statuses;
 *   defaults to 0
 * - enabled: TRUE or FALSE indicating if the status is enabled,
 *   with disabled statuses not being available for use; defaults to TRUE
 *
 * @return
 *   An array of status arrays keyed by name.
 */
function hook_commerce_file_license_status_info() {
  $statuses = array();

  $statuses['active'] = array(
    'name' => 'active',
    'title' => t('Active'),
    'state' => 'allowed',
    'weight' => 0,
  );

  return $statuses;
}

/**
 * Allows modules to alter the license status definitions of other modules.
 *
 * @param $statuses
 *   An array of statuses defined by enabled modules.
 *
 * @see hook_commerce_file_license_status_info()
 */
function hook_commerce_file_license_status_info_alter(&$statuses) {
  $statuses['pending']['title'] = t('Awaiting Approval');
}

/**
 * Defines access limit settings for Commerce File fields and Licenses
 *
 *
 * The limit array structure is as follows:
 * - name: machine-name identifying the limit using lowercase
 *   alphanumeric characters, -, and _
 * - title: the translatable title of the limit, used in administrative
 *   interfaces
 * - base_element: the base form array for the limit setting,
 *   @see http://api.drupal.org/api/drupal/developer--topics--forms_api_reference.html/7
 * - property_info: the info array defining the metadata about the limit setting,
 *   @see hook_entity_property_info()
 *   - In addition to hook_entity_property_info():
 *      - 'default_value': A default value to be used for the setting
 *      - 'zero_value': The value that represents Zero/Empty to this setting
 *      - 'aggregated': TRUE or FALSE. TRUE if the setting's values should be
 *         aggregated across multiple fields, licenses, etc.
 *      - 'inheritable': TRUE or FALSE. TRUE if the setting should inherit it's
 *         value from the field or instance settings if a value is not entered.
 *
 * @return
 *   An array of limit arrays keyed by name.
 */
function hook_commerce_file_license_info() {
  $limits = array();

  $limits['download_limit'] = array(
    'name' => 'download_limit',
    'title' => t('Download Limit'),
    'base_element' => array(
      '#type' => 'textfield',
      '#title' => t('Number of downloads allowed'),
      '#size' => 5,
      '#maxlength' => 5,
    ),
    'property info' => array(
      'type' => 'integer',
      'label' => t('The number of downloads allowed'),
      'description' => t('The number of downloads allowed for this file.'),
      'getter callback' => 'entity_property_verbatim_get',
      'setter callback' => 'entity_property_verbatim_set',
      'default_value' => 10,
      'zero_value' => 0,
      'aggregated' => TRUE,
      'inheritable' => TRUE,
    ),
  );

  return $limits;
}

/**
 * Allows modules to alter the license limit definitions of other modules.
 *
 * @param $limits
 *   An array of limits defined by enabled modules.
 *
 * @see hook_commerce_file_license_info()
 */
function hook_commerce_file_license_info_alter(&$limits) {
  $limits['download_limit']['base_element']['title'] = t('Downloads Granted');
}
