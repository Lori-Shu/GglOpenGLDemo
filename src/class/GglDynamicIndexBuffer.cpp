#include"GglDynamicIndexBuffer.h"

namespace mystd{
using namespace std;
GglDynamicIndexBuffer::GglDynamicIndexBuffer() { createIndexBuffer(); }
GglDynamicIndexBuffer::~GglDynamicIndexBuffer() { glDeleteBuffers(1, &id); }
void GglDynamicIndexBuffer::unBindIndexBuffer() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
void GglDynamicIndexBuffer::bindIndexBuffer() {
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
}
void GglDynamicIndexBuffer::createIndexBuffer() {
  glGenBuffers(1, &id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, 1024 * sizeof(float), nullptr,
               GL_DYNAMIC_DRAW);
}
}