<?php
global $base_url;
?>

<style>

  .gallery_list ul li {
    float:left;
  }
  .gallery_list ul li img{
    width:148px;
    height:84px;
  }

  .gallery_list ul:after {
    content:'';
    clear:both;
    display:block;
    height:0;
    visibility:hidden;

  }
  .detail {
    float:right;
    color:red;
  }

</style>


<div>
  <h2 style="text-align: center;">Gallery</h2>
</div>







<div class='gallery_list' style="border:solid 1px #000000">
  <div>
    <span style="float:right"><input type="text" value="search"/></span> 
  </div>
  <div>
    <div class='g_tabs' >

      <span class="tab_1">All</span>
      <span class="tab_2">Location</span>
      <span class="tab_3">Topic</span>
      <span class="tab_4">Alphabetize by User</span>


      <span class="tab_5">Alphabetize by Title</span>



    </div>
    <div class="tab_1 content" >
      <ul>


        <!-- -->
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_challenges_5.jpg" />

          </div>  
          <div class="title"> Special Edition: Effects of the Boston Marathon</div>
          <div class="brief"> Introduce of Boston Marathon</div>
          <div class='detail'>More</div>
          <div class='gtype'>Video</div>
          <div class="galleryinfo"> 
            Title: Marathon  <br/>
            Location:Boston <br/>
            Project name: Match 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_challenges_6.jpg" />

          </div>  
          <div class="title">Gun violence in Schools-How can it be stopped? </div>
          <div class="brief"> Introduce of Gun violence in Schools</div>
          <div class='detail'>More</div>
          <div class='gtype'>Document</div>
          <div class="galleryinfo"> 
            Title: Gun violence in Schools  <br/>
            Location:France <br/>
            Project name: gun violence 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_challenges_7.jpg" />

          </div>  
           <div class="title">Cyber Bullying and Bullyrag</div>
          <div class="brief"> Introduce of cyber bullying and bullyrag</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Cyber Bullying and Bullyrag  <br/>
            Location:America <br/>
            Project name: Cyber 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_challenges_8.jpg" />

          </div>  
          <div class="title">Broadcasting Your Life - Will you Be Sorry</div>
          <div class="brief"> Introduce of Broadcasting Your Life</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Broadcasting Your Life  <br/>
            Location:Sahara <br/>
            Project name: Broadcasting 
          </div>
        </li>

        <!--  -->

        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_1.jpg" />

          </div>  
          <div class="title"> Special Edition: Effects of the Boston Marathon</div>
          <div class="brief"> Introduce of Boston Marathon</div>
          <div class='detail'>More</div>
          <div class='gtype'>Video</div>
          <div class="galleryinfo"> 
            Title: Marathon  <br/>
            Location:Boston <br/>
            Project name: Match 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_2.jpg" />

          </div>  
          <div class="title">Gun violence in Schools-How can it be stopped? </div>
          <div class="brief"> Introduce of Gun violence in Schools</div>
          <div class='detail'>More</div>
          <div class='gtype'>Document</div>
          <div class="galleryinfo"> 
            Title: Gun violence in Schools  <br/>
            Location:France <br/>
            Project name: gun violence 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_3.jpg" />

          </div>  
          <div class="title">Cyber Bullying and Bullyrag</div>
          <div class="brief"> Introduce of cyber bullying and bullyrag</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Cyber Bullying and Bullyrag  <br/>
            Location:America <br/>
            Project name: Cyber 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_4.jpg" />

          </div>  
          <div class="title">Broadcasting Your Life - Will you Be Sorry</div>
          <div class="brief"> Introduce of Broadcasting Your Life</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Broadcasting Your Life  <br/>
            Location:Sahara <br/>
            Project name: Broadcasting 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_5.jpg" />

          </div>  
          <div class="title"> Special Edition: Effects of the Boston Marathon</div>
          <div class="brief"> Introduce of Boston Marathon</div>
          <div class='detail'>More</div>
          <div class='gtype'>Video</div>
          <div class="galleryinfo"> 
            Title: Marathon  <br/>
            Location:Boston <br/>
            Project name: Match 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_6.jpg" />

          </div>  
          <div class="title">Gun violence in Schools-How can it be stopped? </div>
          <div class="brief"> Introduce of Gun violence in Schools</div>
          <div class='detail'>More</div>
          <div class='gtype'>Document</div>
          <div class="galleryinfo"> 
            Title: Gun violence in Schools  <br/>
            Location:France <br/>
            Project name: gun violence 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_7.jpg" />

          </div>  
          <div class="title">Cyber Bullying and Bullyrag</div>
          <div class="brief"> Introduce of cyber bullying and bullyrag</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Cyber Bullying and Bullyrag  <br/>
            Location:America <br/>
            Project name: Cyber 
          </div>
        </li>
        <li>
          <div>

            <img src="<?php print $base_url; ?>/images/mock_comp_8.jpg" />

          </div>  
          <div class="title">Broadcasting Your Life - Will you Be Sorry</div>
          <div class="brief"> Introduce of Broadcasting Your Life</div>
          <div class='detail'>More</div>
          <div class='gtype'>Project/Murally</div>
          <div class="galleryinfo"> 
            Title: Broadcasting Your Life  <br/>
            Location:Sahara <br/>
            Project name: Broadcasting 
          </div>
        </li>


      </ul>
    </div>

    <div class="tab_2 content">

    </div>
    <div class="tab_3 content" >


    </div>

    <div class="tab_4 content" >


    </div>
    <div class="tab_5 content" >


    </div>


  </div>
</div>




