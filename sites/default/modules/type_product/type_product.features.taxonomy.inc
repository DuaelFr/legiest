<?php
/**
 * @file
 * type_product.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function type_product_taxonomy_default_vocabularies() {
  return array(
    'product_category' => array(
      'name' => 'Catégorie de Produit',
      'machine_name' => 'product_category',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
    'product_theme' => array(
      'name' => 'Thématique de Produit',
      'machine_name' => 'product_theme',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
