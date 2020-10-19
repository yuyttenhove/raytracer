//
// Created by yolan on 19/10/20.
//

#include "MeshGenerator.h"

Mesh* MeshGenerator::generateUnitCube(Material *material) {
    Mesh* mesh = new Mesh(material);
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
