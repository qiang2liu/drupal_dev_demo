<?php
global $user;
$the_m_id = $data['m_id'];
?>

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
	</ul>

</div>

<?php
//Add md5 hash of url to refresh
$hash = md5(microtime());
?>
<div id="mural-iframe-content">
  <iframe id="mural-ly-iframe" frameborder='0' src='http://staging.mural.ly/embed/edgemakers/edgemakers/<?php print $the_m_id . '#' . $hash;?>' width=100% height=600'></iframe>
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
