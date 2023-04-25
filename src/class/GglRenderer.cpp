#include"GglRenderer.h"

namespace mystd{
    using namespace std;
    GglRenderer::GglRenderer(GglVertexArray &va, GglIndexBuffer &ib,
                           GglShader &sd){
        vaPtr=&va;
        ibPtr=&ib;
        sdPtr=&sd;
    }
    GglRenderer::~GglRenderer(){}
    void GglRenderer::clear() { 
        glClearColor(1.0f,1.0f,1.0f,0.2f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); 
    }
    void GglRenderer::draw(){
        sdPtr->useProgram();
        vaPtr->bindVertexArray();
        ibPtr->bindIndexBuffer();
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}