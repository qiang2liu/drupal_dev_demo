/**
 * @file edgemakers_stage.js
 */

  // Load stage list on front page.
  // stage ajax.
  //alert(jQuery(".stage-selector").length);
  if (jQuery(".stage-selector").length !== 0) {
    jQuery.ajax({
      url: '?q=edgemakers/stage/api/list',
      dataType: 'json',
      type : 'GET',
      success : function(data){
        for(var i=0; i<data.length; i++){
          console.log(data[i]);
          var sta_url = '<a class="ctools-use-modal" href="#" onclick="set_ajax_load_by_stage(' + data[i].nid + ');return true;">' + data[i].title + '</a>';
          jQuery('.stage-box').append('<div class="stage-item">' + sta_url + '</div>');
        }
      },
      error :function(){
        alert('An error occurs when getting the stage sets!')
      }
    });
  }
  
  function set_ajax_load_by_stage($stage_id) {
    //jQuery("#ajax-target").load("?q=edgemarkers/stage/get/set/ajax/" + $stage_id);
    jQuery('#stage-set-list').load("?q=edgemarkers/stage/get/set/ajax/" + $stage_id);
  }