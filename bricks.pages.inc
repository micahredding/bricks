<?php

function bricks_menu() {
  $items['admin/bricks/export'] = array(
    'page callback' => 'bricks_export_page',
    'type' => MENU_CALLBACK,
    'page arguments' => array(3),
    'access arguments' => array('administer blocks'),
  );
  return $items;
}

function bricks_export_page($delta = FALSE) {
  $output = array();
  
  if($delta) {
    $output = bricks_block_load($delta);
  } else {
    // do nothing at the moment
    // todo, load all blocks
  }

  dvm($output);
  return 'Copy and paste this into the HOOK_block_default_content section of your module.';

}