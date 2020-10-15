//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_TRIANGLECOLLECTION_H
#define RAYTRACER_TRIANGLECOLLECTION_H

#include "Triangle.h"
#include "../RayUtils/Ray.h"
#include <vector>

class TriangleCollection {

    vector<Triangle *> triangles;

public:

    TriangleCollection(const vector<Triangle *> triangles);

    Triangle *getClosestTriangle(Ray ray);

    bool rayIntersectsTriangle(Vector3D rayOrigin, Vector3D rayVector, Triangle *inTriangle, float *pathLength);
};


#endif //RAYTRACER_TRIANGLECOLLECTION_H
