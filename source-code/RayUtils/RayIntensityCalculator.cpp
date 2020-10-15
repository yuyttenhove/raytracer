//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"
#include "../Geometry/MeshCollection.h"

double RayIntensityCalculator::calculateIntensityRay(Ray *ray, MeshCollection *meshCollection) {

    Vector3D interSectionPoint = Vector3D();
    Triangle *triangle = meshCollection->getClosestTriangle(ray, &interSectionPoint);
    if (triangle == nullptr) {
        return 0;
    } else {
        return triangle->getMesh()->getMaterial()->calculateIntensity(ray, triangle, this, &interSectionPoint);
    }
}

RayIntensityCalculator::RayIntensityCalculator(int numberOfRaysPerBounce, int bounceDepth) {
    this->numberOfRaysPerBounce = numberOfRaysPerBounce;
    this->bounceDepth = bounceDepth;
}

