  (function ($, Drupal) {
        function init () {
          
          fte_ini_google_map(2.050357799709012, 19.992198944091797);
        }
        Drupal.behaviors.map_canvas = {
          attach: init
        };
        
        ////
        
         var fte_map_points_google_map = '';
  // set a global marker array, prepare for batch operation to the points.
  var fte_map_points_markersArray = [];
  var fte_map_points_the_openwindow = null;
 
  function fte_map_set_point_content(the_marker) {
    var content = '';
    var the_position = the_marker.getPosition();
    var the_trip_point_lat = the_position.lat();
    var the_trip_point_lng = the_position.lng();
    content = "<div class='trip_oint_info' > <div>latitude : "+the_trip_point_lat + 
      "</div><div>longitude : " + the_trip_point_lng +"</div></div>";
  
    return content;
  }
 
  

  function fte_map_set_the_points(map,the_points) {
    
    $.each(the_points, function (i,p){
      var the_location = new google.maps.LatLng(p.lat, p.lon);
      var marker = new google.maps.Marker({
        position: the_location, 
        map: map,
        icon: p.icon,
        title: p.title
      });
      var marker_o = {'marker' : marker , 'mid' : p.nid};
      fte_map_points_markersArray.push(marker_o);
      fte_map_map_setup_Listener(marker, map);
      
    });
   
  }
  
  function fte_map_map_openwin(marker, map, contentString) {
    var winfo_exist;
    winfo_exist = 0;
    
    if (fte_map_points_the_openwindow!= null && typeof(fte_map_points_the_openwindow.close) == 'function'){
      winfo_exist = 1;
      fte_map_points_the_openwindow.close();
    }
  
    if (winfo_exist == 0) {
      fte_map_points_the_openwindow = new google.maps.InfoWindow({content: contentString});
    }
    else {
      fte_map_points_the_openwindow.setContent(contentString);
    }
    fte_map_points_the_openwindow.open(map,marker);
  }
  function fte_map_map_setup_Listener(marker,map) {   
      google.maps.event.addListener(marker, 'click',
        function(){
         
          // create openwindow or set openwindow content by ajax
          // first , find the point id
          var the_point_id = 0;
          $.each(fte_map_points_markersArray,function(i, n){
            if (marker == n.marker) {
              the_point_id = n.mid;
              // break the each
              return false;  
            }
          }); 
          if (the_point_id > 0) {
              
              fte_map_map_openwin(marker, map,Drupal.settings.the_challenge_points[the_point_id].info);
            
           
          }
          else {
            alert(Drupal.t('can not find this place.'));
          }
         

        }
      );
    
  }
  
  
  function fte_ini_google_map(original_lat, original_long, mapdata) {
    // step 1. create map , set the center
    original_lat = (typeof(original_lat)== "undefined") ? "2.050357799709012" : original_lat;
    original_long = (typeof(mylon)== "undefined") ? "19.992198944091797" : original_long;
    var myLatlng = new google.maps.LatLng(original_lat,original_long);
    var myOptions;
    if (Drupal.settings.fte_map_map_block == 1) {
      myOptions = {
        zoom: 2,
        center: myLatlng,
        disableDoubleClickZoom: true,
        navigationControl: false,
        
        mapTypeId: google.maps.MapTypeId.ROADMAP
      };
    }
    else {
      myOptions = {
        zoom: 1,
        center: myLatlng,
        disableDoubleClickZoom: true,
        navigationControl: true,
        navigationControlOptions: {
          style: google.maps.NavigationControlStyle.SMALL  
        },
        mapTypeId: google.maps.MapTypeId.ROADMAP
      };
    }
    var map = new google.maps.Map(document.getElementById("map_canvas"), myOptions);
    fte_map_points_google_map = map;

   
     //step2. put the existing points to the map
     
    var the_points = '';
    the_points = Drupal.settings.the_challenge_points;
    
    if ( the_points !='' ) {
      fte_map_set_the_points(map,the_points);
    }
  }
  
 
        
        
        /////
        
        
        
        
        
        
        
      }(jQuery, Drupal));
      
      
     