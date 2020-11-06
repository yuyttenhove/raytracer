//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_MESHCREATORFROMSTRING_H
#define RAYTRACER_MESHCREATORFROMSTRING_H


#include "../Geometry/Mesh.h"

class MeshCreatorFromString {

public:
    static Mesh *createMeshFromString(string meshString);

};


#endif //RAYTRACER_MESHCREATORFROMSTRING_H
