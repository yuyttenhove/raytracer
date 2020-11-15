//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_MESHGENERATOR_H
#define RAYTRACER_MESHGENERATOR_H


#include "Mesh.h"

class MeshGenerator {
public:

    static Mesh *generateSphere(Material *material, int numberOfIterations = 4);

    static Mesh *generateOctahedron(Material *material);

    static Mesh *generateCircle(Material *material, int numberOfSections = 50);

    static Mesh *generateCube(Material *material);

    static Mesh *generateCone(Material *material, int numberOfSections = 10);
};


#endif //RAYTRACER_MESHGENERATOR_H
