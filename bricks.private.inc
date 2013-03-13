<?php
/* @begin Public Helper Functions */
function bricks_array_to_html($block_array) {
  $block = '<div class="block-content>';
  foreach($block_array as $fieldname => $fieldcontent) {
    $block .= '<div class="block-' . $fieldname . '">' . check_markup($fieldcontent) . '</div>';
  }
  $block .= '</div>';
  return $block;
}

function bricks_array_to_form($block) {
  $form = array();
  foreach($block as $fieldname => $fieldcontent) {
    $form[$fieldname] = array(
      '#type' => 'textfield', 
      '#title' => t($fieldname), 
      '#description' => t('This text will appear in the block.'), 
      '#default_value' => $fieldcontent,
    );    
  }
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => 'Reset all block content. (Careful!)',
    '#weight' => '1000',
    '#submit' => array('bricks_block_reset_submit'),
  );
  return $form;
}

function bricks_block_reset_submit($form, &$form_state) {
  $delta = $form['delta']['#value'];
  bricks_block_reset($delta);  
}

function bricks_block_reset($delta) {
  $fields = array_keys(_bricks_defaults($delta));
  foreach($fields as $index => $fieldname) {
    bricks_unset(_b($delta, $fieldname));
  }
}

/* @end Public Helper Functions */

/* @begin Internal Functions */

/* Implement our own hook. Invoke HOOK_block_default_content functions to return block defaults */   
function _bricks_defaults($delta) {
  return module_invoke_all('block_default_content', $delta);
}

/* Bricks Variables */
function bricks_set($key, $value) {
  bricks_master_set($key);
  variable_set(_p($key), $value);
}

function bricks_get($key, $default = '') {
  return variable_get(_p($key), $default);
}

function bricks_unset($key) {
  bricks_master_unset($key);
  variable_del(_p($key));
}

/* keep a master list of the variables for later deletion */
function bricks_master_set($key) {
  $bricks = variable_get('bricks_master_list', array());
  $bricks[$key] = true;
  variable_set('bricks_master_list', $bricks);
}

function bricks_master_unset($key) {
  $bricks = variable_get('bricks_master_list', array());
  unset($bricks[$key]);
  variable_set('bricks_master_list', $bricks);  
}

function bricks_master_unset_all() {
  $bricks = variable_get('bricks_master_list', array());
  foreach($bricks as $key => $true) {
    variable_del(_p($key));
  }
  variable_set('bricks_master_list', array());  
}

/* Nicety Functions */

/* Construct a name by imploding a series of keys, separated by underscores */
function _b(/* $key1, $key2, $key3 */) {
  $keys = func_get_args();
  return implode('_', $keys);
}

/* Prefix a variable name */
function _p($key) {
  return $key;
  // return 'bricks_' . $key;
}