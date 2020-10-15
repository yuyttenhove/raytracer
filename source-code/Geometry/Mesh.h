//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MESH_H
#define RAYTRACER_MESH_H


#include <vector>
#include "Triangle.h"


class Mesh {

    vector<Triangle> triangles;
    Material *material;
public:

    Mesh();

    Mesh(Material *material);

    Mesh(const vector<Triangle> &triangles, Material *material);

    Material *getMaterial();


};


#endif //RAYTRACER_MESH_H
