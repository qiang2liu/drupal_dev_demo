<?php
//title: $title
$images = array();
if(isset($content['field_set_slideshow'])) {
  $oimages = $content['field_set_slideshow']['#items'];
  if(isset($oimages) && count($oimages)>0) {
    foreach($oimages as $image) {
      $images[] = theme('image_style', array('style_name' => 'large', 'path' => $image['uri']));
    }
  }
}
?>
<style>
#content div.tabs {
  display: none;
}
#images{
  width: 960px;
  margin: 0 auto;
}
#images_container img{
  width: 960px;
  max-height: none;
	display:block;
}
#images_container span.content-item{
	display:none;
}
#images_container span.content-item.actived{
	display:block;
}
.controller{
	height:54px;
	background:#3dbec0;
	padding:0 30px;
}
.controller .prev,
.controller .next{
	width:26px;
	height:17px;
	float:left;
	display: inline-block;
	text-indent:-9999em;
}
.controller .prev{
	margin:17px 0 0 0;
}
.controller .next{
	margin:17px 0 0 10px;
  float:right;
}
.controller-dots{
	width:195px;
	float:left;
	border-left:1px solid #62cacc;
	border-right:1px solid #62cacc;
	padding:23px 20px 0;
	height:31px;
}
.controller-dots span{
	width:16px;
	height:8px;
	display:inline-block;
	text-indent:-9999em;
	cursor:pointer;
	line-height:8px;
	float:left;
}
</style>
<script>
	
</script>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

<!--
<div id="set-type-text"><h3><?php echo isset($node->term->name)?$node->term->name: ''; ?></h3></div>
-->
<!--
<div id="set-user-info">
  <dl>
  <dt>
  <?php print $user_picture; ?>
  </dt>

  <?php print render($title_prefix); ?>
  <dd>
    <h2<?php print $title_attributes; ?>><?php print $title; ?></h2>
    <div class="shadeDiv" style="">&nbsp;</div>
  </dd>
  <?php print render($title_suffix); ?>
  </dl>

  <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
  <?php endif; ?>
</div>
-->

  <div id="Image-image-icon" class="set-type-icon set-image-type-icon">
    SlideShow<br/>
  </div>

  <span id="set-title"><?php print $title;?></span>
  <div class="content set-image-content clearfix"<?php print $content_attributes; ?>>
    <?php if(count($images) > 0): ?>
    <div id="images" class="media-box">
      <div id="images_container" class="content-container">
        <?php foreach($images as $i=>$image): ?>
          <span class="content-item<?php if($i == 0) echo ' actived';?>" id="image-item-<?php echo $i?>"><?php echo $image; ?></span>
        <?php endforeach; ?>
      </div>
      <div class="images-controller controller">
        <a href="#x" class="prev" <?php if(count($images) == 1) echo 'disabled="disabled"';?>>Prev</a>
        <div class="images-controller-dots controller-dots">

        </div>
        <a href="#x" class="next" <?php if(count($images) == 1) echo 'disabled="disabled"';?>>Next</a>
      </div>
    </div>
    <?php endif;?>
  </div>

  <div class="clearfix">
  </div>

</div>
<script>
(function($){
	$(document).ready(function(){
		$('.images-controller-dots').mediaSlide();
	});
})(jQuery);

</script>