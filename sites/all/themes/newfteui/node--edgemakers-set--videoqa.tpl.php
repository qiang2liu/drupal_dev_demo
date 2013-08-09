<?php
//title: $title
//url:
$urls = field_get_items('node', $node, 'field_set_url');
$url = $urls && count($urls) > 0 ? $urls[0]['url'] : '';
$ytid = youtube_parser($url);
function youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0)
		return $matches[0];
	return false;
}
$user = user_load($uid);
$username = $user->name;
?>
<style>
#content div.tabs {
  display: none;
}
.field-name-body {
  float: left;
  width: 25%;
  padding:10px 0.5%;
  min-height:332px;
  color:#fff;
  background-color: rgba(215,152,94, 0.7);
  text-align:left;
  margin-right:1%;
}
#yr-wrapper {
  float: left;
}
#comments {
  background: white;
  width: 95%;
  margin:auto;
}
#comments .rate-widget {
  display: none;
}
</style>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <div id="videoqa-icon" class="set-type-icon set-videoqa-type-icon">
    <?php echo isset($node->term->name)?$node->term->name: ''; ?><br/>
  </div>

  <span id="set-title" style="display: none;">Teacher: <?php print $username; ?></span>
  <div id="v-c" class="content set-video-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content['body']);
    ?>    
    <div id="yr-wrapper"><div id="yt">
    You need Flash player 8+ and JavaScript enabled to view this video.
    </div></div>
  </div>

  <div class="clearfix">
    <?php print render($content['comments']); ?>
  </div>

</div>
<script>
(function($){
  $(document).ready(function(){
    setTimeout(function() {loadVideo('<?php echo $ytid;?>');}, 100);
	});
})(jQuery);
function loadVideo(videoid) {
	
	var params = { allowScriptAccess: "always" };
	var atts = { id: "myytplayer" };
  	var videoWidth = ((document.body.clientWidth * 0.70)*0.95)* 0.72;
 	 var whratio = 64/39*1.0;
 	 var vHeight = videoWidth/whratio;
	 swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid=playerapi&version=3",
		"yt", videoWidth, vHeight, "8", null, null, params, atts);

  //Get width from video destination element continar
  function getSzie(){
  	
  }
  getSize();
  window.onresize=function(){
  	getSize();
  }
}
function onYouTubePlayerReady(playerId) {
  var ytplayer = document.getElementById('myytplayer');
  ytplayer.addEventListener("onStateChange", "myOnPlayerStateChange");
  ytplayer.addEventListener("onError", "myOnPlayerError");
}
function myOnPlayerStateChange(newState) {
}
function myOnPlayerError(errorCode) {
  document.getElementById('yt').innerHTML = " Error occurred: " + errorCode;
}
</script>