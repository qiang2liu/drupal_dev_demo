<?php
$topicColor = '#3dbec0';
if(isset($content['field_topic_color'])) {
  $topicColors = $content['field_topic_color']['#items'];
  if(isset($topicColors) && count($topicColors)>0) {
    $topicColor = $topicColors[0]['rgb'];
  }
}
function youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0)
		return $matches[0];
	return false;
}
$videoIds = array();
if(isset($content['field_topic_videos'])) {
  $videos = $content['field_topic_videos']['#items'];
  if(isset($videos) && count($videos)>0) {
    foreach($videos as $video) {
      $videoIds[] = youtube_parser($video['url']);
    }
  }
}
$images = array();
if(isset($content['field_topic_images'])) {
  $oimages = $content['field_topic_images']['#items'];
  if(isset($oimages) && count($oimages)>0) {
    foreach($oimages as $image) {
      $images[] = theme('image_style', array('style_name' => 'edgemakers_topic_image', 'path' => $image['uri']));
    }
  }
}
?>
<style>
.topic_medias:after,
.topic_infos .field:after{
	clear:both;
	display:block;
	content:'';
	height:0;
	visibility:hidden;
}
html{
  background:#dde1e0;
}
body{
	width:1170px;
	margin:30px auto 0;
}
#wrapper{
	width:100%;
}
.breadcrumb{
	display:none;
}
h1{
	font-size:48px;
	font-style:italic;
	text-align:center;
	height:95px;
	line-height:95px;
	color:#fff;
}
.node-edgemakers-topic{
	margin:50px auto 0;
}
.topic_medias{
	width:360px;
	float:left;
}
.topic_infos{
	width:770px;
	float: right;
}
#images{
	margin-bottom:30px;
}
#images_container img{
	width:360px;
	height:300px;
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
#content div.tabs {
  display: none;
}
.topic_infos .field{
	margin-bottom:50px;
}
.topic_infos .field-label{
	float:left;
	color:#fff;
	font-size:22px;
	font-style:italic;
	text-align:center;
	font-weight:normal;
}
.field-name-field-topic-problem .field-label{
	width:181px;
	height:85px;
	padding:20px 0 0 10px;
}
.field-name-field-topic-problem .field-item{
	background:#fff;
	padding:10px 22px 10px 10px;
	position: relative;
	float:left;
	width:540px;

}
.field-name-field-topic-problem .field-item p{
	word-wrap: break-word;

}
.field-name-field-topic-suggestion .field-label{
	padding:20px 0 0 17px;
	height:88px;
	width:222px;
}
.field-name-field-topic-suggestion .field-item{
	width:300px;

	padding:20px;
	float:left;
	background:#fff;
}

.field-name-field-topic-org-resources .field-label{
	width:147px;
	height:73px;
	padding:5px 5px 0;
	line-height: 1.2;
}
.field-name-field-topic-org-resources .field-item{
	padding:10px 30px;
	width:352px;

	float:left;
	background:#fff;
}

#videos_container {
  padding:10px;
}
.videos-controller{
	margin-top:-5px;
}
.controller-dots span.actived,
.controller a[disabled="disabled"] {
	pointer-events: none;
	cursor:default;
}
</style>
<script>
(function($){
	$(document).ready(function(){
		$('.images-controller-dots').mediaSlide();
		//$('.videos-controller-dots').mediaSlide();

		//some UI
		$('.field-name-field-topic-problem .field-item p').append('<div class="right-quote"></div>');
	});
})(jQuery);

</script>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content clearfix"<?php print $content_attributes; ?>>
      <div class="topic_medias">
      <?php if(count($images) > 0): ?>
      <div id="images" class="media-box">
        <div id="images_container" class="content-container">
          <?php foreach($images as $i=>$image): ?>
            <span class="content-item<?php if($i == 0) echo ' actived';?>" id="image-item-<?php echo $i?>"><?php echo $image; ?></span>
          <?php endforeach; ?>
        </div>
        <div class="images-controller controller" style="background:<?php echo $topicColor;?>;">
          <a href="#x" class="prev" <?php if(count($images) == 1) echo 'disabled="disabled"';?>>Prev</a>
          <div class="images-controller-dots controller-dots">

          </div>
          <a href="#x" class="next" <?php if(count($images) == 1) echo 'disabled="disabled"';?>>Next</a>
        </div>
      </div>
      <?php endif;?>
      <?php if(count($videoIds) > 0): ?>
      <div id="videos" class="media-box">
        <div id="videos_container" class="content-container">
        You need Flash player 8+ and JavaScript enabled to view this video.
        <p ><?php echo l(t('Get Flash Player'), 'http://get.adobe.com/flashplayer/', array('attributes' => array('target' => '_blank')));?></p>
        </div>
        <div class="videos-controller controller" style="background:<?php echo $topicColor;?>;">
           <a href="#x" class="prev" <?php if(count($videoIds) == 1) echo 'disabled="disabled"';?>>Prev</a>
           <div class="videos-controller-dots controller-dots">
				<?php foreach($videoIds as $i=>$videoId): ?>
		            <span class="content-item" id="video-item-<?php echo $i?>"><?php echo $videoId; ?></span>
		        <?php endforeach; ?>
        	</div>
        	 <a href="#x" class="next" <?php if(count($videoIds) == 1) echo 'disabled="disabled"';?>>Next</a>
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
jQuery('.node-type-edgemakers-topic h1').css('background-color', "<?php echo $topicColor;?>");
<?php if(count($videoIds) > 0):?>
  loadVideo('<?php echo $videoIds[0];?>');
  <?php if(count($videoIds) > 1):?>
  jQuery('.videos-controller-dots span').bind('click', function(){
  	var idx = jQuery(this).index();
  	var id = jQuery('.videos-controller-dots span').eq(idx).attr('id');
  	jQuery('.videos-controller-dots span.actived').removeClass('actived');
  	jQuery('.videos-controller-dots span').eq(idx).addClass('actived');
  	changeVideo(id);
  })
  jQuery(".videos-controller .prev").bind('click', function() {

    var prevel = jQuery('.videos-controller-dots span.actived').prev();
    if(prevel.length == 0){
    	 prevel = jQuery('.videos-controller-dots span:last');
    }

    jQuery('.videos-controller-dots span.actived').removeClass('actived');
    prevel.addClass('actived');

    changeVideo(prevel[0].id);
  });
  jQuery(".videos-controller .next").bind('click', function() {

    var nextel = jQuery('.videos-controller-dots span.actived').next();

    if(nextel.length == 0){
    	nextel = jQuery('.videos-controller-dots span:first');
    }


      jQuery('.videos-controller-dots span.actived').removeClass('actived');
      nextel.addClass('actived');
    changeVideo(nextel[0].id);
  });
  jQuery('.video-item').bind('click', function() {
    if(!jQuery(this).hasClass('actived')) changeVideo(this.id);
  });
  <?php endif;?>

<?php endif;?>
function loadVideo(videoid) {
	var params = { allowScriptAccess: "always", wmode : 'opaque' };
	var atts = { id: "myytplayer" };

  //Get width from video destination element continar
  var videoWidth = 360;
  var whratio = 64/39*1.0;
  var vHeight = videoWidth/whratio;

	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?rel=0&enablejsapi=1&playerapiid=playerapi&version=3",
		"videos_container", "100%", vHeight, "8", null, null, params, atts);
  jQuery('#video-item-0').addClass('actived');
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
    jQuery('.video-item').removeClass('actived');
    jQuery('#'+elid).addClass('actived');
  }
}
</script>
