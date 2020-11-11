//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_HALVEUNITSPHEREVECTORGENERATOR_H
#define RAYTRACER_HALVEUNITSPHEREVECTORGENERATOR_H


#include "Vector3D.h"

class HalveUnitSphereVectorGenerator {

public:
    static Vector3D generateVectorHalveUnitSphere();

    static Vector3D generateCosineWeightedVector();

    static Vector3D generateCosineWeightedVectorAroundNormal(Vector3D normal);
};


#endif //RAYTRACER_HALVEUNITSPHEREVECTORGENERATOR_H
