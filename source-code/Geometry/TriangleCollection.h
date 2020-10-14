//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_TRIANGLECOLLECTION_H
#define RAYTRACER_TRIANGLECOLLECTION_H

#include "Triangle.h"
#include "../RayUtils/Ray.h"

class TriangleCollection {

public:
    Triangle getClosestTriangle(Ray ray);


};


#endif //RAYTRACER_TRIANGLECOLLECTION_H
