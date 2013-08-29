<?php ?>

<!-- /community -->

<div id="mural-region" class="hidden">
  <div>
  	<iframe id="mural-iframe" border="0" scrolling="no" width="500" height="500" src=""></iframe>
  </div>
  <div id="mural-region-bottom">
    <div id="mural-set-nav" class="set-nav hidden">
      <span id="node-1010" class="prev">Previous</span>
      <span id="mural-back-set-list">&nbsp;</span>
      <span id="node-2020" class="next">Next</span>
    </div>
    <div id="mural-back-to-dashboard" class="back-to-dashboard">
      <span>Back to dashboard</span>
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
<?php //print $messages; ?>
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
  	$link_class = array('ctools-use-modal',  'ctools-modal-modal-popup-small');
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
      <h4><?php echo $firstname && $lastname ? ($firstname.' '.$lastname) : $user->name; ?></h4>
      <?php if ($secondary_menu): ?>
        <nav id="secondary-menu" role="navigation">
        <ul class="link inline clearfix">
          <li class="menu-item first"><a href="<?php echo $base_url.'/edgemakers/user/profile/settings/nojs'?>" class="ctools-use-modal ctools-modal-modal-popup-small">Settings</a></li>
          <li class="menu-item last"><a href="<?php echo $base_url.'/user/logout?destination=home'?>">Log out</a></li>
        </ul>
        </nav>
      <?php endif; ?>
    <?php endif; ?>
  </div>
  <?php if (user_is_logged_in()): ?>
    <div class="user-profile-inner">
      <?php
      if($user->picture) {
        $avatarUri = $user->picture->uri;
      } else {
        $avatarUris = explode('/', variable_get('user_picture_default', ''));
        $avatarUri = file_build_uri(array_pop($avatarUris));
      }
      $login_div = theme('image_style', array('path' => $avatarUri, 'style_name' => 'thumbnail', 'width' => '150', 'height' => '162'));
      print $login_div;
      ?>
    </div>
  <?php else: ?>
    <?php
    global $user;

    $login_div = '<div class="user-profile-inner-url">';
    $login_div .= '<img src="sites/all/themes/newfteui/images/example_08.png" />';
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
<!--this is for profile settings demo-->
<div class="demo-setting-wrapper"></div>
<!--{{{the mock up of the login start-->
<div class="login-regisiter-newpassword-wrapper">
	<ul class="lrn-tab">
		<li>Regisiter</li>
		<li class="active">Log in</li>
		<li>Request new password</li>
	</ul>
	<form class="box-register lrn-box">
		<table>
			<tr>
				<td><input type="text" placeholder="FIRST NAME" /></td>
				<td><input type="text" placeholder="LAST NAME" /></td>
			</tr>
			<tr>
				<td><input type="text" placeholder="EMAIL" /></td>
				<td><input type="text" placeholder="USER NAME" /></td>
			</tr>
			<tr>
				<td><input type="password" placeholder="PASSWORD" /></td>
				<td><input type="password" placeholder="CONFIRM PASSWORD" /></td>
			</tr>
			<tr>
				<td>
					<dl>
						<dt>What's your role?</dt>
						<dd>Teacher <input type="radio" /></dd>
						<dd>Student <input type="radio" /></dd>
					</dl>
				</td>
				<td>
					<dl>
						<dt>Upload Profile Picture</dt>
						<dd><input type="file" /></dd>
					</dl>
                </td>
			</tr>
		</table>
		<div class="submit">
			<button>Continue</button>
		</div>
	</form>
	<form class="box-login tab-active lrn-box">
		<div class="items">
			<input type="text" placeholder="USER NAME OR EMAIL" /><input type="password" placeholder="PASSWORD" />
		</div>
		<div class="submit">
			<button>Login</button>
		</div>
	</form>
	<form class="box-newpassword lrn-box">
		<div class="items">
			<input type="text" placeholder="USER NAME OR EMAIL" />
		</div>
		<div class="submit">
			<button>Email New Password</button>
		</div>
	</form>
</div>
<!--the mock up of the login end--}}}-->
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