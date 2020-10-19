//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_MESHGENERATOR_H
#define RAYTRACER_MESHGENERATOR_H


#include "Mesh.h"

class MeshGenerator {
public:
    static Mesh* generateUnitCube(Material *material);
};


#endif //RAYTRACER_MESHGENERATOR_H
