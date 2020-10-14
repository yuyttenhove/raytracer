//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_RAY_H
#define RAYTRACER_RAY_H


#include "../util/Vector3D.h"

class Ray {
    Vector3D direction;
    Vector3D startPoint;
    int numberOfBouncesBefore;
public:
    Ray(const Vector3D &direction, const Vector3D &startPoint, int numberOfBouncesBefore = 0);

public:
    int getNumberOfBouncesBefore() const;

public:
    void incrementNumberOfBounces();
};


#endif //RAYTRACER_RAY_H
