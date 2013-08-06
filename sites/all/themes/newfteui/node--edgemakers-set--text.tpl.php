<?php
//title: $title
//body: render($content['body'])
?>
<style>
#content div.tabs {
  display: none;
}
</style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>


  <div id="<?php echo isset($node->term->name)?$node->term->name: ''; ?>-image-icon" class="set-type-icon set-image-type-icon">
    Text<br/>
  </div>

  <span id="set-title" style="display: none;"><?php print $title;?></span>
  <div class="content set-text-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content['body']);
    ?>
  </div>

  <div class="clearfix">
  </div>

</div>