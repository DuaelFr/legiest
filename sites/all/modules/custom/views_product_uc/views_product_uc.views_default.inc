<?php
/**
 * @file
 * views_product_uc.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function views_product_uc_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'products';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Produits';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Nos produits';
  $handler->display->display_options['use_more_text'] = 'plus';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Réinitialiser';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Trier par';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Éléments par page';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Tout -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Décalage';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['style_options']['fill_single_line'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Champ: Contenu : Image */
  $handler->display->display_options['fields']['uc_product_image']['id'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['table'] = 'field_data_uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['field'] = 'uc_product_image';
  $handler->display->display_options['fields']['uc_product_image']['label'] = '';
  $handler->display->display_options['fields']['uc_product_image']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['external'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['alter']['html'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uc_product_image']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['hide_empty'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['empty_zero'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['uc_product_image']['settings'] = array(
    'image_style' => 'produits-liste',
    'image_link' => 'content',
  );
  $handler->display->display_options['fields']['uc_product_image']['group_rows'] = 1;
  $handler->display->display_options['fields']['uc_product_image']['delta_offset'] = '0';
  $handler->display->display_options['fields']['uc_product_image']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['uc_product_image']['field_api_classes'] = 0;
  /* Champ: Contenu : Titre */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Champ: Nœud : Lien */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['view_node']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['view_node']['alter']['html'] = 0;
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['view_node']['hide_empty'] = 0;
  $handler->display->display_options['fields']['view_node']['empty_zero'] = 0;
  $handler->display->display_options['fields']['view_node']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['view_node']['text'] = 'Détails du produit';
  /* Champ: Produit : Sell price */
  $handler->display->display_options['fields']['sell_price']['id'] = 'sell_price';
  $handler->display->display_options['fields']['sell_price']['table'] = 'uc_products';
  $handler->display->display_options['fields']['sell_price']['field'] = 'sell_price';
  $handler->display->display_options['fields']['sell_price']['label'] = '';
  $handler->display->display_options['fields']['sell_price']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['external'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['sell_price']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['sell_price']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['sell_price']['alter']['html'] = 0;
  $handler->display->display_options['fields']['sell_price']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sell_price']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['sell_price']['hide_empty'] = 0;
  $handler->display->display_options['fields']['sell_price']['empty_zero'] = 0;
  $handler->display->display_options['fields']['sell_price']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['sell_price']['set_precision'] = 0;
  $handler->display->display_options['fields']['sell_price']['precision'] = '0';
  $handler->display->display_options['fields']['sell_price']['format_plural'] = 0;
  /* Champ: Produit : Buy it now button */
  $handler->display->display_options['fields']['buyitnowbutton']['id'] = 'buyitnowbutton';
  $handler->display->display_options['fields']['buyitnowbutton']['table'] = 'uc_products';
  $handler->display->display_options['fields']['buyitnowbutton']['field'] = 'buyitnowbutton';
  $handler->display->display_options['fields']['buyitnowbutton']['label'] = '';
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['external'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['alter']['html'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['buyitnowbutton']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['buyitnowbutton']['hide_empty'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['empty_zero'] = 0;
  $handler->display->display_options['fields']['buyitnowbutton']['hide_alter_empty'] = 1;
  /* Critère de tri: Contenu : Épinglé (en haut des listes) */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Critère de tri: Contenu : Date de publication */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Critère de filtrage: Contenu : Publié */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Critère de filtrage: Contenu : Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'product_convention' => 'product_convention',
    'product' => 'product',
    'product_file' => 'product_file',
  );

  /* Display: Incontournables (Bloc) */
  $handler = $view->new_display('block', 'Incontournables (Bloc)', 'block_highlight');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Les incontournables';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_highlight' => 'product_highlight',
    'product_new' => 0,
  );

  /* Display: Incontournables Catégorie (Bloc) */
  $handler = $view->new_display('block', 'Incontournables Catégorie (Bloc)', 'block_highlight_category');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Les incontournables';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_highlight' => 'product_highlight',
    'product_new' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Possède l'identifiant de terme de taxonomie (avec profondeur) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = 'Les incontournables <span>%1</span>';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '4';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;

  /* Display: Incontournables Thématique (Bloc) */
  $handler = $view->new_display('block', 'Incontournables Thématique (Bloc)', 'block_highlight_theme');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Les incontournables';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_highlight' => 'product_highlight',
    'product_new' => 0,
  );
  /* Relation: Contenu : Catégorie (field_product_category) */
  $handler->display->display_options['relationships']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['relationships']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['label'] = 'category';
  $handler->display->display_options['relationships']['field_product_category_tid']['required'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Terme de taxonomie : Thématique (field_theme) */
  $handler->display->display_options['arguments']['field_theme_tid']['id'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['table'] = 'field_data_field_theme';
  $handler->display->display_options['arguments']['field_theme_tid']['field'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['relationship'] = 'field_product_category_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_theme_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['title'] = 'Les incontournables <span>%1</span>';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_theme_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_theme_tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['vocabularies'] = array(
    'category_theme' => 'category_theme',
  );
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['not'] = 0;

  /* Display: Nouveaux (Bloc) */
  $handler = $view->new_display('block', 'Nouveaux (Bloc)', 'block_new');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveaux produits';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_new' => 'product_new',
    'product_highlight' => 0,
  );

  /* Display: Nouveaux Catégorie (Bloc) */
  $handler = $view->new_display('block', 'Nouveaux Catégorie (Bloc)', 'block_new_category');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveaux produits';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_new' => 'product_new',
    'product_highlight' => 0,
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Possède l'identifiant de terme de taxonomie (avec profondeur) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'default';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = 'Nouveaux produits <span>%1</span>';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '4';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 0;

  /* Display: Nouveaux Thématique (Bloc) */
  $handler = $view->new_display('block', 'Nouveaux Thématique (Bloc)', 'block_new_theme');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Nouveaux produits';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Nodequeue : File */
  $handler->display->display_options['relationships']['nodequeue_rel']['id'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['nodequeue_rel']['field'] = 'nodequeue_rel';
  $handler->display->display_options['relationships']['nodequeue_rel']['required'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['limit'] = 1;
  $handler->display->display_options['relationships']['nodequeue_rel']['names'] = array(
    'product_new' => 'product_new',
    'product_highlight' => 0,
  );
  /* Relation: Contenu : Catégorie (field_product_category) */
  $handler->display->display_options['relationships']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['relationships']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['label'] = 'category';
  $handler->display->display_options['relationships']['field_product_category_tid']['required'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Terme de taxonomie : Thématique (field_theme) */
  $handler->display->display_options['arguments']['field_theme_tid']['id'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['table'] = 'field_data_field_theme';
  $handler->display->display_options['arguments']['field_theme_tid']['field'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['relationship'] = 'field_product_category_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_theme_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['title'] = 'Nouveaux produits <span>%1</span>';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_type'] = 'taxonomy_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['term_page'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['node'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_options']['limit'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_theme_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_theme_tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['vocabularies'] = array(
    'category_theme' => 'category_theme',
  );
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['not'] = 0;

  /* Display: Produits Catégorie (Page) */
  $handler = $view->new_display('page', 'Produits Catégorie (Page)', 'page_category');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global : Zone de texte */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Titre';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Tous les produits %1</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Vide';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Il n\'y a aucun produit dans cette catégorie.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Contenu : Possède l'identifiant de terme de taxonomie (avec profondeur) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = 'Nos produits <span>%1</span>';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['vocabularies'] = array(
    'product_category' => 'product_category',
  );
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '4';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['term_node_tid_depth']['set_breadcrumb'] = 1;
  $handler->display->display_options['arguments']['term_node_tid_depth']['use_taxonomy_term_path'] = 1;
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Produits Thématique (Page) */
  $handler = $view->new_display('page', 'Produits Thématique (Page)', 'page_theme');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Entête: Global : Zone de texte */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Titre';
  $handler->display->display_options['header']['area']['empty'] = FALSE;
  $handler->display->display_options['header']['area']['content'] = '<h2 class="block-title">Tous les produits %1</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = 1;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* Comportement en l'absence de résultats: Global : Zone de texte */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Vide';
  $handler->display->display_options['empty']['area']['empty'] = FALSE;
  $handler->display->display_options['empty']['area']['content'] = 'Il n\'y a aucun produit dans cette catégorie.';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  $handler->display->display_options['empty']['area']['tokenize'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relation: Contenu : Catégorie (field_product_category) */
  $handler->display->display_options['relationships']['field_product_category_tid']['id'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['table'] = 'field_data_field_product_category';
  $handler->display->display_options['relationships']['field_product_category_tid']['field'] = 'field_product_category_tid';
  $handler->display->display_options['relationships']['field_product_category_tid']['label'] = 'category';
  $handler->display->display_options['relationships']['field_product_category_tid']['required'] = 1;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Filtre contextuel: Terme de taxonomie : Thématique (field_theme) */
  $handler->display->display_options['arguments']['field_theme_tid']['id'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['table'] = 'field_data_field_theme';
  $handler->display->display_options['arguments']['field_theme_tid']['field'] = 'field_theme_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['relationship'] = 'field_product_category_tid';
  $handler->display->display_options['arguments']['field_theme_tid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_theme_tid']['title_enable'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['title'] = 'Nos produits <span>%1</span>';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_theme_tid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_theme_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_theme_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_theme_tid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['field_theme_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['vocabularies'] = array(
    'category_theme' => 'category_theme',
  );
  $handler->display->display_options['arguments']['field_theme_tid']['validate_options']['transform'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['validate']['fail'] = 'empty';
  $handler->display->display_options['arguments']['field_theme_tid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['field_theme_tid']['not'] = 0;
  $handler->display->display_options['path'] = 'taxonomy/term/%';
  $translatables['products'] = array(
    t('Master'),
    t('Nos produits'),
    t('plus'),
    t('Appliquer'),
    t('Réinitialiser'),
    t('Trier par'),
    t('Asc'),
    t('Desc'),
    t('Éléments par page'),
    t('- Tout -'),
    t('Décalage'),
    t('Détails du produit'),
    t('.'),
    t(','),
    t('Incontournables (Bloc)'),
    t('Les incontournables'),
    t('file d\'attente'),
    t('Incontournables Catégorie (Bloc)'),
    t('Tout'),
    t('Les incontournables <span>%1</span>'),
    t('Incontournables Thématique (Bloc)'),
    t('category'),
    t('Nouveaux (Bloc)'),
    t('Nouveaux produits'),
    t('Nouveaux Catégorie (Bloc)'),
    t('Nouveaux produits <span>%1</span>'),
    t('Nouveaux Thématique (Bloc)'),
    t('Produits Catégorie (Page)'),
    t('Titre'),
    t('<h2 class="block-title">Tous les produits %1</h2>'),
    t('Vide'),
    t('Il n\'y a aucun produit dans cette catégorie.'),
    t('Nos produits <span>%1</span>'),
    t('Produits Thématique (Page)'),
  );
  $export['products'] = $view;

  return $export;
}
