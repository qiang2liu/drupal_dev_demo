(function ($, Drupal) {
    edgemakers_box_fields_update();
    function edgemakers_box_fields_update() {
      var forms = $('.node-edgemakers_box-form');
      if(forms.length == 0) {
        setTimeout(edgemakers_box_fields_update, 1000);
        return false;
      } else {
        var field_suffix = forms[0].id.substr(24);
        var index  = $('#edit-field-box-type-und'+field_suffix)[0].selectedIndex;
        edgemakers_box_togglefields(index, field_suffix);
        $('#edit-field-box-type-und'+field_suffix).bind('change', function() {
          var index  = this.selectedIndex;
          edgemakers_box_togglefields(index, field_suffix);
        });
      }
    }
    function edgemakers_box_togglefields(index, field_suffix) {
      var startIndex = 0;
      var terms = $('#edit-field-box-type-und'+field_suffix)[0].options; 
      if(terms.length == 7) {
        startIndex = 1;
      }
      var term = terms[$('#edit-field-box-type-und'+field_suffix)[0].selectedIndex].text;
      $('label[for="edit-title'+field_suffix+'"]')[0].innerHTML = $('label[for="edit-title'+field_suffix+'"]')[0].innerHTML.replace(/.*Title/, term + ' Title');
      if(index == (startIndex + 1)) {
        $('label[for="edit-field-box-url-und-0"]')[0].innerHTML = 'Mural.ly Template';
        document.getElementById('edit-field-box-url-und-0-url').placeholder = 'Leave blank for No Template';
      } else {
        $('label[for="edit-field-box-url-und-0"]')[0].innerHTML = term + ' URL';  
        document.getElementById('edit-field-box-url-und-0-url').placeholder = '';   
      }
      if(index == (startIndex + -1)) {
        $('.form-item-title'+field_suffix).css('display', 'none');
        $('#edit-body'+field_suffix).css('display', 'none');
        $('#edit-field-box-url'+field_suffix).css('display', 'none');
        $('#edit-field-box-image'+field_suffix).css('display', 'none');
        $('#edit-field-box-withthumbnail'+field_suffix).css('display', 'none');
        $('#edit-actions'+field_suffix).css('display', 'none');
      } else {
        $('.form-item-title'+field_suffix).css('display', 'block');
        if(index == (startIndex + 2)) $('#edit-body'+field_suffix).css('display', 'block');
        else $('#edit-body'+field_suffix).css('display', 'none');
        if(index != (startIndex + 2)) $('#edit-field-box-url'+field_suffix).css('display', 'block');
        else $('#edit-field-box-url'+field_suffix).css('display', 'none');
        if(index == (startIndex + 0)) $('#edit-field-box-image'+field_suffix).css('display', 'block');
        else $('#edit-field-box-image'+field_suffix).css('display', 'none');
        if(index > (startIndex + 3)) $('#edit-field-box-withthumbnail'+field_suffix).css('display', 'block');
        else $('#edit-field-box-withthumbnail'+field_suffix).css('display', 'none');
        $('#edit-actions'+field_suffix).css('display', 'block');
      }
    }
})(jQuery,Drupal);