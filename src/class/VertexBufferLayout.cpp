#include"VertexBufferLayout.h"
namespace mystd{
    using namespace std;
VertexBufferLayout::VertexBufferLayout(){

}
VertexBufferLayout ::~VertexBufferLayout(){

}
std::vector<VertexBufferLayoutElement>& VertexBufferLayout ::getElements() {
  return elements;
}
template <>
void VertexBufferLayout::push<double>(int32_t count) {
  elements.push_back(VertexBufferLayoutElement{count, GL_DOUBLE, GL_FALSE});
  stride += count * sizeof(double);
}
template <>
void VertexBufferLayout::push<float>(int32_t count) {
  elements.push_back(VertexBufferLayoutElement{count, GL_FLOAT, GL_FALSE});
  stride += count * sizeof(float);
}
template <>
void VertexBufferLayout::push<unsigned char>(int32_t count) {
  elements.push_back(
      VertexBufferLayoutElement{count, GL_UNSIGNED_BYTE, GL_TRUE});
  stride += count * sizeof(unsigned char);
}
}