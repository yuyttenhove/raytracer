//
// Created by ellio on 15-10-2020.
//

#include "ReflectiveMaterial.h"

ReflectiveMaterial::ReflectiveMaterial(double shininess) : shininess(shininess) {}

double ReflectiveMaterial::calculateIntensity(
        Ray *ray,
        Triangle *triangle,
        RayIntensityCalculator *rayIntensityCalculator,
        Vector3D *interSectionPoint
) {
    int numberOfBounces = ray->getNumberOfBouncesBefore();
    Vector3D direction = ray->getDirection();
    Vector3D normal = triangle->getNormal();

    Vector3D reflectedDirection = direction - 2 * (direction.dot(normal)) * normal;
    Ray reflectedRay = Ray(reflectedDirection, *interSectionPoint, numberOfBounces + 1);

    return rayIntensityCalculator->calculateIntensityRay(&reflectedRay) * shininess;
}

string ReflectiveMaterial::getExportString() {
    return reflectiveMaterialExportName + materialPropertiesDelimiter + to_string(shininess);
}
