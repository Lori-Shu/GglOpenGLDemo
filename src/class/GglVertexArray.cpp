#include"GglVertexArray.h"
#include"VertexBufferLayout.h"
namespace mystd{
    using namespace std;
    GglVertexArray::GglVertexArray(){
        createVertexArray();
    }
    GglVertexArray::~GglVertexArray(){
        glDeleteVertexArrays(1,&id);
    }
    void GglVertexArray::addVertexBuffer(GglVertexBuffer& vb,
                                         VertexBufferLayout& layout) {
        bindVertexArray();
      vb.bindVertexBuffer();
      int32_t offset = 0;
      auto& elements =
          layout.getElements();
         for (int32_t index = 0; index <elements .size();) {
        VertexBufferLayoutElement& e = elements[index];
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, e.count, e.type, e.normalized,
                              layout.stride,reinterpret_cast<const void*>( offset));
        offset += e.count*sizeof(float);
        ++index;
      }
    }
    void GglVertexArray::bindVertexArray() {
        glBindVertexArray(id);
    }
    void GglVertexArray::createVertexArray(){
        glGenVertexArrays(1,&id);
    }
}