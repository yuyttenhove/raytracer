//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"

double RayIntensityCalculator::calculateIntensityRay(Ray ray, TriangleCollection *triangleCollection) {

    Triangle *triangle = triangleCollection->getClosestTriangle(ray);

    if (triangle == nullptr) {
        return 0;
    } else if (triangle->getMaterial()->isLightSource()) {
        return 1;
    }

    return 0;
}

RayIntensityCalculator::RayIntensityCalculator(int numberOfRaysPerBounce, int bounceDepth) {
    this->numberOfRaysPerBounce = numberOfRaysPerBounce;
    this->bounceDepth = bounceDepth;
}

