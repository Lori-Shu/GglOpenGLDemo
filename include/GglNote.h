#pragma once
#include <imgui.h>
#include<parson.h>
#include "GglHttpSender.h"
#include "GglPreBuild.h"
#include"GglTip.h"

namespace mystd{
    struct NoteDetail{
        std::string toJsonStr();
        std::string id;
        std::string title;
        std::string content;
        std::string createTime;
        std::string updateTime;
    };
    class SelectPagePostData{
        public:
        std::string toJsonStr();
        std::string keyword;
        int32_t targetPage;
        std::string userId;
    };
    /**
     * if id ="" is add id!="" is edit(update)
    */
    class AddOrEditNotePostData {
      public:
        std::string toJsonStr();
        std::string userId;
        std::string title;
        std::string content;
        std::string id;
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
   GglHttpSender *httpSenderPtr;
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
         void postForNoteDetailPage(SelectPagePostData *d);
         void postToDeleteNoteDetail(NoteDetail* d);
       private:
         
         bool renderFlag;
         int32_t currentpage;
         int32_t allPages;
         int32_t targetPage;
        GglHttpSender * httpSenderPtr;
         std::unique_ptr<GglNoteEditor> editorPtr;
         static const int32_t notePageSize=10;
         std::array<NoteDetail, notePageSize> noteArray;
         
    };
    
}
