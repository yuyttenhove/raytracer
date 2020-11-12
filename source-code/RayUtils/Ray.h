//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "../util/Vector3D.h"
#include "../Geometry/Triangle.h"

class Ray {
    Vector3D direction;
    Vector3D startPoint;

private:
    double intensity;
    int numberOfBouncesBefore;

public:
    Ray(const Vector3D &direction, const Vector3D &startPoint, double intensity = 1, int numberOfBouncesBefore = 0);

    const Vector3D &getDirection() const;

    const Vector3D &getStartPoint() const;

    int getNumberOfBouncesBefore() const;

    double getIntensity() const;

    void setIntensity(double intensity);

    void bounce(const Vector3D &direction, const Vector3D &startPoint, double intensity);

    bool intersectsTriangle(const Triangle &triangle, float &pathLength) const;
};


#endif //RAYTRACER_RAY_H
