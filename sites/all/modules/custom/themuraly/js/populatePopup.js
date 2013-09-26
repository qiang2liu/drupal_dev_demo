/**
 * Positions the suggestions popup and starts a search
 */
Drupal.jsAC.prototype.populatePopup = function () {
  // Show popup
  if (this.popup) {
    jQuery(this.popup).remove();
  }
  this.selected = false;
  this.popup = document.createElement('div');
  this.popup.id = 'autocomplete';
  this.popup.owner = this;
  var inputPosition = jQuery(this.input).position();
  var inputWrapperPosition = jQuery('div#'+jQuery(this.input).attr('id')+'-wrapper').position();
  jQuery(this.input).parent().css('position','relative');
  jQuery(this.popup).css({
  	position: 'absolute',
   top : '-50px',
   height:'50px',
   overflow:'auto',
   background: '#fff',
//    marginLeft: (inputPosition.left-inputWrapperPosition.left)+'px',
    width: (this.input.offsetWidth - 4) +'px',
    display: 'none'
  });
  jQuery(this.input).before(this.popup);

  // Do search
  this.db.owner = this;
  this.db.search(this.input.value);
};

jQuery("#modalContent").addClass("mural-settings-form-class-popup");