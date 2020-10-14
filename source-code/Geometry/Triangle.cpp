//
// Created by ellio on 14-10-2020.
//

#include "Triangle.h"


Triangle::Triangle(Mesh *mesh, const Vector3D &vec1, const Vector3D &vec2, const Vector3D &normal,
                   const Vector3D &originVec) : mesh(mesh), vec1(vec1), vec2(vec2), normal(normal),
                                                originVec(originVec) {}
