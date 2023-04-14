#pragma once
#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
#include<unistd.h>
#include<unordered_map>
#define Linux
namespace mystd{
    class GglShader{
        public:
         GglShader();
         ~GglShader();
         GglShader &operator=(GglShader &) = delete;
         GglShader &operator=(GglShader &&) = delete;

         void setUniform(std::string uniformName, float v0, float v1, float v2,
                         float v3);
         void useProgram();
         void unUseProgram();
         uint32_t program;
         std::unordered_map<std::string,int32_t> locationCache;

        private:
         void getProgramDir(std::string &path);
         void readShaderFile(
             std::string &vertexShader, std::string &fragmentShader);
         void createShader();
         uint32_t compileShader(uint32_t type, std::string &shader);
         
    };
}