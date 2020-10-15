//
// Created by ellio on 15-10-2020.
//

#include "DiffuseMaterial.h"
#include "../util/HalveUnitSphereVectorGenerator.h"
#include "../util/Matrix3x3.h"
#include <cmath>

DiffuseMaterial::DiffuseMaterial(double albedo) : albedo(albedo) {}

double DiffuseMaterial::calculateIntensity(
        Ray *ray,
        Triangle *triangle,
        RayIntensityCalculator *rayIntensityCalculator,
        Vector3D *interSectionPoint
) {
    int raysPerBounce = rayIntensityCalculator->getNumberOfRaysPerBounce();
    int bouncesBefore = ray->getNumberOfBouncesBefore();
    Vector3D normal = triangle->getNormal();

    Vector3D rotationAxis = normal.cross({0, 0, 1}).normalize();
    double cosTheta = normal.getZ();
    double sinTheta = sqrt((1 - cosTheta) * (1 + cosTheta));

    Matrix3x3 rotationMatrix = Matrix3x3(sinTheta, cosTheta, rotationAxis);

    double sumIntensities = 0.0;
    for (int i = 0; i < raysPerBounce; i++) {
        Vector3D randomVectorInHalveUnitSphere = HalveUnitSphereVectorGenerator::generateVectorHalveUnitSphere();
        double dalembertFactor = randomVectorInHalveUnitSphere.getZ();
        Vector3D rotatedVector = rotationMatrix.dot(randomVectorInHalveUnitSphere);

        Ray bounce = Ray(rotatedVector, *interSectionPoint, bouncesBefore + 1);
        sumIntensities += rayIntensityCalculator->calculateIntensityRay(&bounce) * dalembertFactor;
    }
    return sumIntensities * albedo / raysPerBounce;
}
