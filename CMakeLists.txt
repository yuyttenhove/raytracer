cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracer source-code/main.cpp source-code/util/Vector3D.cpp source-code/util/Vector3D.h)