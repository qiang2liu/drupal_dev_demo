(function ($) {

Drupal.behaviors.muralRefreshAjax = {
  attach: function (context){

    changeTitleAfterSetting();
    
    _refreshStudioGalleryMural();
  
  }
}

})(jQuery);


//Drupal.CTools.AJAX.refreshElements = function() {
//  
//  var url = '?q=/mural/ajax/refresh-elements';
//  
//  try {
//    jQuery.ajax({
//      type: "POST",
//      url: url,
//      data: { 'js': 1, 'ctools_ajax': 1},
//      global: true,
//      success: Drupal.CTools.AJAX.respond,
//      error: function(XMLHttpRequest, textStatus, errorThrown) {
//        alert("Status: " + textStatus);
////        Drupal.CTools.AJAX.handleErrors(XMLHttpRequest, url);
//      },
//      complete: function() {
//      },
//      dataType: 'json'
//    });
//  }
//  catch (err) {
//    alert('An error occurred while attempting to process ' + url);
//    return false;
//  }
//  
//  jQuery("#mural-top-bar #mural-title").addClass("Title changed");
// 
//  return false;
//};