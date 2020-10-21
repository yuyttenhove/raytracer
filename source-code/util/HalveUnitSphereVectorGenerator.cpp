//
// Created by ellio on 15-10-2020.
//

#define _USE_MATH_DEFINES

#include "HalveUnitSphereVectorGenerator.h"
#include <cmath>
#include <random>

Vector3D HalveUnitSphereVectorGenerator::generateVectorHalveUnitSphere() {

    double random1 = rand() / (RAND_MAX + 1.);
    double random2 = rand() / (RAND_MAX + 1.);

    double phi = 2 * M_PI * random1;
    double cosineTheta = random2;
    double sineTheta = sqrt((1 - cosineTheta) * (1 + cosineTheta));

    double x = sineTheta * cos(phi);
    double y = sineTheta * sin(phi);
    double z = cosineTheta;

    return {x, y, z};
}

Vector3D HalveUnitSphereVectorGenerator::generateCosineWeightedVector() {
    double random1 = rand() / (RAND_MAX + 1.);
    double random2 = rand() / (RAND_MAX + 1.);

    double phi = 2 * M_PI * random1;
    double cosineTheta = sqrt(1 - random2);
    double sineTheta = sqrt(random2);

    double x = sineTheta * cos(phi);
    double y = sineTheta * sin(phi);
    double z = cosineTheta;

    return {x, y, z};
}
