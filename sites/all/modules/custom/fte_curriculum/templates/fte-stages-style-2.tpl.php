<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path;
?>






<div class ="stage_bottom_area" style="clear: both">
  
  <div class="bottom_left" style="width: 50%; float:left">
  
    <div class="stage_description_user description" style="width:100%; height : 100px;border: 1px solid green">
  
  
      <a href="#">DESCRIPTION</a> . <a href="#">USERS</a>
      
      <br/>
      
      this is the description
  
    </div>
    
    <div class="stage_description_user user" style="width:100%; height : 100px;border: 1px solid green">
  
  
       <a href="#">DESCRIPTION</a> . <a href="#">USERS</a> 
       
       <br/>
       <ul>
        <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_1.png"></li>
        <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_2.png"></li>
        <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid grey" src="<?php print $base_path;?>images/mock_user_icon_3.png"></li>
        <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_4.png"></li>
        
        
        <div style="clear:both"></div>
        
       </ul>  
        
        
  
    </div> 
    
    
    
    


    <div class="stage_comments" style="width:100%; height : 100px;border: 1px solid green">
  
  
      COMMENTS
  
    </div>
    
  </div>  
  
  
  <div class="bottom_right" style="width:50%;float:left" >
  
    <div class="stage_murals_notes murals" style="width: 100%; border: 1px solid green">
  
          <a href="#">MURSLS</a> . <a href="#">NOTES</a>
      
      <br/>
       mural list
      
 
    </div>


    <div class="stage_murals_notes notes" style="width: 100%; height:90px; border: 1px solid green">
  
          <a href="#">MURSLS</a> . <a href="#">NOTES</a>
      
      <br/>
      note list
  
    </div>
    
  </div>
  
  
  
  
</div>  <!-- stage_bottom_area -->
