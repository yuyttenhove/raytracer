//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_TRIANGLECOLLECTION_H
#define RAYTRACER_TRIANGLECOLLECTION_H

#include "Triangle.h"
#include "../RayUtils/Ray.h"
#include <vector>

class TriangleCollection {

    vector<Triangle> triangles;

public:
    Triangle getClosestTriangle(Ray ray);


};


#endif //RAYTRACER_TRIANGLECOLLECTION_H
