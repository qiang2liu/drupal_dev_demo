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
<div>

	<ul id="mural-region-nav">
		<li>
			<?php
			$delete_link = l(t('Delete'), 
				'mural/delete/' . $data['node']->nid,
				array(
					'attributes' => array(
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
			$duplicate_link = l(t('Duplicate'), 
				'mural/create/' . $the_m_id . '/' . $data['node']->nid
			);
			echo $duplicate_link;
		?>
		</li>
		<li>
			<span class="close-mural-dialog" onclick='window.parent.closeFromIframe();'> X </span>
		</li>
		<li style="width: 50%;text-align: right;">
			<?php echo $data['node']->title; ?>
		</li>
	</ul>

</div>


<div>
<iframe id="mural-ly-iframe" frameborder='0' src='http://staging.mural.ly/embed/edgemakers/edgemakers/<?php print $the_m_id;?>' width=100% height=600'></iframe>

</div>