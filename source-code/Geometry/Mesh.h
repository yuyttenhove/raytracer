//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include <vector>
#include "Triangle.h"
#include "../Materials/Material.h"


class Mesh {

    vector<Triangle *> triangles;
    Material *material;

public:
    Mesh();

    explicit Mesh(Material *material);

    Mesh(const vector<Triangle *> &triangles, Material *material);

    vector<Triangle *> getTriangles();

    Material *getMaterial();

    void addTriangle(Triangle *triangle);

    void addTriangles(const vector<Triangle *>& newTriangles);

    typedef vector<Triangle*>::const_iterator const_iterator;

    const_iterator begin();

    const_iterator end();


};


#endif //RAYTRACER_MESH_H
