<?php
/**
 * @file
 * config_permissions.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function config_permissions_user_default_roles() {
  $roles = array();

  // Exported role: Administrateur Legiest.
  $roles['Administrateur Legiest'] = array(
    'name' => 'Administrateur Legiest',
    'weight' => '3',
    'machine_name' => 'administrateur_legiest',
  );

  // Exported role: Client Organisme Public.
  $roles['Client Organisme Public'] = array(
    'name' => 'Client Organisme Public',
    'weight' => '2',
    'machine_name' => 'client_organisme_public',
  );

  return $roles;
}
