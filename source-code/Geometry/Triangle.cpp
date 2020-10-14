//
// Created by ellio on 14-10-2020.
//

#include "Triangle.h"
#include "Mesh.h"


Triangle::Triangle(Mesh *mesh, const Vector3D &vec1, const Vector3D &vec2, const Vector3D &originVec) :
        mesh(mesh),
        vec1(vec1),
        vec2(vec2),
        originVec(originVec) {
    this->normal = vec1.cross(vec2).normalize();

}

const Vector3D &Triangle::getNormal() const {
    return normal;
}

Material *Triangle::getMaterial() {
    return mesh->getMaterial();
}

