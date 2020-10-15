//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_TRIANGLE_H
#define RAYTRACER_TRIANGLE_H


#include "../util/Vector3D.h"
#include "../Materials/Material.h"

class Mesh;

class Triangle {

    Mesh *mesh;
    Vector3D vertex0;
    Vector3D vertex1;
    Vector3D vertex2;
    Vector3D normal;

public:
    Triangle(Mesh *mesh, const Vector3D &vertex0, const Vector3D &vertex1, const Vector3D &vertex2);

    const Vector3D &getVertex0() const;

    const Vector3D &getVertex1() const;

    const Vector3D &getVertex2() const;

    const Vector3D &getNormal() const;

    Material *getMaterial();

};


#endif //RAYTRACER_TRIANGLE_H
