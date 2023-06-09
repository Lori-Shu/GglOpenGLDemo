#include "GglHttpSender.h"

namespace mystd {
using namespace std;
GglHttpSender::GglHttpSender() {
  assert(curl_global_init(CURL_GLOBAL_DEFAULT) == CURLE_OK);
  curlPtr = curl_easy_init();
  assert(curlPtr != nullptr && "curl init failed");
}
GglHttpSender::~GglHttpSender() {
  curl_easy_cleanup(curlPtr);
  curl_global_cleanup();
}
std::string GglHttpSender::postForJsonStr(std::string url,
                                          std::string jsonData) {

  cout << "post url===" << url << endl;
  cout << "json data===" << jsonData << endl;
  char contentLengthStr[1024];
  sprintf(contentLengthStr,"Content-Length:%d",jsonData.length());
  curl_easy_setopt(curlPtr, CURLOPT_VERBOSE, true);
  curl_slist *headers = nullptr;
  headers = curl_slist_append(headers, "Accept:application/json");
  headers = curl_slist_append(headers, "Content-Type:application/json");
  headers = curl_slist_append(headers, "Charset:UTF-8");
  headers = curl_slist_append(headers, contentLengthStr);
  curl_easy_setopt(curlPtr, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curlPtr, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curlPtr, CURLOPT_POSTFIELDS, jsonData.c_str());

  curl_easy_setopt(curlPtr, CURLOPT_WRITEFUNCTION, getResStr);
  curl_easy_setopt(curlPtr, CURLOPT_WRITEDATA, resBuffer);

  /* Perform the request, res will get the return code */
  CURLcode res = curl_easy_perform(curlPtr);
  /* Check for errors */
  assert(res == CURLE_OK && curl_easy_strerror(res));
  int32_t resLen = 0;
  curl_easy_getinfo(curlPtr, CURLINFO_CONTENT_LENGTH_DOWNLOAD_T, &resLen);
  string resMsg=string(resBuffer, resLen);
  cout << "res msg" << resMsg << endl;
  return resMsg;
}
uint64_t getResStr(void *data, size_t size, size_t nmemb, void *res) {
  size_t buffer_size = size * nmemb;
  if (buffer_size <= 1024 * 10) {
    memcpy(res, data, buffer_size);
  } else if (buffer_size > 1024 * 10) {
    memcpy(res, data, 1024 * 10);
    cout << "返回数据超过buufer大小" << endl;
    return 1024 * 10;
  }
  return buffer_size;
}
JSON_Object *GglHttpSender::getObjectFromCommonResult(JSON_Value *v) {
  JSON_Object *commonResPtr = json_value_get_object(v);
  if (json_object_get_number(commonResPtr, "code") != 200) {
    cout << "return msg is error" << endl;
    return nullptr;
  }
  return json_object_get_object(commonResPtr, "data");
}
JSON_Array *GglHttpSender::getArrayFromCommonResult(JSON_Value *v) {
  JSON_Object *commonResPtr = json_value_get_object(v);
  if (json_object_get_number(commonResPtr, "code") != 200) {
    cout << "return msg is error" << endl;
    return nullptr;
  }

  return json_object_get_array(commonResPtr, "data");
}
} // namespace mystd