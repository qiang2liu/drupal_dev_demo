<?php
/**
 * @file themural admin config.
 */


/**
 *
 * @param unknown_type $form_state
 * @return Ambigous <The, string>
 */
function themuraly_mail_form($form_state) {


  $form['themuraly_mail'] = array(
    '#type' => 'fieldset',
    '#title' => t('Mural mail settings'),
    '#weight' => 5,
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['themuraly_mail_sender'] = array(
 		'#type' => 'textfield',
 		'#title' => t('E-mail from address'),
 		'#description' => t('The e-mail address that all e-mails will be from.'),
 		'#size' => 50,
 		'#default_value' => variable_get('themuraly_mail_sender', 'no-reply@edgemakers.com'),
  );

  $form['themuraly_mail_return'] = array(
  		'#type' => 'textfield',
  		'#title' => t('Reply e-mail address'),
  		'#description' => t('Reply to this email address.'),
  		'#size' => 50,
  		'#default_value' => variable_get('themuraly_mail_return', 'no-reply@edgemakers.com'),
  );

  $form['themuraly_mail']['share_mural_mail_subject'] = array(
    '#type' => 'textfield',
    '#title' => t('Subject'),
    '#description' => t('Share mural mail subject.'),
    '#size' => 50,
    '#maxlength' => 200,
    '#default_value' => variable_get('share_mural_mail_subject', t('Edgemakers share a mural with you.')),
  );


  $share_mural_mail_body = variable_get('share_mural_mail_body', array('value' => '', 'format' => NULL));

  $form['themuraly_mail']['share_mural_mail_body'] = array(
    '#type' => 'text_format',
    '#base_type' => 'textarea',
    '#format' => isset($share_mural_mail_body['format']) ? $share_mural_mail_body['format'] : NULL,
    '#title' => t('Body'),
    '#description' => t('Share mural mail content.'),
    '#default_value' => $share_mural_mail_body['value'],
  );

  $form['themuraly_mail']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node'), // The token types that have specific context. Can be multiple token types like 'term' and/or 'user'
    '#global_types' => TRUE, // A boolean TRUE or FALSE whether to include 'global' context tokens like [current-user:*] or [site:*]. Defaults to TRUE.
    '#click_insert' => TRUE, // A boolean whether to include the 'Click this token to insert in into the the focused textfield' JavaScript functionality. Defaults to TRUE.
  );

  // Perform our custom submit before system submit
//   $form['#submit'][] = 'custom_settings_form_submit';

  return system_settings_form($form);

}