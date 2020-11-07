//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_MESHCOLLECTIONCREATORFROMSTRING_H
#define RAYTRACER_MESHCOLLECTIONCREATORFROMSTRING_H


#include "../Geometry/MeshCollection.h"
#include "MeshCreatorFromString.h"

class MeshCollectionCreatorFromString {

public:
    static MeshCollection createMeshCollectionFromString(string meshCollectionString);

};


#endif //RAYTRACER_MESHCOLLECTIONCREATORFROMSTRING_H
