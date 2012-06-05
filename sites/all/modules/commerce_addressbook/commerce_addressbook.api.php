<?php

/**
 * @file
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Allows modules to alter the list of customer profile labels.
 *
 * During checkout the user selects the "address on file" from a dropdown list
 * of customer profiles. The label used to represent each customer profile
 * is the "thoroughfare" column of the addressfield. By altering the list
 * of labels, a module can use additional data to represent each customer
 * profile. Note that the list should always be keyed by customer profile id.
 *
 * @param $labels
 *   An array of labels, keyed by customer profile id.
 * @param $profiles
 *   An array of customer profile entities.
 */
function hook_commerce_addressbook_labels_alter(&$labels, $profiles) {
  // No example.
}
