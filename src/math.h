#pragma once

#include <cmath>
#include <cstdint>

struct Vec2Int {
  int32_t x, y;

  Vec2Int(int32_t x, int32_t y) : x(x), y(y) {}
};

struct Vec2 {
  float x, y;

  Vec2() : x(0.0f), y(0.0f) {}

  Vec2(float x, float y) : x(x), y(y) {}

  Vec2 operator+(const Vec2 &v) const { return Vec2(x + v.x, y + v.y); }

  Vec2 operator-(const Vec2 &other) const {
    return Vec2(x - other.x, y - other.y);
  }

  Vec2 operator*(float s) const { return Vec2(x * s, y * s); }

  Vec2 operator/(float s) const { return Vec2(x / s, y / s); }
};

struct Vec3 {
  float x, y, z;

  Vec3() : x(0.0f), y(0.0f), z(0.0f) {}

  Vec3(float x, float y, float z) : x(x), y(y), z(z) {}

  Vec3 operator+(const Vec3 &other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
  }

  Vec3 operator-(const Vec3 &v) const {
    return Vec3(x - v.x, y - v.y, z - v.z);
  }

  Vec3 operator*(float s) const { return Vec3(x * s, y * s, z * s); }

  Vec3 operator/(float s) const { return Vec3(x / s, y / s, z / s); }
};

struct Vec4 {
  float x, y, z, w;

  Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

  Vec4 operator+(const Vec4 &v) const {
    return Vec4(x + v.x, y + v.y, z + v.z, w + v.w);
  }

  Vec4 operator-(const Vec4 &v) const {
    return Vec4(x - v.x, y - v.y, z - v.z, w - v.w);
  }

  Vec4 operator*(float s) const { return Vec4(x * s, y * s, z * s, w * s); }

  Vec4 operator/(float s) const { return Vec4(x / s, y / s, z / s, w / s); }
};

struct Mat4 {
  float m[16];

  Mat4() {
    for (int i = 0; i < 16; ++i) m[i] = 0.0f;
  }

  Vec4 operator*(const Vec4 &v) const {
    return Vec4(m[0] * v.x + m[4] * v.y + m[8] * v.z + m[12] * v.w,
                m[1] * v.x + m[5] * v.y + m[9] * v.z + m[13] * v.w,
                m[2] * v.x + m[6] * v.y + m[10] * v.z + m[14] * v.w,
                m[3] * v.x + m[7] * v.y + m[11] * v.z + m[15] * v.w);
  }
};
