//
// Created by ellio on 14-10-2020.
//

#include "Vector3D.h"

int Vector3D::getX() const {
    return x;
}

void Vector3D::setX(int x) {
    Vector3D::x = x;
}

int Vector3D::getY() const {
    return y;
}

void Vector3D::setY(int y) {
    Vector3D::y = y;
}

int Vector3D::getZ() const {
    return z;
}

void Vector3D::setZ(int z) {
    Vector3D::z = z;
}


Vector3D::Vector3D(int x, int y, int z) : x(x), y(y), z(z) {}
