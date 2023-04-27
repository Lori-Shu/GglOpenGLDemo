#pragma once
#include<cstdint>
#include<GL/glew.h>
namespace mystd{

class GglDynamicVertexBuffer{
 public:
  GglDynamicVertexBuffer();
  ~GglDynamicVertexBuffer();
  void unBindVertexBuffer();
  void bindVertexBuffer();
  uint32_t id;

 private:
  void createVertexBuffer();
};
}