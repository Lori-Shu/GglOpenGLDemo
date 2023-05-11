#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include<array>

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
    };
}