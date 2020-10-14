//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"

double RayIntensityCalculator::calculateIntensityRay(Ray ray) {

    Triangle triangle = triangleCollection.getClosestTriangle(ray);


    double totalIntensity = 0;
    for (int i = 0; i < numberOfRaysPerBounce; ++i) {
        Ray bounce = rayBouncer.getBounce(triangle, ray);
        double intensity = calculateIntensityRay(bounce);
        totalIntensity += intensity;
    }

    return totalIntensity;
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

