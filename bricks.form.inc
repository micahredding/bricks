<?php

function bricks_array_to_form($block) {
  $form = array();

  foreach($block as $fieldname => $fieldcontent) {
    $type = bricks_field_type($fieldname, $fieldcontent);
    switch($type) {
      case 'textfield':
        $form[$fieldname] = array(
          '#type' => 'textfield', 
          '#title' => t($fieldname), 
          '#description' => t('This text will appear in the block.'), 
          '#default_value' => $fieldcontent,
        );          
        break;
      case 'textarea':
        $form[$fieldname] = array(
          '#type' => 'textarea', 
          '#title' => t($fieldname), 
          '#description' => t('This text will appear in the block.'), 
          '#default_value' => $fieldcontent,
        );    
        break;
      case 'image':
        $form[$fieldname] = array(
          '#type' => 'managed_file',
          '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
          '#upload_location' => 'public://' . $delta . '/' . 'images/',
          '#default_value' => $fieldcontent,
        );                  
        break;
    }
  }
  $form['export'] = array(
    '#type' => 'submit',
    '#value' => 'Export current block content',
    '#weight' => '999',
    '#submit' => array('bricks_block_export_submit'),
  );
  $form['reset'] = array(
    '#type' => 'submit',
    '#value' => 'Reset all block content. (Careful!)',
    '#weight' => '1000',
    '#submit' => array('bricks_block_reset_submit'),
  );
  return $form;
}


function bricks_block_export_submit($form, &$form_state) {
  // drupal_set_message('hi');
  // $delta = $form['delta']['#value'];
  // drupal_goto('admin/bricks/export/' . $delta);
  // $form_state['redirect'] = 'admin/bricks/export/' . $delta;
  // $output = bricks_block_load($delta);
  $form_state['markup'] = 'hi';
  $form_state['rebuild'] = TRUE;
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


function bricks_form_block_admin_configure_alter($form, &$form_state, $form_id) {
}






