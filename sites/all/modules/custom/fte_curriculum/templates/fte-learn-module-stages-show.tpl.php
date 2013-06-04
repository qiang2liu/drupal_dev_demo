<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
?>



<div

  style="background: url(<?php print base_path() . drupal_get_path('module', 'fte_curriculum') ?>/images/greenline.png) center center repeat-x ;
  display: inline-block;

  ">



<?php
$i = 1;
foreach ($data->stages as $row) {

  if ($i == 1 || $i >= count($data->stages)) {
    $m = '';
  } else {
    $m = 'margin: 10px;';
  }

  if ($i == $data->stagedata->sid) {
    $the_class = "#00ff00";
  } else {
    $the_class = "#fff";
  }
  ?>



    <div style="
         border:1px solid green;
         background:<?php print $the_class; ?>;
         border-radius: 10px;
         cursor:pointer;
         width:20px;
         height:20px;
         display:inline-block;
         text-align:center;
  <?php print $m; ?>
         "
         
         onclick ="change_stage('<?php print $data->stagedata->next_mid;?>',
           '<?php print $row->sid;?>')"
         > 

         <?php print $i++; ?> </div>
         <?php
       }
       ?>



</div>

<?php 

 setcookie('fte_learn_current_yid',$data->stagedata->yid,time()+3600*30);
 if ($data->stagedata->yid == '') {
    setcookie('fte_learn_playtime',0,time()+3600*30);
 } else {
  setcookie('fte_learn_playtime',$data->stagedata->time,time()+3600*30);
 } 
 setcookie('fte_learn_current_mid',$data->stagedata->next_mid,time()+3600*30);
 setcookie('current_stage_id',$data->stagedata->sid,time()+3600*30);
  
  if (!empty($data->stagedata->yid)) {
    
 ?>   

<div id="ytapiplayer">
    You need Flash player 8+ and JavaScript enabled to view this video.
</div>
<?php
      // video stage





    drupal_add_js($the_path.'/js/fte_learn.js');
    drupal_add_js(array('fte_learn_stages' => $data->stagedata), 'setting');
    drupal_add_js(array('fte_learn_stages_yid' =>$data->stagedata->yid), 'setting');
    drupal_add_js(array('fte_learn_stages_playtime' =>$data->stagedata->time), 'setting');
    
    ?>

<script>
  
   var ytplayer;
    var params = {
      allowScriptAccess: "always"
    };
    var atts = {
      id: "myytplayer"
    };
   
  
   $(document).ready(function(){
     
      swfobject.embedSWF("http://www.youtube.com/v/"+Drupal.settings.fte_learn_stages_yid
        +"?enablejsapi=1&playerapiid=ytplayer&version=3&modestbranding=1",
        "ytapiplayer", "780", "439", "8", null, null, params, atts);
  
    
  



}
    


); 
</script>


<?php
    
  } else {
?>

<div>
  <?php print $data->stagedata->content?>
  <?php
    if ($data->stagedata->next_sid >= 0) {
  ?>
  <br/>
  <a href =" /learn/<?php print $data->stagedata->next_mid;?>/stage/<?php print $data->stagedata->next_sid;?>"> next stage </a>
  <?php
  }
  ?>
</div>
</div>

<?php
  }

?>

<script>
  
  
  
  function change_stage(m,s) {
    location.href="/learn/"+m+"/stage/"+s;
  }
  
  </script>
  
  
  
  
  
  