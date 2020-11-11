//
// Created by ellio on 14-10-2020.
//

#include "Vector3D.h"
#include "../MeshCollectionExporter/ExportStrings.h"

double Vector3D::getX() const {
    return x;
}

void Vector3D::setX(double x) {
    Vector3D::x = x;
}

double Vector3D::getY() const {
    return y;
}

void Vector3D::setY(double y) {
    Vector3D::y = y;
}

double Vector3D::getZ() const {
    return z;
}

void Vector3D::setZ(double z) {
    Vector3D::z = z;
}

Vector3D::Vector3D(double x, double y, double z) : x(x), y(y), z(z) {}

Vector3D Vector3D::cross(const Vector3D &otherVec) const {
    double newX = y * otherVec.z - z * otherVec.y;
    double newY = z * otherVec.x - x * otherVec.z;
    double newZ = x * otherVec.y - y * otherVec.x;
    return {newX, newY, newZ};
}

double Vector3D::dot(const Vector3D &otherVec) const {
    return x * otherVec.x + y * otherVec.y + z * otherVec.z;
}

double Vector3D::length() const {
    return sqrt(this->dot(*this));
}

Vector3D Vector3D::normalize() {
    return (*this) * (1 / this->length());
}


Vector3D Vector3D::operator+(const Vector3D &otherVec) const {
    return {otherVec.x + x, otherVec.y + y, otherVec.z + z};
}

Vector3D Vector3D::operator-(const Vector3D &otherVec) const {
    return {x - otherVec.x, y - otherVec.y, z - otherVec.z};
}

Vector3D Vector3D::operator*(double scalar) const {
    return {scalar * x, scalar * y, scalar * z};
}

Vector3D::Vector3D() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

string Vector3D::toExportString() const {
    return to_string(x) + xyzDelimiter + to_string(y) + xyzDelimiter + to_string(z);
}

ostream &operator<<(ostream &os, Vector3D vector) {
    os << vector.getX() << xyzDelimiter << vector.getY() << xyzDelimiter << vector.getZ();
    return os;
}

Vector3D operator*(double scalar, const Vector3D &vector) {
    return vector * scalar;
}
