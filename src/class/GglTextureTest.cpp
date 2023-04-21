#include"GglTest.h"

namespace mystd{
    using namespace std;
    TextureTest::TextureTest(std::string filePath){
        txPtr=make_unique<GglTexture>(filePath);
        testName=std::string("textureTest")+filePath;
        showTestWindow=false;
    }
    TextureTest::~TextureTest() {

    }
    void TextureTest::onImGuiRender(){
        if(showTestWindow){
        ImGui::Begin(testName.c_str());
        ImGui::Image(reinterpret_cast<void*>(txPtr->getTextureId()),ImVec2(txPtr->getWidth(),txPtr->getHeight()));
        ImGui::End();
        }
    }
    
}