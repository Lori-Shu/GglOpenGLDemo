#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "GglBackground.h"
#include "GglIndexBuffer.h"
#include "GglRenderer.h"
#include "GglShader.h"
#include "GglTest.h"
#include "GglTexture.h"
#include "GglVertexArray.h"
#include "GglVertexBuffer.h"
#include "VertexBufferLayout.h"
#include"GglDynamicVertexBuffer.h"
#include"GglDynamicIndexBuffer.h"
#include"GglNote.h"
#include"GglMainWindowManager.h"
#include"GglHttpSender.h"
#include"GglTip.h"
#ifdef Windows
#include <Windows.h>
#endif
void getProgramDir(std::string &path) {
  char proDir[1024];
//   只在Linux环境有效
#ifdef Linux
  int32_t size = readlink("/proc/self/exe", proDir, 1024);
  std::string tp = std::string(proDir);

  int32_t lastIndex = tp.find_last_of('/');
  path = tp.substr(0, lastIndex + 1 - 0);
  std::cout << "proDir==" << path << std::endl;
#endif
#ifdef Windows
  GetModuleFileName(NULL, proDir, 1024);
  std::string tp = std::string(proDir);
  int32_t lastIndex = tp.find_last_of('\\');
  path = tp.substr(0, lastIndex + 1 - 0);
  std::cout << "proDir==" << path << std::endl;
#endif
}

namespace mystd{
    struct GglVertex{
        glm::vec3 position;
        glm::vec4 color;
        glm::vec2 texCoord;
        float vertexId;
    };
    class App final{
        public:
        App();
        ~App();
        void runMainLoop();
        private:
        void  setDebugMessageCallBack();
        void loadVertexBufferDynamicly(int32_t objectRow, int32_t objectColumn);
        GglVertex * createVertexVec4(GglVertex* offsetPtr,float botlx, float botly,
                                                  float id);
        int32_t initEnvironment();
        void loadIndexBufferDynamicly(int32_t objectRow, int32_t objectColumn);
        GLFWwindow* windowPtr;
        std::unique_ptr<mystd::GglVertexArray> vaPtr;
        std::unique_ptr<mystd::GglVertexBuffer> vbPtr;
        std::unique_ptr<mystd::GglDynamicVertexBuffer> dynamicVbPtr;
        std::unique_ptr<mystd::GglDynamicIndexBuffer> dynamicIbPtr;
        std::unique_ptr <mystd::GglIndexBuffer> ibPtr;
        std::unique_ptr<mystd::GglShader> gglShaderPtr;
        glm::mat4 projectionPerspective;
        glm::mat4 projectionOrth;
        glm::mat4 view ;
        glm::mat4 model;
        glm::mat4 mvp;
        std::string programPath;
        std::unique_ptr < mystd::GglRenderer> rdererPtr;
        float imageTranslateXYZ[3] = {0.0f, 0.0f, -100.0f};
        std::unique_ptr<mystd::GglBackground> bkPtr;
        mystd::Test* currentTestPtr;
        std::vector<mystd::Test*> testVt;
        std::vector<std::unique_ptr<mystd::GglTexture>> textureVector;
        std::unique_ptr<mystd::GglNote> notePtr;
        std::unique_ptr<mystd::GglMainWindowManager> windowManagerPtr;
        std::unique_ptr<mystd::GglHttpSender> httpSenderPtr;
    };
}