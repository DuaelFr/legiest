<?php
/**
 * @file
 * views_product_legiest.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function views_product_legiest_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_details|node|product_convention|full';
  $field_group->group_name = 'group_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_convention';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Détails',
    'weight' => '1',
    'children' => array(
      0 => 'field_cc_activity',
      1 => 'field_cc_ape',
      2 => 'display_price',
      3 => 'add_to_cart',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Détails',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_product_details|node|product_convention|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_details|node|product_file|full';
  $field_group->group_name = 'group_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product_file';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Détails',
    'weight' => '1',
    'children' => array(
      0 => 'display_price',
      1 => 'add_to_cart',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Détails',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_product_details|node|product_file|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_product_details|node|product|full';
  $field_group->group_name = 'group_product_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'product';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Détails',
    'weight' => '5',
    'children' => array(
      0 => 'display_price',
      1 => 'weight',
      2 => 'dimensions',
      3 => 'add_to_cart',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Détails',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_product_details|node|product|full'] = $field_group;

  return $export;
}
