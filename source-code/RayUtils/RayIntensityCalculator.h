//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAYINTENSITYCALCULATOR_H
#define RAYTRACER_RAYINTENSITYCALCULATOR_H


#include "Ray.h"
#include "../Geometry/TriangleCollection.h"
#include "RayBouncer.h"

class RayIntensityCalculator {

    TriangleCollection triangleCollection;
    RayBouncer rayBouncer;
    int numberOfRaysPerBounce;
    int bounceDepth;

public:

    RayIntensityCalculator(
            TriangleCollection triangleCollection,
            RayBouncer rayBouncer,
            int numberOfRaysPerBounce,
            int bounceDepth
    );


    double calculateIntensityRay(Ray ray);

};


#endif //RAYTRACER_RAYINTENSITYCALCULATOR_H
