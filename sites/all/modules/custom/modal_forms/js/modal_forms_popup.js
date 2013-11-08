/**
* Provide the HTML to create the modal dialog.
*/
Drupal.theme.prototype.ModalFormsPopup = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content modal-forms-modal-content">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title"></span>';
  html += '        <span class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body"></div></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';

  return html;
}

Drupal.theme.prototype.ModalFormsLogin = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content modal-forms-modal-content">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title"></span>';
  html += '        <span class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body login"></div></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';

  return html;
}

Drupal.theme.prototype.ModalFormsRegister = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content modal-forms-modal-content">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title"></span>';
  html += '        <span class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body register"></div></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';

  return html;
}

Drupal.theme.prototype.ModalFormsPassword = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content modal-forms-modal-content">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title"></span>';
  html += '        <span class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body password"></div></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';

  return html;
}

Drupal.theme.prototype.ModalFormsProfileSetting = function () {
  var html = '';

  html += '<div id="ctools-modal" class="popups-box ctools-profile-settings">';
  html += '  <div class="ctools-modal-content modal-forms-modal-content profilesetting">';
  html += '    <div class="popups-container">';
  html += '      <div class="modal-header popups-title">';
  html += '        <span id="modal-title" class="modal-title setting-title"></span>';
  html += '        <span class="popups-close close">' + Drupal.CTools.Modal.currentSettings.closeText + '</span>';
  html += '        <div class="clear-block"></div>';
  html += '      </div>';
  html += '      <div class="modal-scroll"><div id="modal-content" class="modal-content popups-body profilesetting"></div></div>';
  html += '    </div>';
  html += '  </div>';
  html += '</div>';

  return html;
}
/**
 * @file 
 * Ctools modal custom theme code.
 * 
 * Provide the HTML to create the modal dialog.
 */
Drupal.theme.prototype.ModalFormsMediaUpload = function () {

  var html = '';

  html += '<div id="ctools-modal" class="popups-box">';
  html += '  <div class="ctools-modal-content ctools-sample-modal-content">';
  html += '    <table cellpadding="0" cellspacing="0" id="ctools-face-table">';
  html += '      <tr>';
  html += '        <td class="popups-tl popups-border"></td>';
  html += '        <td class="popups-t popups-border"></td>';
  html += '        <td class="popups-tr popups-border"></td>';
  html += '      </tr>';
  html += '      <tr>';
  html += '        <td class="popups-cl popups-border"></td>';
  html += '        <td class="popups-c" valign="top">';
  html += '          <div class="popups-container">';
  html += '            <div class="modal-header popups-title">';
  html += '              <span id="modal-title" class="modal-title"></span>';
  html += '              <span class="popups-close"><a class="close" href="#">' + Drupal.CTools.Modal.currentSettings.closeText + '</a></span>';
  html += '              <div class="clear-block"></div>';
  html += '            </div>';
  html += '            <div class="modal-scroll"><div class="media-upload-close popups-close"><a class="close" href="#">&nbsp;</a></div><div id="modal-content" class="modal-content popups-body"></div></div>';
  html += '            <div class="popups-buttons"></div>'; //Maybe someday add the option for some specific buttons.
  html += '            <div class="popups-footer"></div>'; //Maybe someday add some footer.
  html += '          </div>';
  html += '        </td>';
  html += '        <td class="popups-cr popups-border"></td>';
  html += '      </tr>';
  html += '      <tr>';
  html += '        <td class="popups-bl popups-border"></td>';
  html += '        <td class="popups-b popups-border"></td>';
  html += '        <td class="popups-br popups-border"></td>';
  html += '      </tr>';
  html += '    </table>';
  html += '  </div>';
  html += '</div>';

  return html;

}

