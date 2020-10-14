//
// Created by ellio on 14-10-2020.
//

#include "Ray.h"

void Ray::incrementNumberOfBounces() {
    numberOfBouncesBefore++;
}

int Ray::getNumberOfBouncesBefore() const {
    return numberOfBouncesBefore;
}

Ray::Ray(const Vector3D &direction, const Vector3D &startPoint, int numberOfBouncesBefore) :
        direction(direction),
        startPoint(startPoint),
        numberOfBouncesBefore(numberOfBouncesBefore) {}
