<?php
/**
 * @file
 * config_shop.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function config_shop_commerce_product_default_types() {
  $items = array(
    'product_file' => array(
      'type' => 'product_file',
      'name' => 'Fichier seul',
      'description' => 'Produit représentant l\'achat unitaire d\'un document virtuel',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'product_standard' => array(
      'type' => 'product_standard',
      'name' => 'Produit physique',
      'description' => 'Produit physique à livrer',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
    'product_subscription' => array(
      'type' => 'product_subscription',
      'name' => 'Abonnement',
      'description' => 'Produit représentant un abonnement à plusieurs fichiers',
      'help' => '',
      'revision' => '1',
      'module' => 'commerce_product_ui',
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function config_shop_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
