<?php
//title: $title
//body: render($content['body'])
?>
<style>
#content div.tabs {
  display: none;
}
.set-text-content {
  width: 720px;
  height:455px;
  margin:0 20px ;
  padding: 0;
  border:none;
  background: transparent;
}
.set-text-content iframe{
	width:100%;
	height:430px;
}

</style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <div id="<?php echo isset($node->term->name)?$node->term->name: ''; ?>-video-icon" class="set-type-icon set-video-type-icon">
    <?php echo isset($node->term->name)?$node->term->name: ''; ?><br/>
  </div>

  <span id="set-title" style="display: none;"><?php print $title; ?></span>
  <div class="content set-text-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content['field_set_document']);
    ?>
  </div>

  <div class="clearfix">
  </div>

</div>
<script>
(function($){
  $(document).ready(function(){
    $('.field-name-field-set-document .field-label').css('display', 'none');
	});
})(jQuery);
</script>
