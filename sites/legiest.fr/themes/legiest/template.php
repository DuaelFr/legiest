<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 * 
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */
/**
 * Themes the shopping cart block title.
 *
 * @param $variables
 *   An associative array containing:
 *   - title: The text to use for the title of the block.
 *   - icon_class: Class to use for the cart icon image or FALSE if the icon is
 *     disabled.
 *   - collapsible: TRUE or FALSE indicating whether or not the cart block is
 *     collapsible.
 *   - collapsed: TRUE or FALSE indicating whether or not the cart block is
 *     collapsed.
 *
 * @ingroup themeable
 */
function legiest_uc_cart_block_title($variables) {
  $title = $variables['title'];

  $output = '';
  
  $output .= l($title, 'cart', array(
    'attributes' => array(
      'title' => t('Show/hide shopping cart contents.'),
      'class' => array('cart-block-title-bar'),
    ),
  ));

  return $output;
}

/**
 * Themes the shopping cart block content.
 *
 * @param $variables
 *   An associative array containing:
 *   - help_text: Text to place in the small help text area beneath the cart
 *     block title or FALSE if disabled.
 *   - items: An associative array of cart item information containing:
 *     - qty: Quantity in cart.
 *     - title: Item title.
 *     - price: Item price.
 *     - desc: Item description.
 *   - item_count: The number of items in the shopping cart.
 *   - item_text: A textual representation of the number of items in the
 *     shopping cart.
 *   - total: The unformatted total of all the products in the shopping cart.
 *   - summary_links: An array of links used in the cart summary.
 *   - collapsed: TRUE or FALSE indicating whether or not the cart block is
 *     collapsed.
 *
 * @ingroup themeable
 */
function legiest_uc_cart_block_content($variables) {
  $item_count = $variables['item_count'];
  $item_text = $variables['item_text'];

  $output = '';
  
  if ($item_count > 0) {
    $output .= l($item_text, 'cart', array('html' => TRUE));
  }
  else {
    $output .= t('Panier vide');
  }

  return $output;
}

function legiest_preprocess_uc_order_invoice_page(&$variables) {
  template_preprocess_uc_order_invoice_page($variables);
  
  drupal_add_css(drupal_get_path('theme', 'legiest') . '/css/invoice-screen.css', array(
    'media' => 'screen'
  ));
  drupal_add_css(drupal_get_path('theme', 'legiest') . '/css/invoice-print.css', array(
    'media' => 'print'
  ));

  $variables['head']    = drupal_get_html_head();
  $variables['styles']  = drupal_get_css();
  $variables['content'] = str_replace('<div style="page-break-after: always;">', '<div class="invoice">', $variables['content']);

  $variables['new_page'] = $_SERVER['REQUEST_URI'] != '/admin/legiest/bulk/invoice/print';
}
