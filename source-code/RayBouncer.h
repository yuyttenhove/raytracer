//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAYBOUNCER_H
#define RAYTRACER_RAYBOUNCER_H


#include "Ray.h"
#include "Triangle.h"

class RayBouncer {

public:
    Ray getBounce(Triangle triangle, Ray ray);

};


#endif //RAYTRACER_RAYBOUNCER_H
