//
// Created by ellio on 14-10-2020.
//

#include "EmissiveMaterial.h"

EmissiveMaterial::EmissiveMaterial(double intensity) : intensity(intensity) {}

bool EmissiveMaterial::bounceRay(Ray &ray, const Vector3D &normal, const Vector3D &interSectionPoint) {
    ray.setIntensity(intensity * ray.getIntensity());
    return false;
}

string EmissiveMaterial::getExportString() {
    return emissiveMaterialExportName + materialPropertiesDelimiter + to_string(intensity);
}

