//
// Created by ellio on 14-10-2020.
//

#include "Ray.h"
#include "../Geometry/Triangle.h"


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

bool Ray::intersectsTriangle(const Triangle &triangle, float *pathLength) const {
    const float EPSILON = 0.000001;
    Vector3D vertex0 = triangle.getVertex0();
    Vector3D vertex1 = triangle.getVertex1();
    Vector3D vertex2 = triangle.getVertex2();
    Vector3D edge1, edge2, h, s, q;
    float a, f, u, v;
    edge1 = vertex1 - vertex0;
    edge2 = vertex2 - vertex0;
    h = direction.cross(edge2);
    a = edge1.dot(h);
    if (a > -EPSILON && a < EPSILON)
        return false;    // This ray is parallel to this triangle.
    f = 1.0 / a;
    s = startPoint - vertex0;
    u = f * s.dot(h);
    if (u < 0.0 || u > 1.0)
        return false;
    q = s.cross(edge1);
    v = f * direction.dot(q);
    if (v < 0.0 || u + v > 1.0)
        return false;
    // At this stage we can compute t to find out where the intersection point is on the line.
    float t = f * edge2.dot(q);
    *pathLength = t;
    if (t > EPSILON) {
        return true;
    } else {
        return false;
    }
}

