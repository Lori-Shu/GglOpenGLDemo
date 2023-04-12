#pragma once
#include <GL/glew.h>

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include<cstdlib>
#include<unistd.h>
#define Linux
namespace mystd{
    class GglShader{
        public:
         GglShader();
         ~GglShader();
         GglShader &operator=(GglShader &) = delete;
         GglShader &operator=(GglShader &&) = delete;
         void setUniform();
         uint32_t program;

        private:
         void getProgramDir(std::string &path);
         void readShaderFile(
             std::string &vertexShader, std::string &fragmentShader);
         void createShader();
         uint32_t compileShader(uint32_t type, std::string &shader);
         
    };
}