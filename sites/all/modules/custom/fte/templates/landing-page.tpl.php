<?php
global $base_url;
function youtube_parser($url) {
	preg_match("#(?<=v=)[a-zA-Z0-9-]+(?=&)|(?<=v\/)[^&\n]+|(?<=v=)[^&\n]+|(?<=youtu.be/)[^&\n]+#", $url, $matches);
	if(is_array($matches) && count($matches) > 0) 
		return $matches[0];
	return false;
}
function _get_videos_list() {
  $renderable_array = array();
  $sql = 'SELECT nid FROM {node} n WHERE n.type = :type AND n.status = :status';
  $result = db_query($sql, array(
    ':type' => 'fte_video',
    ':status' => 1,
  ));
  foreach ($result as $row) {
    $node = node_load($row->nid);		
		$item = field_get_items('node', $node, 'field_video_type');
    $tid = $item[0]['tid'];
		if(isset($tid)) {
			if(!isset($renderable_array[$tid])) $renderable_array[$tid] = array();
			$link = field_get_items('node', $node, 'field_video_link');
			$renderable_array[$tid][] = array(
			  'nid'=>$row->nid,
			  'videoid'=>youtube_parser($link[0]['safe_value']),
			);
	  }
  }
  return $renderable_array;
}
$videos_list = _get_videos_list();
?>
<div class="da-drag-area">
<div class="half-box half-box-right">
	<div class="da-drag-item-box">
    	<div class="da-tabs-box">
        	<em class="active"></em>
            <span class="active">inspiration</span>
            <span>showcases</span>
        </div>
        <div class="da-content-box">
				  <?php if(isset($videos_list['3'])): ?>
        	  <div class="da-content">
            	<ul class="img-list ">
								<?php foreach($videos_list['3'] as $videoinfo):?>
									<?php $nid = $videoinfo['nid']; ?>
                	<li><div class="ytplayerDiv" data-nid="<?php echo $nid;?>" data-videoid="<?php print($videoinfo['videoid'])?>"><img id="myytimg<?php echo $nid;?>" width="202" height="135" src="http://img.youtube.com/vi/<?php print($videoinfo['videoid'])?>/default.jpg" /></div></li>
								<?php endforeach;?>
              </ul>
            </div>
					<?php endif;?>
				  <?php if(isset($videos_list['4'])): ?>
            <div class="da-content hide">
            	<ul class="img-list">
								<?php foreach($videos_list['4'] as $videoinfo):?>
									<?php $nid = $videoinfo['nid']; ?>
                	<li><div class="ytplayerDiv" data-nid="<?php echo $nid;?>" data-videoid="<?php print($videoinfo['videoid'])?>"><img id="myytimg<?php echo $nid;?>" width="202" height="135" src="http://img.youtube.com/vi/<?php print($videoinfo['videoid'])?>/default.jpg" /></div></li>
								<?php endforeach;?>
                </ul>
            </div>
					<?php endif;?>
        </div>
    </div>
</div>

<div class="half-box half-box-left">
	<div class="da-drag-item-box temp-fix-height">
    	<div class="da-tabs-box">
        	<em class="active"></em>
            <span class="active">Activity Stream</span>
        </div>
        <div class="da-content-box">
        	<div class="da-content">
            	<ul>
                	<li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> Brianna</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> Guru</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> John</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> Mark</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> Lisa</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> Brianna</li>
                    <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> Guru</li>
                    
                </ul>
            </div>
        </div>
    </div>
</div>
</div>
<div class="da-bottom-box">
	<div class="da-tabs-box">
    	<em class="active"></em>
        <span class="active">facewall</span>
        <span>friends</span>
        <span>collaborators</span>
        <span>location</span>
        <span>leaderboard</span>
    </div>
    <div class="da-content-box">
    	<div class="da-content">
            <ul>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_06.png"> name</li>
            </ul>
        </div>
        <div class="da-content hide">
            <ul>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_06.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> name</li>
            </ul>
        </div>
        <div class="da-content hide">
            <ul>
            	<li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_06.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> name</li>
                
            </ul>
        </div>
        <div class="da-content hide">
            <ul>
            	<li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> name</li>

                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_06.png"> name</li>
            </ul>
        </div>
        <div class="da-content hide">
            <ul>
               
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_05.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_06.png"> name</li>
                 <li><img src="<?php print $base_url; ?>/images/mock_ico_video_01.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_02.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_03.png"> name</li>
                <li><img src="<?php print $base_url; ?>/images/mock_ico_video_04.png"> name</li>
            </ul>
        </div>
    </div>
</div>
<script>
(function($){
  $(document).ready(function(){
		$('.ytplayerDiv').each(function(){
			var nid = this.dataset['nid'];
			var videoid = this.dataset['videoid'];
			if(!this.dataset['nid']) 
				nid = datasetFallback(this, 'nid');
			if(!this.dataset['videoid'])
				videoid = datasetFallback(this, 'videoid');
			loadVideo(nid, videoid);
		});
	});
})(jQuery);
function datasetFallback(el, property) {
  return el.getAttribute("data-" + property );
}
function loadVideo(nid, videoid) {
	var params = { allowScriptAccess: "always" };
	var atts = { id: "myytplayer"+nid };
	swfobject.embedSWF("http://www.youtube.com/v/"+videoid+"?enablejsapi=1&playerapiid="+nid+"&version=3",
		"myytimg"+nid, "202", "135", "8", null, null, params, atts);
}
function onYouTubePlayerReady(playerId) {
  var elId = 'myytplayer'+playerId;
  var ytplayer = document.getElementById(elId);
	ytplayer.addEventListener("onStateChange", "onPlayerStateChange"+playerId);
}
<?php $videos = array_merge($videos_list['3'], $videos_list['4']);
foreach($videos as $item): ?>
function onPlayerStateChange<?php echo $item['nid'];?>(newState) {
  if(newState == 1) {
		var els = document.getElementsByClassName('ytplayerDiv');
		for(var i=0;i<els.length;i++) {
			var el = els[i];
			var nid = el.dataset['nid'];
			if(nid != <?php echo $item['nid'];?>) {
				var playerEl = document.getElementById('myytplayer'+nid);
				playerEl.pauseVideo();
		  }
		}
  }
}
<?php endforeach; ?>
</script>



 