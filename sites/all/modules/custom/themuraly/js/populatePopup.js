/**
 * Positions the suggestions popup and starts a search
 */
Drupal.jsAC.prototype.populatePopup = function () {
	 alert('ok');
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
  jQuery(this.popup).css({
    marginTop: this.input.offsetHeight +'px',
//    marginLeft: (inputPosition.left-inputWrapperPosition.left)+'px',
    width: (this.input.offsetWidth - 4) +'px',
    display: 'none'
  });
  jQuery(this.input).before(this.popup);

  // Do search
  this.db.owner = this;
  this.db.search(this.input.value);
 
};