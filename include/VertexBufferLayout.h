#pragma once
#include <glad/glad.h>

#include <cassert>
#include <cstdint>
#include <vector>
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
    void push(int32_t count);
    std::vector<VertexBufferLayoutElement> & getElements();
    uint32_t stride = 0;

   private:
    std::vector<VertexBufferLayoutElement> elements;

};

}