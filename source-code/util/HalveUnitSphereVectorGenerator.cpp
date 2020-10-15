//
// Created by ellio on 15-10-2020.
//

#define _USE_MATH_DEFINES

#include "HalveUnitSphereVectorGenerator.h"
#include <cmath>
#include <random>

Vector3D HalveUnitSphereVectorGenerator::generateVectorHalveUnitSphere() {

    std::default_random_engine generator;
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    double random1 = distribution(generator);
    double random2 = distribution(generator);

    double phi = 2 * M_PI * random1;
    double cosineTheta = random2;
    double sineTheta = sqrt((1 - cosineTheta) * (1 + cosineTheta));

    double x = sineTheta * cos(phi);
    double y = sineTheta * sin(phi);
    double z = cosineTheta;

    return {x, y, z};
}
