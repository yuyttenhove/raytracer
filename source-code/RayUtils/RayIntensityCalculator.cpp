//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"
#include "../Geometry/MeshCollection.h"

double RayIntensityCalculator::calculateIntensityRay(Ray &ray) {

    if (ray.getNumberOfBouncesBefore() > bounceDepth) {
        return 0;
    }

    Vector3D interSectionPoint = Vector3D();
    Triangle *triangle = meshCollection->getClosestTriangle(ray, &interSectionPoint);
    if (triangle == nullptr) {
        return 0;
    }

    bool bounced = triangle->getMesh()->getMaterial()->bounceRay(ray, triangle->getNormal(), interSectionPoint);
    if (!bounced) {
        return ray.getIntensity();
    }

    return calculateIntensityRay(ray);  // tail recursion is faster
}

RayIntensityCalculator::RayIntensityCalculator(
        int bounceDepth,
        MeshCollection *meshCollection
) :
        bounceDepth(bounceDepth),
        meshCollection(meshCollection) {}

