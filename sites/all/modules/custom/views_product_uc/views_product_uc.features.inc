<?php
/**
 * @file
 * views_product_uc.features.inc
 */

/**
 * Implements hook_views_api().
 */
function views_product_uc_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function views_product_uc_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: product_highlight
  $nodequeues['product_highlight'] = array(
    'qid' => '2',
    'name' => 'product_highlight',
    'title' => 'Les incontournables',
    'subqueue_title' => '',
    'size' => '0',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'product',
      1 => 'product_convention',
      2 => 'product_file',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: product_new
  $nodequeues['product_new'] = array(
    'qid' => '3',
    'name' => 'product_new',
    'title' => 'Nouveaux produits',
    'subqueue_title' => '',
    'size' => '0',
    'link' => '',
    'link_remove' => '',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '0',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'product',
      1 => 'product_convention',
      2 => 'product_file',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}
