#pragma once

#include"GglPreBuild.h"
#include"GglNote.h"
namespace mystd{
    class GglMainWindowManager{
        public:
         GglMainWindowManager(GglNote* n);
         void switchToNote();
         private:
         GglNote* notePtr;
    };
}