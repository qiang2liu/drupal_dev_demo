<?php ?>

<!-- /community -->

<div id="mural-region" class="hidden">
  <div id="mural-top">Mural top contrl</div>
  <div>
  	<iframe id="mural-iframe" width="500" height="500" src=""></iframe>
  </div>
   <div id="mural-bottom">Mural bottom info</div>
</div>

<div class="community">

  <?php print render($page['community']); ?>
  <div class="indicator"><span></span></div>
</div>
<!--stage title and set title-->
<div class="s-s-title">
  <h2><!--stage title here--></h2>
  <h3><!--set title here--></h3>
</div>
<!-- /tool bar and stage selector -->

<div class="toolbar-stage">
  <div class="tool-bar">
    <!-- {{{toolbar start-->
    <div class="toolbar-handler"></div>
    <div class="toolbar-box">
      <div class="toolbar-item title">
        <h4>Toolbar</h4>
      </div>
      <?php print render($page['tool_bar']); ?>
      <!--  <div class="toolbar-item add-an-idea">
        <h4>
          <?php echo l('Create Mural', 'mural/create') ?>
        </h4>
      </div>
      -->
      <!--
      <div class="toolbar-item test2"></div>
      <div class="toolbar-item upload">
        <h4>Upload</h4>
      </div>

      <div class="toolbar-item murals">
        <h4>Murals</h4>
      </div>
      <div class="toolbar-item media">
        <h4 class="has-child">Media<em></em></h4>
        <ul id="media-list">
          <li class="media-video">Video</li>
          <li class="media-image">Images</li>
          <li class="media-audio">Audio</li>
          <li class="media-docs">Docs</li>
        </ul>
      </div>
      <div class="toolbar-item social">
        <span class="social-twitter"></span>
        <span class="social-facebook"></span>
        <span class="social-gmail"></span>
      </div>
      <div class="toolbar-item tour-guides">
        <h4>Tour Guides</h4>
        <p>images here</p>
      </div>
      -->
    </div>
    <!-- }}} toolbar end -->

    <!-- {{{ Stage Selector start -->
    <div class="stage-selector">
      <div class="stage-selector-inner">
        <div class="stage-selector-handler"><em></em><span>Stage Selector</span></div>
        <div class="stage-box"></div>
      </div>
    </div>
    <!-- }}} Stage Selector end -->
  </div>
  <!--<?php print render($page['tool_bar']); ?>-->
</div>


<!-- /main content -->
<?php print $messages; ?>
<div class="main-content">
  <?php print render($page['content']); ?>
</div>

<!-- /sliding panes -->
<div class="sliding-panes">
  <div class="studio-handler pane-handler" data-aim="studio"></div>
  <div class="chanllenge-handler pane-handler" data-aim="challenge"></div>
  <!--<div class="competitions-handler pane-handler"  data-aim="competitions"></div>-->
  <?php print render($page['sliding_panes']); ?>
</div>
<div class="pane" id="studio">
  <h2 class="pane-tab studio active">Studio</h2>
  <h2 class="pane-tab gallery">Gallery</h2>
  <div class="pane-con studio">

  </div>
  <div class="pane-con gallery">

  </div>

</div>
<div class="pane" id="challenge"></div>
<!--<div class="pane" id="competitions"></div>-->

<!-- / user profile-->
<div class="user-profile">
  <div class="user-box">
    <?php if (user_is_logged_in()): ?>
      <h4><?php echo $user->name; ?></h4>
      <?php if ($secondary_menu): ?>
        <nav id="secondary-menu" role="navigation">
          <?php
          print theme('links__system_secondary_menu', array(
                    'links' => $secondary_menu,
                    'attributes' => array(
                      'class' => array('links', 'inline', 'clearfix'),
                    ),
                  ));
          ?>
        </nav>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <?php if (user_is_logged_in()): ?>
    <div class="user-profile-inner">
      <?php
      global $user;

      $login_div = '';
      $user = user_load($user->uid);
      //$login_div .= theme('image_style', array( 'path' =>  $user->picture->uri, 'style_name' => 'thumbnail', 'width' => '150', 'height' => '162'));
      //print theme_user_picture();
      //$login_div = '<div class="user-profile-inner-url">';
      //$login_div .= '<img src="sites/all/themes/newfteui/images/example_08.png" />';
      $login_div = theme('image_style', array('path' => $user->picture->uri, 'style_name' => 'thumbnail', 'width' => '150', 'height' => '162'));
      //$login_div .= theme('user_picture', array('account' =>$user));
      //$login_div .= '</div>';
      print $login_div;
      ?>
      <!-- <img src="sites/all/themes/newfteui/images/example_08.png" /> -->
    </div>
  <?php else: ?>
    <?php
    global $user;

    $login_div = '';
    $user = user_load($user->uid);
    //$login_div .= theme('image_style', array( 'path' =>  $user->picture->uri, 'style_name' => 'thumbnail', 'width' => '150', 'height' => '162'));
    //print theme_user_picture();
    $login_div = '<div class="user-profile-inner-url">';
    $login_div .= '<img src="sites/all/themes/newfteui/images/example_08.png" />';
    //$login_div .= theme('image_style', array( 'path' =>  $user->picture->uri, 'style_name' => 'thumbnail', 'width' => '150', 'height' => '162'));
    //$login_div .= theme('user_picture', array('account' =>$user));
    $login_div .= '</div>';

    echo l($login_div, 'user/login', array(
      'html' => TRUE,
      'attributes' => array(
        'style' => 'display: block;',
      )
            )
    );
    ?>
  <?php endif; ?>
</div>

<?php
$ignore_mural_bye = getenv('ignore_mural_bye');

if ($ignore_mural_bye != 1 && isset($_SESSION['need_logout_muraleditor']) && $_SESSION['need_logout_muraleditor'] == 1) {
  unset($_SESSION['need_logout_muraleditor']);
  $the_mural_url = variable_get('muralapi_baseurl', 'http://staging.mural.ly') . "/bye";
  ?>
  <iframe height="0" width="0" src="<?php print $the_mural_url ?>"></iframe>
  <?php
}
?>