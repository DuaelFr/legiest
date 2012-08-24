<?php
/**
 * @file
 * contextes.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function contextes_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'all';
  $context->description = 'Toutes les pages du site';
  $context->tag = 'Layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'boxes-legiest_phone' => array(
          'module' => 'boxes',
          'delta' => 'legiest_phone',
          'region' => 'branding',
          'weight' => '-10',
        ),
        'uc_cart-cart' => array(
          'module' => 'uc_cart',
          'delta' => 'cart',
          'region' => 'branding',
          'weight' => '-9',
        ),
        'menu-menu-secondary-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-secondary-menu',
          'region' => 'menu',
          'weight' => '-10',
        ),
        'search-form' => array(
          'module' => 'search',
          'delta' => 'form',
          'region' => 'menu',
          'weight' => '-9',
        ),
        'boxes-legiest_address' => array(
          'module' => 'boxes',
          'delta' => 'legiest_address',
          'region' => 'footer_first',
          'weight' => '-10',
        ),
        'menu-menu-footer-menu' => array(
          'module' => 'menu',
          'delta' => 'menu-footer-menu',
          'region' => 'footer_first',
          'weight' => '-9',
        ),
        'boxes-secure_payment' => array(
          'module' => 'boxes',
          'delta' => 'secure_payment',
          'region' => 'footer_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Toutes les pages du site');
  $export['all'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'categories_legiest';
  $context->description = 'Positionnement des blocs sur les pages des catégories';
  $context->tag = 'Taxonomy';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'product_category' => 'product_category',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-7e99c11f21446f48e803516f7c8ce27c' => array(
          'module' => 'views',
          'delta' => '7e99c11f21446f48e803516f7c8ce27c',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-products-block_new_theme' => array(
          'module' => 'views',
          'delta' => 'products-block_new_theme',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-2d9f38f566546e47ae02bab05b35c50a' => array(
          'module' => 'views',
          'delta' => '2d9f38f566546e47ae02bab05b35c50a',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positionnement des blocs sur les pages des catégories');
  t('Taxonomy');
  $export['categories_legiest'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Page d\'accueil';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'boxes-legiest_edito' => array(
          'module' => 'boxes',
          'delta' => 'legiest_edito',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-products-block_highlight' => array(
          'module' => 'views',
          'delta' => 'products-block_highlight',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-products-block_new' => array(
          'module' => 'views',
          'delta' => 'products-block_new',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-news-block_1' => array(
          'module' => 'views',
          'delta' => 'news-block_1',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'views-news-block' => array(
          'module' => 'views',
          'delta' => 'news-block',
          'region' => 'header_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Page d\'accueil');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'not-front';
  $context->description = 'Tout sauf accueil';
  $context->tag = 'Layout';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Tout sauf accueil');
  $export['not-front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar_legiest';
  $context->description = 'Positionnement du menu latéral';
  $context->tag = 'Layout';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-categories-block_all' => array(
          'module' => 'views',
          'delta' => 'categories-block_all',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'boxes-contact_legiest' => array(
          'module' => 'boxes',
          'delta' => 'contact_legiest',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Positionnement du menu latéral');
  $export['sidebar_legiest'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'thematiques_legiest';
  $context->description = 'Positionnement des blocs sur les pages des thématiques';
  $context->tag = 'Taxonomy';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'category_theme' => 'category_theme',
      ),
      'options' => array(
        'term_form' => '1',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-products-block_highlight_theme' => array(
          'module' => 'views',
          'delta' => 'products-block_highlight_theme',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-products-block_new_theme' => array(
          'module' => 'views',
          'delta' => 'products-block_new_theme',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-2d9f38f566546e47ae02bab05b35c50a' => array(
          'module' => 'views',
          'delta' => '2d9f38f566546e47ae02bab05b35c50a',
          'region' => 'content',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positionnement des blocs sur les pages des thématiques');
  t('Taxonomy');
  $export['thematiques_legiest'] = $context;

  return $export;
}
