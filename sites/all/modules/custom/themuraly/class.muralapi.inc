<?php

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 * Description of class
 *
 * @author test
 */
class Muralapi {

  protected $signing_secret, $the_org, $muralapi_base_url, $user_agent;

  public function __construct() {
    $this->the_org = variable_get('muralapi_org', 'edgemakers');
    $this->signing_secret = variable_get('muralapi_secretkey', 'C54DC45B6C1E4A9321936349FC8BB');
    $this->muralapi_base_url = variable_get('muralapi_baseurl', 'http://staging.mural.ly');
    $this->user_agent = variable_get('muralapi_useragent', 'curl/7.22.0 (i686-pc-linux-gnu) libcurl/7.22.0 OpenSSL/1.0.1 zlib/1.2.3.4 libidn/1.23 librtmp/2.3');
  }

  public function get_auth_string($theuser, $theurl, $themethod) {
    $stringToSign = $theuser . ":" . $themethod . ":" . $theurl;
    $the_string = utf8_encode($stringToSign);
    $the_string = hash_hmac('sha1', $the_string, $this->signing_secret, true);
    $the_string_auth = base64_encode($the_string);
    return $the_string_auth;
  }

  public function get_all_murals($username) {
    $the_auth_string = $this->get_auth_string($username, '/api/murals', 'GET');
    $apiurl = $this->muralapi_base_url . '/api/murals';
    $apiurl = "http://staging.mural.ly/api/murals";
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $username,
        'x-mural-ly-context' => $this->the_org,
        'Authorization' => "MURALLY " . $username . ":" . $the_auth_string,
        'User-Agent' => $this->user_agent,
    );


    $options['method'] = 'GET';



    $ret = curl_http_request($apiurl, $options);
    return $ret;
  }

  public function duplicate_mural($username, $muralid, $params) {
    $params['ownerId'] = $this->the_org;
    $data = drupal_json_encode($params);
    $apiname = "/api/murals/" . $this->the_org . '/' . $muralid . '/duplicate';
    $apiurl = $this->muralapi_base_url . $apiname;
    $the_auth_string = $this->get_auth_string($username, $apiname, 'POST');
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $username,
        'x-mural-ly-context' => $this->the_org,
        'Authorization' => "MURALLY " . $username . ":" . $the_auth_string,
        'User-Agent' => $this->user_agent,
        'Content-Type' => "application/json",
    );


    $options['method'] = 'POST';
    $options['data'] = $data;





    $ret = drupal_http_request($apiurl, $options);
    return $ret;
  }

  public function create_mural($username, $params) {
    /*
      $ret = array();
      $required_key = array('title','room',);
      foreach($required_key as $k=>$v) {
      if (empty($params[$v])) {
      $ret['err'] = 1;
      $ret['err_msg'] = "parameter error";
      return $ret;
      }
      }
     * 
     */
    $params['ownerId'] = $this->the_org;
    $data = drupal_json_encode($params);
    $apiurl = $this->muralapi_base_url . "/api/murals";
    $the_auth_string = $this->get_auth_string($username, '/api/murals', 'POST');
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $username,
        'x-mural-ly-context' => $this->the_org,
        'Authorization' => "MURALLY " . $username . ":" . $the_auth_string,
        'User-Agent' => $this->user_agent,
        'Content-Type' => "application/json",
    );


    $options['method'] = 'POST';
    $options['data'] = $data;





    $ret = drupal_http_request($apiurl, $options);
    return $ret;
  }

  public function create_user($user, $theurl, $themethod) {
    //$user_data = drupal_http_build_query($user);
    $user_data = drupal_json_encode($user);
    $theuser = $this->the_org;

    $the_auth_string = $this->get_auth_string($theuser, $theurl, $themethod);

    $apiurl = $this->muralapi_base_url . $theurl;
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $this->the_org,
        'x-mural-ly-context' => $this->the_org,
        'Authorization' => "MURALLY edgemakers:" . $the_auth_string,
        'User-Agent' => $this->user_agent,
        'Content-Type' => "application/json",
    );


    $options['method'] = $themethod;
    $options['data'] = $user_data;





    $ret = drupal_http_request($apiurl, $options);

    return $ret;
  }

}

?>
