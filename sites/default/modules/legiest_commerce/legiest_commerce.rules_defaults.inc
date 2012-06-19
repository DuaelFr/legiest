<?php
/**
 * @file
 * legiest_commerce rules
 */

/**
 * Implements hook_default_rules_configuration().
 */
function legiest_commerce_default_rules_configuration() {
  $rules = array();
  
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


  //----------------------------------------------------------------------------
  // Independant transition rules

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
    ->condition(rules_condition('legiest_commerce_rules_condition_is_shippable', array(
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
    ->condition(rules_condition('legiest_commerce_rules_condition_is_shippable', array(
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

  
  //----------------------------------------------------------------------------
  // Grouped transition rules

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
    ->condition(rules_condition('legiest_commerce_rules_condition_is_shippable', array(
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
    ->condition(rules_condition('legiest_commerce_rules_condition_is_shippable', array(
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
 * Implements hook_default_rules_configuration_alter().
 */
function legiest_commerce_default_rules_configuration_alter(&$configs) {
  // Disable old commerce_file rule
  $configs['commerce_file_license_issue_order']->active = FALSE;
}
