<?php
/**
 * @file
 * contextes.box.inc
 */

/**
 * Implements hook_default_box().
 */
function contextes_default_box() {
  $export = array();

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'contact_legiest';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Nous contacter';
  $box->options = array(
    'body' => array(
      'value' => '<div id="legiest-contact-us">Nous contacter</div>
<div id="legiest-phone-number-2">04 99 61 65 48</div>',
      'format' => 'full_html',
    ),
  );
  $export['contact_legiest'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'legiest_address';
  $box->plugin_key = 'simple';
  $box->title = 'Coordonnées';
  $box->description = 'Coordonnées';
  $box->options = array(
    'body' => array(
      'value' => '<p>Legiest SARL<br>4 rue Georges Besse<br>ZA de la Plaine<br>BP 12<br>34830 Clapiers</p><p>SIRET 52886183400018 APE 4690Z</p>',
      'format' => 'full_html',
    ),
    'additional_classes' => '',
  );
  $export['legiest_address'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'legiest_phone';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Téléphone Legiest';
  $box->options = array(
    'body' => array(
      'value' => '<div id="legiest-phone-number">04 99 61 65 48</div>
<div id="legiest-working-hours">Lundi > vendredi 9h-18h</div>',
      'format' => 'full_html',
    ),
  );
  $export['legiest_phone'] = $box;

  $box = new stdClass();
  $box->disabled = FALSE; /* Edit this to true to make a default box disabled initially */
  $box->api_version = 1;
  $box->delta = 'secure_payment';
  $box->plugin_key = 'simple';
  $box->title = '<none>';
  $box->description = 'Paiement sécurisé';
  $box->options = array(
    'body' => array(
      'value' => '<p>paiement sécurisé<br><img alt="" src="/sites/legiest.fr/files/cb.png" style="width: 206px; height: 23px;"><br><img alt="" src="/sites/legiest.fr/files/cheques_virements.png" style="width: 171px; height: 33px;"></p>',
      'format' => 'full_html',
    ),
  );
  $export['secure_payment'] = $box;

  return $export;
}
