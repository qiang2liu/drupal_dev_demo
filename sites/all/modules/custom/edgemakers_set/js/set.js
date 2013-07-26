function edgemakers_set_fields_update() {
  var forms = document.getElementsByClassName('node-edgemakers_set-form');
  if(forms.length == 0) {
    setTimeout(edgemakers_set_fields_update, 1000);
    return false;
  } else {
    var field_suffix = forms[0].id.substr(24);
    var index  = document.getElementById('edit-field-set-type-und'+field_suffix).selectedIndex;
    edgemakers_set_togglefields(index, field_suffix);
    document.getElementById('edit-field-set-type-und'+field_suffix).onchange = function() {
      var index  = this.selectedIndex;
      edgemakers_set_togglefields(index, field_suffix);
    };
  }
}
function edgemakers_set_togglefields(index, field_suffix) {
  var startIndex = 0;
  var terms = document.getElementById('edit-field-set-type-und'+field_suffix).options; 
  if(terms.length == 7) {
    startIndex = 1;
  }
  var term = terms[document.getElementById('edit-field-set-type-und'+field_suffix).selectedIndex].text;
  var labels = document.getElementsByTagName('label');
  for(var i=0; i<labels.length; i++) {
    var label = labels[i];
    var forItem = label.getAttribute('for');
    if(forItem == 'edit-title'+field_suffix) {
      label.innerHTML = label.innerHTML.replace(/.*Title/, term + ' Title');
    } else if(forItem == 'edit-field-set-url-und-0') {
      if(index == (startIndex + 1)) {
        label.innerHTML = 'Mural.ly Template';
        document.getElementById('edit-field-set-url-und-0-url').placeholder = 'Leave blank for No Template';
      } else {
        label.innerHTML = term + ' URL';  
        document.getElementById('edit-field-set-url-und-0-url').placeholder = '';   
      }
    }
  }
  if(index == (startIndex + -1)) {
    document.getElementsByClassName('form-item-title'+field_suffix)[0].style.display = 'none';
    document.getElementById('edit-body'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-url'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-image'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-withthumbnail'+field_suffix).style.display = 'none';
    document.getElementById('edit-actions'+field_suffix).style.display = 'none';
  } else {
    document.getElementsByClassName('form-item-title'+field_suffix)[0].style.display = 'block';
    //body only display for text type
    if(index == (startIndex + 2)) document.getElementById('edit-body'+field_suffix).style.display = 'block';
    else document.getElementById('edit-body'+field_suffix).style.display = 'none';
    //url only hide for text and topic type
    if(index != (startIndex) && index != (startIndex + 2) && index != (startIndex + 3)) document.getElementById('edit-field-set-url'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-url'+field_suffix).style.display = 'none';
    //topic dropdownlist only display for topic type
    if(index == (startIndex + 3)) document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'none';
    //image only display for Image type
    if(index == (startIndex)) document.getElementById('edit-field-set-image'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-image'+field_suffix).style.display = 'none';
    //image only display for inspiration and showcase type
    if(index == (startIndex + 4) || index == (startIndex + 5)) document.getElementById('edit-field-set-withthumbnail'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-withthumbnail'+field_suffix).style.display = 'none';
    document.getElementById('edit-actions'+field_suffix).style.display = 'block';
  }
}