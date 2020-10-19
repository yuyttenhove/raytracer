//
// Created by yolan on 19/10/20.
//

#include "MeshTransformer.h"
#include "../util/Matrix3x3.h"

void MeshTransformer::translateMesh(Mesh *mesh, Vector3D translation) {
    for (Triangle* triangle : mesh->getTriangles()){
        triangle->translate(translation);
    }
}

void MeshTransformer::rotateMesh(Mesh *mesh, double theta, Vector3D axis) {
    Matrix3x3 rotationMatrix = Matrix3x3(theta, axis);
    for (Triangle* triangle : mesh->getTriangles()){
        triangle->rotate(rotationMatrix);
    }
}

void MeshTransformer::scaleToOrigin(Mesh *mesh, double scale) {
    for (Triangle* triangle : mesh->getTriangles()){
        triangle->scale(scale);
    }
}

