//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MESHCOLLECTION_H
#define RAYTRACER_MESHCOLLECTION_H

#include "Triangle.h"
#include "Mesh.h"
#include "../RayUtils/Ray.h"
#include <vector>


class MeshCollection {

    vector<Mesh *> meshes;

public:
    MeshCollection(const vector<Mesh *> meshes);

    Triangle *getClosestTriangle(Ray *ray, Vector3D *interSectionPoint);

private:
    bool rayIntersectsTriangle(Vector3D rayOrigin, Vector3D rayVector, Triangle *inTriangle, float *pathLength);
};


#endif //RAYTRACER_MESHCOLLECTION_H
