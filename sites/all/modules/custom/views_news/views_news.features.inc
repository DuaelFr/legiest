<?php
/**
 * @file
 * views_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function views_news_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function views_news_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_fe_nodequeue_export_fields().
 */
function views_news_fe_nodequeue_export_fields() {
  $nodequeues = array();

  // Exported nodequeues: actus_accueil
  $nodequeues['actus_accueil'] = array(
    'qid' => '1',
    'name' => 'actus_accueil',
    'title' => 'Actus accueil',
    'subqueue_title' => '',
    'size' => '0',
    'link' => 'Afficher en page d\'accueil',
    'link_remove' => 'Retirer de la page d\'accueil',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '1',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  // Exported nodequeues: actus_bloc_accueil
  $nodequeues['actus_bloc_accueil'] = array(
    'qid' => '4',
    'name' => 'actus_bloc_accueil',
    'title' => 'Actus bloc accueil',
    'subqueue_title' => '',
    'size' => '0',
    'link' => 'Afficher dans le bloc Dernières actus',
    'link_remove' => 'Retirer du bloc Dernières actus',
    'owner' => 'nodequeue',
    'show_in_ui' => '1',
    'show_in_tab' => '1',
    'show_in_links' => '1',
    'reference' => '0',
    'reverse' => '0',
    'i18n' => '0',
    'subqueues' => '1',
    'types' => array(
      0 => 'news',
    ),
    'roles' => array(),
    'count' => 0,
  );

  return $nodequeues;
}

/**
 * Implements hook_image_default_styles().
 */
function views_news_image_default_styles() {
  $styles = array();

  // Exported image style: actus-diaporama-accueil.
  $styles['actus-diaporama-accueil'] = array(
    'name' => 'actus-diaporama-accueil',
    'effects' => array(
      4 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '960',
          'height' => '360',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: actus-fiche.
  $styles['actus-fiche'] = array(
    'name' => 'actus-fiche',
    'effects' => array(
      6 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '685',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: actus-liste.
  $styles['actus-liste'] = array(
    'name' => 'actus-liste',
    'effects' => array(
      5 => array(
        'label' => 'Scale and Smart Crop',
        'help' => 'Similar to "Scale And Crop", but preserves the portion of the image with the most entropy.',
        'effect callback' => 'smartcrop_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'smartcrop',
        'name' => 'smartcrop_scale_and_crop',
        'data' => array(
          'width' => '130',
          'height' => '90',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
