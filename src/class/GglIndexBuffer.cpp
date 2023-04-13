#include"GglIndexBuffer.h"
namespace mystd{
GglIndexBuffer::GglIndexBuffer(uint32_t *indices, int32_t count){
    createIndexBuffer(indices,count);
}
GglIndexBuffer::~GglIndexBuffer(){
    glDeleteBuffers(1,&id);
}
void GglIndexBuffer::unBindIndexBuffer(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,0);
}
void GglIndexBuffer::bindIndexBuffer(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,id);
}
void GglIndexBuffer::createIndexBuffer(uint32_t *indices, int32_t count){
    glGenBuffers(1, &id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(uint32_t), indices,
                 GL_STATIC_DRAW);
}
}