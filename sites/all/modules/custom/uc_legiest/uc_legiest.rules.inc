<?php
/**
 * @file
 * uc_legiest rules
 */

/**
 * Implements hook_rules_condition_info().
 */
function uc_legiest_rules_condition_info() {
  return array(
    'uc_legiest_rules_condition_user_special' => array(
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
 * Rules condition 'uc_legiest_rules_condition_user_special' execution callback.
 */
function uc_legiest_rules_condition_user_special($user) {
  return user_access('use special order states', $user);
}
