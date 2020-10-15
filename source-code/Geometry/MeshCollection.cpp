//

#include "MeshCollection.h"

//
// Created by ellio on 14-10-2020.

MeshCollection::MeshCollection(const vector<Mesh *> meshes) : meshes(meshes) {}

Triangle *MeshCollection::getClosestTriangle(Ray *ray, Vector3D *interSectionPoint) {
    float t = FLT_MAX;
    float pathLength;
    Triangle *closestTriangle = nullptr;

    const Vector3D &origin = ray->getStartPoint();
    const Vector3D &direction = ray->getDirection();
    for (Mesh *mesh : meshes) {
        for (auto triangle:mesh->getTriangles()) {
            bool intersects = this->rayIntersectsTriangle(
                    origin,
                    direction,
                    triangle,
                    &pathLength
            );
            if (intersects && pathLength < t) {
                t = pathLength;
                closestTriangle = triangle;
            }
        }
    }

    if (closestTriangle != nullptr) {
        *interSectionPoint = origin + direction * t;
    }
    return closestTriangle;
}

bool MeshCollection::rayIntersectsTriangle(Vector3D rayOrigin,
                                           Vector3D rayVector,
                                           Triangle *inTriangle,
                                           float *pathLength) {
    const float EPSILON = 0.0000001;
    Vector3D vertex0 = inTriangle->getVertex0();
    Vector3D vertex1 = inTriangle->getVertex1();
    Vector3D vertex2 = inTriangle->getVertex2();
    Vector3D edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = rayVector.cross(edge2);
    a = edge1.dot(h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.
    f = 1.0 / a;
    s = rayOrigin - vertex0;
    u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = s.cross(edge1);
    v = f * rayVector.dot(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dot(q);
    *pathLength = t;
    if (t > EPSILON) {
        return true;
    } else {
        return false;
    }
}
