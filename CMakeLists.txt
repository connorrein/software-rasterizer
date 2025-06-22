cmake_minimum_required(VERSION 3.15...4.0)

project("Software Rasterizer")

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/framebuffer.cpp
    src/main.cpp
    src/stb_image_write.cpp
)

add_executable(rasterizer ${SOURCES})

target_include_directories(rasterizer PRIVATE third_party)
