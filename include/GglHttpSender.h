#pragma once
#include<curl/curl.h>
#include"GglPreBuild.h"
namespace mystd{
    /**
     * a httpsender using libcurl
    */
    class GglHttpSender{
        public:
            GglHttpSender();
            ~GglHttpSender();
            std::string postForJsonStr(std::string url,std::string jsonData);
        private:
        CURL * curlPtr;
    };
}