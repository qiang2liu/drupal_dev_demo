<?php
/**
 * get items for carousel block to display
 */
function edgemakers_topic_carousel_items() {
  $renderable_array = array();
  $nodes = node_load_multiple(array(), array('type'=>'carousel_item'));
  foreach ($nodes as $node) {
		$topic = field_get_items('node', $node, 'field_carousel_item_topic');
		$image = field_get_items('node', $node, 'field_carousel_item_image');
		$renderable_array[] = array(
			'nid'=>$row->nid,
      'title'=>$row->title,
      'description'=>$row->description,
			'topicid'=>$topic[0]['target_id'],
			'imageurl'=>file_create_url($image[0]['uri']),
		);
  }
  return $renderable_array;
}
/**
 * get items for wicked problems block to display
 */
function edgemakers_topic_problems_items() {
  $terms = array();
  $vocabulary = taxonomy_vocabulary_machine_name_load('challenges_vocabulary');
  $oterms = taxonomy_get_tree($vocabulary->vid);
  foreach($oterms as $term) {
    $tid = $term->tid;
    $term = taxonomy_term_load($tid);
		$topic = field_get_items('taxonomy_term', $term, 'field_challenge_topic');
    $terms[$tid] = array(
      'tid' => $tid,
      'name' => $term->name, 
      'topicid' => $topic[0]['target_id'],
    );
  }
  return $terms;
}
