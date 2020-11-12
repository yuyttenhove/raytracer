//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MESHCOLLECTION_H
#define RAYTRACER_MESHCOLLECTION_H

#include "Triangle.h"
#include "Mesh.h"
#include <cfloat>
#include "../RayUtils/Ray.h"
#include <vector>


class MeshCollection {

    vector<Mesh *> meshes;

public:
    explicit MeshCollection(const vector<Mesh *>& meshes);

    Triangle *getClosestTriangle(const Ray &ray, Vector3D &interSectionPoint);

    const vector<Mesh *> &getMeshes() const;

};


#endif //RAYTRACER_MESHCOLLECTION_H
