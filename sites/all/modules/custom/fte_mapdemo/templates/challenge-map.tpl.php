
stars :  main grand challenges ;<br/> 
blue dots: instance challenge ; <br/>
red dots: project
<br/>
<div id="map_canvas" style="width:420px;height:400px"></div>
 <script>
   (function ($, Drupal) {
     function init () {
       fte_ini_google_map(2.050357799709012, 19.992198944091797);
     }
     Drupal.behaviors.map_canvas = {
       attach: init
     };
     
   }(jQuery, Drupal));
   
   
  </script>
  