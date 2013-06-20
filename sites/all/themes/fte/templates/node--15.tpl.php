<?php
global $base_url;
$the_current_url = $_SERVER['HTTP_HOST'] . request_uri();
?>
<div class="studio-setting">
	Settings
</div>
<div class="studio-popup">
	<table>
    <tr>
    	<td colspan="2" style="text-align:right;"><span class="studio-close">X</span></td>
    </tr>
      <tr>
        <td>Title: </td>
        <td><input name="" type="text" /></td>
      </tr>
      <tr>
        <td>Location: </td>
        <td><input name="" type="text" /></td>
      </tr>
      <tr>
        <td>Category: </td>
        <td><select name="">
          <option>item1</option><option>item2</option><option>item3</option><option>item4</option>
        </select></td>
      </tr>
      <tr>
        <td>sub-category: </td>
        <td><select name="">
          <option>item1</option><option>item2</option><option>item3</option><option>item4</option>
        </select></td>
      </tr>
      <tr>
        <td>Tags: </td>
        <td><input name="" type="text" /></td>
      </tr>
      <tr>
        <td>&nbsp;</td>
        <td><input name="" type="radio" value="" />Public<input name="" type="radio" value="" />Private</td>
      </tr>
      <tr>
        <td>Time and date stamp</td>
        <td>Here is the date</td>
      </tr>
      <tr>
        <td>&nbsp;</td>
        <td><input name="" type="radio" value="" />Shared </td>
      </tr>
</table>

</div>
<h1 class='studio-title'>Studio</h1>
<div class="studio-search"><input type="text" size="30px" placeholder="Search"/></div>
<div class='studiocontent'>
  <div class="studio-columeleft">  <!-- toolbar -->
    <div class="studio-side">
      <h4 class="active">My Actions</h4>
     	<div class="studio-side-inner">
          <h5 class="active">My Projects</h5>
          <ul>
            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/51"><img src="<?php print $base_url; ?>/images/mock_project_1.jpg"/></a>  
              </div>
              <div>Saving the Sahara</div>

            </li>

            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/51"><img src="<?php print $base_url; ?>/images/mock_project_2.jpg"/></a>
              </div>
              <div>Art for Life</div>

            </li>

            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/51"><img src="<?php print $base_url; ?>/images/mock_project_3.jpg"/></a>
              </div>
              <div>Build to Heal</div>

            </li>

          </ul>
        
        
          <h5 class="active">My Competitions</h5> 
          <ul>
            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/52"><img src="<?php print $base_url; ?>/images/mock_project_2.jpg"/></a>  
              </div>
              <div>competion 1</div>

            </li>

            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/52"><img src="<?php print $base_url; ?>/images/mock_project_3.jpg"/></a>
              </div>
              <div>competion 2</div>

            </li>

            <li>

              <div>
                <a href="<?php print $base_url; ?>/node/52"><img src="<?php print $base_url; ?>/images/mock_project_1.jpg"/></a>
              </div>
              <div>competion 3</div>

            </li>

          </ul>
          
          
          
       
        

      </ul>
      </div>
    </div>
    <div class='upload'>
       <img src="<?php print $base_url; ?>/images/mock_upload_icon.png"/>Upload
    </div>

    <div class="tour-guide">
      <h6>Tour Guides</h6>
      <ul>
            <li>
                <a href="<?php print $base_url;?>/node/53"><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_ico_video_01.png" /></a>
            </li>
            <li>
                <a href="<?php print $base_url;?>/node/54"><img src="<?php print $base_url;?>/sites/all/themes/fte/images/mock_ico_video_02.png" /></a>
            </li>
            
        </ul>

    </div>

  </div>
  <div class="studio-columeiddle">
    <ul>
      <li class="title"><!--projects-->
        Projects(2)
        <ul>
          <li>
           
            <a href="<?php print $base_url;?>/node/55"><img src="<?php print $base_url;?>/images/mock_create_new.jpg" /></a>
            
            
            
            
           </li>
          <li>
            
            <a href="<?php print $base_url;?>/node/51"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
            
            
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/51"><img src="<?php print $base_url;?>/images/mock_studio_2.jpg" class="setting-img" /></a>
          </li>
          
        </ul>
        <span>view all</span>
        
        
      </li>  
      
      <li class="title"> <!--assignments-->
        assignments(4)
        <ul>
          <li>
            <a href="<?php print $base_url;?>/node/56"><img src="<?php print $base_url;?>/images/mock_create_new.jpg" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/57"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/57"><img src="<?php print $base_url;?>/images/mock_studio_2.jpg" class="setting-img" /></a>
          </li>
           <li>
            <a href="<?php print $base_url;?>/node/57"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/57"><img src="<?php print $base_url;?>/images/mock_studio_2.jpg" class="setting-img" /></a>
          </li>
          
        </ul>
         <span>view all</span>
      </li> 
      
      <li class="title"><!--portfolios-->
         portfolios(5)
        <ul>
          <li>
            <a href="<?php print $base_url;?>/node/58"><img src="<?php print $base_url;?>/images/mock_create_new.jpg" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/59"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/59"><img src="<?php print $base_url;?>/images/mock_studio_2.jpg" class="setting-img" /></a>
          </li>
           <li>
            <a href="<?php print $base_url;?>/node/59"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/59"><img src="<?php print $base_url;?>/images/mock_studio_1.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/59"><img src="<?php print $base_url;?>/images/mock_studio_2.jpg" class="setting-img" /></a>
          </li>
          
        </ul>
         <span>view all</span>
      </li>  
      
      <li class="title"> <!--personal-->
        personal(3)
        <ul>
          <li>
            <a href="<?php print $base_url;?>/node/60"><img src="<?php print $base_url;?>/images/mock_create_new.jpg"/></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/61"><img src="<?php print $base_url;?>/images/mock_studio_3.jpg" class="setting-img" /></a>
          </li>
          <li>
            <a href="<?php print $base_url;?>/node/61"><img src="<?php print $base_url;?>/images/mock_studio_4.jpg" class="setting-img" /></a>
          </li>
           <li>
            <a href="<?php print $base_url;?>/node/61"><img src="<?php print $base_url;?>/images/mock_studio_5.jpg" class="setting-img" /></a>
          </li>
          
          
        </ul>
        <span>view all</span>
      </li> 
    </ul>
    
  </div>
  <div class="studio-columeright">
  <div class="studio-side-inner">
    <h5 class="active">Collaborators<!--<span id='colla_all'><a href="javascript:void(0);">See All</a></span>--></h5>
    
        
        
        <ul class="half-width">
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_add.jpg" />
            </div>
            <div>
              ADD
            </div>
          </li>
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_1.jpg" />
            </div>
            <div>
              Yu
            </div>
          </li>
          
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_2.jpg" />
            </div>
            <div>
              Devi
            </div>
          </li>
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_3.jpg" />
            </div>
            <div>
              Miguel
            </div>
          </li>
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_4.jpg" />
            </div>
            <div>
              Shanna
            </div>
          </li>
          
          
        </ul>
        
        
        
        <ul id='collamore' style="display:none">
          
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_2.jpg" />
            </div>
            <div>
              Pa
            </div>
          </li>
          
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_1.jpg" />
            </div>
            <div>
              Tom
            </div>
          </li>
          <li>
            <div>
              <img src="<?php print $base_url;?>/images/mock_colla_4.jpg" />
            </div>
            <div>
              Alic
            </div>
          </li>
          
          
          
        </ul>
        
        </div>
        
      
    
    
  </div>

</div>