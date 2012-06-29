<?php

/**
 * @file
 * Export Drupal Commerce file subscriptions to Views.
 */

/**
 * Implements hook_views_data()
 */
function legiest_subscription_views_data() {
  $data = array();

  // -----------------------------------------------------------------------
  // subscription Table

  $data['legiest_subscription']['table']['group']  = t('Subscription');
  $data['legiest_subscription']['table']['base'] = array(
    'field' => 'subscription_id',
    'title' => t('Legiest Subscription'),
    'help' => t('Legiest subscriptions.'),
  );

  // For other base tables, explain how we join
  // 'left_field' is the primary key in the referenced table.
  // 'field' is the foreign key in this table.
  $data['legiest_subscription']['table']['join'] = array(
    'users' => array(
      'left_field' => 'uid',
      'field' => 'uid',
    ),
    'commerce_product' => array(
      'left_field' => 'product_id',
      'field' => 'product_id',
    ),
  );


  $data['legiest_subscription']['subscription_id'] = array(
    'title' => t('Subscription ID', array(), array('context' => 'a legiest subscription')),
    'help' => t('The unique internal identifier of the subscription.'),
    'field' => array(
      'handler' => 'legiest_subscription_handler_field_subscription',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
      'numeric' => TRUE,
    ),
  );

  $data['legiest_subscription']['status'] = array(
    'title' => t('Status'),
    'help' => t('The status of the subscription.'),
    'field' => array(
      'handler' => 'legiest_subscription_handler_field_subscription_status',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'legiest_subscription_handler_filter_subscription_status',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );

  $data['legiest_subscription']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the subscription was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['legiest_subscription']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the subscription was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['legiest_subscription']['revoked'] = array(
    'title' => t('Revoked date'),
    'help' => t('The date the subscription was revoked.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['legiest_subscription']['ending'] = array(
    'title' => t('Ending date'),
    'help' => t('The date the subscription will end.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['legiest_subscription']['duration'] = array(
    'title' => t('Duration'),
    'help' => t('The subscription\'s duration.'),
    'field' => array(
      'handler' => 'legiest_subscription_handler_field_subscription_duration',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['legiest_subscription']['price'] = array(
    'title' => t('Price'),
    'help' => t('The subscription\'s price.'),
    'field' => array(
      'handler' => 'legiest_subscription_handler_field_subscription_price',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
  );

  $data['legiest_subscription']['uid'] = array(
    'title' => t('Owner uid'),
    'help' => t('Uid of the subscription owner.'),
    'field' => array(
      'handler' => 'views_handler_field_user',
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'name', // display this field in the summary
    ),
    'filter' => array(
      'title' => t('Name'),
      'handler' => 'views_handler_filter_user_name',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Subscription owner'),
    ),
  );

  $data['legiest_subscription']['product_id'] = array(
    'title' => t('Product ID'),
    'help' => t('Subscribed product_id.'),
    'field' => array(
      'handler' => 'commerce_product_handler_field_product',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'commerce_product_handler_argument_product_id',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'commerce_product',
      'field' => 'product_id',
      'label' => t('Subscribed product'),
    ),
  );

  
  // -- Admin links ---------------------------------------- //
  $data['legiest_subscription']['view_subscription'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the view of the subscription.'),
      'handler' => 'legiest_subscription_handler_field_subscription_link',
    ),
  );
  $data['legiest_subscription']['edit_subscription'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the subscription.'),
      'handler' => 'legiest_subscription_handler_field_subscription_link_edit',
    ),
  );
  $data['legiest_subscription']['revoke_subscription'] = array(
    'field' => array(
      'title' => t('Revoke link'),
      'help' => t('Provide a simple link to revoke the subscription.'),
      'handler' => 'legiest_subscription_handler_field_subscription_link_revoke',
    ),
  );
  $data['legiest_subscription']['delete_subscription'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the subscription.'),
      'handler' => 'legiest_subscription_handler_field_subscription_link_delete',
    ),
  );


  return $data;
}

/**
 * Implements hook_views_plugins
 */
function legiest_subscription_views_plugins() {
  return array(
    'argument validator' => array(
      'legiest_subscription_user' => array(
        'title' => t('Legiest Subscription User'),
        'handler' => 'legiest_subscription_plugin_argument_validate_user',
        'path' => drupal_get_path('module', 'legiest_subscription') . '/views/handlers', // not necessary for most modules
      ),
    ),
  );
}
