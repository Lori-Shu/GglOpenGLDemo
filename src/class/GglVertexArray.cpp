#include"GglVertexArray.h"
#include"VertexBufferLayout.h"
namespace mystd{
    using namespace std;
    GglVertexArray::GglVertexArray(){
        createVertexArray();
    }
    GglVertexArray::~GglVertexArray(){

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
        // 这个函数的最后一个参数指的是vertebuffer对象“每一份”buffer中“每个元素”（由几个float组成）在它所在的buffer中距离buffer初始位置的偏移量
        glVertexAttribPointer(index, e.count, e.type, e.normalized,
                              layout.stride,reinterpret_cast<const void*>( offset));
        glEnableVertexAttribArray(index);
        offset += e.count*layout.getTypeSize(e.type);
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