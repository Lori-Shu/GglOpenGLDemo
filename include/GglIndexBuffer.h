#pragma once
#include<cstdint>
#include <glad/glad.h>
namespace mystd {
class GglIndexBuffer {
 public:
 /* index buffer must use uint32_t */
  GglIndexBuffer();
    GglIndexBuffer(uint32_t *indices, int32_t count);
  ~GglIndexBuffer();
  void unBindIndexBuffer();
  void bindIndexBuffer();
  uint32_t id;

 private:
  void createIndexBuffer(uint32_t *indices, int32_t count);
};
}  // namespace mystd