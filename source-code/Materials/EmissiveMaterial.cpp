//
// Created by ellio on 14-10-2020.
//

#include "EmissiveMaterial.h"

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

string EmissiveMaterial::getExportString() {
    return emissiveMaterialExportName;
}

