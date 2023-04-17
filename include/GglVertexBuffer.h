#pragma once
#include <glad/glad.h>

#include <cstdint>
namespace mystd{
    class GglVertexBuffer{
        public:
         GglVertexBuffer(float *positions, int32_t size);
         ~GglVertexBuffer();
         void unBindVertexBuffer();
         void bindVertexBuffer();
         uint32_t id;
         private:
          void createVertexBuffer(float *positions, int32_t size);
    };
}