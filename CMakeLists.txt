cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(raytracer source-code/main.cpp source-code/util/Vector3D.cpp source-code/util/Vector3D.h source-code/Ray.cpp source-code/Ray.h source-code/Triangle.cpp source-code/Triangle.h source-code/RayIntensityCalculator.cpp source-code/RayIntensityCalculator.h source-code/TriangleCollection.h source-code/RayBouncer.cpp source-code/RayBouncer.h)