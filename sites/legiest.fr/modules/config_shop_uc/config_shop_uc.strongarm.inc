<?php
/**
 * @file
 * config_shop_uc.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function config_shop_uc_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_fields';
  $strongarm->value = array(
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'company' => 'company',
    'street1' => 'street1',
    'street2' => 'street2',
    'city' => 'city',
    'country' => 'country',
    'postal_code' => 'postal_code',
    'phone' => 'phone',
  );
  $export['uc_address_fields'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_fields_required';
  $strongarm->value = array(
    'first_name' => 'first_name',
    'last_name' => 'last_name',
    'company' => 'company',
    'street1' => 'street1',
    'city' => 'city',
    'country' => 'country',
    'postal_code' => 'postal_code',
  );
  $export['uc_address_fields_required'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_fields_weight';
  $strongarm->value = array(
    'first_name' => '-9',
    'last_name' => '-8',
    'company' => '-10',
    'street1' => '-7',
    'street2' => '-6',
    'city' => '-4',
    'zone' => '-3',
    'country' => '-2',
    'postal_code' => '-5',
    'phone' => '-1',
  );
  $export['uc_address_fields_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_175';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_175'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_250';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!postal_code !city
!country_name_if';
  $export['uc_address_format_250'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_254';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city, !zone_name  !postal_code
!country_name_if';
  $export['uc_address_format_254'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_258';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_258'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_260';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_260'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_312';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_312'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_474';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_474'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_492';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city !zone_code !postal_code
!country_name_if';
  $export['uc_address_format_492'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_540';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city !zone_code !postal_code
!country_name_if';
  $export['uc_address_format_540'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_56';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!postal_code !city
!country_name_if';
  $export['uc_address_format_56'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_638';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city !zone_code !postal_code
!country_name_if';
  $export['uc_address_format_638'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_652';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_652'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_663';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_663'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_666';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_666'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_756';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!postal_code !city
!country_name_if';
  $export['uc_address_format_756'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_address_format_876';
  $strongarm->value = '!company
!first_name !last_name
!street1
!street2
!city  !postal_code
!country_name_if';
  $export['uc_address_format_876'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_add_item_redirect';
  $strongarm->value = '<none>';
  $export['uc_add_item_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_cart_form_enabled';
  $strongarm->value = 1;
  $export['uc_cap_cart_form_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_cart_form_weight';
  $strongarm->value = '-10';
  $export['uc_cap_cart_form_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_coupon_auto_enabled';
  $strongarm->value = 0;
  $export['uc_cap_coupon_auto_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_coupon_auto_weight';
  $strongarm->value = '-8';
  $export['uc_cap_coupon_auto_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_coupon_enabled';
  $strongarm->value = 1;
  $export['uc_cap_coupon_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_coupon_weight';
  $strongarm->value = '-9';
  $export['uc_cap_coupon_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_quotes_enabled';
  $strongarm->value = 0;
  $export['uc_cap_quotes_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cap_quotes_weight';
  $strongarm->value = '-7';
  $export['uc_cap_quotes_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_add_item_msg';
  $strongarm->value = 1;
  $export['uc_cart_add_item_msg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_duration';
  $strongarm->value = '1';
  $export['uc_cart_anon_duration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_anon_unit';
  $strongarm->value = 'weeks';
  $export['uc_cart_anon_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_duration';
  $strongarm->value = '1';
  $export['uc_cart_auth_duration'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_auth_unit';
  $strongarm->value = 'years';
  $export['uc_cart_auth_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_collapsed';
  $strongarm->value = 0;
  $export['uc_cart_block_collapsed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_collapsible';
  $strongarm->value = 1;
  $export['uc_cart_block_collapsible'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_empty_hide';
  $strongarm->value = 0;
  $export['uc_cart_block_empty_hide'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_block_image';
  $strongarm->value = 0;
  $export['uc_cart_block_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_text';
  $strongarm->value = '';
  $export['uc_cart_breadcrumb_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_breadcrumb_url';
  $strongarm->value = '';
  $export['uc_cart_breadcrumb_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_checkout_complete_page';
  $strongarm->value = '';
  $export['uc_cart_checkout_complete_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_delivery_not_shippable';
  $strongarm->value = 1;
  $export['uc_cart_delivery_not_shippable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_email_validation';
  $strongarm->value = 1;
  $export['uc_cart_email_validation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_help_text';
  $strongarm->value = 'Click title to display cart contents.';
  $export['uc_cart_help_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_mail_existing';
  $strongarm->value = 1;
  $export['uc_cart_mail_existing'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_details';
  $strongarm->value = '<b>Optional.</b> New customers may supply custom account details.<br />We will create these for you if no values are entered.';
  $export['uc_cart_new_account_details'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_name';
  $strongarm->value = 0;
  $export['uc_cart_new_account_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_new_account_password';
  $strongarm->value = 0;
  $export['uc_cart_new_account_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_cart_show_help_text';
  $strongarm->value = 0;
  $export['uc_cart_show_help_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_anonymous';
  $strongarm->value = 1;
  $export['uc_checkout_anonymous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_enabled';
  $strongarm->value = 1;
  $export['uc_checkout_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_instructions';
  $strongarm->value = '';
  $export['uc_checkout_instructions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_checkout_review_instructions';
  $strongarm->value = 'Your order is almost complete. Please review the details below and click \'Submit order\' if all the information is correct.  You may use the \'Back\' button to make changes to your order if necessary.';
  $export['uc_checkout_review_instructions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_collapse_current_pane';
  $strongarm->value = 1;
  $export['uc_collapse_current_pane'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_text';
  $strongarm->value = '';
  $export['uc_continue_shopping_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_type';
  $strongarm->value = 'link';
  $export['uc_continue_shopping_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_url';
  $strongarm->value = '';
  $export['uc_continue_shopping_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_continue_shopping_use_last_url';
  $strongarm->value = 1;
  $export['uc_continue_shopping_use_last_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_allow_multiple';
  $strongarm->value = 0;
  $export['uc_coupon_allow_multiple'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_collapse_pane';
  $strongarm->value = 0;
  $export['uc_coupon_collapse_pane'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_default_usage';
  $strongarm->value = 'single';
  $export['uc_coupon_default_usage'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_expiry_hour';
  $strongarm->value = '0';
  $export['uc_coupon_expiry_hour'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_expiry_timezone';
  $strongarm->value = '0';
  $export['uc_coupon_expiry_timezone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_form_components';
  $strongarm->value = array(
    'entry' => 'entry',
    'table' => 0,
    'list' => 0,
  );
  $export['uc_coupon_form_components'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_line_item_format';
  $strongarm->value = 'Coupon [uc_coupon:code]';
  $export['uc_coupon_line_item_format'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_pane_description';
  $strongarm->value = 'Saisir un code de coupon pour cette commande.';
  $export['uc_coupon_pane_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_querystring';
  $strongarm->value = 'coupon';
  $export['uc_coupon_querystring'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_show_in_cart';
  $strongarm->value = 1;
  $export['uc_coupon_show_in_cart'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_coupon_used_order_status';
  $strongarm->value = 'pending';
  $export['uc_coupon_used_order_status'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_code';
  $strongarm->value = 'EUR';
  $export['uc_currency_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_dec';
  $strongarm->value = ',';
  $export['uc_currency_dec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_prec';
  $strongarm->value = '2';
  $export['uc_currency_prec'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_sign';
  $strongarm->value = '€';
  $export['uc_currency_sign'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_currency_thou';
  $strongarm->value = ' ';
  $export['uc_currency_thou'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_customer_list_address';
  $strongarm->value = 'billing';
  $export['uc_customer_list_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_export_email';
  $strongarm->value = 'admin@duael.fr';
  $export['uc_export_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_export_headers';
  $strongarm->value = 1;
  $export['uc_export_headers'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_export_interval';
  $strongarm->value = '1';
  $export['uc_export_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_city';
  $strongarm->value = 'Ville';
  $export['uc_field_city'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_company';
  $strongarm->value = 'Société';
  $export['uc_field_company'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_country';
  $strongarm->value = 'Pays';
  $export['uc_field_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_first_name';
  $strongarm->value = 'Prénom';
  $export['uc_field_first_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_last_name';
  $strongarm->value = 'Nom';
  $export['uc_field_last_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_phone';
  $strongarm->value = 'Numéro de téléphone';
  $export['uc_field_phone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_postal_code';
  $strongarm->value = 'Code postal';
  $export['uc_field_postal_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_street1';
  $strongarm->value = 'Adresse';
  $export['uc_field_street1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_street2';
  $strongarm->value = 'Complément d\'adresse';
  $export['uc_field_street2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_field_zone';
  $strongarm->value = 'État/Région/Département';
  $export['uc_field_zone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_base_dir';
  $strongarm->value = 'sites/legiest.fr/uc_files';
  $export['uc_file_base_dir'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_download_limit_addresses';
  $strongarm->value = '2';
  $export['uc_file_download_limit_addresses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_download_limit_duration_granularity';
  $strongarm->value = 'week';
  $export['uc_file_download_limit_duration_granularity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_download_limit_duration_qty';
  $strongarm->value = '1';
  $export['uc_file_download_limit_duration_qty'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_download_limit_number';
  $strongarm->value = '2';
  $export['uc_file_download_limit_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_file_duplicate_warning';
  $strongarm->value = 1;
  $export['uc_file_duplicate_warning'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_footer_message';
  $strongarm->value = 'none';
  $export['uc_footer_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_cm';
  $strongarm->value = '!value cm';
  $export['uc_length_format_cm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_ft';
  $strongarm->value = '!value ft';
  $export['uc_length_format_ft'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_in';
  $strongarm->value = '!value in';
  $export['uc_length_format_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_format_mm';
  $strongarm->value = '!value mm';
  $export['uc_length_format_mm'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_length_unit';
  $strongarm->value = 'cm';
  $export['uc_length_unit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_li_coupon_weight';
  $strongarm->value = '0';
  $export['uc_li_coupon_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_minimum_subtotal';
  $strongarm->value = 0;
  $export['uc_minimum_subtotal'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_continue_shopping';
  $strongarm->value = '<a href="[site:url]">Return to the front page.</a>';
  $export['uc_msg_continue_shopping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_existing_user';
  $strongarm->value = 'Thank you for shopping at [store:name]. Your current order has been attached to the account we found matching your e-mail address.

<a href="/fr/user">Login</a> to view your current order status and order history. Remember to login when you make your next purchase for a faster checkout experience!';
  $export['uc_msg_order_existing_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_logged_in';
  $strongarm->value = 'Thank you for shopping at [store:name]. While logged in, you may continue shopping or <a href="[uc_order:url]">view your current order status</a> and order history.';
  $export['uc_msg_order_logged_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user';
  $strongarm->value = 'Thank you for shopping at [store:name]. A new account has been created for you here that you may use to view your current order status.

<a href="/fr/user">Login</a> to your new account using the following information:

<strong>Username:</strong> !new_username
<strong>Password:</strong> !new_password';
  $export['uc_msg_order_new_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_new_user_logged_in';
  $strongarm->value = 'Thank you for shopping at [store:name]. A new account has been created for you here that you may use to view your current order status.

Your password and further instructions have been sent to your e-mail address.

For your convenience, you are already logged in with your newly created account.';
  $export['uc_msg_order_new_user_logged_in'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_msg_order_submit';
  $strongarm->value = 'Your order is complete! Your order number is [uc_order:order-number].';
  $export['uc_msg_order_submit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_email';
  $strongarm->value = 1;
  $export['uc_new_customer_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_login';
  $strongarm->value = 0;
  $export['uc_new_customer_login'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_new_customer_status_active';
  $strongarm->value = 1;
  $export['uc_new_customer_status_active'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_order_capitalize_addresses';
  $strongarm->value = 0;
  $export['uc_order_capitalize_addresses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_enabled';
  $strongarm->value = 1;
  $export['uc_pane_billing_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_billing_weight';
  $strongarm->value = '-6';
  $export['uc_pane_billing_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_enabled';
  $strongarm->value = 1;
  $export['uc_pane_cart_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_cart_weight';
  $strongarm->value = '-10';
  $export['uc_pane_cart_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_enabled';
  $strongarm->value = 1;
  $export['uc_pane_comments_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_comments_weight';
  $strongarm->value = '-3';
  $export['uc_pane_comments_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_automatic_enabled';
  $strongarm->value = 0;
  $export['uc_pane_coupon_automatic_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_automatic_weight';
  $strongarm->value = '-1';
  $export['uc_pane_coupon_automatic_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_enabled';
  $strongarm->value = 1;
  $export['uc_pane_coupon_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_coupon_weight';
  $strongarm->value = '-9';
  $export['uc_pane_coupon_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_enabled';
  $strongarm->value = 1;
  $export['uc_pane_customer_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_customer_weight';
  $strongarm->value = '-8';
  $export['uc_pane_customer_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_enabled';
  $strongarm->value = 1;
  $export['uc_pane_delivery_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_delivery_weight';
  $strongarm->value = '-7';
  $export['uc_pane_delivery_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_enabled';
  $strongarm->value = 1;
  $export['uc_pane_payment_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_payment_weight';
  $strongarm->value = '-4';
  $export['uc_pane_payment_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_quotes_enabled';
  $strongarm->value = 1;
  $export['uc_pane_quotes_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_quotes_weight';
  $strongarm->value = '-5';
  $export['uc_pane_quotes_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_recurring-product_enabled';
  $strongarm->value = 0;
  $export['uc_pane_recurring-product_enabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_pane_recurring-product_weight';
  $strongarm->value = '-2';
  $export['uc_pane_recurring-product_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_bank_transfer_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_bank_transfer_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_bank_transfer_weight';
  $strongarm->value = '-9';
  $export['uc_payment_method_bank_transfer_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_check_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_check_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_check_weight';
  $strongarm->value = '-10';
  $export['uc_payment_method_check_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_cod_checkout';
  $strongarm->value = 0;
  $export['uc_payment_method_cod_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_cod_weight';
  $strongarm->value = '-4';
  $export['uc_payment_method_cod_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_other_checkout';
  $strongarm->value = 0;
  $export['uc_payment_method_other_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_other_weight';
  $strongarm->value = '-3';
  $export['uc_payment_method_other_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_ec_checkout';
  $strongarm->value = 0;
  $export['uc_payment_method_paypal_ec_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_ec_weight';
  $strongarm->value = '-5';
  $export['uc_payment_method_paypal_ec_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_wps_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_paypal_wps_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_paypal_wps_weight';
  $strongarm->value = '-8';
  $export['uc_payment_method_paypal_wps_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_virt_admin_checkout';
  $strongarm->value = 1;
  $export['uc_payment_method_virt_admin_checkout'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_method_virt_admin_weight';
  $strongarm->value = '-7';
  $export['uc_payment_method_virt_admin_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_payment_show_order_total_preview';
  $strongarm->value = 1;
  $export['uc_payment_show_order_total_preview'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_api_password';
  $strongarm->value = '1339334895';
  $export['uc_paypal_api_password'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_api_signature';
  $strongarm->value = 'ARvCDkf2jM7rt61mSAxmIS0nB5TzAz1xz09B1-ePAeYvkVZMhFL2h1xs';
  $export['uc_paypal_api_signature'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_api_username';
  $strongarm->value = 'seller_1339334871_biz_api1.duael.fr';
  $export['uc_paypal_api_username'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_landingpage_style';
  $strongarm->value = 'Billing';
  $export['uc_paypal_ec_landingpage_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_review_comment';
  $strongarm->value = 1;
  $export['uc_paypal_ec_review_comment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_review_company';
  $strongarm->value = 1;
  $export['uc_paypal_ec_review_company'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_review_phone';
  $strongarm->value = 1;
  $export['uc_paypal_ec_review_phone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_review_shipping';
  $strongarm->value = 1;
  $export['uc_paypal_ec_review_shipping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_ec_rqconfirmed_addr';
  $strongarm->value = 0;
  $export['uc_paypal_ec_rqconfirmed_addr'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wpp_currency';
  $strongarm->value = 'EUR';
  $export['uc_paypal_wpp_currency'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wpp_server';
  $strongarm->value = 'https://api-3t.sandbox.paypal.com/nvp';
  $export['uc_paypal_wpp_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_address_override';
  $strongarm->value = 1;
  $export['uc_paypal_wps_address_override'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_address_selection';
  $strongarm->value = 'billing';
  $export['uc_paypal_wps_address_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_cancel_return_url';
  $strongarm->value = 'cart';
  $export['uc_paypal_wps_cancel_return_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_checkout_button';
  $strongarm->value = 'Submit Order';
  $export['uc_paypal_wps_checkout_button'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_currency';
  $strongarm->value = 'EUR';
  $export['uc_paypal_wps_currency'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_debug_ipn';
  $strongarm->value = 0;
  $export['uc_paypal_wps_debug_ipn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_email';
  $strongarm->value = 'seller_1339334871_biz@duael.fr';
  $export['uc_paypal_wps_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_language';
  $strongarm->value = 'FR';
  $export['uc_paypal_wps_language'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_no_shipping';
  $strongarm->value = '1';
  $export['uc_paypal_wps_no_shipping'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_payment_action';
  $strongarm->value = 'Sale';
  $export['uc_paypal_wps_payment_action'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_server';
  $strongarm->value = 'https://www.sandbox.paypal.com/cgi-bin/webscr';
  $export['uc_paypal_wps_server'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_paypal_wps_submit_method';
  $strongarm->value = 'single';
  $export['uc_paypal_wps_submit_method'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_add_to_cart_qty';
  $strongarm->value = 1;
  $export['uc_product_add_to_cart_qty'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_product_image_widget';
  $strongarm->value = 'colorbox';
  $export['uc_product_image_widget'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_display_debug';
  $strongarm->value = 0;
  $export['uc_quote_display_debug'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_err_msg';
  $strongarm->value = 'There were problems getting a shipping quote. Please verify the delivery and product information and try again.
If this does not resolve the issue, please call in to complete your order.';
  $export['uc_quote_err_msg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_log_errors';
  $strongarm->value = 1;
  $export['uc_quote_log_errors'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_pane_description';
  $strongarm->value = 'Shipping quotes are generated automatically when you enter your address and may be updated manually with the button below.';
  $export['uc_quote_pane_description'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_require_quote';
  $strongarm->value = 1;
  $export['uc_quote_require_quote'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_quote_store_default_address';
  $strongarm->value = UcAddress::__set_state(array(
   'first_name' => '',
   'last_name' => '',
   'company' => '',
   'street1' => '',
   'street2' => '',
   'city' => '',
   'zone' => 0,
   'country' => '56',
   'postal_code' => '',
   'phone' => '',
   'email' => '',
));
  $export['uc_quote_store_default_address'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_fail';
  $strongarm->value = 'fail';
  $export['uc_recurring_checkout_fail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_message';
  $strongarm->value = '';
  $export['uc_recurring_checkout_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_checkout_process';
  $strongarm->value = 1;
  $export['uc_recurring_checkout_process'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_payment_methods';
  $strongarm->value = array(
    'check' => 'check',
    'cod' => 'cod',
    'other' => 'other',
  );
  $export['uc_recurring_payment_methods'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_product_checkout_pane_message';
  $strongarm->value = '';
  $export['uc_recurring_product_checkout_pane_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_recurring_trigger_renewals';
  $strongarm->value = 1;
  $export['uc_recurring_trigger_renewals'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_reflate_email';
  $strongarm->value = 'admin@duael.fr';
  $export['uc_reflate_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_reflate_interval';
  $strongarm->value = '30';
  $export['uc_reflate_interval'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_reports_reported_statuses';
  $strongarm->value = array(
    'completed' => 'completed',
    'abandoned' => 0,
    'canceled' => 0,
    'in_checkout' => 0,
    'pending' => 0,
    'processing' => 0,
    'paypal_pending' => 0,
    'payment_received' => 0,
  );
  $export['uc_reports_reported_statuses'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_reports_table_size';
  $strongarm->value = '30';
  $export['uc_reports_table_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_sign_after_amount';
  $strongarm->value = 1;
  $export['uc_sign_after_amount'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_city';
  $strongarm->value = '';
  $export['uc_store_city'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_country';
  $strongarm->value = '840';
  $export['uc_store_country'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_email';
  $strongarm->value = 'contact@legiest.fr';
  $export['uc_store_email'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_email_include_name';
  $strongarm->value = 1;
  $export['uc_store_email_include_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_fax';
  $strongarm->value = '';
  $export['uc_store_fax'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_help_page';
  $strongarm->value = '';
  $export['uc_store_help_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_name';
  $strongarm->value = 'Legiest';
  $export['uc_store_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_owner';
  $strongarm->value = '';
  $export['uc_store_owner'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_phone';
  $strongarm->value = '';
  $export['uc_store_phone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_postal_code';
  $strongarm->value = '';
  $export['uc_store_postal_code'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street1';
  $strongarm->value = '';
  $export['uc_store_street1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_street2';
  $strongarm->value = '';
  $export['uc_store_street2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_store_zone';
  $strongarm->value = 0;
  $export['uc_store_zone'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_use_next_buttons';
  $strongarm->value = 1;
  $export['uc_use_next_buttons'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_g';
  $strongarm->value = '!value g';
  $export['uc_weight_format_g'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_kg';
  $strongarm->value = '!value kg';
  $export['uc_weight_format_kg'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_lb';
  $strongarm->value = '!value lb';
  $export['uc_weight_format_lb'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_format_oz';
  $strongarm->value = '!value oz';
  $export['uc_weight_format_oz'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uc_weight_unit';
  $strongarm->value = 'kg';
  $export['uc_weight_unit'] = $strongarm;

  return $export;
}
