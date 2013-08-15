<?php
//title: $title
//url:
$urls = field_get_items('node', $node, 'field_youtube_url');
$url = $urls && count($urls) > 0 ? $urls[0]['url'] : '';
$ytid = youtube_parser($url);
function youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0)
		return $matches[0];
	return false;
}

if ($ytid) :
	//print("Video model.");
	$media_type = 'video';
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

  //console.log(duration_s);
  //console.log(duration_m);
  //console.log(drration_ms);

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

  <div id="<?php echo $media_type; ?>-video-icon" class="set-type-icon set-video-type-icon">
    <?php echo isset($node->term->name)?$node->term->name: ''; ?> video <br/>
    Duration: <span id="yotube-duration-time"></span>
  </div>

  <span id="set-title" style="display: none;"><?php print $title;?></span>
  <div class="content set-video-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
    ?>
    <div id="yt">
    You need Flash player 8+ and JavaScript enabled to view this video.
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

<?php
else : 
?>
<div id="Image-image-icon" class="set-type-icon set-image-type-icon">
  Image<br/>
</div>
<span id="set-title" style="display: none;"><?php print $title;?></span>
  <div class="content set-image-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      
      $media_image = array(
				'path' => $url,
      );

			print theme('image', $media_image);

      //print render($content['field_youtube_url']);
      //print render($content);

    ?>
    <span id="image-download-it">
    <?php

      $image_uri = file_create_url($node->field_youtube_url[$node->language][0]['url']);
      $download_uri = 'download/file/fid/' . $node->field_youtube_url[$node->language][0]['url'];
      
      $download_uri = $image_uri;

      $download_icon = array('path' => drupal_get_path('theme', 'newfteui'). '/images/iconDownload.png');

      $download_icon_img = theme('image' , $download_icon);
      echo l($download_icon_img, $download_uri, array(
        'attributes' => array(
        ),
        'html' => TRUE,
        )
      );
    ?>
    </span>
  </div>
<?php endif; ?>