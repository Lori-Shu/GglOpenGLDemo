#pragma once

#include <glad/glad.h>

#include <iostream>
#include <string>
namespace mystd{
    class GglTexture{
        public:
         GglTexture(std::string path);
         ~GglTexture();
         void bind(uint32_t slot);
         void unBind();

        private:
         void createTexture();

         uint32_t textureId;
         uint8_t* localBuffer;
         std::string filePath;
         int32_t width, height, bitsPerPixel;
    };
}