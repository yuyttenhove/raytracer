//
// Created by ellio on 6-11-2020.
//

#include "MeshCollectionCreatorFromString.h"

MeshCollection MeshCollectionCreatorFromString::createMeshCollectionFromString(string meshCollectionString) {
    size_t pos;
    std::string tempMeshSubString;
    vector<Mesh *> meshes;
    while ((pos = meshCollectionString.find(meshDelimiter)) != std::string::npos) {
        tempMeshSubString = meshCollectionString.substr(0, pos);
        Mesh *newMesh = MeshCreatorFromString::createMeshFromString(tempMeshSubString);
        meshes.push_back(newMesh);
        meshCollectionString.erase(0, pos + meshDelimiter.length());
    }

    Mesh *newMesh = MeshCreatorFromString::createMeshFromString(meshCollectionString);
    meshes.push_back(newMesh);
    return MeshCollection(meshes);
}
