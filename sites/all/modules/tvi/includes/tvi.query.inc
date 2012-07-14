<?php
// $Id: tvi.query.inc,v 1.1 2009/12/04 01:40:56 awebb Exp $

//******************************************************************************
// TVI Database Interface
//******************************************************************************

/**
 * Return a default setting object.
 */
function tvi_default_settings($type = TVI_TYPE_TERM, $xid = 0) {
  $settings = new stdClass();

  $settings->type = $type;
  $settings->xid  = $xid;

  $settings->view_name = 0;
  $settings->display = TVI_DEFAULT_DISPLAY;
  $settings->status  = 0;

  $settings->is_default = TRUE;

  return $settings;
}

//------------------------------------------------------------------------------

/**
 * Load a setting from the database or return a default, if the $return_default
 * flag is set.
 */
function tvi_load_settings($xid, $type = TVI_TYPE_TERM, $return_default = TRUE) {

  if ($type == TVI_TYPE_VOCAB) {
    $vocabulary = taxonomy_vocabulary_load($xid);
    $xid = $vocabulary->machine_name;
  }
  elseif ($type == TVI_TYPE_TERM && module_exists('uuid')) {
    $xid = reset(entity_get_uuid_by_id('taxonomy_term', array($xid)));
  }

  $settings = variable_get('tvi_' . $type . '_' . $xid);

  if (!is_object($settings)) {
    return ($return_default ? tvi_default_settings($type, $xid) : NULL);
  }

  $settings->is_default = FALSE;
  return $settings;
}

//------------------------------------------------------------------------------

/**
 * Save settings information for a taxonomy vocabulary or term to the database.
 */
function tvi_update_settings($settings) {
  if (is_array($settings)) {
    $settings = (object)$settings;
  }

  variable_set('tvi_' . $settings->type . '_' . $settings->xid, $settings);
}

//------------------------------------------------------------------------------

/**
 * Delete settings information for a taxonomy vocabulary or term in 
 * the database.
 */
function tvi_remove_settings($xid, $type = TVI_TYPE_TERM) {

  if ($type == TVI_TYPE_VOCAB) {
    $vocabulary = taxonomy_vocabulary_load($xid);
    $xid = $vocabulary->machine_name;
  }
  elseif ($type == TVI_TYPE_TERM && module_exists('uuid')) {
    $xid = reset(entity_get_uuid_by_id('taxonomy_term', array($xid)));
  }

  variable_del('tvi_' . $type . '_' . $xid);
}

//------------------------------------------------------------------------------
