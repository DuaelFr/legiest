<?php
/**
 * @file
 * contextes.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function contextes_default_fe_block_settings() {
  $export = array();

  // act
  $theme = array();

  $theme['boxes-contact_legiest'] = array(
    'module' => 'boxes',
    'delta' => 'contact_legiest',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-legiest_address'] = array(
    'module' => 'boxes',
    'delta' => 'legiest_address',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-legiest_edito'] = array(
    'module' => 'boxes',
    'delta' => 'legiest_edito',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-legiest_phone'] = array(
    'module' => 'boxes',
    'delta' => 'legiest_phone',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['boxes-secure_payment'] = array(
    'module' => 'boxes',
    'delta' => 'secure_payment',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -2,
  );

  $theme['menu-menu-espace-clients'] = array(
    'module' => 'menu',
    'delta' => 'menu-espace-clients',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['menu-menu-footer-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-footer-menu',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['menu-menu-secondary-menu'] = array(
    'module' => 'menu',
    'delta' => 'menu-secondary-menu',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['nice_menus-1'] = array(
    'module' => 'nice_menus',
    'delta' => '1',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '<none>',
    'cache' => -1,
  );

  $theme['search-form'] = array(
    'module' => 'search',
    'delta' => 'form',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-main'] = array(
    'module' => 'system',
    'delta' => 'main',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['system-main-menu'] = array(
    'module' => 'system',
    'delta' => 'main-menu',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['uc_cart-cart'] = array(
    'module' => 'uc_cart',
    'delta' => 'cart',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => 'admin*',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-2d9f38f566546e47ae02bab05b35c50a'] = array(
    'module' => 'views',
    'delta' => '2d9f38f566546e47ae02bab05b35c50a',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-7e99c11f21446f48e803516f7c8ce27c'] = array(
    'module' => 'views',
    'delta' => '7e99c11f21446f48e803516f7c8ce27c',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block_all'] = array(
    'module' => 'views',
    'delta' => 'categories-block_all',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-block_subcats_theme'] = array(
    'module' => 'views',
    'delta' => 'categories-block_subcats_theme',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-sub_block_lvl2'] = array(
    'module' => 'views',
    'delta' => 'categories-sub_block_lvl2',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-sub_block_lvl3'] = array(
    'module' => 'views',
    'delta' => 'categories-sub_block_lvl3',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-categories-sub_block_lvl4'] = array(
    'module' => 'views',
    'delta' => 'categories-sub_block_lvl4',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-news-block'] = array(
    'module' => 'views',
    'delta' => 'news-block',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-news-block_1'] = array(
    'module' => 'views',
    'delta' => 'news-block_1',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-products-block_highlight'] = array(
    'module' => 'views',
    'delta' => 'products-block_highlight',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-products-block_highlight_theme'] = array(
    'module' => 'views',
    'delta' => 'products-block_highlight_theme',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-products-block_new'] = array(
    'module' => 'views',
    'delta' => 'products-block_new',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-products-block_new_category'] = array(
    'module' => 'views',
    'delta' => 'products-block_new_category',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $theme['views-products-block_new_theme'] = array(
    'module' => 'views',
    'delta' => 'products-block_new_theme',
    'theme' => 'act',
    'status' => 0,
    'weight' => '0',
    'region' => '',
    'custom' => '0',
    'visibility' => '0',
    'pages' => '',
    'title' => '',
    'cache' => -1,
  );

  $export['act'] = $theme;

  $theme_default = variable_get('theme_default', 'garland');
  $themes = list_themes();
  foreach ($export as $theme_key => $settings) {
    if ($theme_key != $theme_default && empty($themes[$theme_key]->status)) {
      unset($export[$theme_key]);
    }
  }
  return $export;
}
