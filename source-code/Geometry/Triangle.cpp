//
// Created by ellio on 14-10-2020.
//

#include "Triangle.h"
#include "Mesh.h"


const Vector3D &Triangle::getNormal() const {
    return normal;
}

Triangle::Triangle(Mesh *mesh, const Vector3D &vertex0, const Vector3D &vertex1, const Vector3D &vertex2) :
        mesh(mesh),
        vertex0(vertex0),
        vertex1(vertex1),
        vertex2(vertex2) {
    Vector3D vec1 = vertex1 - vertex0;
    Vector3D vec2 = vertex2 - vertex0;

    normal = vec1.cross(vec2).normalize();
}

const Vector3D &Triangle::getVertex0() const {
    return vertex0;
}

const Vector3D &Triangle::getVertex1() const {
    return vertex1;
}

const Vector3D &Triangle::getVertex2() const {
    return vertex2;
}

Mesh *Triangle::getMesh() const {
    return mesh;
}

void Triangle::translate(Vector3D translation) {
    vertex0 = vertex0 + translation;
    vertex1 = vertex1 + translation;
    vertex2 = vertex2 + translation;
}

void Triangle::rotate(Matrix3x3 rotationMatrix) {
    vertex0 = rotationMatrix.dot(vertex0);
    vertex1 = rotationMatrix.dot(vertex1);
    vertex2 = rotationMatrix.dot(vertex2);

    Vector3D vec1 = vertex1 - vertex0;
    Vector3D vec2 = vertex2 - vertex0;
    normal = vec1.cross(vec2).normalize();
}

void Triangle::scale(double scale) {
    vertex0 = scale * vertex0;
    vertex1 = scale * vertex1;
    vertex2 = scale * vertex2;
}

