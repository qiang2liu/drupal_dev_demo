<a name="top"></a>
<div>
  
  <ul>
    
    <li>
       play the three videos one by one automatically
    </li>
    <li>
       click the image in the video list can play that video 
    </li>
    <li>
       leave this page and access it again, it play one video according to the latest status when you leave.   
    </li>
  </ul>
  
</div>
<div id="ytapiplayer">
    You need Flash player 8+ and JavaScript enabled to view this video.
</div>

<h2>  video list</h2>
<?php
   
  foreach($data as  $row) {
    print  "<div class = 'video_container' data-ytid = '" .$row->yid."'> ";
    print  "<h3>" . check_plain($row->title) . "</h3>";
    $the_image_path = theme('image',
      array('path'=>'http://img.youtube.com/vi/' . $row->yid . '/hqdefault.jpg',)
    );
    print  "<div class = 'video_body' >";
    ?>
   
    <a href="javascript:void(0);" onclick="play_the_video('<?php print $row->yid;?>');">
        <?php print $the_image_path;?>
    </a>
  <?php
  
    print "</div>";
    print "</div>";
  }

 ?>

<script>

 ( function($){
     play_videos(Drupal.settings.fte_video_demo);
   
  
   
 }
 
)(jQuery);
   
   
  </script>

