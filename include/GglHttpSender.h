#pragma once
#include<curl/curl.h>
#include"GglPreBuild.h"
namespace mystd{
    struct GglServerUrls{
      static constexpr char SELECT_NOTE_PAGE_URL[] =
          "http://192.168.56.100:8989/note/selectNotePage";
      static constexpr char ADD_NOTE_URL[] =
          "http://192.168.56.100:8536/note/addNote";
    };
    uint64_t getResStr(void *data, size_t size, size_t nmemb, void *res);
    /**
     * a httpsender using libcurl
    */
    class GglHttpSender{
        public:
            GglHttpSender();
            ~GglHttpSender();
            std::string postForJsonStr(std::string url,std::string jsonData);
        private:
          
          CURL *curlPtr;
          static constexpr int32_t resMaxSize=1024*10;
          char resBuffer[resMaxSize];
    };
}