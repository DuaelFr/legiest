<?php
/**
 * @file
 * type_product_uc.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function type_product_uc_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_uc_product_default_classes().
 */
function type_product_uc_uc_product_default_classes() {
  $items = array(
    'product' => array(
      'name' => t('Produit physique'),
      'base' => 'uc_product',
      'description' => t('Produit physique soumis à livraison.'),
      'has_title' => '1',
      'title_label' => t('Nom'),
      'help' => '',
    ),
    'product_convention' => array(
      'name' => t('Convention collective'),
      'base' => 'uc_product',
      'description' => t('Type de contenu spécial pour les conventions collectives.'),
      'has_title' => '1',
      'title_label' => t('Nom'),
      'help' => '',
    ),
    'product_file' => array(
      'name' => t('Produit virtuel'),
      'base' => 'uc_product',
      'description' => t('Produit virtuel contenant un ou plusieurs fichiers à télécharger hors convention collective.'),
      'has_title' => '1',
      'title_label' => t('Nom'),
      'help' => '',
    ),
  );
  return $items;
}
