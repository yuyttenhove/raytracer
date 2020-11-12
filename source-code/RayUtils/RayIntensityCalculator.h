//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAYINTENSITYCALCULATOR_H
#define RAYTRACER_RAYINTENSITYCALCULATOR_H


#include "Ray.h"

class MeshCollection;

class RayIntensityCalculator {

    int bounceDepth;
    MeshCollection *meshCollection;

public:

    RayIntensityCalculator(int bounceDepth, MeshCollection *meshCollection);

    double calculateIntensityRay(Ray &ray);

};


#endif //RAYTRACER_RAYINTENSITYCALCULATOR_H
