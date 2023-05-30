#pragma once
#include"GglPreBuild.h"
#include<imgui.h>

namespace mystd{
class GglNoteEditor {
 public:
  GglNoteEditor();
  ~GglNoteEditor();
  void render();
  void show();
  void hide();

 private:
  bool renderFlag;
  char titleBuf[256];
  char mainContentBuf[1024 * 10];
  
};
    class GglNote{
        public:
         GglNote();
         void render();
         void show();
         void hide();

        private:
         bool renderFlag;
         int currentpage;
         int allPage;
         int targetPage;
         std::unique_ptr<GglNoteEditor> editorPtr;
    };
    
}