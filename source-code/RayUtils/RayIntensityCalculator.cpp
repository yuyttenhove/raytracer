//
// Created by ellio on 14-10-2020.
//

#include "RayIntensityCalculator.h"
#include "../Geometry/MeshCollection.h"

double RayIntensityCalculator::calculateIntensityRay(Ray *ray) {

    if (ray->getNumberOfBouncesBefore() > bounceDepth) {
        return 0;
    }

    Vector3D interSectionPoint = Vector3D();
    Triangle *triangle = meshCollection->getClosestTriangle(ray, &interSectionPoint);
    if (triangle == nullptr) {
        return world->getIntensity(ray->getDirection());
    } else {
        return triangle->getMesh()->getMaterial()->calculateIntensity(ray, triangle, this, &interSectionPoint);
    }
}

RayIntensityCalculator::RayIntensityCalculator(int numberOfRaysPerBounce, int bounceDepth,
                                               MeshCollection *meshCollection, World *world) :
        numberOfRaysPerBounce(numberOfRaysPerBounce),
        bounceDepth(bounceDepth),
        meshCollection(meshCollection),
        world(world) {}

int RayIntensityCalculator::getNumberOfRaysPerBounce() const {
    return numberOfRaysPerBounce;
}

