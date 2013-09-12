/**
 * @file edgemakers stage manage js.
 */

function disp_confirm(id) {
  var r=confirm("Are you sure?");
  if (r==true)
  {
    var url = jQuery("#"+id).attr("href");
    window.location = url;
    return true;
  }
  else
    {
    return false;
  }
}