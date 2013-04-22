<?php

function bricks_array_to_form($block) {
  $form = array();
  foreach($block as $fieldname => $fieldcontent) {
    if(strlen($fieldcontent) > 50) {
      $form[$fieldname] = array(
        '#type' => 'textarea', 
        '#title' => t($fieldname), 
        '#description' => t('This text will appear in the block.'), 
        '#default_value' => $fieldcontent,
      );    
    } else {
      $form[$fieldname] = array(
        '#type' => 'textfield', 
        '#title' => t($fieldname), 
        '#description' => t('This text will appear in the block.'), 
        '#default_value' => $fieldcontent,
      );          
    }
  }
  $form['export'] = array(
    '#type' => 'button',
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
  $delta = $form['delta']['#value'];
  $form_state['redirect'] = array('admin/bricks/export/' . $delta);
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






