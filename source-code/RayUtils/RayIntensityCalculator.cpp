//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"
#include "../Geometry/MeshCollection.h"

double RayIntensityCalculator::calculateIntensityRay(Ray &ray) {
    while (ray.getNumberOfBouncesBefore() <= bounceDepth) {
        Vector3D interSectionPoint = Vector3D();
        Triangle *triangle = meshCollection->getClosestTriangle(ray, &interSectionPoint);
        if (triangle == nullptr) {
            break;
        }

        bool bounced = triangle->getMesh()->getMaterial()->bounceRay(ray, triangle->getNormal(), interSectionPoint);
        if (!bounced) {
            return ray.getIntensity();
        }
    }
    return 0;
}

RayIntensityCalculator::RayIntensityCalculator(
        int bounceDepth,
        MeshCollection *meshCollection
) :
        bounceDepth(bounceDepth),
        meshCollection(meshCollection) {}

