//
// Created by ellio on 14-10-2020.
//

#include "Mesh.h"

Material *Mesh::getMaterial() {
    return material;
}

Mesh::Mesh(const vector<Triangle> &triangles, Material *material) : triangles(triangles), material(material) {}

Mesh::Mesh(Material *material) : material(material) {
    triangles = vector<Triangle>();
}

Mesh::Mesh() {
    material = nullptr;
    triangles = vector<Triangle>();
}

