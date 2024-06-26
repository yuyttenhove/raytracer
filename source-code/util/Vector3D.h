//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H

#include <cmath>
#include <iostream>
#include <string>

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

    Vector3D operator+(const Vector3D &otherVec) const;

    Vector3D operator-(const Vector3D &otherVec) const;

    Vector3D operator*(double scalar) const;

    double dot(const Vector3D &otherVec) const;

    double length() const;

    Vector3D normalize();

    Vector3D cross(const Vector3D &otherVec) const;

    string toExportString() const;

};

ostream &operator<<(ostream &os, Vector3D vector);

Vector3D operator*(double scalar, const Vector3D &vector);


#endif //RAYTRACER_VECTOR3D_H
