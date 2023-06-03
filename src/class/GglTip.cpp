#include"GglTip.h"

namespace mystd{
    using namespace std;
    GglTip GglTip::tipInstance;
    GglTip::GglTip(){
        showFlag=false;
        memset(tipWords,0,tipWordsSize);
    }
    GglTip::~GglTip(){
    }
    void GglTip::render(){
        if(showFlag){
            ImGui::Begin("tip window");
            ImGui::Text(tipWords);
            if(ImGui::Button("close")){
                hide();
            }
            ImGui::End();
        }
    }
    void GglTip::show(){
        showFlag=true;
        cout<<"change to true"<<endl;
    }
    void GglTip::hide(){
        showFlag=false;
    }
    GglTip *GglTip::getInstance() {
        cout<<"instance position==="<<&tipInstance<<endl;
        cout << "flag===" << tipInstance.showFlag << endl;
        return &tipInstance;
    }
    void GglTip::setMsg(std::string msg) {
        memcpy(tipWords,msg.data(),msg.length()+1);
    }
}