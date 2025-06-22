#include "framebuffer.h"
#include "math.h"
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>

const int WIDTH = 800;
const int HEIGHT = 600;

void draw_line(Framebuffer &framebuffer, Vec2Int p0, Vec2Int p1, Vec3 color) {
  int32_t dx = std::abs(p1.x - p0.x);
  int32_t dy = std::abs(p1.y - p0.y);
  int32_t sx = p0.x < p1.x ? 1 : -1;
  int32_t sy = p0.y < p1.y ? 1 : -1;
  int32_t err = dx - dy;
  while (true) {
    framebuffer.set_pixel(p0, color);
    if (p0.x == p1.x && p0.y == p1.y)
      break;
    int32_t e2 = 2 * err;
    if (e2 > -dy) {
      err -= dy;
      p0.x += sx;
    }
    if (e2 < dx) {
      err += dx;
      p0.y += sy;
    }
  }
}

int main(int argc, char **argv) {
  Framebuffer framebuffer(WIDTH, HEIGHT);
  draw_line(framebuffer, Vec2Int(100, 100), Vec2Int(700, 500),
            Vec3(1.0f, 0.0f, 0.0f));
  framebuffer.save("output.png");
  return 0;
}
