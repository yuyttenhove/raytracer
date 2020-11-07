//
// Created by ellio on 6-11-2020.
//

#include "MeshCollectionStringCreator.h"

string MeshCollectionStringCreator::generateMeshCollectionString(MeshCollection meshCollection) {
    vector<Mesh *> meshes = meshCollection.getMeshes();

    string meshCollectionString;
    for (auto mesh: meshes) {
        meshCollectionString += MeshStringCreator::generateMeshString(mesh);
        meshCollectionString += meshDelimiter;
    }

    return meshCollectionString.substr(0, meshCollectionString.size() - 1);
}
