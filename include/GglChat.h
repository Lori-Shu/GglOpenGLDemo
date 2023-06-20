#pragma once
#include "GglHttpReceiver.h"
#include "GglHttpSender.h"
#include "GglPreBuild.h"
#include<imgui.h>
namespace mystd{
    struct ChatMessage{
        std::string userId;
        std::string targetUserId;
        std::string content;
        std::string toJsonStr();
    };
    struct SelectUserPostData{
        std::string username;
        std::string toJsonStr();
    };
    class GglFriendManager{
        public:
          GglFriendManager(GglHttpSender*s);
          ~GglFriendManager();
          void render();
          void show();
          void hide();
          private:
          GglHttpSender*pHttpSender;
          bool showFlag;
          int32_t bufSize;
          char buf[1024];
    };
    class GglChat{
        public:
          GglChat(GglHttpSender * s);
          ~GglChat();
          void render();
          void show();
          void hide();
          void switchChatTarget(std::string id);
        private:
        void chatCallBack(evhttp_request * pReq,void * pArgs);
        std::unique_ptr<GglHttpReceiver> pHttpReceiver;
        std::unique_ptr<GglFriendManager> pFriendMannager;
        GglHttpSender * pHttpSender;
        std::unordered_map<std::string,UserDetail> friends;
        std::unordered_map<std::string,std::vector<ChatMessage>> chatMap;
        bool showFlag;
        std::string currentChatId;
        const int32_t chatBufLen=1024;
        char chatBuf[1024];
    };
}