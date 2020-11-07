//
// Created by ellio on 7-11-2020.
//

#ifndef RAYTRACER_MESHCOLLECTIONFROMFILEREADER_H
#define RAYTRACER_MESHCOLLECTIONFROMFILEREADER_H


#include "../Geometry/MeshCollection.h"
#include "MeshCollectionCreatorFromString.h"
#include <fstream>


class MeshCollectionFromFileReader {

public:
    static MeshCollection readMeshCollectionFromFile(string fullFilePath);

};


#endif //RAYTRACER_MESHCOLLECTIONFROMFILEREADER_H
