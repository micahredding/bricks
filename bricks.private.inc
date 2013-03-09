<?php

/* @begin Internal Functions */
function _bricks_defaults($delta) {
  /* Invoke HOOK_block_default_content functions to return block defaults */    
  return module_invoke_all('block_default_content', $delta);
}

/* Bricks Variables */
function bricks_set($key, $value) {
  $prefix = 'bricks_';
  $key = $prefix . $key;
  variable_set($key, $value);
}

function bricks_get($key, $default = '') {
  $prefix = 'bricks_';
  $key = $prefix . $key;
  return variable_get($key, $default);
}

function bricks_unset($key) {
  $prefix = 'bricks_';
  $key = $prefix . $key;
  variable_del($key);
}

/* Nicety Functions */

/* Construct a name by imploding a series of keys, separated by underscores */
function _b(/* $key1, $key2, $key3 */) {
  $keys = func_get_args();
  return implode('_', $keys);
}