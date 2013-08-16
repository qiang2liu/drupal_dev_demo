<?php
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

  <span class="close-mural-dialog" onclick='window.parent.closeFromIframe();'> X </span>
  <span id="mural-title">
		<?php echo $data['node']->title; ?>
  </span>
	<ul id="mural-region-nav">
		<li>
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
			echo $delete_link; ?>
		</li>
		<li>
			<?php print_r($data['seturl'])?>
		</li>
		<li>
		<?php
		  $img_duplicate = array(
        'path' => drupal_get_path('theme' , 'newfteui') . '/images/iconMuralDuplicate.png',
      );
			$duplicate_link = l(t('Duplicate'),
				'mural/create/' . $the_m_id . '/' . $data['node']->nid
//         array(
//           'attributes' => array(
//             'class' => array('mural-nav-link'),
//           ),
//         )
			);
			echo $duplicate_link;
		?>
		</li>
	</ul>

</div>

<div>
  <iframe id="mural-ly-iframe" frameborder='0' src='http://staging.mural.ly/embed/edgemakers/edgemakers/<?php print $the_m_id;?>' width=100% height=600'></iframe>
</div>
<script>
  //jQuery("#mural-ly-iframe").attr("src", source);
  jQuery("#mural-ly-iframe").attr("width", jQuery(window).width());
  jQuery("#mural-ly-iframe").attr("height", jQuery(document).height() - 40);
</script>
