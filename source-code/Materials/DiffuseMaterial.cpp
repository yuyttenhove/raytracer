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

    Vector3D zAxis = {0, 0, 1};
    Vector3D rotationAxis = zAxis.cross(normal);

    Matrix3x3 rotationMatrix;
    if (rotationAxis.length() < 0.0001) {
        double res = normal.dot({0, 0, 1});
        rotationMatrix = Matrix3x3();
        rotationMatrix.setElement(0, 0, 1);
        rotationMatrix.setElement(1, 1, 1);
        rotationMatrix.setElement(2, 2, res);
    } else {
        double cosTheta = normal.getZ();
        double sinTheta = sqrt((1 - cosTheta) * (1 + cosTheta));
        rotationMatrix = Matrix3x3(sinTheta, cosTheta, rotationAxis);
    }


    double sumIntensities = 0.0;
    for (int i = 0; i < raysPerBounce; i++) {
//        Vector3D randomVectorInHalveUnitSphere = HalveUnitSphereVectorGenerator::generateVectorHalveUnitSphere();
        Vector3D randomVectorInHalveUnitSphere = HalveUnitSphereVectorGenerator::generateCosineWeightedVector();
//        double dalembertFactor = randomVectorInHalveUnitSphere.getZ();
        Vector3D rotatedVector = rotationMatrix.dot(randomVectorInHalveUnitSphere);

        Ray bounce = Ray(rotatedVector, *interSectionPoint, bouncesBefore + 1);
        double intensityRay = rayIntensityCalculator->calculateIntensityRay(&bounce);
//        sumIntensities += 2 * intensityRay * dalembertFactor;
        sumIntensities += intensityRay;
    }

    return sumIntensities * albedo / raysPerBounce;
}
