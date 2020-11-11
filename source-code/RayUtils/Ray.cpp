//
// Created by ellio on 14-10-2020.
//

#include "Ray.h"


Ray::Ray(const Vector3D &direction, const Vector3D &startPoint, double intensity, int numberOfBouncesBefore) :
        direction(direction),
        startPoint(startPoint),
        intensity(intensity),
        numberOfBouncesBefore(numberOfBouncesBefore) {}

int Ray::getNumberOfBouncesBefore() const {
    return numberOfBouncesBefore;
}

const Vector3D &Ray::getDirection() const {
    return direction;
}

const Vector3D &Ray::getStartPoint() const {
    return startPoint;
}

double Ray::getIntensity() const {
    return intensity;
}

void Ray::setIntensity(double intensity) {
    Ray::intensity = intensity;
}

void Ray::bounce(const Vector3D &newDirection, const Vector3D &newStartPoint, double newIntensity) {
    direction = newDirection;
    startPoint = newStartPoint;
    intensity = newIntensity;
    numberOfBouncesBefore++;
}

