#pragma once
#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
#include<unistd.h>
#include<unordered_map>
#include<glm/glm.hpp>
#define Linux
namespace mystd{
    class GglShader{
        public:
         GglShader();
         ~GglShader();
         GglShader &operator=(GglShader &) = delete;
         GglShader &operator=(GglShader &&) = delete;

         void setUniform4f(std::string uniformName, float v0, float v1, float v2,
                         float v3);
        void setUniform1i(std::string uniformName,int32_t i);
        void setUniformMatrix4f(std::string uniformName,glm::mat4 mtx);
        void useProgram();
        void unUseProgram();
        void getProgramDir(std::string &path);
        uint32_t program;
        std::unordered_map<std::string, int32_t> locationCache;

       private:
        void readShaderFile(std::string &vertexShader,
                            std::string &fragmentShader);
        void createShader();
        uint32_t compileShader(uint32_t type, std::string &shader);
        int32_t getUniformLocation(std::string name);
         
    };
}