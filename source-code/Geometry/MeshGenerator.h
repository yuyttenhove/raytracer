//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_MESHGENERATOR_H
#define RAYTRACER_MESHGENERATOR_H


#include "Mesh.h"

class MeshGenerator {
public:
    static Mesh *generateOctahedron(Material *material, int numberOfIterations = 0);

    static Mesh *generateUnitCircle(Material *material, int numberOfTriangles = 50);

    static Mesh *generateUnitCube(Material *material);
};


#endif //RAYTRACER_MESHGENERATOR_H
