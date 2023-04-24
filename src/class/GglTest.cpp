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
        if (ImGui::Button("x")) {
          showTestWindow = !showTestWindow;
        }
        ImGui::Image(reinterpret_cast<void*>(txPtr->getTextureId()),ImVec2(txPtr->getWidth(),txPtr->getHeight()));
        ImGui::End();
        }
    }
    GglBKColorTest::GglBKColorTest(mystd::GglShader* shader):gglsr(shader),rgba({0.0f}) {
        testName=string("bgColor");
    }
    GglBKColorTest::~GglBKColorTest(){

    }
    void GglBKColorTest::onImGuiRender(){
        if(showTestWindow){
            ImGui::Begin("BackgroundColorTestWindow");
            if(ImGui::Button("x")){
                showTestWindow=!showTestWindow;
            }
            ImGui::ColorEdit4("==color",rgba);
            gglsr->useProgram();
            gglsr->setUniform4f("uColor", rgba[0], rgba[1], rgba[2], rgba[3]);
            ImGui::End();
        }
    }
}