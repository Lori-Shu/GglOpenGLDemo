#include"GglNote.h"

namespace mystd{
    using namespace std;
GglNote::GglNote(GglHttpSender *s){
    renderFlag=false;
    currentpage=0;
    allPage=0;
    targetPage=-1;
    editorPtr=make_unique<GglNoteEditor>();
    httpSender=s;
    SelectPagePostData data;
    data.keyWord="";
    data.targetPage=1;
    postForNoteDetailPage(&data);
    
}
void GglNote::show(){
    renderFlag=true;
}
void GglNote::hide(){
    renderFlag=false;
}
void GglNote::render(){
    if(renderFlag){
        
        ImGui::Columns(4,"note intro",true);
        ImGui::Text("title");
        ImGui::NextColumn();
        ImGui::Text("edit time");
        ImGui::NextColumn();
        ImGui::Text("editButton");
        ImGui::NextColumn();
        ImGui::Text("deleteButton");
        
        ImGui::Separator();
        for(int index=0;index<notePageSize;){
          ImGui::NextColumn();
          ImGui::Text(noteArray[index].title.c_str());
          ImGui::NextColumn();
          ImGui::Text(noteArray[index].content.c_str());
          ImGui::NextColumn();
          ImGui::PushID(string("edit").append(to_string(index)).c_str());
          if(ImGui::Button("edit")){
       
            cout << "buttonid===" <<string("edit").append(to_string(index)) <<endl;
            editorPtr->show();
          }
          ImGui::PopID();
          ImGui::NextColumn();
          ImGui::PushID(string("delete").append(to_string(index)).c_str());
          if(ImGui::Button("delete")){

            cout << "buttonid===" <<string("delete").append(to_string(index)) << endl;
          }
          ImGui::PopID();
          ImGui::Separator();
          ++index;
        }
        ImGui::Columns(1);
        ImGui::Text(string("page:").append(to_string(currentpage)).append("/")
        .append(to_string(allPage)).c_str());
        ImGui::Button("<previous page");
        ImGui::SameLine();
        ImGui::Button("next page>");
        ImGui::SameLine();
        ImGui::InputInt("target page",&targetPage);
        ImGui::SameLine();
        ImGui::Button("jump");
        ImGui::Separator();
        editorPtr->render();
        }
}
GglNoteEditor::GglNoteEditor(){
    renderFlag=false;
}
GglNoteEditor::~GglNoteEditor(){}
void GglNoteEditor::render(){
    if(renderFlag){
        ImGui::Begin("NoteEditor");
        if(ImGui::Button("close")){
            hide();
        }
        ImGui::InputText("title 最长100",titleBuf,256);
        ImGui::InputTextMultiline("main content", mainContentBuf, 1024*10);
        if (ImGui::Button("submit change")) {
            
        }
        ImGui::End();
    }
}
void GglNoteEditor::show(){
    renderFlag=true;
}
void GglNoteEditor::hide(){
    renderFlag=false;
}
std::string SelectPagePostData:: toJsonStr(){
    char buffer[1024];
    sprintf(buffer,"{\"keyWord\":\"%s\",\"targetPage\":%d}",keyWord,targetPage);
    return buffer;
}
void GglNote::postForNoteDetailPage(SelectPagePostData * d){
    // std::string res= httpSender->postForJsonStr(selectNotePpageUrl, d->toJsonStr());
    std::string res="{\"title\":\"this is title\",\"content\":\"this is content\",\"createTime\":\"\",\"updateTime\":\"\"}";
    rapidjson::Document document;
    document.Parse(res.c_str());
    if(document.IsArray()){
        auto ay= document.GetArray();
        for(int32_t index=0;index<notePageSize;){
            if(index>=document.Size()){
                noteArray[index]={"","","",""};
                ++index;
                continue;
            }
            NoteDetail detail;
            rapidjson::Value& v = ay[index];
            detail.title=v["title"].GetString();
            detail.content = v["content"].GetString();
            detail.createTime = v["createTime"].GetString();
            detail.updateTime = v["updateTime"].GetString();
            noteArray[index]=detail;
            ++index;
        }
    }else if(document.IsObject()){
        auto obj = document.GetObject();
        for (int32_t index = 0; index < notePageSize;) {
            if (index ==0) {
                NoteDetail detail;
                detail.title = obj["title"].GetString();
                detail.content = obj["content"].GetString();
                detail.createTime = obj["createTime"].GetString();
                detail.updateTime = obj["updateTime"].GetString();
                noteArray[index] = detail;
                ++index;
                continue;
            }
            noteArray[index] = {"", "", "", ""};
            ++index;
        }
    }

}
}
