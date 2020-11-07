//
// Created by ellio on 6-11-2020.
//

#include <string>
#include <fstream>
#include "Geometry/Mesh.h"
#include "SystemSpecificConstants.h"
#include "MeshCollectionExporter/MeshCollectionStringCreator.h"
#include "Materials/DiffuseMaterial.h"
#include "Materials/EmissiveMaterial.h"
#include "Geometry/MeshGenerator.h"
#include "Geometry/MeshTransformer.h"

using namespace std;

int main() {

    // the name of the file where the meshCollection export will reside
    string fileName = "HalfBacklitSphere.txt";

    DiffuseMaterial diffuseMaterial = DiffuseMaterial(0.7);
    Mesh *sphere = MeshGenerator::generateSphere(&diffuseMaterial, 3);
    MeshTransformer::translateMesh(sphere, {3, 0, 0});

    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh lightSource = Mesh(&emissiveMaterial);
    Triangle triangle = Triangle(&lightSource, {-1, 1000, -1000}, {-1, 0, 1000}, {-1, 0, -1000});
    lightSource.addTriangle(&triangle);

    vector<Mesh *> meshes{&lightSource, sphere};
    MeshCollection meshCollection = MeshCollection(meshes);


    string meshCollectionString = MeshCollectionStringCreator::generateMeshCollectionString(meshCollection);

    // @Yolan LEES DIT: hier maak ik het volle path aan waar de textFile gesaved zal worden
    // EXPORT_ADDRESS is een string die ik aan SystemSpecificConstants.h heb toegevoegd, bij mij is die vb:
    // C:\Users\ellio\CLionProjects\raytracer\source-code\Export
    // ik heb dus nog een extra map Export aangemaakt. Als je dat gedaan hebt en deze code werkt, verwijder best
    // deze comment
    string fullExportLocation = EXPORT_ADDRESS + "\\" + fileName;

    ofstream outputStream;
    outputStream.open(fullExportLocation);
    outputStream << meshCollectionString;
    outputStream.close();

    return 0;
}