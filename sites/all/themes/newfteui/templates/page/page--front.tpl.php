<?php global $user;
//print_r($user);
$the_role_array = $user->roles;
if ($user->uid == 1 ||  in_array('site admin', $the_role_array)) {
	$the_admin = 1;
}
else {
	$the_admin = 0;
}
?>

<!-- /community -->

<div id="mural-region" data-user=<?php print $the_admin; ?> class="hidden">
  <div>
  	<iframe id="mural-iframe" border="0" scrolling="no" width="500" height="500" src=""></iframe>
  </div>
  <div id="mural-region-bottom">
    <div id="mural-set-nav" class="set-nav hidden">
      <span id="node-1010" class="prev">Previous</span>
      <span id="mural-back-set-list">&nbsp;</span>
      <span id="node-2020" class="next">Next</span>
    </div>
    <div id="mural-studio-nav" class="show-nav">
      <input type="hidden" name="mural-display-type" id="mural-display-type" />
      <span id="100" class="prev">Previous</span>
      <span id="200" class="next">Next</span>
    </div>
    <div id="mural-back-to-dashboard" class="back-to-dashboard">
      <span>X</span>
    </div>
  </div>
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
      <!-- <div class="toolbar-item add-an-idea">
        <h4>
          <?php echo l('Create Mural', 'mural/create') ?>
        </h4>
      </div>
      -->
      <div class="toolbar-item tour-guides">
        <h4>Tour Guides</h4>
        <p>
	        	<?php
	        		$img = array(
								'path' => drupal_get_path('theme', 'newfteui') . '/images/iconTourGuide1.png',
	        		);
							$img_src = theme('image', $img);
							echo l($img_src, '', array(
								'attributes' => array(
									'class' => array('set-to-destination'),
									'videoid' => 'EAuXzCiIWlU',
								),
								'html' => true,
							));
	        	?>

        </p>
      </div>
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

<div class="teacher-notes">
  <div class="teacher-notes-header">My teacher notes</div>
  <div class="indicator"><span></span></div>
  <div class="teacher-notes-cont"></div>
</div>

<!-- /main content -->
<?php  print $messages; ?>
<div class="main-content">
  <?php print render($page['content']); ?>
</div>

<!-- /sliding panes -->
<div class="sliding-panes">
  <?php
  global $user;
  if ($user->uid) :
  ?>
  <div class="studio-handler pane-handler" data-aim="studio"></div>
  <?php
  else :
    $mural_link = 'modal_forms/nojs/login';
  	$link_class = array('ctools-use-modal',  'ctools-modal-modal-popup-login');
  	$login_link = l('<div class="studio-handler pane-handler"></div>', $mural_link , array(
    		'attributes' => array(
    			'class' => $link_class,
    		),
        'html' => TRUE,
      )
    );

    echo $login_link;

  endif;
  ?>
  <div class="chanllenge-handler pane-handler" data-aim="challenge"></div>
  <div class="competitions-handler pane-handler"  data-aim="competitions"></div>
  <?php print render($page['sliding_panes']); ?>
</div>
<div class="pane" id="studio">
  <h2 class="pane-tab studio active">Studio</h2>
  <h2 class="pane-tab gallery">Gallery</h2>
  <div class="pane-con studio">
    <?php print render($page['studio_pane']); ?>
  </div>
  <div class="pane-con gallery">
    <?php print render($page['gallery_pane']); ?>
  </div>

</div>
<div class="pane" id="challenge">
	<?php print render($page['challenge']); ?>
</div>
<div class="pane" id="competitions"></div>

<!-- / user profile-->
<div class="user-profile">
  <div class="user-box">
    <?php if (user_is_logged_in()):
      global $user;
      $user = user_load($user->uid);
      $firstnames = field_get_items('user', $user, 'field_firstname');
      $firstname = $firstnames && count($firstnames) ? $firstnames[0]['value'] : '';
      $lastnames = field_get_items('user', $user, 'field_lastname');
      $lastname = $lastnames && count($lastnames) ? $lastnames[0]['value'] : '';
    ?>
      <h4 title="<?php echo $firstname && $lastname ? ($firstname.' '.$lastname) : $user->name; ?>"><?php echo $firstname && $lastname ? ($firstname.' '.$lastname) : $user->name; ?></h4>
      <?php
      $profile_setting_url = l(t('Settings'),
        'edgemakers/user/profile/settings/nojs',
        array(
          'attributes' => array(
            'class' => array(
              'ctools-use-modal',
              'ctools-modal-modal-popup-profilesetting',
            ),
          ),
        )
      );
      $logout_url = l(t('Log out'),
        'user/logout',
        array(
          'query' => array(
            'destination' => 'home'
          ),
          'attributes' => array(
            'class' => array(

            )
          ),
        )
      );
      ?>
      <nav id="secondary-menu" role="navigation">
      <ul class="link inline clearfix">
        <li class="menu-item first"><?php echo $profile_setting_url; ?></li>
        <li class="menu-item last"><?php echo $logout_url; ?></li>
      </ul>
      </nav>
    <?php endif; ?>
  </div>
  <?php if (user_is_logged_in()): ?>
    <div class="user-profile-inner">
      <?php

      if($user->picture) {
        $avatarUri = $user->picture->uri;
      } else {
        $picture = get_user_avatar($user);
        if (isset($picture->uri)) {
          $avatarUri = $picture->uri;
        } else
        {
        $avatarUris = explode('/', variable_get('user_picture_default', ''));
        $avatarUri = file_build_uri(array_pop($avatarUris));
        }
      }
      // Add edgemakers_profile_avatar style in image style config.
      $login_div = theme('image_style', array('path' => $avatarUri, 'style_name' => 'edgemakers_profile_avatar'));
      $login_div = '<div class="user-profile-avatar"><div class="avatar-picture">' . $login_div . '</div></div>';
      print $login_div;
      ?>
    </div>
  <?php else: ?>
    <?php
    $login_div = '<div class="user-profile-inner-url">';
    $login_div .= '<img src="sites/all/themes/newfteui/images/example_08.png" />';
    $login_div .= '</div>';

    echo l($login_div, 'user/login', array(
      'html' => TRUE,
      'attributes' => array(
        'class' => array('user-login-link'),
        'style' => 'display: block;',
      )
            )
    );
    echo l('Registration', 'user/register', array(
      'attributes' => array(
        'class' => array('user-registration-link'),
        'style' => 'display: none;',
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



<?php
if(user_is_logged_in()) {
  if (isset($_SESSION['userchangepass']) && $_SESSION['userchangepass'] == 1) {
    unset($_SESSION['userchangepass']);
?>
    <script>
    jQuery(document).ready(function(){
      jQuery("a[href='/edgemakers/user/profile/settings/nojs']").trigger("click");
    });
    </script>
    <?php
  }
} else {
  //if user is not logged in and is linked from other websites, login popup will appear
  if(isset($_SERVER['HTTP_REFERER']) && isset($_SERVER['HTTP_HOST']) && $_SERVER['HTTP_REFERER'] != '') {
    $parts = parse_url($_SERVER['HTTP_REFERER']);
    if($parts && isset($parts['host']) && $parts['host'] != $_SERVER['HTTP_HOST']) {
      if(isset($_GET['registration'])) {
?>
      <script>
      jQuery(document).ready(function(){
        jQuery(".user-profile a.user-registration-link").trigger("click");
      });
      </script>
      <?php } else { ?>
      <script>
      jQuery(document).ready(function(){
        jQuery(".user-profile a.user-login-link").trigger("click");
      });
      </script>
      <?php
      }
    }
  }
}
?>
