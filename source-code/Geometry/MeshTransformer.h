//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_MESHTRANSFORMER_H
#define RAYTRACER_MESHTRANSFORMER_H


#include "Mesh.h"

class MeshTransformer {
public:
    static void translateMesh(Mesh *mesh, Vector3D translation);

    static void rotateMesh(Mesh *mesh, double theta, Vector3D axis);

    static void scaleToOrigin(Mesh *mesh, double scale);
};


#endif //RAYTRACER_MESHTRANSFORMER_H
