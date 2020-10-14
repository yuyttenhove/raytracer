//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "../util/Vector3D.h"

class Mesh;

class Triangle {

    Mesh *mesh;

    Vector3D vec1;
    Vector3D vec2;
    Vector3D normal;
    Vector3D originVec;
public:
    const Vector3D &getNormal() const;

public:
    Triangle(Mesh *mesh, const Vector3D &vec1, const Vector3D &vec2, const Vector3D &originVec);

};


#endif //RAYTRACER_TRIANGLE_H
