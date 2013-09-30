/**
 * @file 
 * hook Drupal.behaviors() js for reload.
 */

(function ($) {

Drupal.behaviors.mediaListAjaxload = {
  attach: function (context){

    media_ajax_load_list();
    _refreshStudioGallery();
  
  }
}

})(jQuery);
