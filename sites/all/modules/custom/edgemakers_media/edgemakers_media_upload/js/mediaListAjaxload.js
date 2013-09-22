/**
 * @file 
 * hook Drupal.behaviors() js for reload.
 */

(function ($) {

Drupal.behaviors.mediaListAjaxload = {
  attach: function (context){

    _refreshStudioGallery();
  
  }
}

})(jQuery);
