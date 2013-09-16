<?php
global $user;
global $base_url;
$mural_url = 'http://mural.ly/embed/edgemakers/edgemakers/';
// echo "Domain: $base_url";
$path = parse_url($base_url);
// print('<pre>' . print_r($path, TRUE) . '</pre>');
switch (strtolower($path['host'])) {
  case 'edgemakers.com':
    $mural_url = 'http://mural.ly/embed/edgemakers/edgemakers/';
    break;
  case 'dev.edgemakers.com':
    $mural_url = 'http://mural.ly/embed/dev-edgemakers/dev-edgemakers/';
    break;
  case 'staging.edgemakers.com':
    $mural_url = 'http://mural.ly/embed/staging-edgemakers/staging-edgemakers/';
    break;
  case 'test.edgemakers.com':
    $mural_url = 'http://mural.ly/embed/test-edgemakers/test-edgemakers/';
    break;
}

$the_m_id = $data['m_id'];

// Add mural share link, it's edgemakers admin url, not muraly.ly share url.
// Share url.
$share_url = 'http://mural.ly/!/#/' . $data['node']->field_muraluser['und'][0]['value'] . '/' . $the_m_id;

//     http://mural.ly/!/#/lwgmural/1377178465904

// Popup dialog.
drupal_add_library('system', 'ui.dialog');
?>

<script>
  function showShareUrl() {
    jQuery( "#mural-share-url" ).dialog({
/*      dialogClass: "no-close", */
      dialogClass: 'noTitleStuff',
      width: "480px",
      resizable: false,
      modal: true,
      buttons: {
        Close: function() {
          jQuery( this ).dialog( "close" );
        }
      }
    });
    jQuery(".ui-dialog-buttonpane").attr("style", "border-top-width: 0px;");

  }
</script>
<div id="mural-share-url" class="hidden" title="Mural URL">
  <h3>&nbsp;</h3>
  <input size="52" name="mural-share-url" id="mural-share-url" value="<?php echo $share_url; ?>" readonly="readonly" />
</div>

<style>
div.breadcrumb {
  display: none;
}
body {
  background-image: url();
  background-color: rgb(240, 240, 240);
}

.page-mural #wrapper {
  width: 100%;
}
</style>
<div id="mural-top-bar">

  <div id="mural-title">
		<?php echo $data['node']->title; ?>
  </div>
	<ul id="mural-region-nav">
<!-- 	  <li> -->
<!--  	    <span class="close-mural-dialog" onclick='window.parent.closeFromIframe();'> X </span> -->
<!-- 	  </li> -->
	  <?php if ($user->uid == $data['node']->uid) : ?>
		<li class="mural-nav-link-delete">
			<?php

        $delete_link = l(t('Delete'),
  				'mural/delete/' . $data['node']->nid,
  				array(
  					'attributes' => array(
              'class' => array('mural-nav-link'),
  						'onclick' => 'return confirm("Are you sure?")',
  					),
  				)
  			);
			  echo $delete_link;

      ?>
		</li>
		<li>
			<?php print_r($data['seturl'])?>
		</li>

		<li class="mural-nav-link-duplicate">
		<?php
		  $img_duplicate = array(
        'path' => drupal_get_path('theme' , 'newfteui') . '/images/iconMuralDuplicate.png',
      );

			$icon_duplicate = theme('image', $img_duplicate);

			$duplicate_link = l($icon_duplicate,
				'mural/create/' . $the_m_id . '/' . $data['node']->nid,
        array(
          'attributes' => array(
//             'class' => array('mural-nav-link'),
          ),
					'html' => TRUE,

        )
			);
			echo $duplicate_link;
		?>
		</li>
		<?php endif; ?>
		<?php

		function _isShowMuralUrl() {
      global $user;
      $allow_roles = array('site administrator' , 'site admin');
      foreach ($user->roles AS $key => $val) {
        if (in_array($val, $allow_roles)) {
          return 1;
        }
      }
      return 0;
    }

		if (_isShowMuralUrl()) :
		?>
		<li class="mural-nav-link-delete">
		  <a href="#" class="mural-nav-link" onClick="showShareUrl();return false;"/>Mural Url</a>
		</li>
		<?php
		endif;
		?>
	</ul>

</div>

<?php
//Add md5 hash of url to refresh
$hash = md5(microtime());
?>
<div id="mural-iframe-content">
  <iframe id="mural-ly-iframe" frameborder='0' src='<?php print $mural_url . $the_m_id . '#' . $hash;?>' width=100% height=600'></iframe>
</div>
<script>
  //jQuery("#mural-ly-iframe").attr("src", source);
  function lyszie(){
  	jQuery("#mural-ly-iframe").attr("width", jQuery(window).width());
  	jQuery("#mural-ly-iframe").attr("height", jQuery(window).height()-36);

  }
  lyszie();
  jQuery(window).resize(function(){
  	lyszie();
  });
</script>
