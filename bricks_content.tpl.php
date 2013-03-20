<?php
/* You're provided with an array called "content", consisting of field names and field content */
?>
<div class="block-content">
  <?php foreach($content as $fieldname => $fieldcontent): ?>
    <div class="block-<?php print $fieldname; ?>">
      <?php print $fieldcontent; ?>
    </div>
  <?php endforeach; ?>
</div>