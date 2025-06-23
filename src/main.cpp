#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <iostream>

#include "framebuffer.h"
#include "math.h"
#include "mesh.h"

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
    if (p0.x == p1.x && p0.y == p1.y) break;
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
  Mesh mesh;
  mesh.load_from_obj("mesh.obj");
  for (size_t i = 0; i < mesh.face_count(); ++i) {
    auto face = mesh.face(i);
    for (size_t j = 0; j < 3; ++j) {
      Vec3 v0 = mesh.vertex(face[j]).position;
      Vec3 v1 = mesh.vertex(face[(j + 1) % 3]).position;
      Vec2Int p0(static_cast<int32_t>(v0.x * WIDTH / 2 + WIDTH / 2),
                 static_cast<int32_t>(-v0.y * HEIGHT / 2 + HEIGHT / 2));
      Vec2Int p1(static_cast<int32_t>(v1.x * WIDTH / 2 + WIDTH / 2),
                 static_cast<int32_t>(-v1.y * HEIGHT / 2 + HEIGHT / 2));
      draw_line(framebuffer, p0, p1, Vec3(1.0f, 1.0f, 1.0f));
    }
  }
  framebuffer.save("output.png");
  return 0;
}
