#pragma once
#include<cstdint>
#include<GL/glew.h>
namespace mystd{
    class GglVertexBuffer{
        public:
         GglVertexBuffer(double *positions, int32_t size);
         ~GglVertexBuffer();
         void unBindVertexBuffer();
         void bindVertexBuffer();
         uint32_t id;
         private:
          void createVertexBuffer(double *positions, int32_t size);
    };
}