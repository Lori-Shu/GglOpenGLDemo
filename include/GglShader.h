#pragma once
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
namespace mystd{
    class GglShader{
        public:
         GglShader();
         ~GglShader();
         GglShader &operator=(GglShader &) = delete;
         GglShader &operator=(GglShader &&) = delete;
         uint32_t program;

        private:
        std::string readVertexShader();
        std::string readFragShader();
        std::string readFile(std::string &path);
        void createShader(std::string vertexShader, std::string fragShader);
        uint32_t compileShader(uint32_t type,std::string &shader);
        const std::string shaderFolder =
            "/home/lori/cppprojects/OpenGLDemo/src/shader/";
    };
}