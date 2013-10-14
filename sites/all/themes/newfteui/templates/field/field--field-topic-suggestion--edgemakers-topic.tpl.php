<?php
global $user;
global $base_url;

if ($node = menu_get_object()) {
//   print("Get nid from url" . $node->nid);
  if ($user->uid) {
    $mural_link = $base_url . '/mural/topic/create/' . $node->nid;
    $link_class = array('create-mural', 'create-mural-topic');
    $create_mural_url = l(t('Create Mural'), $mural_link , array(
    		'attributes' => array(
    			'class' => $link_class,
    		  'onClick' => 'showMuralDialog("' . $mural_link . '");return false;',
    		)
      )
    );
  }
  else {
    $mural_link = 'modal_forms/nojs/login';
  	$link_class = array('ctools-use-modal',  'ctools-modal-modal-popup-profilesetting');
  	$create_mural_url = l(t(''), $mural_link , array(
    		'attributes' => array(
    			'class' => $link_class,
    		),
        'html' => TRUE,
      )
    );
  }
}

?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php if (!$label_hidden): ?>
    <div class="field-label"<?php print $title_attributes; ?>><?php print $label ?>?&nbsp;</div>
  <?php endif; ?>
  <div class="field-items"<?php print $content_attributes; ?>>
    <?php foreach ($items as $delta => $item): ?>
      <div class="field-item <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>><?php print render($item); ?></div>
      <div class="su-right <?php print $delta % 2 ? 'odd' : 'even'; ?>"<?php print $item_attributes[$delta]; ?>>
      <?php echo $create_mural_url;?>
      </div>
    <?php endforeach; ?>
  </div>
</div>