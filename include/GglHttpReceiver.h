#pragma once
#include<evhttp.h>
#include"GglPreBuild.h"
namespace mystd{
    void generalCallback(evhttp_request* req,void * arg);
    class GglHttpReceiver{
        public:
          GglHttpReceiver(std::string port, std::string uri,
                          void (*c)(evhttp_request *req, void *args));
          ~GglHttpReceiver();
        private:
          event_base* pEventBase;
          evhttp* pEvhttp;
    };
}