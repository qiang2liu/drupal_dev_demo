<?php
global $base_url;
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
			$screenshot = field_get_items('node', $node, 'field_video_screenshot');
			$renderable_array[$tid][] = array(
			  'nid'=>$row->nid,
			  'link'=>$link[0]['safe_value'],
			  'screenshot'=>file_create_url($screenshot[0]['uri']),
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
                	<li><a class="myytplayer" id="myytplayer<?php echo $nid;?>" href="javascript:playVideo(<?php echo $nid;?>, '<?php print($videoinfo['link'])?>', '<?php echo $videoinfo['screenshot'];?>');"><img width="202" height="135" src="<?php print($videoinfo['screenshot']); ?>"></a></li>
								<?php endforeach;?>
              </ul>
            </div>
					<?php endif;?>
				  <?php if(isset($videos_list['4'])): ?>
            <div class="da-content hide">
            	<ul class="img-list">
								<?php foreach($videos_list['4'] as $videoinfo):?>
                	<li><a class="myytplayer" id="myytplayer<?php echo $nid;?>" href="javascript:playVideo(<?php echo $nid;?>, '<?php print($videoinfo['link'])?>', '<?php echo $videoinfo['screenshot'];?>');"><img width="202" height="135" src="<?php print($videoinfo['screenshot']); ?>"></a></li>
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
var screenshotInfo = [];
function playVideo(nid, url, screenshot) {
	var ytplayer = document.getElementById("myytplayer"+nid);
  //ytplayer.innerHTML = '<iframe width="202" height="135" src="'+url+'?rel=0&autoplay=1" frameborder="0" allowfullscreen></iframe>';
	ytplayer.innerHTML = '<object width="202" height="135"><param name="movie" value="'+url+'?version=3&amp;autoplay=1&amp;rel=0"></param><param name="allowFullScreen" value="true"></param><param name="allowscriptaccess" value="always"></param><param name="autoplay" value="true"><embed src="'+url+'?version=3&amp;autoplay=1&amp;rel=0" type="application/x-shockwave-flash" width="202" height="135" allowscriptaccess="always" allowfullscreen="true"></embed></object>';
	/*var params = { allowScriptAccess: "always" };
	var atts = { id: "myytplayer"+nid };
	swfobject.embedSWF(url+"?enablejsapi=1&playerapiid=ytplayer"+nid+"&version=3",
		"ytapiplayer", "202", "135", "8", null, null, params, atts);*/
  if(screenshotInfo) {
	  var oldplayer = document.getElementById("myytplayer"+screenshotInfo[0]);
		if(oldplayer) oldplayer.innerHTML = '<img width="202" height="135" src="'+ screenshotInfo[1] +'"/>';
	}
	screenshotInfo = [nid, screenshot];
}
/*function onYouTubePlayerReady(playerId) {
	var ytplayer = document.getElementById(playerId);
	if (ytplayer) {
    ytplayer.playVideo();
  }
}*/
</script>



 