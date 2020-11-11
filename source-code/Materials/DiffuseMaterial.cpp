//
// Created by ellio on 15-10-2020.
//

#include "DiffuseMaterial.h"
#include "../MeshCollectionExporter/ExportStrings.h"
#include "../util/HalveUnitSphereVectorGenerator.h"

DiffuseMaterial::DiffuseMaterial(double albedo) : albedo(albedo) {}

double DiffuseMaterial::calculateIntensity(
        Ray *ray,
        Triangle *triangle,
        RayIntensityCalculator *rayIntensityCalculator,
        Vector3D *interSectionPoint
) {
    int bouncesBefore = ray->getNumberOfBouncesBefore();
    Vector3D normal = triangle->getNormal();

    Vector3D bounceDirection = HalveUnitSphereVectorGenerator::generateCosineWeightedVectorAroundNormal(normal);
    Ray bounce = Ray(bounceDirection, *interSectionPoint, bouncesBefore + 1);

    return albedo * rayIntensityCalculator->calculateIntensityRay(&bounce);
}

string DiffuseMaterial::getExportString() {
    return diffuseMaterialExportName + materialPropertiesDelimiter + to_string(albedo);
}
