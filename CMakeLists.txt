cmake_minimum_required(VERSION 3.17)
project(raytracer)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        raytracer
        source-code/main.cpp
        source-code/util/Vector3D.cpp
        source-code/util/Vector3D.h
        source-code/Geometry/Triangle.cpp
        source-code/Geometry/Triangle.h
        source-code/RayUtils/Ray.cpp
        source-code/RayUtils/Ray.h
        source-code/Geometry/MeshCollection.h
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
        source-code/Geometry/MeshCollection.cpp
        source-code/Geometry/Mesh.cpp source-code/Geometry/Mesh.h
        source-code/util/MatrixUtils.cpp
        source-code/util/MatrixUtils.h
        source-code/Materials/ReflectiveMaterial.cpp
        source-code/Materials/ReflectiveMaterial.h
        source-code/util/Matrix3x3.cpp
        source-code/util/Matrix3x3.h
        source-code/Materials/DiffuseMaterial.cpp
        source-code/Materials/DiffuseMaterial.h
        source-code/util/HalveUnitSphereVectorGenerator.cpp
        source-code/util/HalveUnitSphereVectorGenerator.h
        source-code/Geometry/MeshGenerator.cpp
        source-code/Geometry/MeshGenerator.h
        source-code/Geometry/MeshTransformer.cpp
        source-code/Geometry/MeshTransformer.h
        source-code/SystemSpecificConstants.h
        source-code/MeshCollectionExporter/ExportStrings.h
        source-code/MeshCollectionExporter/MeshStringCreator.cpp
        source-code/MeshCollectionExporter/MeshStringCreator.h
        source-code/MeshCollectionExporter/MeshCollectionStringCreator.cpp
        source-code/MeshCollectionExporter/MeshCollectionStringCreator.h
        source-code/MeshCollectionImporter/MeshCollectionCreatorFromString.cpp
        source-code/MeshCollectionImporter/MeshCollectionCreatorFromString.h
        source-code/MeshCollectionImporter/MeshCreatorFromString.cpp
        source-code/MeshCollectionImporter/MeshCreatorFromString.h
        source-code/MeshCollectionImporter/MeshCollectionFromFileReader.cpp
        source-code/MeshCollectionImporter/MeshCollectionFromFileReader.h source-code/util/RandomUtils.cpp source-code/util/RandomUtils.h)


add_executable(
        meshExporter
        source-code/util/Vector3D.cpp
        source-code/util/Vector3D.h
        source-code/Geometry/Triangle.cpp
        source-code/Geometry/Triangle.h
        source-code/RayUtils/Ray.cpp
        source-code/RayUtils/Ray.h
        source-code/Geometry/MeshCollection.h
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
        source-code/Geometry/MeshCollection.cpp
        source-code/Geometry/Mesh.cpp source-code/Geometry/Mesh.h
        source-code/util/MatrixUtils.cpp source-code/util/MatrixUtils.h
        source-code/Materials/ReflectiveMaterial.cpp
        source-code/Materials/ReflectiveMaterial.h
        source-code/util/Matrix3x3.cpp
        source-code/util/Matrix3x3.h
        source-code/Materials/DiffuseMaterial.cpp
        source-code/Materials/DiffuseMaterial.h
        source-code/util/HalveUnitSphereVectorGenerator.cpp
        source-code/util/HalveUnitSphereVectorGenerator.h
        source-code/Geometry/MeshGenerator.cpp
        source-code/Geometry/MeshGenerator.h
        source-code/Geometry/MeshTransformer.cpp
        source-code/Geometry/MeshTransformer.h
        source-code/SystemSpecificConstants.h
        source-code/MeshFileExporter.cpp
        source-code/MeshCollectionExporter/ExportStrings.h
        source-code/MeshCollectionExporter/MeshStringCreator.cpp
        source-code/MeshCollectionExporter/MeshStringCreator.h
        source-code/MeshCollectionExporter/MeshCollectionStringCreator.cpp
        source-code/MeshCollectionExporter/MeshCollectionStringCreator.h
        source-code/MeshCollectionImporter/MeshCollectionCreatorFromString.cpp
        source-code/MeshCollectionImporter/MeshCollectionCreatorFromString.h
        source-code/MeshCollectionImporter/MeshCreatorFromString.cpp
        source-code/MeshCollectionImporter/MeshCreatorFromString.h
        source-code/MeshCollectionImporter/MeshCollectionFromFileReader.cpp
        source-code/MeshCollectionImporter/MeshCollectionFromFileReader.h source-code/util/RandomUtils.cpp source-code/util/RandomUtils.h)
