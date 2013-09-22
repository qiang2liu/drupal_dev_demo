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