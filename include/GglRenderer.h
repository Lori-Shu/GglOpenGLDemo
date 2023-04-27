#pragma once
#include"GglVertexArray.h"
#include"GglIndexBuffer.h"
#include"GglShader.h"

namespace mystd{
    class GglRenderer{
        public:
         GglRenderer();
        GglRenderer(GglVertexArray& va, GglIndexBuffer& ib,
                                 GglShader& sd);
         ~GglRenderer();
         void clear();
         void draw();
         
        private:
         GglVertexArray* vaPtr;
        GglIndexBuffer* ibPtr;
         GglShader* sdPtr;
    };
}