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
</style>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

<div id="set-type-text"><h3><?php echo isset($node->term->name)?$node->term->name: ''; ?></h3></div>
<div id="set-user-info">
  <dl>
  <dt>
  <?php print $user_picture; ?>
  </dt>

  <?php print render($title_prefix); ?>
  <dd>
    <h2<?php print $title_attributes; ?>>Teacher: <?php print $username; ?></h2>
    <div class="shadeDiv" style="">&nbsp;</div>
  </dd>
  <?php print render($title_suffix); ?>
  </dl>

  <?php if ($display_submitted): ?>
    <span class="submitted"><?php print $submitted ?></span>
  <?php endif; ?>
</div>
  <div class="content set-video-content clearfix"<?php print $content_attributes; ?>>
    <?php
      // We hide the comments and links now so that we can render them later.
      hide($content['comments']);
      hide($content['links']);
      print render($content['body']);
    ?>    
    <div id="yt">
    You need Flash player 8+ and JavaScript enabled to view this video.
    </div>
  </div>

  <div class="clearfix">
    <?php if (!empty($content['links'])): ?>
      <div class="links"><?php print render($content['links']); ?></div>
    <?php endif; ?>

    <?php print render($content['comments']); ?>
  </div>

</div>
<script>
(function($){
  $(document).ready(function(){
    loadVideo('<?php echo $ytid;?>');
	});
})(jQuery);
function loadVideo(videoid) {
	var params = { allowScriptAccess: "always" };
	var atts = { id: "myytplayer" };
	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid=playerapi&version=3",
		"yt", "840", "425", "8", null, null, params, atts);
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