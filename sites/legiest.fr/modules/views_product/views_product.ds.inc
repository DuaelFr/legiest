<?php
/**
 * @file
 * views_product.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function views_product_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product_convention|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product_convention';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'uc_product_image',
        1 => 'group_product_details',
        2 => 'body',
        3 => 'display_price',
        4 => 'field_cc_ape',
        5 => 'field_cc_activity',
        6 => 'add_to_cart',
      ),
    ),
    'fields' => array(
      'uc_product_image' => 'ds_content',
      'group_product_details' => 'ds_content',
      'body' => 'ds_content',
      'display_price' => 'ds_content',
      'field_cc_ape' => 'ds_content',
      'field_cc_activity' => 'ds_content',
      'add_to_cart' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product_convention|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product_file|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product_file';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'uc_product_image',
        1 => 'group_product_details',
        2 => 'display_price',
        3 => 'add_to_cart',
        4 => 'body',
      ),
    ),
    'fields' => array(
      'uc_product_image' => 'ds_content',
      'group_product_details' => 'ds_content',
      'display_price' => 'ds_content',
      'add_to_cart' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product_file|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|product|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'product';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'hide_empty_regions' => 0,
    'hide_sidebars' => 0,
    'regions' => array(
      'ds_content' => array(
        0 => 'uc_product_image',
        1 => 'display_price',
        2 => 'dimensions',
        3 => 'weight',
        4 => 'add_to_cart',
        5 => 'group_product_details',
        6 => 'body',
      ),
    ),
    'fields' => array(
      'uc_product_image' => 'ds_content',
      'display_price' => 'ds_content',
      'dimensions' => 'ds_content',
      'weight' => 'ds_content',
      'add_to_cart' => 'ds_content',
      'group_product_details' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(),
  );
  $export['node|product|full'] = $ds_layout;

  return $export;
}
