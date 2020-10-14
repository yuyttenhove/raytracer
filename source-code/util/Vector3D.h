//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H

#include <cmath>
#include <iostream>

using namespace std;


class Vector3D {

    double x;
    double y;
    double z;

public:
    Vector3D(double x, double y, double z);

    Vector3D();

public:
    double getX() const;

    void setX(double x);

    double getY() const;

    void setY(double y);

    double getZ() const;

    void setZ(double z);

    Vector3D operator+(Vector3D otherVec);

    Vector3D operator*(double scalar);

    double dot(Vector3D otherVec) const;

    double length();

    Vector3D scalar(double scalar);

    Vector3D normalize();

    Vector3D cross(Vector3D otherVec) const;

};

ostream &operator<<(ostream &os, Vector3D vector);


#endif //RAYTRACER_VECTOR3D_H
