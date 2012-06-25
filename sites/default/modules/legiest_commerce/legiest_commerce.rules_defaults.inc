<?php
/**
 * @file
 * legiest_commerce rules
 */

//------------------------------------------------------------------------------
// HOOKS

/**
 * Implements hook_default_rules_configuration().
 */
function legiest_commerce_default_rules_configuration() {
  $rules = array();
  
  $rules += _legiest_commerce_default_rules_configuration_shipping_weight();
  $rules += _legiest_commerce_default_rules_configuration_shipping_area();
  $rules += _legiest_commerce_default_rules_configuration_shipping_rates();
  $rules += _legiest_commerce_default_rules_configuration_taxes();
  $rules += _legiest_commerce_default_rules_configuration_states();
  
  //----------------------------------------------------------------------------
  // Common rules
    
  // Make the products creation process easier
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Create Product Display');
  $rule->active = TRUE;
  $rule->event('commerce_product_insert')
    ->action('entity_create', array(
      'type' => 'node',
      'param_type' => 'product_display',
      'param_title:select' => 'commerce-product:title',
      'param_author:select' => 'commerce-product:creator',
    ))
    ->action('data_set', array(
      'data:select' => 'entity-created:field-reference',
      'value:select' => 'commerce-product',
    ))
    ->action('data_set', array(
      'data:select' => 'entity-created:status',
      'value' => '1',
    ))
    ->action('entity_save', array(
      'data:select' => 'entity-created',
      'immediate' => '1',
    ))
    ->action('redirect', array(
      'url' => 'node/[entity-created:nid]/edit',
    ));
  $rules['create_product_display'] = $rule;
  
  // Alter default commerce_file rule to fit our needs and our new states.
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Issue licenses on order update');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
    ->condition(
      rules_or()
        ->condition('data_is', array(
          'data:select' => 'commerce-order:state',
          'op' => '==',
          'value' => 'completed',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order:status',
          'op' => '==',
          'value' => 'processing',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order:status',
          'op' => '==',
          'value' => 'pending_special',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order:status',
          'op' => '==',
          'value' => 'processing_special',
        ))
    )
    ->condition(
      rules_or()
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:state',
          'op' => '==',
          'value' => 'completed',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:status',
          'op' => '==',
          'value' => 'processing',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:status',
          'op' => '==',
          'value' => 'pending_special',
        ))
        ->condition('data_is', array(
          'data:select' => 'commerce-order-unchanged:status',
          'op' => '==',
          'value' => 'processing_special',
        ))
        ->negate()
    )
    ->action('commerce_file_license_issue_order', array(
      'order:select' => 'commerce-order',
      'license-status' => 'active',
    ));
  $rules['legiest_commerce_file_license_issue_order'] = $rule;

  
  return $rules;
}

/**
 * Implements hook_default_rules_configuration_alter().
 */
function legiest_commerce_default_rules_configuration_alter(&$configs) {
  // Disable old commerce_file rule
  $configs['commerce_file_license_issue_order']->active = FALSE;
}


//------------------------------------------------------------------------------
// CALLBACKS

/**
 * Define rules and components related to shipping area
 */
function _legiest_commerce_default_rules_configuration_shipping_area() {
  $rules = array();


  //--------------------------
  // Component conditions area

  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order'
    ),
  );
  
  // Shipping address is in france
  $rule = rules_or($variables);
  $rule->label = t('(Legiest Commerce) Condition Shipping France');
  $rule->active = TRUE;
  $rule
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'FR', // France
    ));
  $rules['legiest_commerce_condition_shipping_france'] = $rule;
  
  
  // Shipping address is in area 1
  $rule = rules_or($variables);
  $rule->label = t('(Legiest Commerce) Condition Shipping Area 1');
  $rule->active = TRUE;
  $rule
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'GP', // Guadeloupe
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'GF', // Guyane française
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'MQ', // Martinique
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'YT', // Mayotte
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'RE', // Réunion
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'BL', // Saint-Pierre-et-Miquelon
    ));
  $rules['legiest_commerce_condition_shipping_area1'] = $rule;
  
  
  // Shipping address is in area 2
  $rule = rules_or($variables);
  $rule->label = t('(Legiest Commerce) Condition Shipping Area 2');
  $rule->active = TRUE;
  $rule
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'BE', // Belgique
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'MC', // Monaco
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'NC', // Nouvelle-Calédonie
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'PF', // Polynésie française
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'MF', // Saint Barthélemy
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'PM', // Saint-Martin (partie française)
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'CH', // Suisse
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'TF', // Terres australes françaises
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'WF', // Wallis et Futuna
    ));
  $rules['legiest_commerce_condition_shipping_area2'] = $rule;
  
  
  return $rules;
}

/**
 * Define rules and components related to shipping weight
 */
function _legiest_commerce_default_rules_configuration_shipping_weight() {
  $rules = array();


  //------------------------------
  // Component calculations weight
  
  // Calculate total weight of line item
  $variables = array(
    'line_item' => array(
      'label' => 'Line item',
      'type' => 'commerce_line_item',
    ),
    'total_weight' => array(
      'label' => 'Total weight',
      'type' => 'decimal',
      'parameter' => FALSE,
    ),
  );
  $provides = array(
    'total_weight'
  );

  $rule = rule($variables, $provides);
  $rule->label = t('(Legiest Commerce) Calculate total weight of line item');
  $rule->active = TRUE;
  $rule
    ->condition('entity_has_field', array(
      'entity:select' => 'line_item',
      'field' => 'commerce_product',
    ))
    ->condition('entity_has_field', array(
      'entity:select' => 'line-item:commerce-product',
      'field' => 'field_weight',
    ))
    ->action('data_calc', array(
      'input_1:select' => 'line-item:commerce-product:field-weight:weight',
      'op' => '*',
      'input_2:select' => 'line-item:quantity',
      'result:var' => 'result',
      'result:label' => 'Résultat du calcul',
    ))
    ->action('data_set', array(
      'data:select' => 'total-weight',
      'value:select' => 'result',
    ));
  $rules['legiest_commerce_action_calculate_weight_line_item'] = $rule;

  
  // Calculate total weight of an order
  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order',
    ),
    'total_weight' => array(
      'label' => 'Total weight',
      'type' => 'decimal',
      'parameter' => FALSE,
    ),
  );
  $provides = array(
    'total_weight'
  );

  $rule = rule($variables, $provides);
  $rule->label = t('(Legiest Commerce) Calculate total weight of order');
  $rule->active = TRUE;
  $rule
    ->action('data_set', array(
      'data:select' => 'total_weight',
      'value' => '0',
    ))
    ->action(
      rules_loop(array(
      	'list:select' => 'commerce-order:commerce-line-items',
        'item:var' => 'line_item',
        'item:label' => 'Line item',
      ))
      ->action('component_legiest_commerce_action_calculate_weight_line_item', array(
        'line_item:select' => 'line-item',
        'total_weight:var' => 'total_weight_line_item',
        'total_weight:label' => 'Total weight of line item',
      ))
      ->action('data_calc', array(
        'input_1:select' => 'total-weight',
        'op' => '+',
        'input_2:select' => 'total-weight-line-item',
        'result:var' => 'result',
        'result:label' => 'Résultat du calcul',
      ))
      ->action('data_set', array(
        'data:select' => 'total-weight',
        'value:select' => 'result',
      ))
    );
  $rules['legiest_commerce_action_calculate_weight_order'] = $rule;

  
  //----------------------------
  // Component conditions weight

  $variables = array(
    'total_weight' => array(
      'label' => 'Total Weight',
      'type' => 'decimal'
    ),
  );
  
  // Total weight is between 0 and 99g
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight between 0 and 99g');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_or()
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '=',
        'value' => '0',
      ))
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '>',
        'value' => '0',
      ))
    )
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '<',
      'value' => '0.1',
    ));
  $rules['legiest_commerce_condition_weight_0_100'] = $rule;
  
  // Total weight is between 100g and 499g
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight between 100g and 499g');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_or()
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '=',
        'value' => '0.1',
      ))
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '>',
        'value' => '0.1',
      ))
    )
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '<',
      'value' => '0.5',
    ));
  $rules['legiest_commerce_condition_weight_100_500'] = $rule;
  
  // Total weight is between 500g and 1kg
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight between 500g and 1kg');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_or()
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '=',
        'value' => '0.5',
      ))
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '>',
        'value' => '0.5',
      ))
    )
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '<',
      'value' => '1',
    ));
  $rules['legiest_commerce_condition_weight_500_1000'] = $rule;
  
  // Total weight is between 1kg and 2kg
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight between 1kg and 2kg');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_or()
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '=',
        'value' => '1',
      ))
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '>',
        'value' => '1',
      ))
    )
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '<',
      'value' => '2',
    ));
  $rules['legiest_commerce_condition_weight_1000_2000'] = $rule;
  
  // Total weight is between 2kg and 10kg
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight between 2kg and 10kg');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_or()
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '=',
        'value' => '2',
      ))
      ->condition('data_is', array(
        'data:select' => 'total_weight',
        'op' => '>',
        'value' => '2',
      ))
    )
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '<',
      'value' => '10',
    ));
  $rules['legiest_commerce_condition_weight_2000_10000'] = $rule;
  
  // Total weight is over 10kg
  $rule = rules_and($variables);
  $rule->label = t('(Legiest Commerce) Condition weight over 10kg');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'total_weight',
      'op' => '>=',
      'value' => '10',
    ));
  $rules['legiest_commerce_condition_weight_10000+'] = $rule;

  return $rules;
}

/**
 * Define rules and components related to shipping rates
 */
function _legiest_commerce_default_rules_configuration_shipping_rates() {
  $rules = array();


  //---------------------------
  // Component rates for france

  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order'
    ),
  );

  // Enable "free_shipping" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "free_shipping"');
  $rule->active = TRUE;
  $rule
    ->condition(
      rules_condition('data_is', array(
        'data:select' => 'commerce-order:commerce-order-total:amount',
        'op' => '<',
        'value' => '9900',
      ))->negate()
    )
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'free_shipping',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_france_free'] = $rule;

  // Enable "france" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "france"');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:commerce-order-total:amount',
      'op' => '<',
      'value' => '9900',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'france',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_france_standard'] = $rule;

  // Enable france's rates
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rates for France');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_shipping_france', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('component_legiest_commerce_action_enable_rate_france_standard', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('component_legiest_commerce_action_enable_rate_france_free', array(
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_france'] = $rule;


  //---------------------------
  // Component rates for area 1

  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order'
    ),
    'total_weight' => array(
      'label' => 'Total weight',
      'type' => 'decimal'
    ),
  );

  // Enable "area1_0_100" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_0_100"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_0_100', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_0_100',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_0_100'] = $rule;

  // Enable "area1_100_500" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_100_500"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_100_500', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_100_500',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_100_500'] = $rule;

  // Enable "area1_500_1000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_500_1000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_500_1000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_500_1000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_500_1000'] = $rule;

  // Enable "area1_1000_2000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_1000_2000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_1000_2000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_1000_2000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_1000_2000'] = $rule;

  // Enable "area1_2000_10000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_2000_10000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_2000_10000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_2000_10000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_2000_10000'] = $rule;

  // Enable "area1_10000+" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area1_10000+"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_10000+', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area1_10000+',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area1_10000+'] = $rule;

  // Enable area1's rates
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rates for Area 1');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_shipping_area1', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_0_100', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_100_500', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_500_1000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_1000_2000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_2000_10000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1_10000+', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ));
  $rules['legiest_commerce_action_enable_rate_area1'] = $rule;


  //---------------------------
  // Component rates for area 2

  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order'
    ),
    'total_weight' => array(
      'label' => 'Total weight',
      'type' => 'decimal'
    ),
  );

  // Enable "area2_0_100" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_0_100"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_0_100', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_0_100',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_0_100'] = $rule;

  // Enable "area2_100_500" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_100_500"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_100_500', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_100_500',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_100_500'] = $rule;

  // Enable "area2_500_1000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_500_1000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_500_1000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_500_1000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_500_1000'] = $rule;

  // Enable "area2_1000_2000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_1000_2000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_1000_2000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_1000_2000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_1000_2000'] = $rule;

  // Enable "area2_2000_10000" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_2000_10000"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_2000_10000', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_2000_10000',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_2000_10000'] = $rule;

  // Enable "area2_10000+" rate
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rate "area2_10000+"');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_weight_10000+', array(
      'total_weight:select' => 'total_weight',
    ))
    ->action('commerce_shipping_service_rate_order', array(
      'shipping_service_name' => 'area2_10000+',
      'commerce_order:select' => 'commerce_order',
    ));
  $rules['legiest_commerce_action_enable_rate_area2_10000+'] = $rule;

  // Enable area2's rates
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Enable flat rates for Area 2');
  $rule->active = TRUE;
  $rule
    ->condition('component_legiest_commerce_condition_shipping_area2', array(
      'commerce_order:select' => 'commerce_order',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_0_100', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_100_500', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_500_1000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_1000_2000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_2000_10000', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2_10000+', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ));
  $rules['legiest_commerce_action_enable_rate_area2'] = $rule;

  
  //-----------------------
  // Collect rates trigger

  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Enable shipping rates');
  $rule->active = TRUE;
  $rule->event('commerce_shipping_collect_rates')
    ->action('component_legiest_commerce_action_calculate_weight_order', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:var' => 'total_weight',
      'total_weight:label' => 'Total weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_france', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area1', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ))
    ->action('component_legiest_commerce_action_enable_rate_area2', array(
      'commerce_order:select' => 'commerce_order',
      'total_weight:select' => 'total_weight',
    ));
  $rules['legiest_commerce_action_enable_shipping_rates'] = $rule;
  

  return $rules;
}


/**
 * Define rules and components related to states and transitions
 */
function _legiest_commerce_default_rules_configuration_states() {
  $rules = array();


  //---------------------------
  // Automatic transition rules

  // Transition auto "Vérification : Expédier" => "Vérification : Vérifier"
  // Si aucun produit physique
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Jump forward over shipping step');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
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
      'commerce_order:select' => 'commerce_order',
    ))->negate())
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'checkout_review',
    ))
    ->action('redirect', array(
      'url' => 'checkout/[commerce-order:order-id]/review',
    ));
  $rules['legiest_commerce_jump_forward_shipping'] = $rule;


  // Transition auto "Vérification : Expédier" => "Vérification : Procéder au paiement"
  // Si aucun produit physique et action utilisateur
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Jump backward over shipping step');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
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
      'commerce_order:select' => 'commerce_order',
    ))->negate())
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'checkout_checkout',
    ))
    ->action('redirect', array(
      'url' => 'checkout/[commerce-order:order-id]',
    ));
  $rules['legiest_commerce_jump_backward_shipping'] = $rule;

  
  //----------------------------------
  // States transition component rules

  $variables = array(
    'commerce_order' => array(
      'label' => 'Order',
      'type' => 'commerce_order'
    ),
    'commerce_order_unchanged' => array(
      'label' => 'Order before changes',
      'type' => 'commerce_order'
    ),
  );

  // Transition auto "En cours de traitement" => "Terminé"
  // Si aucun produit physique
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Order no shipping');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing',
    ))
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'commerce_order:select' => 'commerce_order',
    ))->negate())
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'completed',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from processing to completed',
    ));
  $rules['legiest_commerce_order_no_shipping'] = $rule;

  // Transition auto "En attente" => "En cours de traitement"
  // Si reste à payer 0
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Order paid');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->condition('commerce_payment_order_balance_comparison', array(
      'commerce_order:select' => 'commerce_order',
      'op' => '<=',
      'value' => '0',
    ))
    ->condition(rules_condition('legiest_commerce_rules_condition_user_special', array(
      'user:select' => 'commerce-order:owner',
    ))->negate())
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'processing',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending to processing',
    ));
  $rules['legiest_commerce_order_paid'] = $rule;

  // Transition auto "En attente : Administration" => "Terminé"
  // Si reste à payer 0
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Order paid special');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending_special',
    ))
    ->condition('commerce_payment_order_balance_comparison', array(
      'commerce_order:select' => 'commerce_order',
      'op' => '<=',
      'value' => '0',
    ))
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'completed',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending_special to completed',
    ));
  $rules['legiest_commerce_order_paid_special'] = $rule;

  // Transition auto "En cours de traitement : Administration" => "En attente : administration"
  // Si aucun produit physique
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Order no shipping special');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing_special',
    ))
    ->condition(rules_condition('commerce_physical_rules_order_is_shippable', array(
      'commerce_order:select' => 'commerce_order',
    ))->negate())
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'pending_special',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from processing_special to pending_special',
    ));
  $rules['legiest_commerce_order_no_shipping_special'] = $rule;

  // Transition auto "En attente" => "En cours de traitement : administration"
  // Si client possède la permission "use special order states"
  $rule = rule($variables);
  $rule->label = t('(Legiest Commerce) Alternative order process');
  $rule->active = TRUE;
  $rule
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->condition('legiest_commerce_rules_condition_user_special', array(
      'user:select' => 'commerce-order:owner',
    ))
    ->action('commerce_order_update_status', array(
      'commerce_order:select' => 'commerce_order',
      'order_status' => 'processing_special',
    ))
    ->action('drupal_message', array(
      'message' => 'Automatic transition from pending to processing_special',
    ));
  $rules['legiest_commerce_order_client_special'] = $rule;

  
  //---------------------
  // States trigger rules 

  // Declencheur commande "En attente"
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Order becomes pending');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending',
    ))
    ->action('component_legiest_commerce_order_client_special', array(
      'commerce_order:select' => 'commerce_order',
      'commerce_order_unchanged:select' => 'commerce_order_unchanged',
    ))
    ->action('component_legiest_commerce_order_paid', array(
      'commerce_order:select' => 'commerce_order',
      'commerce_order_unchanged:select' => 'commerce_order_unchanged',
    ));
  $rules['legiest_commerce_order_becomes_pending'] = $rule;

  // Declencheur commande "En cours de traitement"
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Order becomes processing');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing',
    ))
    ->action('component_legiest_commerce_order_no_shipping', array(
      'commerce_order:select' => 'commerce_order',
      'commerce_order_unchanged:select' => 'commerce_order_unchanged',
    ));
  $rules['legiest_commerce_order_becomes_processing'] = $rule;

  // Declencheur commande "En cours de traitement : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Order becomes processing_special');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'processing_special',
    ))
    ->action('component_legiest_commerce_order_no_shipping_special', array(
      'commerce_order:select' => 'commerce_order',
      'commerce_order_unchanged:select' => 'commerce_order_unchanged',
    ));
  $rules['legiest_commerce_order_becomes_processing_special'] = $rule;

  // Declencheur commande "En attente : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Order becomes pending_special');
  $rule->active = TRUE;
  $rule->event('commerce_order_update')
    ->condition('data_is', array(
      'data:select' => 'commerce-order:status',
      'value' => 'pending_special',
    ))
    ->action('component_legiest_commerce_order_paid_special', array(
      'commerce_order:select' => 'commerce_order',
      'commerce_order_unchanged:select' => 'commerce_order_unchanged',
    ));
  $rules['legiest_commerce_order_becomes_pending_special'] = $rule;

  return $rules;
}


/**
 * Define rules and components related to taxes
 */
function _legiest_commerce_default_rules_configuration_taxes() {
  $rules = array();
  
  
  // Billing address without VAT
  $rule = rules_or($variables);
  $rule->label = t('(Legiest Commerce) Condition Billing region without VAT');
  $rule->active = TRUE;
  $rule
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'GP', // Guadeloupe
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'GF', // Guyane française
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'MQ', // Martinique
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'YT', // Mayotte
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'RE', // Réunion
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_billing|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'BL', // Saint-Pierre-et-Miquelon
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'NC', // Nouvelle-Calédonie
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'PF', // Polynésie française
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'MF', // Saint Barthélemy
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'PM', // Saint-Martin (partie française)
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'TF', // Terres australes françaises
    ))
    ->condition('commerce_order_compare_address', array(
      'commerce_order:select' => 'commerce_order',
      'address_field' => 'commerce_customer_shipping|commerce_customer_address',
      'address_component' => 'country',
      'value' => 'WF', // Wallis et Futuna
    ));
  $rules['legiest_commerce_condition_billing_no_vat'] = $rule;

  // Declencheur commande "En attente : Administration"
  $rule = rules_reaction_rule();
  $rule->label = t('(Legiest Commerce) Apply tax "tva_standard"');
  $rule->active = TRUE;
  $rule->event('commerce_product_calculate_sell_price')
    ->condition(rules_condition('component_legiest_commerce_condition_billing_no_vat', array(
      'commerce_order:select' => 'commerce-line-item:order',
    ))->negate())
    ->action('commerce_tax_rate_apply', array(
      'commerce_line_item:select' => 'commerce_line_item',
      'tax_rate_name' => 'tva_standard',
      'applied_tax:var' => 'applied_tax',
      'applied_tax:label' => 'Taxe appliquée',
    ));
  $rules['legiest_commerce_apply_tax_tva_standard'] = $rule;

  return $rules;
}
