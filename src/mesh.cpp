#include "mesh.h"

#include <fstream>

void Mesh::load_from_obj(const std::string &filename) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    throw std::runtime_error("Failed to open file: " + std::string(filename));
  }

  std::string line;
  while (std::getline(file, line)) {
    if (line.rfind("v ", 0) == 0) {
      Vec3 position;
      sscanf(line.c_str(), "v %f %f %f", &position.x, &position.y, &position.z);
      vertices_.emplace_back(position, Vec3(), Vec2());
    } else if (line.rfind("f ", 0) == 0) {
      uint32_t v0, vt0, vn0, v1, vt1, vn1, v2, vt2, vn2;
      sscanf(line.c_str(), "f %d/%d/%d %d/%d/%d %d/%d/%d", &v0, &vt0, &vn0, &v1,
             &vt1, &vn1, &v2, &vt2, &vn2);
      faces_.push_back({v0 - 1, v1 - 1, v2 - 1});
    }
  }
}
