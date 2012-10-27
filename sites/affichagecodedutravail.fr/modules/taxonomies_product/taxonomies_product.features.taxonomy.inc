<?php
/**
 * @file
 * taxonomies_product.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function taxonomies_product_taxonomy_default_vocabularies() {
  return array(
    'product_category' => array(
      'name' => 'Catégorie de Produit',
      'machine_name' => 'product_category',
      'description' => 'Classement par catégorie',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'metatags' => array(),
    ),
  );
}
