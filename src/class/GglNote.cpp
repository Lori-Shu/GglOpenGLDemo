#include "GglNote.h"

namespace mystd {
using namespace std;
GglNote::GglNote(GglHttpSender *s) {
  renderFlag = false;
  currentpage = 0;
  allPages = 0;
  targetPage = -1;
  editorPtr = make_unique<GglNoteEditor>(s);
  httpSenderPtr = s;
}
void GglNote::show() { renderFlag = true; }
void GglNote::hide() { renderFlag = false; }
void GglNote::render() {
  if (renderFlag) {
    if (ImGui::Button("add note")) {
      editorPtr->setCurreentDetail({"", "", "", ""});
      editorPtr->show();
    }
    ImGui::Columns(4, "note intro", true);
    ImGui::Text("title");
    ImGui::NextColumn();
    ImGui::Text("edit time");
    ImGui::NextColumn();
    ImGui::Text("editButton");
    ImGui::NextColumn();
    ImGui::Text("deleteButton");

    ImGui::Separator();
    for (int index = 0; index < notePageSize;) {
      ImGui::NextColumn();
      ImGui::Text(noteArray[index].title.c_str());
      ImGui::NextColumn();
      ImGui::Text(noteArray[index].content.c_str());
      ImGui::NextColumn();
      ImGui::PushID(string("edit").append(to_string(index)).c_str());
      if (ImGui::Button("edit")) {

        cout << "buttonid===" << string("edit").append(to_string(index))
             << endl;
        editorPtr->setCurreentDetail(noteArray[index]);
        editorPtr->show();
      }
      ImGui::PopID();
      ImGui::NextColumn();
      ImGui::PushID(string("delete").append(to_string(index)).c_str());
      if (ImGui::Button("delete")) {

        cout << "buttonid===" << string("delete").append(to_string(index))
             << endl;
        postToDeleteNoteDetail(&noteArray[index]);
      }
      ImGui::PopID();
      ImGui::Separator();
      ++index;
    }
    ImGui::Columns(1);
    ImGui::Text(string("page:")
                    .append(to_string(currentpage))
                    .append("/")
                    .append(to_string(allPages))
                    .c_str());
    ImGui::Button("<previous page");
    ImGui::SameLine();
    ImGui::Button("next page>");
    ImGui::SameLine();
    ImGui::InputInt("target page", &targetPage);
    ImGui::SameLine();
    ImGui::Button("jump");
    ImGui::Separator();
    editorPtr->render();
  }
}
GglNoteEditor::GglNoteEditor(GglHttpSender *s) {
  renderFlag = false;
  httpSenderPtr = s;
  memset(titleBuf, 0, 256 * sizeof(char));
  memset(mainContentBuf, 0, 10 * 1024 * sizeof(char));
}
GglNoteEditor::~GglNoteEditor() {}
static int inputEnterCallback(ImGuiInputTextCallbackData *data) {
  if (data->EventKey == ImGuiKey_Enter) {
    // 在缓冲区中添加\r\n
    data->EventChar=0;
    data->InsertChars(data->CursorPos,"\n" );

    // 将光标移动到下一行
    data->CursorPos += 1;

    // 允许ImGui处理其他输入事件
    return 0;
  }
  return 0;
}
void GglNoteEditor::render() {
  if (renderFlag) {
    ImGui::Begin("NoteEditor");
    if (ImGui::Button("close")) {
      hide();
    }
    ImGui::InputText("title 最长100", titleBuf, 256,
                     ImGuiInputTextFlags_CallbackCharFilter,
                     inputEnterCallback);
    ImGui::InputTextMultiline(
        "main content", mainContentBuf, 1024 * 10, ImVec2(0, 0),
        ImGuiInputTextFlags_CallbackCharFilter, inputEnterCallback);
    if (ImGui::Button("submit change")) {
      persistNote();
    }
    ImGui::End();
  }
}
void GglNoteEditor::show() { renderFlag = true; }
void GglNoteEditor::hide() { renderFlag = false; }
void GglNoteEditor::setCurreentDetail(NoteDetail d) {
  currentDetail = d;
  memcpy(titleBuf, d.title.c_str(), d.title.length() + 1);
  memcpy(mainContentBuf, d.content.c_str(), d.content.length() + 1);
}
void GglNoteEditor::persistNote() {
  GglTip *tipPtr = GglTip::getInstance();
  if (strlen(titleBuf) <= 0) {
    tipPtr->setMsg("title can not be empty");
    tipPtr->show();
    return;
  }
  AddNotePostData pd;
  pd.title = titleBuf;
  pd.content = mainContentBuf;
  pd.userId = currentUserDetail.id.c_str();
  string res = httpSenderPtr->postForJsonStr(GglServerUrls::ADD_NOTE_URL,
                                             pd.toJsonStr());
  JSON_Value *resValue = json_parse_string(res.c_str());

  assert(json_value_get_type(resValue) == JSONObject &&
         "remote return value is not an commonresult object!");
  JSON_Object *obj = json_value_get_object(resValue);

  tipPtr->setMsg(json_object_get_string(obj, "data"));
  json_value_free(resValue);
  tipPtr->show();
}
std::string NoteDetail::toJsonStr() {
  char buffer[1024];
  sprintf(buffer,
          "{\"id\":\"%s\",\"title\":\"%s\",\"content\":\"%s\",\"createTime\":"
          "\"%s\",\"updateTime\":\"%s\"}",
          id.c_str(), title.c_str(), content.c_str(), createTime.c_str(),
          updateTime.c_str());
  return buffer;
}
std::string SelectPagePostData::toJsonStr() {
  char buffer[1024];
  sprintf(buffer, "{\"keyword\":\"%s\",\"targetPage\":%d,\"userId\":\"%s\"}",
          keyword.c_str(), targetPage, userId.c_str());
  return buffer;
}
std::string AddNotePostData::toJsonStr() {
  char buffer[1024];
  sprintf(buffer, "{\"userId\":\"%s\",\"title\":\"%s\",\"content\":\"%s\"}",
          userId, title, content);
  return buffer;
}
void GglNote::postForNoteDetailPage(SelectPagePostData *d) {
  std::string res = httpSenderPtr->postForJsonStr(
      GglServerUrls::SELECT_NOTE_PAGE_URL, d->toJsonStr());
  // std::string res="{\"title\":\"this is title\",\"content\":\"this is
  // content\",\"createTime\":\"\",\"updateTime\":\"\"}";
  JSON_Value *rootValuePtr = json_parse_string(res.c_str());
  JSON_Object *objPtr = httpSenderPtr->getObjectFromCommonResult(rootValuePtr);
  currentpage = json_object_get_number(objPtr, "targetPage");
  allPages = json_object_get_number(objPtr, "allPages");
  JSON_Array *ayPtr = json_object_get_array(objPtr, "notes");
  for (int32_t index = 0; index < notePageSize;) {
    if (index >= json_array_get_count(ayPtr)) {
      noteArray[index] = {"", "", "", ""};
      ++index;
      continue;
    }
    NoteDetail detail;
    JSON_Object *objPtr = json_array_get_object(ayPtr, index);
    detail.id = json_object_get_string(objPtr, "id");
    detail.title = json_object_get_string(objPtr, "title");
    detail.content = json_object_get_string(objPtr, "content");
    detail.createTime = json_object_get_string(objPtr, "createTime");
    detail.updateTime = json_object_get_string(objPtr, "updateTime");
    noteArray[index] = detail;
    ++index;
  }
  json_value_free(rootValuePtr);
}
void GglNote::postToDeleteNoteDetail(NoteDetail *d) {
  GglTip *tipPtr = GglTip::getInstance();
  if (d->id.empty()) {
    tipPtr->setMsg("noteDetail is empty");
    tipPtr->show();
    return;
  }
  std::string res = httpSenderPtr->postForJsonStr(
      GglServerUrls::DELETE_NOTE_URL, d->toJsonStr());
  JSON_Value *rootValuePtr = json_parse_string(res.c_str());
  JSON_Object *objPtr = json_value_get_object(rootValuePtr);
  if (json_object_get_number(objPtr, "code") == 200.0) {

    tipPtr->setMsg(json_object_get_string(objPtr, "data"));
    tipPtr->show();
  }
  json_value_free(rootValuePtr);
}
} // namespace mystd