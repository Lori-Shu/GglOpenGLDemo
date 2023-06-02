#pragma once
#include <imgui.h>
#include<parson.h>
#include "GglHttpSender.h"
#include "GglPreBuild.h"

namespace mystd{
    struct NoteDetail{
        std::string title;
        std::string content;
        std::string createTime;
        std::string updateTime;
    };
    class SelectPagePostData{
        public:
        std::string toJsonStr();
        char* keyWord;
        int32_t targetPage;
    };
    class AddNotePostData {
      public:
        std::string toJsonStr();
        char* userId;
        char* title;
        char* content;
    };
class GglNoteEditor {
 public:
   GglNoteEditor(GglHttpSender *s);
   ~GglNoteEditor();
   void render();
   void show();
   void hide();
   void setCurreentDetail(NoteDetail d);

 private:
   void persistNote();
   GglHttpSender *httpSender;
   NoteDetail currentDetail;
   bool renderFlag;
   char titleBuf[256];
   char mainContentBuf[1024 * 10];
  
};
    class GglNote{
        public:
         GglNote(GglHttpSender *s);
         void render();
         void show();
         void hide();

        private:
         void postForNoteDetailPage(SelectPagePostData *d);
         bool renderFlag;
         int32_t currentpage;
         int32_t allPage;
         int32_t targetPage;
        GglHttpSender * httpSender;
         std::unique_ptr<GglNoteEditor> editorPtr;
         static const int32_t notePageSize=10;
         std::array<NoteDetail, notePageSize> noteArray;
         
    };
    
}
