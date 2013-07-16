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

  public function create_user($user, $theurl, $themethod) {
    $user_data = drupal_http_build_query($user);
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
