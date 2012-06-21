<?php
/**
 * @file
 * legiest_commerce rules
 */

/**
 * Implements hook_rules_condition_info().
 */
function legiest_commerce_rules_condition_info() {
  return array(
    'legiest_commerce_rules_condition_user_special' => array(
      'label' => t('User is special'),
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User'),
          'description' => t('The user who may be special (ie have the "use special order states" permission).'),
        ),
      ),
      'group' => t('User'),
    ),
  );
}

/**
 * Rules condition 'legiest_commerce_rules_condition_user_special' execution callback.
 */
function legiest_commerce_rules_condition_user_special($user) {
  return user_access('use special order states', $user);
}
