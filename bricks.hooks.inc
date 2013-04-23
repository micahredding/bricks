<?php

/* @begin Theme bricks block content using custom TPL, bricks_content.tpl.php */
function bricks_array_to_html($block_array) {
  // preprocessing for specific field types
  foreach($block_array as $fieldname => $fieldcontent) {
    $type = bricks_field_type($fieldname, $fieldcontent);
    if($type == 'image') {
      $image_id = $fieldcontent;
      $image = file_load($image_id);
      $image_url = file_create_url($image->uri);  
      $block_array[$fieldname] = $image_url;
      // or
      $block_array[$fieldname] = '<img src="' . $image_url . '" />';
    }
  }
  return theme('bricks_content', array('content' => $block_array));
}

function bricks_field_type($fieldname, $fieldcontent) {
  $type = 'textfield';
  if(is_string($fieldcontent) && strlen($fieldcontent) > 50) {
    $type = 'textarea';
  }
  if (strpos($fieldname, 'image') !== FALSE) {
    $type = 'image';
  }
  return $type;
}

function bricks_theme($existing, $type, $theme, $path) {
  return array(
    'bricks_content' => array(
      'template' => 'bricks_content',
      'variables' => array(),
    ),
  );
}
/* @end */

/* @begin implement own own module hook. Invoke all HOOK_block_default_content functions to return block defaults for this delta. */   
function _bricks_defaults($delta) {
  return module_invoke_all('block_default_content', $delta);
}
/* @end */