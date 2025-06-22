#include "framebuffer.h"
#include "stb_image_write.h"
#include <algorithm>
#include <cstdint>

static inline uint8_t float_to_u8(float c) {
  return static_cast<uint8_t>(std::clamp(c * 255.0f, 0.0f, 255.0f));
}

void Framebuffer::save(const char *filename) const {
  std::vector<uint8_t> out(width * height * 3);
  for (size_t i = 0; i < width * height; ++i) {
    out[i * 3 + 0] = float_to_u8(colors[i].x);
    out[i * 3 + 1] = float_to_u8(colors[i].y);
    out[i * 3 + 2] = float_to_u8(colors[i].z);
  }
  stbi_write_png(filename, width, height, 3, out.data(), width * 3);
}
