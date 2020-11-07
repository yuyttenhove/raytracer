//
// Created by ellio on 7-11-2020.
//

#include "MeshCollectionFromFileReader.h"

MeshCollection MeshCollectionFromFileReader::readMeshCollectionFromFile(string fullFilePath) {

    ifstream ifs(fullFilePath);
    string meshCollectionString((std::istreambuf_iterator<char>(ifs)), (std::istreambuf_iterator<char>()));

    return MeshCollectionCreatorFromString::createMeshCollectionFromString(meshCollectionString);
}
