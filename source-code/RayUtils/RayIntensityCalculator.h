//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAYINTENSITYCALCULATOR_H
#define RAYTRACER_RAYINTENSITYCALCULATOR_H


#include "Ray.h"
#include "../Geometry/TriangleCollection.h"
#include "RayBouncer.h"

class RayIntensityCalculator {

    int numberOfRaysPerBounce;
    int bounceDepth;

public:

    RayIntensityCalculator(int numberOfRaysPerBounce, int bounceDepth);

    double calculateIntensityRay(Ray ray, TriangleCollection *triangleCollection);

};


#endif //RAYTRACER_RAYINTENSITYCALCULATOR_H
