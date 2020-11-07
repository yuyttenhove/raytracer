//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_MESHCREATORFROMSTRING_H
#define RAYTRACER_MESHCREATORFROMSTRING_H


#include "../Geometry/Mesh.h"
#include "../MeshCollectionExporter/ExportStrings.h"
#include "../Materials/DiffuseMaterial.h"
#include "../Materials/ReflectiveMaterial.h"
#include "../Materials/EmissiveMaterial.h"


class MeshCreatorFromString {

public:
    static Mesh *createMeshFromString(string meshString);

private:
    static Material *createMaterialFromString(string materialString);

    static vector<Triangle *> createTrianglesFromString(string trianglesString, Mesh *mesh);

    static Triangle *createTriangleFromString(string triangleString, Mesh *mesh);

    static Vector3D *createVector3dFromString(string vector3DString);

};


#endif //RAYTRACER_MESHCREATORFROMSTRING_H
