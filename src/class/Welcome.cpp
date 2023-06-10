#include"Welcome.h"
namespace mystd{
    using namespace std;
    
    std::string RegisterPostData::toJsonStr(){
        char buffer[1024];
        sprintf(buffer,"{\"id\":\"%s\",\"username\":\"%s\",\"password\":\"%s\"}",id.c_str(),username.c_str(),password.c_str());
        return string(buffer);
    }
    std::string LoginPostData::toJsonStr(){
        char buffer[1024];
        sprintf(buffer,
                "{\"username\":\"%s\",\"password\":\"%s\"}",
                username.c_str(), password.c_str());
        return string(buffer);
    }
    Welcome::Welcome(bool *isL, GglHttpSender *s, GglNote *n) {
        showFlag=true;
        isLoginPtr=isL;
        httpSenderPtr=s;
        notePtr=n;
        memset(usernameBuffer,0,usernameBufSize);
        memset(passwordBuffer, 0, passwordBufSize);
    }
    Welcome::~Welcome(){}
    void Welcome::render(){
        if(showFlag){
            ImGui::Text("welcome to ggl_zone client");
            ImGui::LabelText("labelu", "username:");
            ImGui::InputText("##usernameInput", usernameBuffer, usernameBufSize);
            ImGui::LabelText("labelp", "password:");
            ImGui::InputText("##passwordInput", passwordBuffer, passwordBufSize,ImGuiInputTextFlags_Password);
            if(ImGui::Button("login")){
                login();
            }
            if (ImGui::Button("register")) {
                registerUser();
            }
        }
    }
    void Welcome::show() {
        showFlag=true;
    }
    void Welcome::hide(){
        showFlag=false;
    }
    void Welcome::login(){
        LoginPostData data;
        data.username = string(usernameBuffer);
        data.password = string(passwordBuffer);
        std::string res = httpSenderPtr->postForJsonStr(
            GglServerUrls::LOGIN_URL, data.toJsonStr());
        JSON_Value *jVal = json_parse_string(res.c_str());
         assert(json_value_get_type(jVal) == JSONObject &&
               "res content problem");
        GglTip *tipPtr = GglTip::getInstance();
        JSON_Object* objPtr= httpSenderPtr->getObjectFromCommonResult(jVal);
        if(objPtr==nullptr){
            tipPtr->setMsg("登录失败！");
            tipPtr->show();
            json_value_free(jVal);
            return;
        }
        tipPtr->setMsg("登录成功！");
        currentUserDetail.id = json_object_get_string(objPtr, "id");
        currentUserDetail.username = json_object_get_string(objPtr, "username");
        json_value_free(jVal);
        tipPtr->show();
        SelectPagePostData ptData;
        ptData.keyword = "";
        ptData.targetPage = 1;
        ptData.userId = currentUserDetail.id;
        notePtr->postForNoteDetailPage(&ptData);
        *isLoginPtr=true;
        hide();
    }
    void Welcome::registerUser(){
        RegisterPostData data;
        data.id="";
        data.username=string(usernameBuffer);
        data.password = string(passwordBuffer);
        std::string res= httpSenderPtr->postForJsonStr(GglServerUrls::REGISTER_URL,data.toJsonStr());
        JSON_Value *jVal=json_parse_string(res.c_str());
        assert(json_value_get_type(jVal)==JSONObject&&"res content problem");
        JSON_Object *objPtr= json_value_get_object(jVal);
        GglTip *tipPtr = GglTip::getInstance();
        if(json_object_get_number(objPtr,"code")!=200){
            tipPtr->setMsg(json_object_get_string(objPtr, "data"));
            tipPtr->show();
            json_value_free(jVal);
            return;
        }
        tipPtr->setMsg(json_object_get_string(objPtr, "data"));
        json_value_free(jVal);
        tipPtr->show();
        
    }
}
