#pragma once 
#include <glad/glad.h>
#include<cstdint>
namespace mystd{

class GglDynamicIndexBuffer {
 public:
  GglDynamicIndexBuffer();
  ~GglDynamicIndexBuffer();
  void unBindIndexBuffer();
  void bindIndexBuffer();
  uint32_t id;

 private:
  void createIndexBuffer();
};
}