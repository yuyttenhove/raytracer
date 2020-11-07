#define _USE_MATH_DEFINES

#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "SystemSpecificConstants.h"
#include "MeshCollectionImporter/MeshCollectionFromFileReader.h"
#include "Geometry/MeshGenerator.h"
#include "Geometry/MeshTransformer.h"
#include <random>
#include <chrono>

using namespace std;

int main() {

    int numberOfRaysPerBounce = 10;
    int bounceDepth = 3;
    int width = 500;
    int height = 500;
    bool smoothen = false;


    auto start = chrono::steady_clock::now();

    string fullFileName = EXPORT_ADDRESS + "\\" + "HalfBacklitSphere.txt";
    MeshCollection meshCollection = MeshCollectionFromFileReader::readMeshCollectionFromFile(fullFileName);

//    DiffuseMaterial diffuseMaterial = DiffuseMaterial(0.7);
//    Mesh *sphere = MeshGenerator::generateSphere(&diffuseMaterial, 3);
//    MeshTransformer::translateMesh(sphere, {3, 0, 0});
//
//    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
//    Mesh lightSource = Mesh(&emissiveMaterial);
//    Triangle triangle = Triangle(&lightSource, {-1, 1000, -1000}, {-1, 0, 1000}, {-1, 0, -1000});
//    lightSource.addTriangle(&triangle);
//
//    vector<Mesh *> meshes{&lightSource,sphere};
//    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, smoothen, numberOfRaysPerBounce, bounceDepth);

    scene.render(SAVE_ADDRESS);

    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Elapsed time in seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";

    return 0;
}