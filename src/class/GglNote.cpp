#include"GglNote.h"

namespace mystd{
    using namespace std;
GglNote::GglNote(){
    renderFlag=false;
    currentpage=0;
    allPage=0;
    targetPage=-1;
    editorPtr=make_unique<GglNoteEditor>();
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
        for(int index=0;index<10;){
          ImGui::NextColumn();
          ImGui::Text("1");
          ImGui::NextColumn();
          ImGui::Text("2");
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
}
