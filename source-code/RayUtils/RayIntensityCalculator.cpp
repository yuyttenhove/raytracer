//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"

double RayIntensityCalculator::calculateIntensityRay(Ray ray) {

    Triangle triangle = triangleCollection.getClosestTriangle(ray);

    if (triangle.getMaterial()->isLightSource()) {
        return 1;
    } else {
        return 0;
    }
}

RayIntensityCalculator::RayIntensityCalculator(
        TriangleCollection triangleCollection,
        RayBouncer rayBouncer,
        int numberOfRaysPerBounce,
        int bounceDepth
) {
    this->triangleCollection = triangleCollection;
    this->rayBouncer = rayBouncer;
    this->numberOfRaysPerBounce = numberOfRaysPerBounce;
    this->bounceDepth = bounceDepth;
}

