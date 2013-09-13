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
  
//  jQuery("#modalContent").addClass("mural-settings-form-class");
//  alert("load.");
//  getLocationElement();

//  showInviteEmailBox();
  
});

function getLocationElement() {
  jQuery("#edit-field-city").attr("style", "color: red;");
  console.log(jQuery("#edit-field-city").attr("class"));
}

jQuery(function() {
  jQuery('#modalContent').ajaxComplete(function() {
    jQuery("#modalContent").addClass("mural-settings-form-class");
  });
});


jQuery(function () {
  if (!Drupal.Ajax) return;
  Drupal.Ajax.plugins.yourAction = function (hook, args) {
    console.log(hook);
    console.log(args);
    if (hook == 'message' && args.data.form_id == 'your_form' && args.data.status == true) {
      // args.data.status is true only after validation clears
      // Your js here
    }
  };
});