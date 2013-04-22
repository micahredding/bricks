<?php

/* @begin Theme bricks block content using custom TPL, bricks_content.tpl.php */
function bricks_array_to_html($block_array) {
  return theme('bricks_content', array('content' => $block_array));
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