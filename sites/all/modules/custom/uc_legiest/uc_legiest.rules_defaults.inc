<?php
/**
 * @file
 * uc_legiest rules
 */

//------------------------------------------------------------------------------
// HOOKS

/**
 * Implements hook_default_rules_configuration().
 */
function uc_legiest_default_rules_configuration() {
  $rules = array();

  $rules += _uc_legiest_default_rules_configuration_shipping_area();
  $rules += _uc_legiest_default_rules_configuration_shipping_weight();
  $rules += _uc_legiest_default_rules_configuration_states();
  
  // Override uc_file_renewal
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Renew purchased files');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition(
      rules_or()
        ->condition('data_is', array(
          'data:select' => 'updated-order:order-status',
          'value' => 'payment_received',
        ))
        ->condition('data_is', array(
          'data:select' => 'updated-order:order-status',
          'value' => 'special_processing',
        ))
    )
    ->action('uc_file_order_renew', array(
      'order:select' => 'updated_order',
    ));
  $rules['uc_legiest_file_renewal'] = $rule;
  
  return $rules;
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function uc_legiest_default_rules_configuration_alter(&$configs) {
  // Shipping rates
  $methods = module_invoke_all('uc_shipping_method');
  foreach ($methods as $method) {
    if (empty($configs['get_quote_from_' . $method['id']])) {
      continue;
    }
    $rule = $configs['get_quote_from_' . $method['id']];
    
    $rule->label = '(UC Legiest) Autorule for shipping rate "' . $method['title'] . '"';

    // Particular case "france"
    if ($method['title'] == 'france') {
      $rule->condition('component_uc_legiest_condition_shipping_france', array(
          'order:select' => 'order',
        ))
        ->condition('data_is', array(
          'data:select' => 'order:order-total',
          'op' => '<',
          'value' => '99.00',
        ));
    }
    // Particular case "free_shipping"
    elseif ($method['title'] == 'free_shipping') {
      $rule->condition('component_uc_legiest_condition_shipping_france', array(
          'order:select' => 'order',
        ))
        ->condition(
          rules_condition('data_is', array(
          	'data:select' => 'order:order-total',
          	'op' => '<',
          	'value' => '99.00',
          ))->negate()
        );
    }
    // General case "areaX_MIN_MAX" / "areaX_MIN+"
    elseif (preg_match('#^area[1-2]_[0-9]+(_[0-9]+)?\+?$#', $method['title'])) {
      $parts = explode('_', $method['title']);

      $area_cond_name = 'component_uc_legiest_condition_shipping_' . $parts[0];
      $weight_cond_name = 'component_uc_legiest_condition_weight_' . $parts[1];
      if (!empty($parts[2])) {
        $weight_cond_name .= '_' . $parts[2];
      }

      $rule->condition($area_cond_name, array(
          'order:select' => 'order',
        ))
        ->condition($weight_cond_name, array(
          'order:select' => 'order',
        ));
    }
  }
  
  // Tax rates
  $rates = uc_taxes_rate_load();
  foreach ($rates as $rate) {
    if (empty($configs['uc_taxes_' . $rate->id])) {
      continue;
    }
    $rule = $configs['uc_taxes_' . $rate->id];
    
    $rule->label = '(UC Legiest) Autorule for tax rate "' . $rate->name . '"';
    
    if ($rate->name == 'TVA') {
      $rule->condition('component_uc_legiest_condition_shipping_france', array(
          'order:select' => 'order',
        ));
    }
  }
  
  // Disable uc_file_renewal for override
  if (!empty($configs['uc_file_renewal'])) {
    $rule = $configs['uc_file_renewal'];
    $rule->label .= ' [DO NOT ENABLE]';
    $rule->active = FALSE;
  }
  
  // Disable uc_checkout_complete_paid to avoid collision
  if (!empty($configs['uc_checkout_complete_paid'])) {
    $rule = $configs['uc_checkout_complete_paid'];
    $rule->label .= ' [DO NOT ENABLE]';
    $rule->active = FALSE;
  }
}


//------------------------------------------------------------------------------
// CALLBACKS

/**
 * Define rules and components related to shipping area
 */
function _uc_legiest_default_rules_configuration_shipping_area() {
  $rules = array();


  //--------------------------
  // Component conditions area

  $variables = array(
    'order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
  );
  
  // Shipping address is in france
  $rule = rules_or($variables);
  $rule->label = t('(UC Legiest) Condition Shipping France');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_delivery_country', array(
      'order:select' => 'order',
      'countries' => array(
        '250' => '250', // France
      ),
    ));
  $rules['uc_legiest_condition_shipping_france'] = $rule;
  
  
  // Shipping address is in area 1
  $rule = rules_or($variables);
  $rule->label = t('(UC Legiest) Condition Shipping Area 1');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_delivery_country', array(
      'order:select' => 'order',
      'countries' => array(
        '312' => '312', // Guadeloupe
        '254' => '254', // Guyane
        '474' => '474', // Martinique
        '175' => '175', // Mayotte
        '638' => '638', // Réunion
        '666' => '666', // Saint-Pierre-et-Miquelon
      ),
    ));
  $rules['uc_legiest_condition_shipping_area1'] = $rule;
  
  
  // Shipping address is in area 2
  $rule = rules_or($variables);
  $rule->label = t('(UC Legiest) Condition Shipping Area 2');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_delivery_country', array(
      'order:select' => 'order',
      'countries' => array(
        '56'  => '56',  // Belgique
        '492' => '492', // Monaco
        '540' => '540', // Nouvelle-Calédonie
        '258' => '258', // Polynésie française
        '652' => '652', // Saint Barthélemy
        '663' => '663', // Saint-Martin (partie française)
        '756' => '756', // Suisse
        '260' => '260', // Terres australes françaises
        '876' => '876', // Wallis et Futuna
      ),
    ));
  $rules['uc_legiest_condition_shipping_area2'] = $rule;
  
  
  return $rules;
}

/**
 * Define rules and components related to shipping weight
 */
function _uc_legiest_default_rules_configuration_shipping_weight() {
  $rules = array();


  //----------------------------
  // Component conditions weight

  $variables = array(
    'order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
  );
  
  // Total weight is between 0 and 99g
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight between 0 and 99g');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '0',
      'product_weight_comparison' => 'greater_equal',
    ))
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '100',
      'product_weight_comparison' => 'less',
    ));
  $rules['uc_legiest_condition_weight_0_100'] = $rule;
  
  // Total weight is between 100g and 499g
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight between 100g and 499g');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '100',
      'product_weight_comparison' => 'greater_equal',
    ))
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '500',
      'product_weight_comparison' => 'less',
    ));
  $rules['uc_legiest_condition_weight_100_500'] = $rule;
  
  // Total weight is between 500g and 1kg
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight between 500g and 1kg');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '500',
      'product_weight_comparison' => 'greater_equal',
    ))
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '1000',
      'product_weight_comparison' => 'less',
    ));
  $rules['uc_legiest_condition_weight_500_1000'] = $rule;
  
  // Total weight is between 1kg and 2kg
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight between 1kg and 2kg');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '1000',
      'product_weight_comparison' => 'greater_equal',
    ))
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '2000',
      'product_weight_comparison' => 'less',
    ));
  $rules['uc_legiest_condition_weight_1000_2000'] = $rule;
  
  // Total weight is between 2kg and 10kg
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight between 2kg and 10kg');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '2000',
      'product_weight_comparison' => 'greater_equal',
    ))
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '10000',
      'product_weight_comparison' => 'less',
    ));
  $rules['uc_legiest_condition_weight_2000_10000'] = $rule;
  
  // Total weight is over 10kg
  $rule = rules_and($variables);
  $rule->label = t('(UC Legiest) Condition weight over 10kg');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_condition_products_weight', array(
      'order:select' => 'order',
      'products' => array('all' => 'all'),
      'weight_units' => 'g',
      'product_weight_value' => '10000',
      'product_weight_comparison' => 'greater_equal',
    ));
  $rules['uc_legiest_condition_weight_10000+'] = $rule;

  return $rules;
}

/**
 * Define rules and components related to states and transitions
 */
function _uc_legiest_default_rules_configuration_states() {
  $rules = array();

  //----------------------------------
  // States transition component rules

  $variables = array(
    'order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
    'updated_order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
  );

  // Déclenché quand état commande "En attente"
  // Change statut si méthode de paiement "Virement Administratif" et utilisateur possède un rôle adéquat
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order pending to special_processing if client special and virt_admin payment');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'updated-order:payment-method',
      'value' => 'virt_admin',
    ))
    ->condition('uc_legiest_rules_condition_user_special', array(
      'user:select' => 'updated-order:customer',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'updated_order',
      'order_status' => 'special_processing',
    ));
  $rules['uc_legiest_order_virt_admin_client_special'] = $rule;

  // Déclenché quand état commande "En attente"
  // Envoie un mail à l'admin si méthode de paiement "Virement Administratif" et utilisateur ne possède un rôle adéquat
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Mail admin for order to be manually validated');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'updated-order:payment-method',
      'value' => 'virt_admin',
    ))
    ->condition(rules_condition('uc_legiest_rules_condition_user_special', array(
      'user:select' => 'updated-order:customer',
    ))->negate())
    ->action('mail', array(
      'to' => variable_get('uc_legiest_admin_mail', variable_get('site_mail')),
      'subject' => 'Commande publique en attente de validation',
      'message' => 'Une nouvelle commande publique d\'un utilisateur inconnu a été passée sur le site.<br \>Elle est accessible à l\'adresse [order:admin-url].',
      'from' => variable_get('site_mail'),
    ))
    ->action('drupal_message', array(
      'message' => 'Votre commande a été mise en attente car vous n\'êtes pas encore connu de nos services, elle sera validée par un administrateur dès qu\'il sera en mesure de certifier que vous êtes bien un organisme public français.',
    ));
  $rules['uc_legiest_order_virt_admin_client_not_special'] = $rule;

  // Déclenché quand état commande "En attente"
  // Change statut si méthode de paiement autre que "Virement Administratif" et reste à payer 0
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order pending to processing if nothing to pay');
  $rule->active = TRUE;
  $rule
    ->condition('uc_payment_condition_order_balance', array(
      'order:select' => 'updated_order',
      'balance_comparison' => 'less_equal',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'updated_order',
      'order_status' => 'processing',
    ));
  $rules['uc_legiest_order_paid'] = $rule;

  //---------------------
  // States trigger rules 

  // Declencheur commande pending
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes pending');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition('data_is', array(
      'data:select' => 'updated-order:order-status',
      'value' => 'pending',
    ))
    ->action('component_uc_legiest_order_virt_admin_client_special', array(
      'order:select' => 'order',
      'updated_order:select' => 'updated_order',
    ))
    ->action('component_uc_legiest_order_virt_admin_client_not_special', array(
      'order:select' => 'order',
      'updated_order:select' => 'updated_order',
    ))
    ->action('component_uc_legiest_order_paid', array(
      'order:select' => 'order',
      'updated_order:select' => 'updated_order',
    ));
  $rules['uc_legiest_order_becomes_pending'] = $rule;

  // Declencheur commande processing
  // Change statut si aucun produit à expédier
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes processing');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition('data_is', array(
      'data:select' => 'updated-order:order-status',
      'value' => 'processing',
    ))
    ->condition(rules_condition('uc_order_condition_is_shippable', array(
      'order:select' => 'updated_order',
    ))->negate())
    ->action('uc_order_update_status', array(
      'order:select' => 'updated_order',
      'order_status' => 'completed',
    ));
  $rules['uc_legiest_order_becomes_processing'] = $rule;

  // Declencheur commande payment_received
  // Change statut automatiquement
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order status payment_received to processing');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition('data_is', array(
      'data:select' => 'updated-order:order-status',
      'value' => 'payment_received',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'updated_order',
      'order_status' => 'processing',
    ));
  $rules['uc_legiest_order_becomes_payment_received'] = $rule;

  // Declencheur commande special_processing
  // Change statut si aucun produit à expédier
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes special_processing');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition('data_is', array(
      'data:select' => 'updated-order:order-status',
      'value' => 'special_processing',
    ))
    ->condition('uc_order_condition_is_shippable', array(
      'order:select' => 'updated_order',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'updated_order',
      'order_status' => 'special_pending',
    ));
  $rules['uc_legiest_order_becomes_processing_special'] = $rule;

  // Declencheur commande special_pending
  // Change statut si paiement déjà complété
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes special_pending');
  $rule->active = TRUE;
  $rule->event('uc_order_status_update')
    ->condition('data_is', array(
      'data:select' => 'updated-order:order-status',
      'value' => 'special_pending',
    ))
    ->condition('uc_payment_condition_order_balance', array(
      'order:select' => 'order',
      'balance_comparison' => 'less_equal',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'order',
      'order_status' => 'completed',
    ));
  $rules['uc_legiest_order_becomes_pending_special'] = $rule;

  // Declencheur commande special_pending
  // Change statut si paiement complété
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order special_pending is paid');
  $rule->active = TRUE;
  $rule->event('uc_payment_entered')
    ->condition('data_is', array(
      'data:select' => 'order:order-status',
      'value' => 'special_pending',
    ))
    ->condition('uc_payment_condition_order_balance', array(
      'order:select' => 'order',
      'balance_comparison' => 'less_equal',
    ))
    ->action('uc_order_update_status', array(
      'order:select' => 'order',
      'order_status' => 'completed',
    ));
  $rules['uc_legiest_order_pending_special_is_paid'] = $rule;


  return $rules;
}
