<?php
/**
 * @file
 * type_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function type_page_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function type_page_node_info() {
  $items = array(
    'page' => array(
      'name' => t('Page standard'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Titre'),
      'help' => '',
    ),
  );
  return $items;
}
