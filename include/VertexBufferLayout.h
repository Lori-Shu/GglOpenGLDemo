#pragma once
#include<vector>
#include<cstdint>
#include<GL/glew.h>
#include<cassert>
namespace mystd{
struct VertexBufferLayoutElement{
    int32_t count;
    uint32_t type;
    unsigned char normalized;

};
class VertexBufferLayout {
 public:
  VertexBufferLayout();
  ~VertexBufferLayout();
    template<typename T>
    void push(int32_t count){
        assert(false && "you should not call this primitive method!");
    } 
    std::vector<VertexBufferLayoutElement> & getElements();
    uint32_t stride = 0;

   private:
    std::vector<VertexBufferLayoutElement> elements;

};

}