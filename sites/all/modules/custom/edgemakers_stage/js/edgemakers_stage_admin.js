/**
 * @file edgemakers stage manage js.
 */

function disp_confirm(id) {
  var r=confirm("Are you sure?");
  if (r==true)
  {
//    alert(id);
    var url = jQuery("#"+id).attr("href");
//    alert("You pressed OK!" + id);
    window.location = url;
    return true;
  }
  else
    {
//    alert("You pressed Cancel!");
    return false;
  }
}