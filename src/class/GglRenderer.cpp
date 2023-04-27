#include"GglRenderer.h"

namespace mystd{
    using namespace std;
    GglRenderer::GglRenderer(){}
    GglRenderer::GglRenderer(GglVertexArray &va, GglIndexBuffer &ib,
                           GglShader &sd){
        vaPtr=&va;
        ibPtr=&ib;
        sdPtr=&sd;
    }
    GglRenderer::~GglRenderer(){}
    void GglRenderer::clear() { 
        glClearColor(0.0f,0.0f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
    }
    void GglRenderer::draw(){
        sdPtr->useProgram();
        vaPtr->bindVertexArray();
        ibPtr->bindIndexBuffer();
        glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    }
}