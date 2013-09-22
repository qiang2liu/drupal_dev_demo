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


?>

<script>
function youtubeFeedCallback(json) {
  //console.log(json);
  //document.getElementById("#yotube-duration-time").innerHtml = json["data"]["duration"];
  var duration_s = json["data"]["duration"];
  var duration_m = 0;
  var drration_ms = duration_s;

  if (duration_s > 60) {
    duration_m = Math.floor(duration_s / 60);
    drration_ms = duration_s - ( duration_m * 60 );
    duration = duration_m + " mins " + drration_ms + " second(s)";
  }
  else {
    duration = drration_ms + " second(s)";
  }

  console.log(duration_s);
  console.log(duration_m);
  console.log(drration_ms);

  jQuery("#yotube-duration-time").empty();
  jQuery("#yotube-duration-time").html("Unknow");
  jQuery("#yotube-duration-time").html(duration);
}
</script>

<script type="text/javascript" src="http://gdata.youtube.com/feeds/api/videos/<?php echo $ytid;?>?v=2&alt=jsonc&callback=youtubeFeedCallback&prettyprint=true"></script>

<style>
#content div.tabs {
  display: none;
}
</style>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<!--
<div id="set-type-text"><h3><?php echo isset($node->term->name)?$node->term->name: ''; ?></h3></div>
<div id="ytduration"></div>
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

  <div id="<?php echo isset($node->term->name)?$node->term->name: ''; ?>-video-icon" class="set-type-icon set-video-type-icon">
    <?php echo isset($node->term->name)?$node->term->name: ''; ?> video <br/>
    Duration: <span id="yotube-duration-time"></span>
  </div>

  <span id="set-title"><?php print $title;?></span>
  <div class="content set-video-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
    <div id="yt">
    You need Flash player 8+ and JavaScript enabled to view this video.
    <p><?php echo l(t('Get Flash Player'), 'http://get.adobe.com/flashplayer/', array('attributes' => array('target' => '_blank')));?></p>
    </div>
  </div>

  <div class="clearfix">
  </div>

</div>
<script>
(function($){
  $(document).ready(function(){
    setTimeout(function() {loadVideo('<?php echo $ytid;?>');}, 100);
	});
})(jQuery);
function loadVideo(videoid) {
	var params = { allowScriptAccess: "always", wmode : 'opaque' };
	var atts = { id: "myytplayer" };

  //Get width from video destination element continar
  var videoWidth = jQuery(".set-video-content").width();
  var whratio = 64/39*1.0;
  var vHeight = videoWidth/whratio;

  jQuery("#download-flash").attr("style", "width: " + videoWidth + "px; height: " + vHeight + "px;");

	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid=playerapi&version=3",
		"yt", "100%", vHeight, "8", null, null, params, atts);


}
function onYouTubePlayerReady(playerId) {
  var ytplayer = document.getElementById('myytplayer');
  ytplayer.addEventListener("onStateChange", "myOnPlayerStateChange");
  ytplayer.addEventListener("onError", "myOnPlayerError");
}
function myOnPlayerStateChange(newState) {
  var elDuration = document.getElementById('ytduration');
  if(elDuration) {
    var ytplayer = document.getElementById('myytplayer');
    document.getElementById('ytduration').innerHTML = "Duration: " + formatSecondsAsTime(ytplayer.getDuration());
  }
}
function myOnPlayerError(errorCode) {
  document.getElementById('yt').innerHTML = " Error occurred: " + errorCode;
}
function formatSecondsAsTime(secs) {
  var hr = Math.floor(secs / 3600);
  var min = Math.floor((secs - (hr * 3600)) / 60);
  var sec = Math.floor(secs - (hr * 3600) - (min * 60));
  if (hr < 10) {
    hr = "0" + hr;
  }
  if (min < 10) {
    min = "0" + min;
  }
  if (sec < 10) {
    sec = "0" + sec;
  }
  return hr + ':' + min + ':' + sec;
}
</script>