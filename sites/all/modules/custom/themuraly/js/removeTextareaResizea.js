/**
 * @file Remove textarea resize attribute
 */
 
//form-textarea-wrapper resizable textarea-processed resizable-textarea
jQuery(document).ready(function(){
  jQuery(".form-item-body-und-0-value .form-textarea-wrapper").removeClass("resizable");
  jQuery(".form-item-body-und-0-value .form-textarea-wrapper").removeClass("textarea-processed");
  jQuery(".form-item-body-und-0-value .form-textarea-wrapper").removeClass("resizable-textarea");
  
//  jQuery("#edit-field-city").attr("style", "color: red;");
//  console.log(jQuery("#edit-field-city").attr("class"));
  
  jQuery(".div.modal-forms-modal-content.modal-header").css({
    "top": "35px",
    "right": "72px"
  });
  
//  getLocationElement();
  
});

function getLocationElement() {
  jQuery("#edit-field-city").attr("style", "color: red;");
  console.log(jQuery("#edit-field-city").attr("class"));
}

