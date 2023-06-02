#include"GglNote.h"

namespace mystd{
    using namespace std;
GglNote::GglNote(GglHttpSender *s){
    renderFlag=false;
    currentpage=0;
    allPage=0;
    targetPage=-1;
    editorPtr=make_unique<GglNoteEditor>(s);
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
        if(ImGui::Button("add note")){
            editorPtr->setCurreentDetail({"","","",""});
            editorPtr->show();
        }
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
GglNoteEditor::GglNoteEditor(GglHttpSender * s){
    renderFlag=false;
    httpSender=s;
    memset(titleBuf,0,256*sizeof(char));
    memset(mainContentBuf, 0, 10*1024 * sizeof(char));
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
            persistNote();
            
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
void GglNoteEditor::setCurreentDetail(NoteDetail d){
    currentDetail=d;
    memcpy(titleBuf,d.title.data(),d.title.length()+1);
    memcpy(mainContentBuf, d.content.data(), d.content.length() + 1);
}
void GglNoteEditor::persistNote() {
    AddNotePostData pd;
    pd.title = titleBuf;
    pd.content = mainContentBuf;
    pd.userId = "helloImgui!";
    string res =
        httpSender->postForJsonStr(GglServerUrls::ADD_NOTE_URL, pd.toJsonStr());
    cout << "post res===" << res << endl;
}
std::string SelectPagePostData:: toJsonStr(){
    char buffer[1024];
    sprintf(buffer,"{\"keyWord\":\"%s\",\"targetPage\":%d}",keyWord,targetPage);
    return buffer;
}
std::string AddNotePostData::toJsonStr(){
    char buffer[1024];
    sprintf(buffer, "{\"userId\":\"%s\",\"title\":\"%s\",\"content\":\"%s\"}", userId,
            title,content);
    return buffer;
}
void GglNote::postForNoteDetailPage(SelectPagePostData * d){
    // std::string res= httpSender->postForJsonStr(selectNotePpageUrl, d->toJsonStr());
    std::string res="{\"title\":\"this is title\",\"content\":\"this is content\",\"createTime\":\"\",\"updateTime\":\"\"}";
    JSON_Value* rootValuePtr=json_parse_string(res.c_str());
    if(json_value_get_type(rootValuePtr)==JSONArray){
        JSON_Array* ayPtr=json_value_get_array(rootValuePtr);
        for(int32_t index=0;index<notePageSize;){
            if(index>=json_array_get_count(ayPtr)){
                noteArray[index]={"","","",""};
                ++index;
                continue;
            }
            NoteDetail detail;
            JSON_Object* objPtr= json_array_get_object(ayPtr,index);
            detail.title=json_object_get_string(objPtr, "title");
            detail.content = json_object_get_string(objPtr, "content");
            detail.createTime = json_object_get_string(objPtr, "createTime");
            detail.updateTime = json_object_get_string(objPtr, "updateTime");
            noteArray[index]=detail;
            ++index;
        }
    } else if (json_value_get_type(rootValuePtr) == JSONObject) {

        JSON_Object* objPtr=json_value_get_object(rootValuePtr);
        for (int32_t index = 0; index < notePageSize;) {
            if (index ==0) {
                NoteDetail detail;
                detail.title = json_object_get_string(objPtr, "title");
                detail.content = json_object_get_string(objPtr, "content");
                detail.createTime =
                    json_object_get_string(objPtr, "createTime");
                detail.updateTime =
                    json_object_get_string(objPtr, "updateTime");
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