<?php

/**
 * @file
 * Template file for agreement form.
 */

drupal_add_css(drupal_get_path('module', 'uc_termsofservice') .'/uc_termsofservice.css', 'theme', 'all');
?>

<div class="tos-text">
  <?php print drupal_render($form['tos_text']); ?>
</div>

<div class ="tos-agree">
  <?php print drupal_render($form['tos_agree']); ?>
</div>
<?php print drupal_render($form);?>
