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


  //---------------------------
  // Automatic transition rules

  // Transition auto "Vérification : Expédier" => "Vérification : Vérifier"
  // Si aucun produit physique
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Jump forward over shipping step');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'checkout_shipping',
    ))
    ->condition(
      rules_or()
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:status',
          'op' => '==',
          'value' => 'checkout_shipping',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:status',
          'op' => '==',
          'value' => 'checkout_review',
        ))
        ->negate()
    )
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'uc_order:select' => 'uc_order',
    ))->negate())
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'checkout_review',
    ))
    ->action('redirect', array(
      'url' => 'checkout/[commerce-order:order-id]/review',
    ));
  $rules['uc_legiest_jump_forward_shipping'] = $rule;


  // Transition auto "Vérification : Expédier" => "Vérification : Procéder au paiement"
  // Si aucun produit physique et action utilisateur
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Jump backward over shipping step');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'checkout_shipping',
    ))
    ->condition('data_is', array(
      'data:select' => 'commerce-order-unchanged:status',
      'op' => '==',
      'value' => 'checkout_review',
    ))
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'uc_order:select' => 'uc_order',
    ))->negate())
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'checkout_checkout',
    ))
    ->action('redirect', array(
      'url' => 'checkout/[commerce-order:order-id]',
    ));
  $rules['uc_legiest_jump_backward_shipping'] = $rule;

  
  //----------------------------------
  // States transition component rules

  $variables = array(
    'uc_order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
    'uc_order_unchanged' => array(
      'label' => 'Order before changes',
      'type' => 'uc_order'
    ),
  );

  // Transition auto "En cours de traitement" => "Terminé"
  // Si aucun produit physique
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order no shipping');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing',
    ))
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'uc_order:select' => 'uc_order',
    ))->negate())
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'completed',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from processing to completed',
    ));
  $rules['uc_legiest_order_no_shipping'] = $rule;

  // Transition auto "En attente" => "En cours de traitement"
  // Si reste à payer 0
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order paid');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->condition('commerce_payment_order_balance_comparison', array(
      'uc_order:select' => 'uc_order',
      'op' => '<=',
      'value' => '0',
    ))
    ->condition(rules_condition('uc_legiest_rules_condition_user_special', array(
      'user:select' => 'commerce-order:owner',
    ))->negate())
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'processing',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending to processing',
    ));
  $rules['uc_legiest_order_paid'] = $rule;

  // Transition auto "En attente : Administration" => "Terminé"
  // Si reste à payer 0
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order paid special');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending_special',
    ))
    ->condition('commerce_payment_order_balance_comparison', array(
      'uc_order:select' => 'uc_order',
      'op' => '<=',
      'value' => '0',
    ))
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'completed',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending_special to completed',
    ));
  $rules['uc_legiest_order_paid_special'] = $rule;

  // Transition auto "En cours de traitement : Administration" => "En attente : administration"
  // Si aucun produit physique
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Order no shipping special');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing_special',
    ))
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'uc_order:select' => 'uc_order',
    ))->negate())
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'pending_special',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from processing_special to pending_special',
    ));
  $rules['uc_legiest_order_no_shipping_special'] = $rule;

  // Transition auto "En attente" => "En cours de traitement : administration"
  // Si client possède la permission "use special order states"
  $rule = rule($variables);
  $rule->label = t('(UC Legiest) Alternative order process');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->condition('uc_legiest_rules_condition_user_special', array(
      'user:select' => 'commerce-order:owner',
    ))
    ->action('uc_order_update_status', array(
      'uc_order:select' => 'uc_order',
      'order_status' => 'processing_special',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending to processing_special',
    ));
  $rules['uc_legiest_order_client_special'] = $rule;

  
  //---------------------
  // States trigger rules 

  // Declencheur commande "En attente"
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes pending');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->action('component_uc_legiest_order_client_special', array(
      'uc_order:select' => 'uc_order',
      'uc_order_unchanged:select' => 'uc_order_unchanged',
    ))
    ->action('component_uc_legiest_order_paid', array(
      'uc_order:select' => 'uc_order',
      'uc_order_unchanged:select' => 'uc_order_unchanged',
    ));
  $rules['uc_legiest_order_becomes_pending'] = $rule;

  // Declencheur commande "En cours de traitement"
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes processing');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing',
    ))
    ->action('component_uc_legiest_order_no_shipping', array(
      'uc_order:select' => 'uc_order',
      'uc_order_unchanged:select' => 'uc_order_unchanged',
    ));
  $rules['uc_legiest_order_becomes_processing'] = $rule;

  // Declencheur commande "En cours de traitement : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes processing_special');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing_special',
    ))
    ->action('component_uc_legiest_order_no_shipping_special', array(
      'uc_order:select' => 'uc_order',
      'uc_order_unchanged:select' => 'uc_order_unchanged',
    ));
  $rules['uc_legiest_order_becomes_processing_special'] = $rule;

  // Declencheur commande "En attente : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Order becomes pending_special');
  $rule->active = TRUE;
  $rule->event('uc_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending_special',
    ))
    ->action('component_uc_legiest_order_paid_special', array(
      'uc_order:select' => 'uc_order',
      'uc_order_unchanged:select' => 'uc_order_unchanged',
    ));
  $rules['uc_legiest_order_becomes_pending_special'] = $rule;

  return $rules;
}


/**
 * Define rules and components related to taxes
 */
function _uc_legiest_default_rules_configuration_taxes() {
  $rules = array();

  
  $variables = array(
    'uc_order' => array(
      'label' => 'Order',
      'type' => 'uc_order'
    ),
  );
  
  
  // Billing address with VAT
  $rule = rules_or($variables);
  $rule->label = t('(UC Legiest) Condition Billing region with VAT');
  $rule->active = TRUE;
  $rule
    ->condition('uc_order_compare_address', array(
      'uc_order:select' => 'uc_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'FR', // France
    ));
  $rules['uc_legiest_condition_billing_with_vat'] = $rule;

  // Declencheur commande "En attente : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(UC Legiest) Apply tax "tva_standard"');
  $rule->active = TRUE;
  $rule->event('commerce_product_calculate_sell_price')
    ->condition('component_uc_legiest_condition_billing_with_vat', array(
      'uc_order:select' => 'commerce-line-item:order',
    ))
    ->action('commerce_tax_rate_apply', array(
      'commerce_line_item:select' => 'commerce_line_item',
      'tax_rate_name' => 'tva_standard',
      'applied_tax:var' => 'applied_tax',
      'applied_tax:label' => 'Taxe appliquée',
    ));
  $rules['uc_legiest_apply_tax_tva_standard'] = $rule;

  return $rules;
}
