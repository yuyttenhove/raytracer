//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_MESHCOLLECTIONSTRINGCREATOR_H
#define RAYTRACER_MESHCOLLECTIONSTRINGCREATOR_H

#include <string>
#include "../Geometry/MeshCollection.h"
#include "MeshStringCreator.h"

using namespace std;

class MeshCollectionStringCreator {

public:
    static string generateMeshCollectionString(MeshCollection meshCollection);

};


#endif //RAYTRACER_MESHCOLLECTIONSTRINGCREATOR_H
