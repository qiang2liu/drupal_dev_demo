<?php
/**
 * @file
 * edgemakers_features_other.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function edgemakers_features_other_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'api';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api';
  $endpoint->authentication = array(
    'oauth2_server' => array(
      'server' => 'api',
    ),
  );
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
      'yaml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/x-www-form-urlencoded' => TRUE,
      'application/x-yaml' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
    ),
  );
  $endpoint->resources = array(
    'notification' => array(
      'actions' => array(
        'mural_updated' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => '',
            ),
          ),
        ),
      ),
    ),
    'system' => array(
      'actions' => array(
        'connect' => array(
          'enabled' => '1',
          'settings' => array(
            'oauth2_server' => array(
              'require_authentication' => '1',
              'scope' => 'basic',
            ),
          ),
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['api'] = $endpoint;

  return $export;
}
