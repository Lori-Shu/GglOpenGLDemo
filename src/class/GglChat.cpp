#include"GglChat.h"

namespace mystd{
    using namespace std;
    std::string ChatMessage::toJsonStr() {
        char tempBuf[1024]={0};
        sprintf("{\"userId\":\"%s\",\"targetUserId\":\"%s\",\"content\":\"%s\"}",userId.c_str(),targetUserId.c_str(),content.c_str());
        return tempBuf;
    }
    std::string SelectUserPostData::toJsonStr() {
        char tempBuf[1024] = {0};
        sprintf(
            "{\"userId\":\"%s\"}",username.c_str());
        return tempBuf;
    }
    GglFriendManager::GglFriendManager(GglHttpSender *s) {
        showFlag=false;
        pHttpSender=s;
        bufSize=1024;
        memset(buf, 0, bufSize);
    }
    GglFriendManager ::~GglFriendManager(){

    }
    void GglFriendManager::render(){
        if(showFlag){
            ImGui::Begin("friend manager");
            ImGui::Text("新朋友用户名：");
            ImGui::LabelText("##userIdInputLabel","username:");
            ImGui::InputText("##userIdInput", buf, bufSize-1);
            if(ImGui::Button("查询用户")){
                SelectUserPostData supd;
                supd.username=buf;
                pHttpSender->postForJsonStr(GglServerUrls::SELECT_USER_URL,supd.toJsonStr());
            }
            ImGui::End();
        }
    }
    void GglFriendManager::show(){showFlag=true;}
    void GglFriendManager::hide(){showFlag=false;}
    GglChat::GglChat(GglHttpSender *s) {
        pHttpReceiver =
          make_unique<GglHttpReceiver>("8666", "/chat", &GglChat::chatCallBack);
        pFriendMannager=make_unique<GglFriendManager>();
        pHttpSender=s;
        showFlag=false;
        currentChatId=currentUserDetail.id;
    }
GglChat::~GglChat(){}
void GglChat::render(){
    if(showFlag){
        ImGui::Columns(2,"##chatColumn",true);
        ImGui::Text("friends");
        ImGui::NextColumn();
        ImGui::Text("current chat target: %s",friends[currentChatId]);
        ImGui::Separator();
        ImGui::NextColumn();
        ImGui::BeginListBox("##friendsBox");
        for(auto ite=friends.begin();ite!=friends.end();){
            ImGui::Text("username:%s",ite->second.username);
            string butId="->##";
            butId.append(ite->second.id);
            ImGui::SameLine();
            if(ImGui::Button(butId.c_str())){
              switchChatTarget(ite->second.id);
            }
            ++ite;
        }
        ImGui::EndListBox();
        ImGui::NextColumn();
        vector<ChatMessage> & msgs= chatMap[currentChatId];
        for(int32_t index=0;index<msgs.size();){
            if(currentUserDetail.id.compare(msgs[index].targetUserId)==0){
              ImGui::Text("~~~~~~%s", msgs[index].content.c_str());
              
            }else if(currentUserDetail.id.compare(msgs[index].targetUserId)!=0){
              ImGui::Text("#%s", msgs[index].content.c_str());
            }
            ++index;
        }
        ImGui::Separator();
        ImGui::InputTextMultiline("##chatInput",chatBuf,chatBufLen,ImVec2(20.0f,10.0f));
        if(ImGui::Button("send message")){
            ChatMessage cMsg;
            cMsg.userId=currentUserDetail.id;
            cMsg.targetUserId=currentChatId;
            cMsg.content=chatBuf;
            string res= pHttpSender->postForJsonStr(GglServerUrls::SEND_CHAT_MESSAGE_URL,cMsg.toJsonStr());
            JSON_Value* pValue=json_parse_string(res.c_str());
            JSON_Object* pObj= pHttpSender->getObjectFromCommonResult(pValue);
            string resMsg= json_object_get_string(pObj,"data");
            assert(resMsg.compare("ok")==0&&"消息发送服务端错误");
            chatMap[cMsg.targetUserId].push_back(cMsg);
        }
        }
}
void GglChat::show(){showFlag=true;}
void GglChat::hide(){showFlag=false;}
void GglChat::switchChatTarget(std::string id){

}
void GglChat::chatCallBack(evhttp_request *pReq, void *pArgs){
    evbuffer* pInputMsg=evhttp_request_get_input_buffer(pReq);
    char msgBuf[1024]={0};
    int32_t len= evbuffer_remove(pInputMsg,msgBuf,1024);
    JSON_Value* pValue= json_parse_string(msgBuf);
    JSON_Object* pObj= pHttpSender->getObjectFromCommonResult(pValue);
    JSON_Object* pMsgObj= json_object_get_object(pObj,"data");
    ChatMessage cMsg;
    cMsg.userId=json_object_get_string(pMsgObj, "userId");
    cMsg.targetUserId= json_object_get_string(pMsgObj, "targetUserId");
    cMsg.content= json_object_get_string(pMsgObj, "content");
    if(0==cMsg.userId.compare(currentUserDetail.id)){
    chatMap[cMsg.targetUserId].push_back(cMsg);
    } else if (0 != cMsg.userId.compare(currentUserDetail.id)){
    chatMap[cMsg.userId].push_back(cMsg);
    }
    json_value_free(pValue);
    evbuffer *buffer = evhttp_request_get_output_buffer(pReq);
    const char *ret = "send_ok";
    evbuffer_add(buffer, ret, strlen(ret));
    evhttp_send_reply(pReq, HTTP_OK, "", buffer);
}
}