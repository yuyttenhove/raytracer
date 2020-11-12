//
// Created by yolan on 19/10/20.
//

#define _USE_MATH_DEFINES

#include <cmath>
#include "MeshGenerator.h"


Mesh *MeshGenerator::generateCube(Material *material) {
    Mesh *mesh = new Mesh(material);
    // ground plane
    mesh->addTriangle(new Triangle(mesh, {-1, -1, -1}, {-1, 1, -1}, {1, -1, -1}));
    mesh->addTriangle(new Triangle(mesh, {1, 1, -1}, {1, -1, -1}, {-1, 1, -1}));

    // upper plane
    mesh->addTriangle(new Triangle(mesh, {-1, -1, 1}, {1, -1, 1}, {-1, 1, 1}));
    mesh->addTriangle(new Triangle(mesh, {1, 1, 1}, {-1, 1, 1}, {1, -1, 1}));

    // front plane
    mesh->addTriangle(new Triangle(mesh, {-1, 1, 1}, {-1, 1, -1}, {-1, -1, -1}));
    mesh->addTriangle(new Triangle(mesh, {-1, -1, -1}, {-1, -1, 1}, {-1, 1, 1}));

    // back plane
    mesh->addTriangle(new Triangle(mesh, {1, 1, 1}, {1, -1, -1}, {1, 1, -1}));
    mesh->addTriangle(new Triangle(mesh, {1, -1, -1}, {1, 1, 1}, {1, -1, 1}));

    // left plane
    mesh->addTriangle(new Triangle(mesh, {1, 1, 1}, {1, 1, -1}, {-1, 1, -1}));
    mesh->addTriangle(new Triangle(mesh, {1, 1, 1}, {-1, 1, -1}, {-1, 1, 1}));

    // right plane
    mesh->addTriangle(new Triangle(mesh, {1, -1, 1}, {-1, -1, -1}, {1, -1, -1}));
    mesh->addTriangle(new Triangle(mesh, {1, -1, 1}, {-1, -1, 1}, {-1, -1, -1}));
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

Mesh *MeshGenerator::generateOctahedron(Material *material) {
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

    // bottom front triangle
    mesh->addTriangle(new Triangle(mesh, lowXHighYVector, bottomVector, lowXLowYVector));
    // bottom right triangle
    mesh->addTriangle(new Triangle(mesh, lowXLowYVector, bottomVector, highXLowYVector));
    // bottom back triangle
    mesh->addTriangle(new Triangle(mesh, highXLowYVector, bottomVector, highXHighYVector));
    // bottom left triangle
    mesh->addTriangle(new Triangle(mesh, highXHighYVector, bottomVector, lowXHighYVector));

    return mesh;
}

Mesh *MeshGenerator::generateSphere(Material *material, int numberOfIterations) {
    Mesh *octahedron = generateOctahedron(material);
    vector<Triangle *> triangles = octahedron->getTriangles();

    // divide triangles
    for (int i = 0; i < numberOfIterations; ++i) {
        vector<Triangle *> newTriangles = vector<Triangle *>();
        for (auto triangle : triangles) {
            // normal points out of screen
            //        C    
            //       / \   
            //      D - E   
            //     / \ / \
            //    A - F - B

            Vector3D A = triangle->getVertex0();
            Vector3D B = triangle->getVertex1();
            Vector3D C = triangle->getVertex2();

            Vector3D D = {(A.getX() + C.getX()) * 0.5, (A.getY() + C.getY()) * 0.5, (A.getZ() + C.getZ()) * 0.5};
            Vector3D E = {(B.getX() + C.getX()) * 0.5, (B.getY() + C.getY()) * 0.5, (B.getZ() + C.getZ()) * 0.5};
            Vector3D F = {(A.getX() + B.getX()) * 0.5, (A.getY() + B.getY()) * 0.5, (A.getZ() + B.getZ()) * 0.5};

            Triangle *AFD = new Triangle(nullptr, A, F, D);
            Triangle *FBE = new Triangle(nullptr, F, B, E);
            Triangle *DFE = new Triangle(nullptr, D, F, E);
            Triangle *DEC = new Triangle(nullptr, D, E, C);

            newTriangles.push_back(AFD);
            newTriangles.push_back(FBE);
            newTriangles.push_back(DFE);
            newTriangles.push_back(DEC);
        }
        triangles = newTriangles;
    }

    // normalize vectors
    Mesh *mesh = new Mesh(material);
    for (auto triangle : triangles) {

        Vector3D vertex0 = triangle->getVertex0();
        Vector3D vertex1 = triangle->getVertex1();
        Vector3D vertex2 = triangle->getVertex2();

        mesh->addTriangle(new Triangle(mesh, vertex0.normalize(), vertex1.normalize(), vertex2.normalize()));
    }

    return mesh;
}
