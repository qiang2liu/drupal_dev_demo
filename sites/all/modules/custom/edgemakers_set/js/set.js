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
    document.getElementById('edit-field-set-murally-type-und-0').onchange = function() {
      edgemakers_set_murallyfield(1, field_suffix);
    };
    document.getElementById('edit-field-set-murally-type-und-1').onchange = function() {
      edgemakers_set_murallyfield(1, field_suffix);
    };
    document.getElementById('edit-field-set-murally-type-und-2').onchange = function() {
      edgemakers_set_murallyfield(1, field_suffix);
    };
  }
}
function edgemakers_set_togglefields(index, field_suffix) {
  var startIndex = 0;
  var terms = document.getElementById('edit-field-set-type-und'+field_suffix).options; 
  if(terms.length == 12) {
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
        label.innerHTML = '';
      } else {
        label.innerHTML = term + ' URL';
      }
    } else if(forItem == 'edit-field-set-image-und-0') {
      if(index == startIndex) {
        label.innerHTML = 'Image';
      } else {
        label.innerHTML = term + ' Thumbnail';
      }
    }
  }
  if(index == (startIndex + -1)) {
    document.getElementsByClassName('form-item-title'+field_suffix)[0].style.display = 'none';
    document.getElementById('edit-body'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-url'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-murally-type'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-survey'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-image'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-set-document'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-teacher-notes'+field_suffix).style.display = 'none';
    document.getElementById('edit-actions'+field_suffix).style.display = 'none';
  } else {
    document.getElementsByClassName('form-item-title'+field_suffix)[0].style.display = 'block';
    //body only display for text, video with comments and video with Q&A type
    if(index == (startIndex + 2) || index == (startIndex + 6) || index == (startIndex + 7)) document.getElementById('edit-body'+field_suffix).style.display = 'block';
    else document.getElementById('edit-body'+field_suffix).style.display = 'none';
    //url only display for inspiration, showcase, video with comments, video with Q&A and video type
    if(index == (startIndex + 4) || index == (startIndex + 5) || index == (startIndex + 6) || index == (startIndex + 7) || index == (startIndex + 9)) document.getElementById('edit-field-set-url'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-url'+field_suffix).style.display = 'none';
    //murally type only display for mural type
    if(index == (startIndex + 1)) document.getElementById('edit-field-set-murally-type'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-murally-type'+field_suffix).style.display = 'none';
    edgemakers_set_murallyfield(index == (startIndex + 1), field_suffix);
    //topic dropdownlist only display for topic type
    if(index == (startIndex + 3)) document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-topic'+field_suffix).style.display = 'none';
    //survey dropdownlist only display for survey & assessment type
    if(index == (startIndex + 8)) document.getElementById('edit-field-set-survey'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-survey'+field_suffix).style.display = 'none';
    //image only display for Image, Text, Topic Page, Survey & Assessment, Document type
    if(index != (startIndex + 1)) document.getElementById('edit-field-set-image'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-image'+field_suffix).style.display = 'none';
    //document only display for document type
    if(index == (startIndex+10)) document.getElementById('edit-field-set-document'+field_suffix).style.display = 'block';
    else document.getElementById('edit-field-set-document'+field_suffix).style.display = 'none';
    document.getElementById('edit-field-teacher-notes'+field_suffix).style.display = 'block';
    document.getElementById('edit-actions'+field_suffix).style.display = 'block';
  }
}
function edgemakers_set_murallyfield(ismurally, field_suffix) {
  var elUrl = document.getElementById('edit-field-set-url'+field_suffix);
  if(ismurally) {
    var elEmptyMural = document.getElementById('edit-field-set-murally-type-und-0');
    var elSharedMural = document.getElementById('edit-field-set-murally-type-und-1');
    var elTemplateMural = document.getElementById('edit-field-set-murally-type-und-2');
    if(elSharedMural.checked || elTemplateMural.checked) {
      elUrl.parentNode.removeChild(elUrl);
      document.getElementsByClassName('form-item-field-set-murally-type-und')[elSharedMural.checked ? 2 : 3].appendChild(elUrl);
      elUrl.style.display = 'block';
    } else if(elEmptyMural.checked) {
      elUrl.style.display = 'none';
    }
  } else {
    if(elUrl.parentNode.className) {
      var elMurally = document.getElementById('edit-field-set-murally-type'+field_suffix);
      elUrl.parentNode.removeChild(elUrl);
      elMurally.parentNode.insertBefore(elUrl, elMurally);
    }
  }
}