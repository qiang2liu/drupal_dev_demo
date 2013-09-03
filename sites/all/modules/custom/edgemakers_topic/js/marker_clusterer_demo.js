(function ($) {

// @link http://www.tdmarketing.co.nz/blog/2011/03/09/create-marker-with-custom-labels-in-google-maps-api-v3/
// Define the overlay, derived from google.maps.OverlayView
function Label(opt_options) {
     // Initialization
     this.setValues(opt_options);
 
     // Here go the label styles
     var span = this.span_ = document.createElement('span');
     span.style.cssText = 'position: relative; left: -50%; top: -35px; ' +
                          'white-space: nowrap;color:#ffffff;' +
                          'padding: 2px;font-family: Arial; font-weight: bold;' +
                          'font-size: 12px;';
 
     var div = this.div_ = document.createElement('div');
     div.appendChild(span);
     div.style.cssText = 'position: absolute; display: none';
};
 
Label.prototype = new google.maps.OverlayView;
 
Label.prototype.onAdd = function() {
     var pane = this.getPanes().overlayImage;
     pane.appendChild(this.div_);
 
     // Ensures the label is redrawn if the text or position is changed.
     var me = this;
     this.listeners_ = [
          google.maps.event.addListener(this, 'position_changed',
               function() { me.draw(); }),
          google.maps.event.addListener(this, 'text_changed',
               function() { me.draw(); }),
          google.maps.event.addListener(this, 'zindex_changed',
               function() { me.draw(); })
     ];
};
 
// Implement onRemove
Label.prototype.onRemove = function() {
     this.div_.parentNode.removeChild(this.div_);
 
     // Label is removed from the map, stop updating its position/text.
     for (var i = 0, I = this.listeners_.length; i < I; ++i) {
          google.maps.event.removeListener(this.listeners_[i]);
     }
};
 
// Implement draw
Label.prototype.draw = function() {
     var projection = this.getProjection();
     var position = projection.fromLatLngToDivPixel(this.get('position'));
     var div = this.div_;
     div.style.left = position.x + 'px';
     div.style.top = position.y + 'px';
     div.style.display = 'block';
     div.style.zIndex = this.get('zIndex'); //ALLOW LABEL TO OVERLAY MARKER
     this.span_.innerHTML = this.get('text').toString();
};

var beaches = [
  ['Bondi Beach', -33.890542, 151.274856, 4],
  ['Coogee Beach', -33.923036, 151.259052, 5],
  ['Cronulla Beach', -34.028249, 151.157507, 3],
  ['Manly Beach', -33.80010128657071, 151.28747820854187, 2],
  ['Maroubra Beach', -33.950198, 151.259302, 1]
];

// End Define Label function

// Stores current opened infoWindow.
var currentInfoWindow = null;

/**
 * Create google map.
 *
 * @param object map
 *   Object of map options.
 * @return object
 *   On success returns gmap object.
 */
function gmap3ToolsCreateMap(map) {
  if (map.mapId === null) {
    alert(Drupal.t('gmap3_tools error: Map id element is not defined.'));
    return null;
  }

  // Create map.
  var mapOptions = map.mapOptions;
  mapOptions.center = new google.maps.LatLng(mapOptions.centerX, mapOptions.centerY);
  var gmap = new google.maps.Map(document.getElementById(map.mapId), mapOptions);
  
  // Store gmap in map element so it can be accessed later from js if needed.
  $('#' + map.mapId).data('gmap', gmap);

  // Try HTML5 geolocation.
  if (map.gmap3ToolsOptions.geolocation && navigator.geolocation) {
    navigator.geolocation.getCurrentPosition(function(position) {
      var pos = new google.maps.LatLng(position.coords.latitude, position.coords.longitude);
      gmap.setCenter(pos);
      gmap3ToolsCreateMarkers(map, gmap);
    }, function() {
      // Geolocation service failed.
      gmap3ToolsCreateMarkers(map, gmap);
    });
  }
  else {
    // Do not use geolocation or browser do not support geolocation.
    gmap3ToolsCreateMarkers(map, gmap);
  }

  return gmap;
}

/**
 * Create markers.
 *
 * @param {object} map
 *   gmap3 tools object.
 * @param {Map} gmap
 *   Google Map object.
 */
function gmap3ToolsCreateMarkers(map, gmap) {
  // Array for storing all markers that are on this map.
  var gmapMarkers = [];

  // Create markers for this map.
  var markersNum = 0;
  $.each(map.markers, function (i, markerData) {

    var markerLat = markerData.lat;
    var markerLng = markerData.lng;

    // Is marker relative from map center?
    if (markerData.markerOptions.relative) {
      var pos = gmap.getCenter();
      markerLat = pos.lat() + markerLat;
      markerLng = pos.lng() + markerLng;
    }

    var marker = new google.maps.Marker({
      position: new google.maps.LatLng(markerLat, markerLng),
      map: gmap
    });

    // Marker options.
    var markerOptions = $.extend({}, map.markerOptions, markerData.markerOptions);
    marker.setOptions(markerOptions);

    // Title of marker.
    if (typeof markerData.title !== 'undefined') {
      marker.setTitle(markerData.title);
    }

    // If marker has content then create info window for it.
    if (typeof markerData.content !== 'undefined') {
      google.maps.event.addListener(marker, 'click', function(e) {
        if (map.gmap3ToolsOptions.closeCurrentInfoWindow &&  currentInfoWindow != null) {
          currentInfoWindow.close();
        }
        var infoWindowOptions = map.infoWindowOptions;
        infoWindowOptions.position = marker.getPosition();
        infoWindowOptions.content = markerData.content;
        infoWindowOptions.map = gmap;
        currentInfoWindow = new google.maps.InfoWindow(infoWindowOptions);
        
        
        ///
        $("#demo5").paginate({
				count 		: 10,
				start 		: 1,
				display     : 7,
				border					: true,
				border_color			: '#fff',
				text_color  			: '#fff',
				background_color    	: 'black',	
				border_hover_color		: '#ccc',
				text_hover_color  		: '#000',
				background_hover_color	: '#fff', 
				images					: false,
				mouse					: 'press',
				onChange     			: function(page){
											$('._current','#paginationdemo').removeClass('_current').hide();
											$('#p'+page).addClass('_current').show();
										  }
			});
        ///
        
        
      });
    }

    // Draggable markers with lat and lng form items support.
    if (markerOptions.draggable && (markerOptions.dragLatElement || markerOptions.dragLngElement)) {
      var $latItem = $(markerOptions.dragLatElement);
      var $lngItem = $(markerOptions.dragLngElement);
      google.maps.event.addListener(marker, 'drag', function() {
        $latItem.val(marker.getPosition().lat());
        $lngItem.val(marker.getPosition().lng());
      });
    }
    
    var label = new Label({
        map: gmap
      });
      label.set('zIndex', 1234);
      label.bindTo('position', marker, 'position');
      label.set('text', markerData.label);
    //label.bindTo('text', marker, 'position');

    ++markersNum;
    gmapMarkers.push(marker);
  });

  if (markersNum) {
    // If we are centering markers on map we should move map center near makers.
    // We are doing this so first map center (on first display) will be near
    // map center when all markers are displayed - we will avoid map move
    // when map displays markers.
    // @todo - this can be more smarter - first get exact center from markers
    // and then apply it.
    if (map.gmap3ToolsOptions.defaultMarkersPosition !== 'default') {
      map.mapOptions.center = new google.maps.LatLng(map.markers[0].lat, map.markers[0].lng);
    }

    // Default markers position on map.
    if (map.gmap3ToolsOptions.defaultMarkersPosition === 'center') {
      gmap3ToolsCenterMarkers(gmap, map.markers, markersNum);
    }
    else if (map.gmap3ToolsOptions.defaultMarkersPosition === 'center zoom') {
      var bounds = new google.maps.LatLngBounds();
      for (var i = 0; i < markersNum; i++) {
        var marker = map.markers[i];
        bounds.extend(new google.maps.LatLng(marker.lat, marker.lng));
      }
      gmap.fitBounds(bounds);
    }
  }

  // Store markers in map element so it can be accessed later from js if needed.
  $('#' + map.mapId).data('gmapMarkers', gmapMarkers);
}

/**
 * Center markers on map.
 */
function gmap3ToolsCenterMarkers(map, markers, markersNum) {
  var centerLat = 0;
  var centerLng = 0;
  $.each(markers, function (i, markerData) {
    centerLat += parseFloat(markerData.lat);
    centerLng += parseFloat(markerData.lng);
  });
  centerLat /= markersNum;
  centerLng /= markersNum;
  map.setCenter(new google.maps.LatLng(centerLat, centerLng));
}

/**
 * Attach gmap3_tools maps.
 */
Drupal.behaviors.gmap3_tools = {
  attach: function (context, settings) {
    // Create all defined google maps.
    if (Drupal.settings.gmap3_tools === undefined) {
      return;
    }
    $.each(Drupal.settings.gmap3_tools.maps, function(i, map) {
      // @todo - we should really use css selector here and not only element id.
      var $mapElement = $('#' + map.mapId, context);
      if ($mapElement.length === 0 || $mapElement.hasClass('gmap3-tools-processed')) {
        return;
      }
      $mapElement.addClass('gmap3-tools-processed');
      var gmap = gmap3ToolsCreateMap(map);
    });
  }
};

})(jQuery);
