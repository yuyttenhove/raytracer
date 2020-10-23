//
// Created by yolan on 19/10/20.
//

#define _USE_MATH_DEFINES

#include <cmath>
#include "MeshGenerator.h"


Mesh *MeshGenerator::generateUnitCube(Material *material) {
    Mesh *mesh = new Mesh(material);
    // ground plane
    mesh->addTriangle(new Triangle(mesh, {-.5, -.5, -.5}, {-.5, .5, -.5}, {.5, -.5, -.5}));
    mesh->addTriangle(new Triangle(mesh, {.5, .5, -.5}, {.5, -.5, -.5}, {-.5, .5, -.5}));

    // upper plane
    mesh->addTriangle(new Triangle(mesh, {-.5, -.5, .5}, {.5, -.5, .5}, {-.5, .5, .5}));
    mesh->addTriangle(new Triangle(mesh, {.5, .5, .5}, {-.5, .5, .5}, {.5, -.5, .5}));

    // front plane
    mesh->addTriangle(new Triangle(mesh, {-.5, .5, .5}, {-.5, .5, -.5}, {-.5, -.5, -.5}));
    mesh->addTriangle(new Triangle(mesh, {-.5, -.5, -.5}, {-.5, -.5, .5}, {-.5, .5, .5}));

    // back plane
    mesh->addTriangle(new Triangle(mesh, {.5, .5, .5}, {.5, -.5, -.5}, {.5, .5, -.5}));
    mesh->addTriangle(new Triangle(mesh, {.5, -.5, -.5}, {.5, .5, .5}, {.5, -.5, .5}));

    // left plane
    mesh->addTriangle(new Triangle(mesh, {.5, .5, .5}, {.5, .5, -.5}, {-.5, .5, -.5}));
    mesh->addTriangle(new Triangle(mesh, {.5, .5, .5}, {-.5, .5, -.5}, {-.5, .5, .5}));

    // right plane
    mesh->addTriangle(new Triangle(mesh, {.5, -.5, .5}, {-.5, -.5, -.5}, {.5, -.5, -.5}));
    mesh->addTriangle(new Triangle(mesh, {.5, -.5, .5}, {-.5, -.5, .5}, {-.5, -.5, -.5}));
    return mesh;
}

Mesh *MeshGenerator::generateUnitCircle(Material *material, int numberOfTriangles) {
    if (numberOfTriangles < 3) {
        cout << "please use 3 or more triangles when making a circle";
        numberOfTriangles = 3;
    }
    double angleTriangles = 2 * M_PI / numberOfTriangles;
    Matrix3x3 newTriangleSideFindMatrix = Matrix3x3(angleTriangles, {0, 0, 1});

    Mesh *mesh = new Mesh(material);

    Vector3D origin = {0, 0, 0};
    Vector3D firstVec = {1, 0, 0};
    Vector3D secondVec;
    for (int i = 0; i < numberOfTriangles - 1; ++i) {
        secondVec = newTriangleSideFindMatrix.dot(firstVec);
        mesh->addTriangle(new Triangle(mesh, origin, firstVec, secondVec));
        firstVec = secondVec;
    }

    mesh->addTriangle(new Triangle(mesh, origin, firstVec, {1, 0, 0}));
    return mesh;
}

Mesh *MeshGenerator::generateOctahedron(Material *material, int numberOfIterations) {
    Mesh *mesh = new Mesh(material);

    Vector3D highXHighYVector = Vector3D(1, 1, 0).normalize();
    Vector3D lowXHighYVector = Vector3D(-1, 1, 0).normalize();
    Vector3D highXLowYVector = Vector3D(1, -1, 0).normalize();
    Vector3D lowXLowYVector = Vector3D(-1, -1, 0).normalize();
    Vector3D topVector = Vector3D(0, 0, 1).normalize();
    Vector3D bottomVector = Vector3D(0, 0, -1).normalize();

    // top front triangle
    mesh->addTriangle(new Triangle(mesh, lowXHighYVector, lowXLowYVector, topVector));
    // top right triangle
    mesh->addTriangle(new Triangle(mesh, lowXLowYVector, highXLowYVector, topVector));
    // top back triangle
    mesh->addTriangle(new Triangle(mesh, highXLowYVector, highXHighYVector, topVector));
    // top left triangle
    mesh->addTriangle(new Triangle(mesh, highXHighYVector, lowXHighYVector, topVector));

    // top front triangle
    mesh->addTriangle(new Triangle(mesh, bottomVector, lowXHighYVector, lowXLowYVector));
    // top right triangle
    mesh->addTriangle(new Triangle(mesh, bottomVector, lowXLowYVector, highXLowYVector, topVector));
    // top back triangle
    mesh->addTriangle(new Triangle(mesh, bottomVector, highXLowYVector, highXHighYVector, topVector));
    // top left triangle
    mesh->addTriangle(new Triangle(mesh, bottomVector, highXHighYVector, lowXHighYVector, topVector));

    return nullptr;
}
