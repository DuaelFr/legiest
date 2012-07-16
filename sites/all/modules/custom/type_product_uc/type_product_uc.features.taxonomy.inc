<?php
/**
 * @file
 * type_product_uc.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function type_product_uc_taxonomy_default_vocabularies() {
  return array(
    'cc_activity' => array(
      'name' => 'Activité',
      'machine_name' => 'cc_activity',
      'description' => 'Activité liée aux conventions collectives',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'cc_ape' => array(
      'name' => 'Code APE',
      'machine_name' => 'cc_ape',
      'description' => 'Code APE de classement des conventions collectives',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
