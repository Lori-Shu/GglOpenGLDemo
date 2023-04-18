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
int32_t VertexBufferLayout ::getTypeSize(uint32_t type){
    if(type==GL_FLOAT){
        return sizeof(float);
    }
    if (type == GL_INT) {
        return sizeof(int32_t);
    }
    if(type==GL_BYTE){
        return sizeof(int8_t);
    }
    return 0;
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