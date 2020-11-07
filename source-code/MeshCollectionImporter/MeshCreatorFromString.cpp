//
// Created by ellio on 6-11-2020.
//

#include "MeshCreatorFromString.h"

Mesh *MeshCreatorFromString::createMeshFromString(string meshString) {
    size_t position = meshString.find(materialDelimiter);
    string materialString = meshString.substr(0, position);

    Material *material = createMaterialFromString(materialString);
    Mesh *mesh = new Mesh(material);

    string trianglesString = meshString.erase(0, position + materialDelimiter.length());
    const vector<Triangle *> &triangles = createTrianglesFromString(trianglesString, mesh);

    for (auto triangle : triangles) {
        mesh->addTriangle(triangle);
    }

    return mesh;
}

Material *MeshCreatorFromString::createMaterialFromString(string materialString) {
    size_t position = materialString.find(materialPropertiesDelimiter);

    string materialNameString = materialString.substr(0, position);
    string propertiesString = materialString.erase(0, position + materialPropertiesDelimiter.length());

    if (materialNameString == diffuseMaterialExportName) {
        double albedo = stod(propertiesString);
        return new DiffuseMaterial(albedo);
    } else if (materialNameString == reflectiveMaterialExportName) {
        double shininess = stod(propertiesString);
        return new ReflectiveMaterial(shininess);
    } else if (materialNameString == emissiveMaterialExportName) {
        double intensity = stod(propertiesString);
        return new EmissiveMaterial(intensity);
    }
    return nullptr;
}

vector<Triangle *> MeshCreatorFromString::createTrianglesFromString(string trianglesString, Mesh *mesh) {

    size_t pos;
    std::string tempTriangleSubString;
    vector<Triangle *> triangles;
    while ((pos = trianglesString.find(trianglesDelimiter)) != std::string::npos) {
        tempTriangleSubString = trianglesString.substr(0, pos);
        Triangle *newTriangle = createTriangleFromString(tempTriangleSubString, mesh);
        triangles.push_back(newTriangle);
        trianglesString.erase(0, pos + trianglesDelimiter.length());
    }

    Triangle *newTriangle = createTriangleFromString(tempTriangleSubString, mesh);
    triangles.push_back(newTriangle);

    return triangles;
}

Triangle *MeshCreatorFromString::createTriangleFromString(string triangleString, Mesh *mesh) {
    size_t position = triangleString.find(trianglePointDelimiter);
    string vertex0String = triangleString.substr(0, position);
    string remainingVertices = triangleString.erase(0, position + trianglePointDelimiter.length());

    position = remainingVertices.find(trianglePointDelimiter);
    string vertex1String = remainingVertices.substr(0, position);
    string vertex2String = remainingVertices.erase(0, position + trianglePointDelimiter.length());

    Vector3D *vertex0 = createVector3dFromString(vertex0String);
    Vector3D *vertex1 = createVector3dFromString(vertex1String);
    Vector3D *vertex2 = createVector3dFromString(vertex2String);

    return new Triangle(mesh, *vertex0, *vertex1, *vertex2);
}

Vector3D *MeshCreatorFromString::createVector3dFromString(string vector3DString) {

    size_t position = vector3DString.find(trianglePointDelimiter);
    string xString = vector3DString.substr(0, position);
    string yzString = vector3DString.erase(0, position + xyzDelimiter.length());

    position = yzString.find(trianglePointDelimiter);
    string yString = yzString.substr(0, position);
    string zString = yzString.erase(0, position + xyzDelimiter.length());

    double x = stod(xString);
    double y = stod(yString);
    double z = stod(zString);

    return new Vector3D(x, y, z);

}
