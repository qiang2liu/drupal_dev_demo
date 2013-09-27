(function($) {

Drupal.behaviors.muralRefreshAjax = {
  attach: function (context){
    
    changeTitleAfterSetting();
    
    _refreshStudioGalleryMural();
    
    parent.jQuery("#iframe-topic-gmap").attr("src", "?q=edgemakers/topic/gmap");
    
    jQuery('#my-mural-list').load("?q=mural/get/list/ajax", function(){

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
    
      jQuery('ul#mural-list li a').each(function( index ) {
        jQuery(this).bind('click', function(){
          if (jQuery("#mural-region").length !== 0) {
            var source = jQuery(this).attr("href");
            jQuery("#mural-back-to-dashboard").show();
            showMuralDialog(source);
          }
          return false;
        });
      });
      
    });
  
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