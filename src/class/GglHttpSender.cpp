#include "GglHttpSender.h"

namespace mystd {
using namespace std;
GglHttpSender::GglHttpSender() { 
    curlPtr = curl_easy_init(); 
    assert(curlPtr!=nullptr&&"curl init failed");
}
GglHttpSender::~GglHttpSender() {
    curl_easy_cleanup(curlPtr);
}
std::string GglHttpSender::postForJsonStr(std::string url,
                                          std::string jsonData) {

  char * resStr;

    curl_easy_setopt(curlPtr, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curlPtr, CURLOPT_POSTFIELDS, jsonData.c_str());
    curl_easy_setopt(curlPtr,CURLOPT_WRITEDATA,&resStr);
    /* Perform the request, res will get the return code */
    CURLcode res = curl_easy_perform(curlPtr);
    /* Check for errors */
    assert(res == CURLE_OK && curl_easy_strerror(res));
    return string(resStr);
   
    }
}  // namespace mystd