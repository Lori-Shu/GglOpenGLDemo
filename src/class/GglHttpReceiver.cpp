#include"GglHttpReceiver.h"
namespace mystd{
    using namespace std;
    void generalCallback(evhttp_request *req, void *arg) {
        evbuffer* buffer= evhttp_request_get_output_buffer(req);
        const char * ret="unknown resource!";
        evbuffer_add(buffer,ret,strlen(ret));
        evhttp_send_reply(req,HTTP_OK,"",buffer);
    }
    GglHttpReceiver::GglHttpReceiver(std::string port, std::string uri,void (*c)(evhttp_request* req,void *args)) {
      pEventBase = event_base_new();
      pEvhttp = evhttp_new(pEventBase);
      if(evhttp_bind_socket(pEvhttp,"127.0.0.1",atoi(port.c_str()))==0){
        cout<<"evhttp 绑定端口成功！"<<endl;
      }
      evhttp_set_gencb(pEvhttp,generalCallback,nullptr);
      evhttp_set_cb(pEvhttp,uri.c_str(),c,nullptr);
      event_base_dispatch(pEventBase);
    }
    GglHttpReceiver ::~GglHttpReceiver(){
        evhttp_free(pEvhttp);
        event_base_free(pEventBase);
        
    }
}