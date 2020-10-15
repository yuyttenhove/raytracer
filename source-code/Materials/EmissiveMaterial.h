//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_EMISSIVEMATERIAL_H
#define RAYTRACER_EMISSIVEMATERIAL_H


#include "Material.h"

class EmissiveMaterial : public Material {

    double intensity;

public:

    EmissiveMaterial(double intensity);

    double calculateIntensity(Ray *ray, Triangle *triangle, RayIntensityCalculator *rayIntensityCalculator) override;
};


#endif //RAYTRACER_EMISSIVEMATERIAL_H
