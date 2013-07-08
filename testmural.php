<?php
ini_set('display_errors','on');

$secret_string = "C54DC45B6C1E4A9321936349FC8BB";
$the_org = "edgemakers";
$the_u = "testuser";
$the_url = '/api/murals';
$the_method = "GET";

$stringToSign = $the_u . ":" . $the_method . ":" . $the_url;

$the_string = $stringToSign;

echo $the_string, "<p/>";

$the_string = utf8_encode($stringToSign);
echo $the_string, "<p/>";
//$the_string = mhash(MHASH_SHA1 , $secret_string, $the_string);
$the_string = hash_hmac('sha1' ,    $the_string,   $secret_string,true);
echo $the_string, "<p/>";
$the_string_auth = base64_encode($the_string);
echo $the_string_auth;

