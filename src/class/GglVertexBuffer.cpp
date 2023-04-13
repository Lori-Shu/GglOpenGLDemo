#include"GglVertexBuffer.h"
namespace mystd{
GglVertexBuffer::GglVertexBuffer(double *positions,int32_t size){
    createVertexBuffer(positions,size);
}
GglVertexBuffer::~GglVertexBuffer() {
    glDeleteBuffers(1,&id);
}
void GglVertexBuffer::unBindVertexBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
void GglVertexBuffer::bindVertexBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER, id);
}
void GglVertexBuffer::createVertexBuffer(double *positions, int32_t size){
    glGenBuffers(1, &id);
    glBindBuffer(GL_ARRAY_BUFFER, id);
    glBufferData(GL_ARRAY_BUFFER, size * sizeof(double), positions,
                 GL_STATIC_DRAW);


}
}
