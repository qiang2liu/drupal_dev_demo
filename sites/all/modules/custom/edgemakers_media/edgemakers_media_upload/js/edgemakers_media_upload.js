
/**
 * AJAX responder command to dismiss the modal.
 */
(function ($) {
  Drupal.CTools = Drupal.CTools || {};
  Drupal.CTools.Modal = Drupal.CTools.Modal || {};
  Drupal.CTools.Modal.media_list_reload = function(command) {
    alert("media list reload?");
    media_ajax_load_list();
  }
});

jQuery(document).ready(function(){
  media_ajax_load_list();
});

function media_ajax_load_list() {
console.log("media_ajax_load_list loaded.");
/*jQuery.ajax({
  url: "?q=edgemarkers/media/get/list/ajax",
  type: 'GET',
  sucess(): {
    jQuery('ul#media-list li a').each(function( index ) {

      var nid = jQuery(this).attr('id').substring(11);
      //alert("Node nid:" + nid);
      var ajaxUrl = '?q=edgemakers/stage/api/set/info/ajax/' + nid;
      var ajaxContent;
      
      jQuery(this).bind('click', function(){

        //openAjaxLoad("ajaxload");
        
        jQuery.ajax({
          url: ajaxUrl,
          type: "GET",
          success: function(data) {

            jQuery("#stage-set-view").html(data);
            jQuery("#set-view-region").show();
            jQuery("#stage-set-list").hide();
            jQuery("#back-set-list").show();
            
            return false;

          },
          error :function(){
            jQuery("#stage-set-view").html("Load set data error.");
            return false;
          }
        });
        
        return false;

      });
    });
  }
  
});
*/
  jQuery('#my-media-list').load("?q=edgemarkers/media/get/list/ajax", function(){
	jQuery('.media .has-child em').bind('click', function(){
		jQuery(this).parents('.media').find('.item-list').toggle();
	});
    jQuery('ul#media-list li a').each(function( index ) {

      var nid = jQuery(this).attr('id').substring(11);
      //alert("Node nid:" + nid);
      var ajaxUrl = '?q=edgemakers/stage/api/set/info/ajax/' + nid;
      var ajaxContent;
      
      jQuery(this).bind('click', function(){

        //openAjaxLoad("ajaxload");
        
        jQuery.ajax({
          url: ajaxUrl,
          type: "GET",
          success: function(data) {

            jQuery("#stage-set-view").html(data);
            jQuery("#set-view-region").show();
            jQuery("#stage-set-list").hide();
            jQuery("#back-set-list").show();
            
            return false;

          },
          error :function(){
            jQuery("#stage-set-view").html("Load set data error.");
            return false;
          }
        });
        
        return false;

      });
    });
  });
}