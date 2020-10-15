//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAYINTENSITYCALCULATOR_H
#define RAYTRACER_RAYINTENSITYCALCULATOR_H


#include "Ray.h"
#include "RayBouncer.h"

class MeshCollection;

class RayIntensityCalculator {

    int numberOfRaysPerBounce;
    int bounceDepth;
    MeshCollection *meshCollection;

public:

    RayIntensityCalculator(int numberOfRaysPerBounce, int bounceDepth, MeshCollection *meshCollection);

    double calculateIntensityRay(Ray *ray);

    int getNumberOfRaysPerBounce() const;

};


#endif //RAYTRACER_RAYINTENSITYCALCULATOR_H
