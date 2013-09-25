/**
 * @file edgemakers stage manage js.
 */

function disp_confirm(id) {
  var r=confirm("Are you sure?");
  //alert(r);
  if (r===true)
  {
    var url = jQuery("#"+id).attr("href");
    window.location = url;
    return true;
  }
  else
    {
    //alert("return false.");
    return false;
  }
}
(function ($) {
  Drupal.behaviors.confirm = {
    attach: function(context, settings) {
      var events =  $('.set-delete-link').clone(true).data('events');// Get the jQuery events.
      $('.set-delete-link').unbind('click'); // Remove the click events.
      $('.set-delete-link').click(function () {
        if (confirm('Are you sure?')) {
          $.each(events.click, function() {
            //this.handler(); // Invoke the click handlers that was removed.
          });
        }
        // Prevent default action.
        return false;
      });
    }
  }
})(jQuery);
