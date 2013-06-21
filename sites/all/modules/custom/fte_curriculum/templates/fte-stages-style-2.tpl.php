<?php

$the_path = drupal_get_path('module', 'fte_curriculum');
//drupal_add_js($the_path.'/js/fte_learn.js');
global $base_path;
global $base_url;
?>






<div class ="stage_bottom_area" style="clear: both">


	<div class="stage_bottom_content">
        <div class="stage_bottom_content_tab">
            <em class="stage_bottom_switcher active"></em>
            <span class="active">Description</span>
            <span>Users</span>
            <!--<span>MURSLS</span>-->
            <span>Notes</span>
            
         </div>
         <div class="stage_bottom_content_inner">
            <div class="stage_bottom_content_inner_content">
              <?php  if ($data==2) {?>
          <p>Here's Brieana, our young and relevant tour guide, making all this change - easier.</p>
            <?php
             }
			  
			?>
            
            <?php  if ($data==3) {?>
          <p>We'd like to introduce you to John Kao, our founder and longtime Creativity and Innovation instructor, professor and mentor. He's going to talk about what it means to "Lean forward.</p>
            <?php
             }
			  
			?>
            
            <?php  if ($data==4) {?>
          <p>Now we'd like to show you an Apple ad from 1997 which describes pretty well - who you are.</p>
            <?php
             }
			  
			?>
            
            


              
            </div>  
            <div class="stage_bottom_content_inner_content">
                <ul>
                <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_1.png"></li>
                <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_2.png"></li>
                <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid grey" src="<?php print $base_path;?>images/mock_user_icon_3.png"></li>
                <li style="float:left"> <img style="width:46px; height:46px ;border: 2px solid green" src="<?php print $base_path;?>images/mock_user_icon_4.png"></li>     
                <div style="clear:both"></div>   
              </ul>
             </div>
            <!--<div class="stage_bottom_content_inner_content">
              
              <ul>
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option>public</option></select></div>
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option>public</option></select></div>
              
            </li>
            
             <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option selected>public</option></select></div>
              
            </li style="float:left">
            
            <li style="float:left;margin:10px">
              <div style="text-align:center"><img src="<?php print $base_url;?>/images/mock_mural_icon.jpg"/></div>
              <div><select name="pp"><option>private</option><option selected>public</option></select></div>
              
            </li>
            
            <li style="clear:both"></li>
          </ul>
              
            </div>-->
            <div class="stage_bottom_content_inner_content">This is NOTES.</div>
        </div>
      </div>  
		<div class="stage_comments" >
          <div class="stage_bottom_content_tab">
            <em class="stage_bottom_switcher active"></em>
            <span>Comments</span>
          
          </div>
           <div class="stage_bottom_content_inner">
             <p>This is comments.</p>
            </div>
       </div>

  
  
  
  
  
</div>  <!-- stage_bottom_area -->
