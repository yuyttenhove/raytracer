cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

#add_executable(raytracer source-code/main.cpp source-code/util/Vector3D.cpp source-code/util/Vector3D.h source-code/RayUtils/Ray.cpp source-code/RayUtils/Ray.h source-code/Geometry/Triangle.cpp source-code/Geometry/Triangle.h source-code/RayUtils/RayIntensityCalculator.cpp source-code/RayUtils/RayIntensityCalculator.h source-code/Geometry/TriangleCollection.h source-code/RayUtils/RayBouncer.cpp source-code/RayUtils/RayBouncer.h source-code/Geometry/Mesh.cpp source-code/Geometry/Mesh.h source-code/Materials/Material.h source-code/Materials/EmissiveMaterial.cpp source-code/Materials/EmissiveMaterial.h source-code/Scene/Camera.cpp source-code/Scene/Camera.h source-code/util/Picture.cpp source-code/util/Picture.h source-code/Scene/Scene.cpp source-code/Scene/Scene.h)
add_executable(
        raytracer
        source-code/main.cpp
        source-code/util/Vector3D.cpp
        source-code/util/Vector3D.h
        source-code/Geometry/Triangle.cpp
        source-code/Geometry/Triangle.h
        source-code/RayUtils/Ray.cpp
        source-code/RayUtils/Ray.h

        source-code/Geometry/TriangleCollection.h
        source-code/RayUtils/RayIntensityCalculator.cpp
        source-code/RayUtils/RayIntensityCalculator.h
        source-code/RayUtils/RayBouncer.cpp
        source-code/RayUtils/RayBouncer.h
        source-code/Materials/Material.h
        source-code/Materials/EmissiveMaterial.cpp
        source-code/Materials/EmissiveMaterial.h
        source-code/Scene/Camera.cpp
        source-code/Scene/Camera.h
        source-code/util/Picture.cpp
        source-code/util/Picture.h
        source-code/Scene/Scene.cpp
        source-code/Scene/Scene.h
        source-code/Geometry/TriangleCollection.cpp source-code/Geometry/Mesh.cpp source-code/Geometry/Mesh.h)
