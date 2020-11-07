//
// Created by ellio on 6-11-2020.
//

#include "MeshStringCreator.h"

string MeshStringCreator::generateMeshString(Mesh *mesh) {
    string meshString = mesh->getMaterial()->getExportString();
    meshString += materialDelimiter;

    string totalTrianglesString;
    const vector<Triangle *> triangles = mesh->getTriangles();
    for (auto triangle: triangles) {
        totalTrianglesString += generateTriangleString(triangle);
        totalTrianglesString += trianglesDelimiter;
    }

    // trim off the last triangleDelimiter
    return meshString + totalTrianglesString.substr(0, totalTrianglesString.size() - 1);
}

string MeshStringCreator::generateTriangleString(Triangle *triangle) {
    Vector3D vertex0 = triangle->getVertex0();
    Vector3D vertex1 = triangle->getVertex1();
    Vector3D vertex2 = triangle->getVertex2();
    return vertex0.toExportString()
           + trianglePointDelimiter
           + vertex1.toExportString()
           + trianglePointDelimiter
           + vertex2.toExportString();
}
