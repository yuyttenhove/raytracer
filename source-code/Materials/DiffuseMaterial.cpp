//
// Created by ellio on 15-10-2020.
//

#include "DiffuseMaterial.h"
#include "../MeshCollectionExporter/ExportStrings.h"
#include "../util/HalveUnitSphereVectorGenerator.h"

DiffuseMaterial::DiffuseMaterial(double albedo) : albedo(albedo) {}

bool DiffuseMaterial::bounceRay(Ray &ray, const Vector3D &normal, const Vector3D &interSectionPoint) {
    Vector3D bounceDirection = HalveUnitSphereVectorGenerator::generateCosineWeightedVectorAroundNormal(normal);
    ray.bounce(bounceDirection, interSectionPoint, albedo * ray.getIntensity());
    return true;
}

string DiffuseMaterial::getExportString() {
    return diffuseMaterialExportName + materialPropertiesDelimiter + to_string(albedo);
}
