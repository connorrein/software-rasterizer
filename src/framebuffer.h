#include <cstdint>
#include <limits>
#include <vector>

#include "math.h"
#include "stb_image_write.h"

class Framebuffer {
  uint32_t width, height;
  std::vector<Vec3> colors;
  std::vector<float> depth;

public:
  Framebuffer(uint32_t width, uint32_t height)
      : width(width), height(height),
        colors(width * height, Vec3(0.0f, 0.0f, 0.0f)),
        depth(width * height, std::numeric_limits<float>::max()) {}

  void set_pixel(Vec2Int pos, Vec3 color) {
    if (pos.x < 0 || pos.x >= width || pos.y < 0 || pos.y >= height)
      return;
    colors[index(pos)] = color;
  }

  void save(const char *filename) const;

private:
  uint32_t index(Vec2Int pos) const { return pos.y * width + pos.x; }
};
