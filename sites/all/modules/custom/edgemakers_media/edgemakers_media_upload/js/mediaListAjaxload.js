/**
 * @file 
 * hook Drupal.behaviors() js for reload.
 */
jQuery(document).ready(function(){
	(function ($) {
	
	Drupal.behaviors.mediaListAjaxload = {
	  attach: function (context){
	
	    media_ajax_load_list();
	    _refreshStudioGallery();
	  
	  }
	}
	
	})(jQuery);
});