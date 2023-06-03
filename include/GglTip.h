#pragma once
#include"GglPreBuild.h"
#include"imgui.h"
namespace mystd{
    class GglTip{
        public:
          
          ~GglTip();
          void render();
          void show();
          void hide();
          static GglTip *getInstance();
          void setMsg(std::string msg);
          private:
          /**
           *  will construct singleton 
          */
            GglTip();
            static GglTip tipInstance;
            bool showFlag;
            static constexpr int32_t tipWordsSize = 1024;
            char tipWords[tipWordsSize];
    };
}