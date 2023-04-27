#include"GglDynamicVertexBuffer.h"

namespace mystd{
    using namespace std;
    GglDynamicVertexBuffer::GglDynamicVertexBuffer() {
      createVertexBuffer();
    }
    GglDynamicVertexBuffer::~GglDynamicVertexBuffer() {
      glDeleteBuffers(1, &id);
    }
    void GglDynamicVertexBuffer::unBindVertexBuffer() {
      glBindBuffer(GL_ARRAY_BUFFER, 0);
    }
    void GglDynamicVertexBuffer::bindVertexBuffer() {
      glBindBuffer(GL_ARRAY_BUFFER, id);
    }
    void GglDynamicVertexBuffer::createVertexBuffer() {
      glGenBuffers(1, &id);
      glBindBuffer(GL_ARRAY_BUFFER, id);
      glBufferData(GL_ARRAY_BUFFER, 1024 * sizeof(float), nullptr,
                   GL_DYNAMIC_DRAW);
    }
}