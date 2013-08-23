<?php
function youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0) 
		return $matches[0];
	return false;
}
$videoIds = array();
$videos = $content['field_topic_videos']['#items'];
if(isset($videos) && count($videos)>0) {
  foreach($videos as $video) {
    $videoIds[] = youtube_parser($video['url']);
  }
}
$images = array();
$oimages = $content['field_topic_images']['#items'];
if(isset($oimages) && count($oimages)>0) {
  foreach($oimages as $image) {
    $images[] = theme('image_style', array('style_name' => 'edgemakers_topic_image', 'path' => $image['uri']));
  }
}
?>
<style>
#content div.tabs {
  display: none;
}
.controller {
  width: 200px;
}
.controller a{
  cursor:pointer;
}
.controller a.prev{
  float:left;
  width:10px;
}
.controller a.next{
  float:right;
  width:10px;
}
.controller-dots{
  margin:0 auto;
  width: 160px;
}
.controller-dots span{
  text-indent:-9999px;
  display: block;
  float: left;
  width: 10px;
  height: 20px;
  margin: 1px;
  background: #ccc;
  cursor:pointer;
}
.controller-dots span.active{
  cursor:auto;
}
.controller-dots img{
  display: none;
}
</style>
<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content clearfix"<?php print $content_attributes; ?>>
      <div class="topic_medias">
      <?php if(count($images) > 0): ?>
      <div id="images">
        <div id="images_container">
          <?php print_r($images[0]); ?>
        </div>
        <div class="images-controller controller">
          <a href="#" class="prev" <?php if(count($images) == 1) echo 'disabled="disabled"';?>>Prev</a>
          <div class="images-controller-dots controller-dots">
          <?php foreach($images as $i=>$image): ?>
            <span class="image-item<?php if($i == 0) echo ' active';?>" id="image-item-<?php echo $i?>"><?php echo $image; ?></span>
          <?php endforeach; ?>
          </div>
          <a href="#" class="next" <?php if(count($imageUrls) == 1) echo 'disabled="disabled"';?>>Next</a>
        </div>
      </div>
      <?php endif;?>
      <?php if(count($videoIds) > 0): ?>
      <div id="videos">
        <div id="videos_container">
        You need Flash player 8+ and JavaScript enabled to view this video.
        </div>
        <div class="videos-controller controller">
          <a href="#" class="prev" <?php if(count($videoIds) == 1) echo 'disabled="disabled"';?>>Prev</a>
          <div class="videos-controller-dots controller-dots">
          <?php foreach($videoIds as $i=>$videoId): ?>
            <span class="video-item" id="video-item-<?php echo $i?>"><?php echo $videoId; ?></span>
          <?php endforeach; ?>
          </div>
          <a href="#" class="next" <?php if(count($videoIds) == 1) echo 'disabled="disabled"';?>>Next</a>
        </div>
      </div>
      <?php endif;?>
      </div>
      <div class="topic_infos">
      <?php
        print render($content['field_topic_problem']);
        print render($content['field_topic_suggestion']);
        print render($content['field_topic_org_resources']);
      ?>
      </div>
  </div>
</div>
<script>
<?php if(count($videoIds) > 0):?>
  loadVideo('<?php echo $videoIds[0];?>');
  <?php if(count($videoIds) > 1):?>
  jQuery(".videos-controller .prev").bind('click', function() {
    var prevel = jQuery('.video-item.active').prev();
    if(prevel.length == 0)
      var prevel = jQuery('.video-item:last');
    changeVideo(prevel[0].id);
  });
  jQuery(".videos-controller .next").bind('click', function() {
    var nextel = jQuery('.video-item.active').next();
    if(nextel.length == 0)
      nextel = jQuery('#video-item-0');
    changeVideo(nextel[0].id);
  });
  jQuery('.video-item').bind('click', function() {
    if(!jQuery(this).hasClass('active')) changeVideo(this.id);
  });
  <?php endif;?>  
  <?php if(count($images) > 1):?>
  jQuery(".images-controller .prev").bind('click', function() {
    var prevel = jQuery('.image-item.active').prev();
    if(prevel.length == 0)
      var prevel = jQuery('.image-item:last');
    changeImage(prevel[0].id);
  });
  jQuery(".images-controller .next").bind('click', function() {
    var nextel = jQuery('.image-item.active').next();
    if(nextel.length == 0)
      nextel = jQuery('#image-item-0');
    changeImage(nextel[0].id);
  });
  jQuery('.image-item').bind('click', function() {
    if(!jQuery(this).hasClass('active')) changeImage(this.id);
  });
  <?php endif;?>
<?php endif;?>
function loadVideo(videoid) {
	var params = { allowScriptAccess: "always", wmode : 'opaque' };
	var atts = { id: "myytplayer" };

  //Get width from video destination element continar
  var videoWidth = 200;
  var whratio = 64/39*1.0;
  var vHeight = videoWidth/whratio;

	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid=playerapi&version=3",
		"videos_container", "100%", vHeight, "8", null, null, params, atts);
  jQuery('#video-item-0').addClass('active');
}
function onYouTubePlayerReady(playerId) {
  ytplayer = document.getElementById('myytplayer');
  ytplayer.addEventListener("onStateChange", "myOnPlayerStateChange");
  ytplayer.addEventListener("onError", "myOnPlayerError");
}
function myOnPlayerStateChange(newState) {
}
function myOnPlayerError(errorCode) {
  document.getElementById('videos_container').innerHTML = " Error occurred: " + errorCode;
}
function changeVideo(elid) {
  if(typeof ytplayer != 'undefined') {
    var videoid = document.getElementById(elid).innerHTML;
    ytplayer.loadVideoById(videoid);
    jQuery('.video-item').removeClass('active');
    jQuery('#'+elid).addClass('active');
  }
}
function changeImage(elid) {
  var image = document.getElementById(elid).innerHTML;
  document.getElementById('images_container').innerHTML = image;
  jQuery('.image-item').removeClass('active');
  jQuery('#'+elid).addClass('active');
}
</script>
