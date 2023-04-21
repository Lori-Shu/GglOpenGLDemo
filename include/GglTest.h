#pragma once
#include<string>
#include<memory>
#include"GglTexture.h"
#include<imgui.h>
#include<vector>
#include"GglPreBuild.h"
namespace mystd{
    class Test {
        public:
        Test(){};
        virtual ~Test(){};
        virtual void onImGuiRender(){std::cout<<"should not in this method but the children's"<<std::endl;};
        std::string testName;
        bool showTestWindow;
    };

    class TextureTest:public Test{
        public:
         TextureTest(std::string filePath);
         ~TextureTest();
         void onImGuiRender();

        private:
         std::unique_ptr<GglTexture> txPtr;
    };
}