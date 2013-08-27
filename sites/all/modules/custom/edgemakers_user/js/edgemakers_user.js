function profileBackground() {
  jQuery(".form-item-preset-background label.option").bind("click", function(){
    jQuery('.form-item-preset-background label.option').removeClass('active');
    jQuery(this).addClass('active');
    changeBgImage(jQuery(this).find('span.image img')[0].src);
  });
  jQuery("#edgemakers-user-profile-settings-form .form-submit[value=SAVE]").bind("click", function(){
    var firstname = document.getElementById('edit-field-firstname-und-0-value').value;
    var lastname = document.getElementById('edit-field-lastname-und-0-value').value;
    if(firstname && lastname)
      jQuery('.user-profile .user-box h4').text(firstname +' '+ lastname);
  });
  jQuery('.form-item-field-profile-background-und-0 img').bind('click', function(){
    jQuery('.form-item-preset-background label.option').removeClass('active');
    jQuery('.form-item-preset-background input[type=radio]').attr('checked', false);
    changeBgImage(this.src);
  });
}
Drupal.behaviors.fileUpload = {
  attach: function(context, settings) {
    jQuery("body").ajaxComplete(function(event,request, settings){
      //if(window.location.pathname.match(/home/)) {
        if (form_build_id = settings.url.match(/file\/ajax\/field_profile_background\/und\/0\/(.*)$/)) {
          if(jQuery('[value="'+form_build_id[1]+'"]').closest('form').find('[id$=remove-button]').length == 0) {
            jQuery('.form-item-preset-background label.option').removeClass('active');
            changeBgImage();
          } else {
            jQuery('.form-item-field-profile-background-und-0 img').bind('click', function(){
              jQuery('.form-item-preset-background label.option').removeClass('active');
              jQuery('.form-item-preset-background input[type=radio]').attr('checked', false);
              changeBgImage(this.src);
            });
            jQuery('[value="'+form_build_id[1]+'"]').closest('form').find('[id$=remove-button]').bind('click', function(){
              if(jQuery('.form-item-preset-background label.option.active').length > 0) {
                changeBgImage(jQuery('.form-item-preset-background label.option.active span.image img')[0].src);
              } else {
                changeBgImage();
              }
            });
            jQuery('.form-item-field-profile-background-und-0 img')[0].click();
          }
        }
      //}  
    });
  }
};
Drupal.behaviors.autoUpload = {
  attach: function(context, settings) {
    jQuery('.form-item input.form-submit[value=Upload]').hide();
    jQuery('.form-item input.form-file').change(function() {
      var parent = jQuery(this).closest('.form-item');

      //setTimeout to allow for validation
      //would prefer an event, but there isn't one
      setTimeout(function() {
        if(!jQuery('.error', parent).length) {
          jQuery('input.form-submit[value=Upload]', parent).mousedown();
        }
      }, 100);
    });
  }
};
function changeBgImage(src) {
  if(src) {
    src = src.replace(/styles\/[^\/]*\/public\//, '');
    jQuery('html').css('background-image', 'url("'+src+'")', 'important');
  } else {
    jQuery('html').css('background-image', '');
  }
}