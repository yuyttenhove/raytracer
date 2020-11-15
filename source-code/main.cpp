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

    int numberOfSamples = 5;
    int bounceDepth = 8;
    int width = 500;
    int height = 500;
    double viewingAngle = (double) 60 / 180 * M_PI;
    bool smoothen = false;
    bool msaa = true;


    auto start = chrono::steady_clock::now();

    string fullFileName = EXPORT_ADDRESS + PATH_DELIMITER + "HalfBacklitSphere.txt";
//    MeshCollection meshCollection = MeshCollectionFromFileReader::readMeshCollectionFromFile(fullFileName);

    DiffuseMaterial diffuseMaterial = DiffuseMaterial(0.7);
    Mesh *sphere = MeshGenerator::generateSphere(&diffuseMaterial, 2);
    MeshTransformer::translateMesh(sphere, {6, 0, 2});

    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh lightSource = Mesh(&emissiveMaterial);
    Triangle triangle = Triangle(&lightSource, {-1, 1000, -1000}, {-1, 0, 1000}, {-1, 0, -1000});
    lightSource.addTriangle(&triangle);

    ReflectiveMaterial reflectiveMaterial = ReflectiveMaterial(.6);
    Mesh *mirror = MeshGenerator::generateCube(&reflectiveMaterial);
    MeshTransformer::scaleToOrigin(mirror, 50);
    MeshTransformer::translateMesh(mirror, {6, 0, -51});

    DiffuseMaterial dark = DiffuseMaterial(.4);
    Mesh *cone = MeshGenerator::generateCone(&dark, 10);
    MeshTransformer::translateMesh(cone, {6, 0, .2});


    vector<Mesh *> meshes{&lightSource,sphere, mirror, cone};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, viewingAngle, smoothen, bounceDepth);

    scene.render(SAVE_ADDRESS, numberOfSamples, msaa);

    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Elapsed time in seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";

    return 0;
}