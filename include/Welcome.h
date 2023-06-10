#pragma once
#include "GglPrebuild.h"
#include<imgui.h>
#include"GglHttpSender.h"
#include"parson.h"
#include"GglTip.h"
#include"GglNote.h"
namespace mystd{
    struct RegisterPostData{
        std::string id;
        std::string username;
        std::string password;
        std::string toJsonStr();
    };
    struct LoginPostData {
        std::string username;
        std::string password;
        std::string toJsonStr();
    };
    
    class Welcome{
        public:
          Welcome(bool *isL, GglHttpSender *s,GglNote* n);
          ~Welcome();
          void render();
          void show();
          void hide();
        private:
          void login();
          void registerUser();
          bool showFlag;
          bool *isLoginPtr;
          GglHttpSender* httpSenderPtr;
          GglNote* notePtr;
          static constexpr int32_t usernameBufSize = 128;
          char usernameBuffer[usernameBufSize];
          static constexpr int32_t passwordBufSize = 128;
          char passwordBuffer[passwordBufSize];
    };
}