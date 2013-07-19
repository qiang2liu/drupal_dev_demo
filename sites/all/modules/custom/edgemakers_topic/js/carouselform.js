function edgemakers_topic_url_field_action() {
  var elDrop = document.getElementById("edit-field-carousel-item-topic-und");
  var elLinkWrapper = document.getElementById("edit-field-carousel-item-link");
  if(elDrop.value == '_none') elLinkWrapper.style.display = "block"; 
  else elLinkWrapper.style.display = "none";
}