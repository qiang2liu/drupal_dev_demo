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
  
  public function retrieve_a_mural($username, $muralid) {
    $apistr = '/api/murals/' . $this->the_org . '/' . $muralid;
    $apiurl = $this->muralapi_base_url . $apistr;
    $the_auth_string = $this->get_auth_string($username, $apistr, 'GET');
    
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
  public function get_all_murals($username) {
    $the_auth_string = $this->get_auth_string($username, '/api/murals', 'GET');
    $apiurl = $this->muralapi_base_url . '/api/murals';
  
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
  public function create_room($username, $title) {
    $apistr = "/api/rooms";
    $apiurl = $this->muralapi_base_url . $apistr;
    $the_auth_string = $this->get_auth_string($username, $apistr, 'POST');
    $data = array('title' => $title);
    $data = drupal_json_encode($data);
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

  public function update_mural_properties($theuser, $muralid, $the_name, $the_value) {
    $themethod = "PUT";
    $the_owner = $this->the_org;
    $theapi = "/api/murals/" . $the_owner . "/" . $muralid . "/" . $the_name;
    $theurl = $this->muralapi_base_url . $theapi;
    $the_auth_string = $this->get_auth_string($theuser, $theapi, $themethod);
    $data = array();
    $data['value'] = $the_value;
    $data = drupal_json_encode($data);

    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $theuser,
      'x-mural-ly-context' => $this->the_org,
      'Authorization' => "MURALLY " . $theuser . ":" . $the_auth_string,
      'User-Agent' => $this->user_agent,
      'Content-Type' => "application/json",
    );
    $options['method'] = $themethod;
    $options['data'] = $data;

    $ret = drupal_http_request($theurl, $options);
    return $ret;
  }

  public function delete_mural($username, $muralid) {
    $the_method = "DELETE";
    $the_api = "/api/murals/" . $this->the_org . "/" . $muralid;
    $theurl = $this->muralapi_base_url . $the_api;
    $the_auth_string = $this->get_auth_string($username, $the_api, $the_method);
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $username,
      'x-mural-ly-context' => $this->the_org,
      'Authorization' => "MURALLY " . $username . ":" . $the_auth_string,
      'User-Agent' => $this->user_agent,
      
    );
    $options['method'] = $the_method;
    

    $ret = drupal_http_request($theurl, $options);
    return $ret;
  }

  public function archive_mural($username, $muralid, $archive_flag) {
    $the_method = "POST";
    $the_api = "/api/murals/" . $this->the_org . "/" . $muralid . "/archive";
    $theurl = $this->muralapi_base_url . $the_api;
    $the_auth_string = $this->get_auth_string($username, $the_api, $the_method);
    $data = array();
    $the_flag = (bool) $archive_flag;
    if ($the_flag) {
      $data['archive'] = 1;
    } else {
      $data['archive'] = 0;
    }

    $data = drupal_json_encode($data);
    $options = array();
    $options['headers'] = array('x-mural-ly-user' => $username,
      'x-mural-ly-context' => $this->the_org,
      'Authorization' => "MURALLY " . $username . ":" . $the_auth_string,
      'User-Agent' => $this->user_agent,
      'Content-Type' => "application/json",
    );
    $options['method'] = $the_method;
    $options['data'] = $data;

    $ret = drupal_http_request($theurl, $options);
    return $ret;
  }
  public function invite_user_mural($username, $muralid, $muraluserids = array(),$muraluseremails = array()) {
    $params = array();
    $params['members'] = $muraluserids;
    $params['pendings'] = $muraluseremails;
    
    $data = drupal_json_encode($params);
    $the_api = "/api/murals/" . $this->the_org . "/" . $muralid . "/collaborators";
    $apiurl = $this->muralapi_base_url . $the_api;
    $the_auth_string = $this->get_auth_string($username, $the_api, 'POST');
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
  

}

?>
