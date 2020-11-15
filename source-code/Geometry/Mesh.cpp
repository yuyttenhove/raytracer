//
// Created by ellio on 14-10-2020.
//

#include "Mesh.h"

Material *Mesh::getMaterial() {
    return material;
}

Mesh::Mesh(const vector<Triangle *> &triangles, Material *material) : triangles(triangles), material(material) {}

Mesh::Mesh(Material *material) : material(material) {
    triangles = vector<Triangle *>();
}

Mesh::Mesh() {
    material = nullptr;
    triangles = vector<Triangle *>();
}

vector<Triangle *> Mesh::getTriangles() {
    return triangles;
}

void Mesh::addTriangle(Triangle *triangle) {
    triangles.push_back(triangle);
}

void Mesh::addTriangles(const vector<Triangle *>& newTriangles) {
    triangles.insert(triangles.end(), newTriangles.begin(), newTriangles.end());
}

Mesh::const_iterator Mesh::begin() {
    return triangles.cbegin();
}

Mesh::const_iterator Mesh::end() {
    return triangles.cend();
}

