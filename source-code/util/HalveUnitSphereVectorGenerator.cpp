//
// Created by ellio on 15-10-2020.
//

#define _USE_MATH_DEFINES

#include "HalveUnitSphereVectorGenerator.h"
#include "../util/RandomUtils.h"
#include "../util/Matrix3x3.h"

Vector3D HalveUnitSphereVectorGenerator::generateVectorHalveUnitSphere() {

    double random1 = RandomUtils::randomUniform();
    double random2 = RandomUtils::randomUniform();

    double phi = 2 * M_PI * random1;
    double cosineTheta = random2;
    double sineTheta = sqrt((1 - cosineTheta) * (1 + cosineTheta));

    double x = sineTheta * cos(phi);
    double y = sineTheta * sin(phi);
    double z = cosineTheta;

    return {x, y, z};
}

Vector3D HalveUnitSphereVectorGenerator::generateCosineWeightedVector() {
    double random1 = RandomUtils::randomUniform();
    double random2 = RandomUtils::randomUniform();

    double phi = 2 * M_PI * random1;
    double cosineTheta = sqrt(1 - random2);
    double sineTheta = sqrt(random2);

    double x = sineTheta * cos(phi);
    double y = sineTheta * sin(phi);
    double z = cosineTheta;

    return {x, y, z};
}

Vector3D HalveUnitSphereVectorGenerator::generateCosineWeightedVectorAroundNormal(const Vector3D &normal) {
    Vector3D cosineWeightedVector = generateCosineWeightedVector();
    Vector3D rotationAxis = Vector3D(0, 0, 1).cross(normal);

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

    return rotationMatrix.dot(cosineWeightedVector);
}
