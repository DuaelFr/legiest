  <?php

/**
 * @file
 * This file is the default customer invoice template for Ubercart.
 *
 * Available variables:
 * - $products: An array of product objects in the order, with the following
 *   members:
 *   - title: The product title.
 *   - model: The product SKU.
 *   - qty: The quantity ordered.
 *   - total_price: The formatted total price for the quantity ordered.
 *   - individual_price: If quantity is more than 1, the formatted product
 *     price of a single item.
 *   - details: Any extra details about the product, such as attributes.
 * - $line_items: An array of line item arrays attached to the order, each with
 *   the following keys:
 *   - line_item_id: The type of line item (subtotal, shipping, etc.).
 *   - title: The line item display title.
 *   - formatted_amount: The formatted amount of the line item.
 * - $shippable: TRUE if the order is shippable.
 *
 * Tokens: All site, store and order tokens are also available as
 * variables, such as $site_logo, $store_name and $order_first_name.
 *
 * Display options:
 * - $op: 'view', 'print', 'checkout-mail' or 'admin-mail', depending on
 *   which variant of the invoice is being rendered.
 * - $business_header: TRUE if the invoice header should be displayed.
 * - $shipping_method: TRUE if shipping information should be displayed.
 * - $help_text: TRUE if the store help message should be displayed.
 * - $email_text: TRUE if the "do not reply to this email" message should
 *   be displayed.
 * - $store_footer: TRUE if the store URL should be displayed.
 * - $thank_you_message: TRUE if the 'thank you for your order' message
 *   should be displayed.
 *
 * @see template_preprocess_uc_order()
 */
?>
<script type="text/css">
.invoice tbody { border-top: none; }

.invoice-content {
  margin-bottom: 0;
}
#invoice-header {
  margin-bottom: 0;
}
#store-name {
  text-transform: uppercase;
  color: #0062A0;
  font-weight: bold;
}
#store-slogan {
  font-size: 85%;
  color: #DC0932;
}
#store-address {
  font-size: 90%;
  color: #555;
}
.invoice-number {
  float: left;
  font-size: 150%;
  font-weight: bold;
  margin-bottom: 0;
}
.invoice-date {
  float: right;
  padding-right: 20px;
  margin-bottom: 0;
}
#purchasing-header {
  font-size: 150%;
  color: #0062A0;
}
.purch-order-infos-title {
  background-color: #ddd;
  color: #333;
}
.shipping-infos {
  background-color: #efefef;
  color: #666;
  font-weight: bold;
  
}
.penalties-infos {
  font-size: 80%;
}
.rib-infos table {
  margin-bottom: 0;
}
.rib-infos td {
  border: 1px solid; 
  font-size: 90%;
  padding: 2px 4px;
}
.iban-swift-infos {
  font-size: 90%;
  color: #666;
  margin-bottom: 0;
}
.soc-compt-infos {
  font-size: 90%;
  color: #999;
  text-align: center;
}
</script>
<div class="invoice">
<table class="first-level-table" width="95%" border="0" cellspacing="0" cellpadding="1" align="center" bgcolor="#006699" style="font-family: verdana, arial, helvetica; font-size: small;">
  <tr>
    <td id="invoice-border">
      <table width="100%" border="0" cellspacing="0" cellpadding="5" align="center" bgcolor="#FFFFFF" style="font-family: verdana, arial, helvetica; font-size: small;">
        <?php if ($business_header): ?>
        <tr valign="top">
          <td>
            <table id="invoice-header" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
              <tr>
                <td>
                  <?php print $site_logo; ?>
                </td>
                <td width="98%">
                  <div style="padding-left: 1em;">
                  <span id="store-name" style="font-size: large;"><?php //print $store_name; ?>Droit du Travail</span><br />
                  <span id="store-slogan"><?php //print $site_slogan; ?></span>
                  </div>
                </td>
                <td id="store-address" nowrap="nowrap">
                  <?php print $store_address; ?><br />Tél : <?php print $store_phone; ?><br /><?php print $store_email; ?>
                </td>
              </tr>
            </table>
          </td>
        </tr>
        <?php endif; ?>
        <tr>
          <td>
            <?php
              $date_time = explode(' - ', $order_created);
              $date_elements = explode('/', $date_time[0]);
              $order_date = $date_elements[1] . '/' . $date_elements[0] . '/' . $date_elements[2];
              $order_date_time = $order_date . ' - ' . $date_time[1];
            ?>
            <p class="invoice-number">Facture n° L<?php print strip_tags($order_link); ?></p>
            <p class="invoice-date">Date : <?php print $order_date; ?></span></p>
          </td>
        </tr>
        <tr valign="top">
          <td>

            <?php if ($thank_you_message): ?>
            <p><b><?php print t('Thanks for your order, !order_first_name!', array('!order_first_name' => $order_first_name)); ?></b></p>

            <?php if (isset($order->data['new_user'])): ?>
            <p><b><?php print t('An account has been created for you with the following details:'); ?></b></p>
            <p><b><?php print t('Username:'); ?></b> <?php print $order_new_username; ?><br />
            <b><?php print t('Password:'); ?></b> <?php print $order_new_password; ?></p>
            <?php endif; ?>

            <p><b><?php print t('Want to manage your order online?'); ?></b><br />
            <?php print t('If you need to check the status of your order, please visit our home page at !store_link and click on "My account" in the menu or login with the following link:', array('!store_link' => $store_link)); ?>
            <br /><br /><?php print $site_login_link; ?></p>
            <?php endif; ?>

            <table class="invoice-content" cellpadding="4" cellspacing="0" border="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
              <tr>
                <td class="purch-order-infos-title" colspan="2"  >
                  <b><?php print t('Purchasing Information:'); ?></b>
                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php print t('E-mail Address:'); ?></b>
                </td>
                <td width="98%">
                  <?php print $order_email; ?>
                </td>
              </tr>
              <tr>
                <td colspan="2">

                  <table width="100%" cellspacing="0" cellpadding="0" style="font-family: verdana, arial, helvetica; font-size: small;">
                    <tr>
                      <td valign="top" width="50%">
                        <b><?php print t('Billing Address:'); ?></b><br />
                        <?php print $order_billing_address; ?><br />
                        <br />
                        <b><?php print t('Billing Phone:'); ?></b><br />
                        <?php print $order_billing_phone; ?><br />
                      </td>
                      <?php if ($shippable): ?>
                      <td valign="top" width="50%">
                        <b><?php print t('Shipping Address:'); ?></b><br />
                        <?php print $order_shipping_address; ?><br />
                        <br />
                        <b><?php print t('Shipping Phone:'); ?></b><br />
                        <?php print $order_shipping_phone; ?><br />
                      </td>
                      <?php endif; ?>
                    </tr>
                  </table>

                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php print t('Order Grand Total:'); ?></b>
                </td>
                <td width="98%">
                  <b><?php print $order_total; ?></b>
                </td>
              </tr>
              <tr>
                <td nowrap="nowrap">
                  <b><?php print t('Payment Method:'); ?></b>
                </td>
                <td width="98%">
                  <?php print $order_payment_method; ?>
                </td>
              </tr>

              <tr>
                <td class="purch-order-infos-title" colspan="2">
                  <b><?php print t('Order Summary:'); ?></b>
                </td>
              </tr>

              <?php if ($shippable): ?>
              <tr>
                <td class="shipping-infos" colspan="2"><?php print t('Shipping Details:'); ?></td>
              </tr>
              <?php endif; ?>

              <tr>
                <td colspan="2">

                  <table border="0" cellpadding="1" cellspacing="0" width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">
                    <tr>
                      <td nowrap="nowrap">
                        <b><?php print t('Order #:'); ?></b>
                      </td>
                      <td width="98%">
                        <?php print $order_link; ?>
                      </td>
                    </tr>

                    <tr>
                      <td nowrap="nowrap">
                        <b><?php print t('Order Date: '); ?></b>
                      </td>
                      <td width="98%">
                        <?php print $order_date_time; ?>
                      </td>
                    </tr>

                    <?php if ($shipping_method && $shippable): ?>
                    <tr>
                      <td nowrap="nowrap">
                        <b><?php print t('Shipping Method:'); ?></b>
                      </td>
                      <td width="98%">
                        <?php print $order_shipping_method; ?>
                      </td>
                    </tr>
                    <?php endif; ?>

                    <tr>
                      <td nowrap="nowrap">
                        <?php print t('Products Subtotal:'); ?>&nbsp;
                      </td>
                      <td width="98%">
                        <?php print $order_subtotal; ?>
                      </td>
                    </tr>

                    <?php foreach ($line_items as $item): ?>
                    <?php if ($item['type'] == 'subtotal' || $item['type'] == 'total')  continue; ?>

                    <tr>
                      <td nowrap="nowrap">
                        <?php print $item['title']; ?>:
                      </td>
                      <td>
                        <?php print $item['formatted_amount']; ?>
                      </td>
                    </tr>

                    <?php endforeach; ?>

                    <tr>
                      <td>&nbsp;</td>
                      <td>------</td>
                    </tr>

                    <tr>
                      <td nowrap="nowrap">
                        <b><?php print t('Total for this Order:'); ?>&nbsp;</b>
                      </td>
                      <td>
                        <b><?php print $order_total; ?></b>
                      </td>
                    </tr>

                    <tr>
                      <td colspan="2">
                        <br /><br /><b><?php print t('Products on order:'); ?>&nbsp;</b>

                        <table width="100%" style="font-family: verdana, arial, helvetica; font-size: small;">

                          <?php foreach ($products as $product): ?>
                          <tr>
                            <td valign="top" nowrap="nowrap">
                              <b><?php print $product->qty; ?> x </b>
                            </td>
                            <td width="98%">
                              <b><?php print $product->title; ?> - <?php print $product->total_price; ?></b>
                              <?php print $product->individual_price; ?><br />
                              <?php print t('SKU'); ?>: <?php print $product->model; ?><br />
                              <?php print $product->details; ?>
                            </td>
                          </tr>
                          <?php endforeach; ?>
                        </table>

                      </td>
                    </tr>
                  </table>

                </td>
              </tr>
              <?php if ($help_text || $email_text || $store_footer): ?>
              <tr>
                <td colspan="2">
                  <hr noshade="noshade" size="1" /><br />

                  <?php if ($help_text): ?>
                  <p><b><?php print t('Where can I get help with reviewing my order?'); ?></b><br />
                  <?php print t('To learn more about managing your orders on !store_link, please visit our <a href="!store_help_url">help page</a>.', array('!store_link' => $store_link, '!store_help_url' => $store_help_url)); ?>
                  <br /></p>
                  <?php endif; ?>

                  <?php if ($email_text): ?>
                  <p><?php print t('Please note: This e-mail message is an automated notification. Please do not reply to this message.'); ?></p>

                  <p><?php print t('Thanks again for shopping with us.'); ?></p>
                  <?php endif; ?>

                  <!--
                  <?php if ($store_footer): ?>
                  <p><b><?php print $store_link; ?></b><br /><b><?php print $site_slogan; ?></b></p>
                  <?php endif; ?>
                  -->
                </td>
              </tr>
              <?php endif; ?>              
            </table>
          </td>
        </tr>
        <tr>
          <td class="penalties-infos">       
          Pénalités de retard : Taux annuel de : 8,00 %<br />
          Frais de recouvrement : Le montant de l'indemnité forfaitaire légale est de 40 euros (art. D. 441-5 du Code du Commerce)
          </td>
        </tr>
        <tr>
          <td class="rib-infos">
            <table>
              <tr>
                <td>Code Banque</td>               
                <td>Code Guichet</td>
                <td>Numéro de Compte</td>                
                <td>Clé RIB</td>                
                <td>Domiciliation</td>
              </tr>
              <tr>
                <td>12506</td>                
                <td>20049</td>
                <td>56039910946</td>                
                <td>02</td>                
                <td>Crédit Agricole Besançon Entreprises</td>
              </tr>
            </table>
            <p class="iban-swift-infos">
            IBAN : FR76 1250 6200 4956 0399 1094 602<br/>
            SWIFT : AGRIFRPP825
            </p>
          </td>
        </tr> 
        <tr>
          <td class="soc-compt-infos">
            LEGIEST - SARL au capital de 7 500 € - RCS MONTPELLIER - SIRET : 52886183400018<br />
            TVA FR 67 528861834
          </td>
        </tr> 
      </table>
    </td>
  </tr>
</table>
</div>
