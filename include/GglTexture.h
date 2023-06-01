#pragma once

#include<string>
#include <glad/glad.h>
#include<iostream>
namespace mystd{
    class GglTexture{
        public:
         GglTexture(std::string path);
         ~GglTexture();
         void bind(uint32_t slot);
         void unBind();
        uint32_t getTextureId();
        int32_t getWidth();
        int32_t getHeight();

       private:
        void createTexture();

        uint32_t textureId;
        uint8_t* localBuffer;
        std::string filePath;
        int32_t width, height, bitsPerPixel;
    };
}