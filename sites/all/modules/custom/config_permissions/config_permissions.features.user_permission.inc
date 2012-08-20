<?php
/**
 * @file
 * config_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function config_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access devel information.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'user',
  );

  // Exported permission: admin_display_suite.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: admin_fields.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: admin_view_modes.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(),
    'module' => 'ds',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(),
    'module' => 'block',
  );

  // Exported permission: administer boxes.
  $permissions['administer boxes'] = array(
    'name' => 'administer boxes',
    'roles' => array(),
    'module' => 'boxes',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: administer custom search.
  $permissions['administer custom search'] = array(
    'name' => 'administer custom search',
    'roles' => array(),
    'module' => 'custom_search',
  );

  // Exported permission: administer devel menu items.
  $permissions['administer devel menu items'] = array(
    'name' => 'administer devel menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(),
    'module' => 'image',
  );

  // Exported permission: administer imce.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(),
    'module' => 'imce',
  );

  // Exported permission: administer languages.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(),
    'module' => 'locale',
  );

  // Exported permission: administer main-menu menu items.
  $permissions['administer main-menu menu items'] = array(
    'name' => 'administer main-menu menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer management menu items.
  $permissions['administer management menu items'] = array(
    'name' => 'administer management menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(),
    'module' => 'menu',
  );

  // Exported permission: administer menu-footer-menu menu items.
  $permissions['administer menu-footer-menu menu items'] = array(
    'name' => 'administer menu-footer-menu menu items',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-secondary-menu menu items.
  $permissions['administer menu-secondary-menu menu items'] = array(
    'name' => 'administer menu-secondary-menu menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer module filter.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(),
    'module' => 'module_filter',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer navigation menu items.
  $permissions['administer navigation menu items'] = array(
    'name' => 'administer navigation menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer nodequeue.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(),
    'module' => 'nodequeue',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: administer order workflow.
  $permissions['administer order workflow'] = array(
    'name' => 'administer order workflow',
    'roles' => array(),
    'module' => 'uc_order',
  );

  // Exported permission: administer own product features.
  $permissions['administer own product features'] = array(
    'name' => 'administer own product features',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_product',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: administer product classes.
  $permissions['administer product classes'] = array(
    'name' => 'administer product classes',
    'roles' => array(),
    'module' => 'uc_product',
  );

  // Exported permission: administer product features.
  $permissions['administer product features'] = array(
    'name' => 'administer product features',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_product',
  );

  // Exported permission: administer product stock.
  $permissions['administer product stock'] = array(
    'name' => 'administer product stock',
    'roles' => array(),
    'module' => 'uc_stock',
  );

  // Exported permission: administer products.
  $permissions['administer products'] = array(
    'name' => 'administer products',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_product',
  );

  // Exported permission: administer rules.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: administer search.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer store.
  $permissions['administer store'] = array(
    'name' => 'administer store',
    'roles' => array(),
    'module' => 'uc_store',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: administer user-menu menu items.
  $permissions['administer user-menu menu items'] = array(
    'name' => 'administer user-menu menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'user',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(),
    'module' => 'views',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(),
    'module' => 'system',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass rules access.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(),
    'module' => 'rules',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: configure quotes.
  $permissions['configure quotes'] = array(
    'name' => 'configure quotes',
    'roles' => array(),
    'module' => 'uc_quote',
  );

  // Exported permission: configure taxes.
  $permissions['configure taxes'] = array(
    'name' => 'configure taxes',
    'roles' => array(),
    'module' => 'uc_taxes',
  );

  // Exported permission: create news content.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: create orders.
  $permissions['create orders'] = array(
    'name' => 'create orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: create product content.
  $permissions['create product content'] = array(
    'name' => 'create product content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: create product_convention content.
  $permissions['create product_convention content'] = array(
    'name' => 'create product_convention content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: create product_file content.
  $permissions['create product_file content'] = array(
    'name' => 'create product_file content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any news content.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any product content.
  $permissions['delete any product content'] = array(
    'name' => 'delete any product content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any product_convention content.
  $permissions['delete any product_convention content'] = array(
    'name' => 'delete any product_convention content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any product_file content.
  $permissions['delete any product_file content'] = array(
    'name' => 'delete any product_file content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete orders.
  $permissions['delete orders'] = array(
    'name' => 'delete orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: delete own news content.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own product content.
  $permissions['delete own product content'] = array(
    'name' => 'delete own product content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own product_convention content.
  $permissions['delete own product_convention content'] = array(
    'name' => 'delete own product_convention content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own product_file content.
  $permissions['delete own product_file content'] = array(
    'name' => 'delete own product_file content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete payments.
  $permissions['delete payments'] = array(
    'name' => 'delete payments',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_payment',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(),
    'module' => 'admin_menu',
  );

  // Exported permission: download file.
  $permissions['download file'] = array(
    'name' => 'download file',
    'roles' => array(
      0 => 'authenticated user',
    ),
    'module' => 'uc_file',
  );

  // Exported permission: edit any news content.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any product content.
  $permissions['edit any product content'] = array(
    'name' => 'edit any product content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any product_convention content.
  $permissions['edit any product_convention content'] = array(
    'name' => 'edit any product_convention content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any product_file content.
  $permissions['edit any product_file content'] = array(
    'name' => 'edit any product_file content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit boxes.
  $permissions['edit boxes'] = array(
    'name' => 'edit boxes',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'boxes',
  );

  // Exported permission: edit orders.
  $permissions['edit orders'] = array(
    'name' => 'edit orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: edit own news content.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own product content.
  $permissions['edit own product content'] = array(
    'name' => 'edit own product content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own product_convention content.
  $permissions['edit own product_convention content'] = array(
    'name' => 'edit own product_convention content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own product_file content.
  $permissions['edit own product_file content'] = array(
    'name' => 'edit own product_file content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: execute php code.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: fulfill orders.
  $permissions['fulfill orders'] = array(
    'name' => 'fulfill orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_shipping',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(),
    'module' => 'features',
  );

  // Exported permission: manipulate all queues.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manipulate queues.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: manual payments.
  $permissions['manual payments'] = array(
    'name' => 'manual payments',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_payment',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: search content.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'search',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(),
    'module' => 'user',
  );

  // Exported permission: submit translations to localization server.
  $permissions['submit translations to localization server'] = array(
    'name' => 'submit translations to localization server',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'l10n_client',
  );

  // Exported permission: switch users.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(),
    'module' => 'devel',
  );

  // Exported permission: translate interface.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'locale',
  );

  // Exported permission: unconditionally delete orders.
  $permissions['unconditionally delete orders'] = array(
    'name' => 'unconditionally delete orders',
    'roles' => array(),
    'module' => 'uc_order',
  );

  // Exported permission: use advanced search.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(),
    'module' => 'search',
  );

  // Exported permission: use custom search.
  $permissions['use custom search'] = array(
    'name' => 'use custom search',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'custom_search',
  );

  // Exported permission: use on-page translation.
  $permissions['use on-page translation'] = array(
    'name' => 'use on-page translation',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'l10n_client',
  );

  // Exported permission: use special order states.
  $permissions['use special order states'] = array(
    'name' => 'use special order states',
    'roles' => array(
      0 => 'Client Organisme Public',
    ),
    'module' => 'uc_legiest',
  );

  // Exported permission: use text format ds_code.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(),
    'module' => 'filter',
  );

  // Exported permission: use text format full_html.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'filter',
  );

  // Exported permission: view all downloads.
  $permissions['view all downloads'] = array(
    'name' => 'view all downloads',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_file',
  );

  // Exported permission: view all orders.
  $permissions['view all orders'] = array(
    'name' => 'view all orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: view customers.
  $permissions['view customers'] = array(
    'name' => 'view customers',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: view own orders.
  $permissions['view own orders'] = array(
    'name' => 'view own orders',
    'roles' => array(
      0 => 'Administrateur Legiest',
      1 => 'authenticated user',
    ),
    'module' => 'uc_order',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: view payments.
  $permissions['view payments'] = array(
    'name' => 'view payments',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_payment',
  );

  // Exported permission: view reports.
  $permissions['view reports'] = array(
    'name' => 'view reports',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'uc_store',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'node',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'Administrateur Legiest',
    ),
    'module' => 'system',
  );

  return $permissions;
}
