<?php
$topicColor = '#3dbec0';
$topicColors = $content['field_topic_color']['#items'];
if(isset($topicColors) && count($topicColors)>0) {
  $topicColor = $topicColors[0]['rgb'];
}
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
/* topic-murals */
#topic-murals .project-title{
	width:196px;
	padding-right:14px;
	float:left;
}
#topic-murals .project-title h3{
	width:155px;
	line-height:48px;
	text-align:center;
	color:#fff;
	font-size:24px;
	background:#d53f38;
}
#topic-murals .project-title p{
	background:#fff;
	padding:10px;
	font-size:20px;
	font-style:italic;
	color:#3f4b56;
}
#topic-murals .project-con{
	width:960px;
	float:left;
	margin-bottom:50px;
}
#topic-mural-list li{
	width:162px;
	float:left;
	margin-right:12px;
	height:220px;
	padding:10px;
	text-align:center;
	position:relative;
	background:#fff;
}
#topic-mural-list li.last{
	margin-right:0;
}
#topic-mural-list li h3{
	font-size:22px;
	font-style:italic;
	padding-bottom:10px;
	margin-bottom:20px;
	text-overflow:ellipsis; overflow:hidden; white-space:nowrap;
}
#topic-mural-list li  .mural-title{
	font-size:16px;
}
#topic-mural-list li span.user-avatar{
	display: block;
	width:104px;
	height:104px;
	border-radius:52px;
	border:1px solid #e2e5e3;
	overflow:hidden;
	position:absolute;
	bottom:-53px;
	left:38px;
}
</style>
<script>
(function($){
	$.fn.extend({
		mediaSlide: function(options){
			var defaults = {
				contentContainer : '.content-container',
				contentItem      : '.content-item',
				parent           : '.media-box',
				siblingsNext     : '.next',
				siblingsPre      : '.prev'
			}
			var options=$.extend(defaults, options);
			return this.each(function(){
				var self = $(this);
				var item = self.parents(options.parent).find(options.contentContainer).find(options.contentItem);
				var len = self.parents(options.parent).find(options.contentContainer).find(options.contentItem).length;
				for(var i=0; i<len; i++){
					self.append('<span class="media-indicator"></span>');
				}
				self.find('.media-indicator').eq(0).addClass('actived');

				//next button
				self.siblings(options.siblingsNext).bind('click', function(){
					var idx = self.find('.media-indicator.actived').index();
					if(idx<self.find('.media-indicator').length-1){
						self.find('.media-indicator.actived').removeClass('actived');
						self.find('.media-indicator').eq(idx+1).addClass('actived');
						item.eq(idx).hide();
						item.eq(idx+1).fadeIn(300);
					}

				});

				//pre button
				self.siblings(options.siblingsPre).bind('click', function(){
					var idx = self.find('.media-indicator.actived').index();
					if(idx>0){
						self.find('.media-indicator.actived').removeClass('actived');
						self.find('.media-indicator').eq(idx-1).addClass('actived');
						item.eq(idx).hide();
						item.eq(idx-1).fadeIn(300);
					}
				});

				//indicator click
				self.find('.media-indicator').bind('click', function(){
					var idx = self.find('.media-indicator.actived').index();
					var crt = $(this).index();
					self.find('.media-indicator.actived').removeClass('actived');
					$(this).addClass('actived');
					item.eq(idx).hide();
					item.eq(crt).fadeIn(300);
				})

			});
		}
	});
	$(document).ready(function(){
		$('.images-controller-dots').mediaSlide();
		$('.videos-controller-dots').mediaSlide();

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
          <a href="#x" class="next" <?php if(count($imageUrls) == 1) echo 'disabled="disabled"';?>>Next</a>
        </div>
      </div>
      <?php endif;?>
      <?php if(count($videoIds) > 0): ?>
      <div id="videos" class="media-box">
        <div id="videos_container">
        You need Flash player 8+ and JavaScript enabled to view this video.
        <p><?php echo l(t('Get Flash Player'), 'http://get.adobe.com/flashplayer/', array('attributes' => array('target' => '_blank')));?></p>
        <?php foreach($videoIds as $i=>$videoId): ?>
            <span class="content-item" id="video-item-<?php echo $i?>"><?php echo $videoId; ?></span>
          <?php endforeach; ?>
        </div>
        <div class="videos-controller controller" style="background:<?php echo $topicColor;?>;">
          <a href="#x" class="prev" <?php if(count($videoIds) == 1) echo 'disabled="disabled"';?>>Prev</a>
          <div class="videos-controller-dots controller-dots">

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
