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
    jQuery("body").ajaxComplete(function(event,request, settings) {
      //if(window.location.pathname.match(/home/)) {
        if (form_build_id = settings.url.match(/file\/ajax\/field_profile_background\/und\/0\/(.*)$/)) {
          if(jQuery('[value="'+form_build_id[1]+'"]').closest('form').find('[id=edit-field-profile-background-und-0-remove-button]').length == 0) {
            jQuery('.form-item-preset-background label.option').removeClass('active');
            changeBgImage();
          } else {
            jQuery('.form-item-field-profile-background-und-0 img').bind('click', function(){
              jQuery('.form-item-preset-background label.option').removeClass('active');
              jQuery('.form-item-preset-background input[type=radio]').attr('checked', false);
              changeBgImage(this.src);
            });
            jQuery('[value="'+form_build_id[1]+'"]').closest('form').find('[id=edit-field-profile-background-und-0-remove-button]').bind('click', function(){
              if(jQuery('.form-item-preset-background label.option.active').length > 0) {
                changeBgImage(jQuery('.form-item-preset-background label.option.active span.image img')[0].src);
              } else {
                changeBgImage();
              }
            });
            jQuery('.form-item-field-profile-background-und-0 img')[0].click();
          }
        } else if (form_build_id = settings.url.match(/file\/ajax\/field_profile_picture\/und\/0\/(.*)$/)) {
          if(jQuery('[value="'+form_build_id[1]+'"]').closest('form').find('[id=edit-field-profile-picture-und-0-remove-button]').length == 0) {
            changeProfileImage();
          } else {
            if(jQuery('.form-item-field-profile-picture-und-0 img').length > 0) {
              changeProfileImage(jQuery('.form-item-field-profile-picture-und-0 img')[0].src);
            }
          }
        }
    //}  
    });
  }
};
function changeProfileImage(src) {
  var imgEl = jQuery('.user-profile-inner img');
  if(imgEl.length > 0) {
    if(src) {
      imgEl[0].src = src;
    } else {
      imgEl[0].src = '/sites/default/files/styles/thumbnail/public/default_avatar.png';
    }
  }
}
function changeBgImage(src) {
  if(src) {
    src = src.replace(/styles\/[^\/]*\/public\//, '');
    jQuery('html').css('background-image', 'url("'+src+'")', 'important');
  } else {
    jQuery('html').css('background-image', '');
  }
}