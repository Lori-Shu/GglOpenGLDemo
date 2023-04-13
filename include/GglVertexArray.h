#pragma once
#include<cstdint>
#include"GglVertexBuffer.h"
#include"VertexBufferLayout.h"
namespace mystd{
    class GglVertexArray{
        public:
         GglVertexArray();
         ~GglVertexArray();
         void addVertexBuffer(GglVertexBuffer& vb,VertexBufferLayout& layout);
         void bindVertexArray();
         uint32_t id;
         private:
         void createVertexArray();
    };
}
