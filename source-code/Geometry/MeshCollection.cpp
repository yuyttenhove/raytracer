//

#include "MeshCollection.h"

//
// Created by ellio on 14-10-2020.

MeshCollection::MeshCollection(const vector<Mesh *> meshes) : meshes(meshes) {}

Triangle *MeshCollection::getClosestTriangle(const Ray &ray, Vector3D &interSectionPoint) {
    float t = FLT_MAX;
    float pathLength;
    Triangle *closestTriangle = nullptr;

    const Vector3D &origin = ray.getStartPoint();
    const Vector3D &direction = ray.getDirection();
    for (Mesh *mesh : meshes) {
        for (auto triangle:mesh->getTriangles()) {
            bool triangleFacesRay = triangle->getNormal().dot(ray.getDirection()) < 0;

            if (triangleFacesRay) {
                bool intersects = ray.intersectsTriangle(*triangle, &pathLength);
                if (intersects && pathLength < t) {
                    t = pathLength;
                    closestTriangle = triangle;
                }
            }
        }
    }
    if (closestTriangle != nullptr) {
        interSectionPoint = origin + direction * t;
    }
    return closestTriangle;
}

const vector<Mesh *> &MeshCollection::getMeshes() const {
    return meshes;
}
