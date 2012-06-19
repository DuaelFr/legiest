<?php
/**
 * @file
 * type_product.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function type_product_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function type_product_node_info() {
  $items = array(
    'product_display' => array(
      'name' => t('Produit'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
