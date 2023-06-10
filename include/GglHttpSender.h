#pragma once
#include<curl/curl.h>
#include"GglPreBuild.h"
#include"parson.h"
namespace mystd{
    struct GglServerUrls{
      static constexpr char SELECT_NOTE_PAGE_URL[] =
          "http://192.168.56.100:8536/note/selectPage";
      static constexpr char ADD_NOTE_URL[] =
          "http://192.168.56.100:8536/note/addNote";
      static constexpr char REGISTER_URL[] =
          "http://192.168.56.100:8536/register";
      static constexpr char LOGIN_URL[] =
          "http://192.168.56.100:8536/login";
      static constexpr char DELETE_NOTE_URL[] = "http://192.168.56.100:8536/note/delete";
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
            JSON_Object* getObjectFromCommonResult(JSON_Value* v);
            JSON_Array *getArrayFromCommonResult(JSON_Value *v);

          private:
            CURL *curlPtr;
            static constexpr int32_t resMaxSize = 1024 * 10;
            char resBuffer[resMaxSize];
    };
}