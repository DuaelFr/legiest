<?php
/**
 * @file
 * context_tmp.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function context_tmp_context_default_contexts() {
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
          'weight' => '0',
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
  $context->name = 'categories';
  $context->description = 'Positionnement des blocs sur les pages des catégories';
  $context->tag = 'Taxonomy';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'product_category' => 'product_category',
      ),
      'options' => array(
        'term_form' => '0',
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
        'views-products-block_new_category' => array(
          'module' => 'views',
          'delta' => 'products-block_new_category',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-2d9f38f566546e47ae02bab05b35c50a' => array(
          'module' => 'views',
          'delta' => '2d9f38f566546e47ae02bab05b35c50a',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positionnement des blocs sur les pages des catégories');
  t('Taxonomy');
  $export['categories'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = 'Page d\'accueil du site';
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
        'views-products-block_highlight' => array(
          'module' => 'views',
          'delta' => 'products-block_highlight',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-products-block_new' => array(
          'module' => 'views',
          'delta' => 'products-block_new',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Layout');
  t('Page d\'accueil du site');
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sidebar';
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
  $export['sidebar'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'themes';
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
        'views-categories-block_subcats_theme' => array(
          'module' => 'views',
          'delta' => 'categories-block_subcats_theme',
          'region' => 'content',
          'weight' => '10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Positionnement des blocs sur les pages des thématiques');
  t('Taxonomy');
  $export['themes'] = $context;

  return $export;
}
