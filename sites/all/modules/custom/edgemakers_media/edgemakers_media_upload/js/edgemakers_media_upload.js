jQuery(document).ready(function(){
  media_ajax_load_list();
  //Drupal.behaviors.mediaListAjaxload();
});


/**
 * Note: Change it should sync to mediaListAjaxLoad.js
 */
function media_ajax_load_list() {

  jQuery('#my-media-list').load("?q=edgemarkers/media/get/list/ajax", function(){
    
    console.log("media_ajax_load_list loaded.");
    
  	jQuery('.toolbar-item').each(function(){
  		var self = jQuery(this);
  		
  		if(self.children().first().hasClass('has-child')){
  			self.find('h4>em').bind('click', function(){
  				if(!self.find('.item-list').hasClass('active')){
  					jQuery('.toolbar-item').find('.item-list').removeClass('active');
  					self.find('.item-list').addClass('active')
  				}
  			})
  		}
  	});

    jQuery('ul#media-list li a').each(function( index ) {

      var nid = jQuery(this).attr('id').substring(11);
      var title = jQuery(this).html();

      //alert("Node nid:" + nid);
      var ajaxUrl = '?q=edgemakers/media/info/ajax/' + nid;
      var ajaxContent;
      
      jQuery(this).bind('click', function(){

        //openAjaxLoad("ajaxload");
        
        jQuery.ajax({
          url: ajaxUrl,
          type: "GET",
          success: function(data) {

            jQuery("#stage-set-view").html(data);
            jQuery("#set-view-region").show();
            //jQuery("#stage-set-list").hide();
            jQuery("#back-to-dashboard").removeClass("hidden");
            jQuery("#back-to-dashboard").show();
            jQuery("#set-nav").hide();
            
            //Set title
            jQuery(".s-s-title h3").html(title);
            
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