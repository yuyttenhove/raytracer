//
// Created by ellio on 14-10-2020.
//

#include "EmissiveMaterial.h"
#include "../RayUtils/RayIntensityCalculator.h"


EmissiveMaterial::EmissiveMaterial(double intensity) : intensity(intensity) {}

double
EmissiveMaterial::calculateIntensity(
        Ray *ray,
        Triangle *triangle,
        RayIntensityCalculator *rayIntensityCalculator,
        Vector3D *interSectionPoint
) {
    return intensity;
}

