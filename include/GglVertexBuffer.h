#pragma once
#include<cstdint>
#include<GL/glew.h>
namespace mystd{
    class GglVertexBuffer{
        public:
         GglVertexBuffer();
          GglVertexBuffer(float *positions, int32_t size);
         ~GglVertexBuffer();
         void unBindVertexBuffer();
         void bindVertexBuffer();
         uint32_t id;
         private:
          void createVertexBuffer(float *positions, int32_t size);    
        };
}