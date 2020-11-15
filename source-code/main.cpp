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

    int numberOfSamples = 3;
    int bounceDepth = 8;
    int width = 1000;
    int height = 500;
    double viewingAngle = (double) 60 / 180 * M_PI;
    bool smoothen = false;
    bool msaa = true;


    auto start = chrono::steady_clock::now();

    string fullFileName = EXPORT_ADDRESS + PATH_DELIMITER + "HalfBacklitSphere.txt";
//    MeshCollection meshCollection = MeshCollectionFromFileReader::readMeshCollectionFromFile(fullFileName);

    DiffuseMaterial groundMaterial = DiffuseMaterial(0.3);
    Mesh *ground = MeshGenerator::generatePlane(&groundMaterial);
    MeshTransformer::scaleToOrigin(ground, 20);
    MeshTransformer::translateMesh(ground, {6, 0, -1});

    DiffuseMaterial objectMaterial = DiffuseMaterial(0.9);

    Mesh *cube = MeshGenerator::generateCube(&objectMaterial);
    MeshTransformer::translateMesh(cube, {6, -6, 0});
    MeshTransformer::rotateMesh(cube, M_PI_4 * .75, {0, 0, 1});

    Mesh *octahedron = MeshGenerator::generateOctahedron(&objectMaterial);
    MeshTransformer::translateMesh(octahedron, {6, -3, 0});
    MeshTransformer::rotateMesh(octahedron, M_PI_4 * .75, {0, 0, 1});

    Mesh *cone = MeshGenerator::generateCone(&objectMaterial);
    MeshTransformer::translateMesh(cone, {6, 0, 0});

    Mesh *cylinder = MeshGenerator::generateCylinder(&objectMaterial);
    MeshTransformer::translateMesh(cylinder, {6, 3, 0});

    Mesh *sphere = MeshGenerator::generateSphere(&objectMaterial);
    MeshTransformer::translateMesh(sphere, {6, 6, 0});

    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh lightSource = Mesh(&emissiveMaterial);
    Triangle triangle = Triangle(&lightSource, {-1, 1000, -1000}, {-1, 0, 1000}, {-1, 0, -1000});
    lightSource.addTriangle(&triangle);

    vector<Mesh *> meshes{&lightSource, ground, cube, octahedron, cone, cylinder, sphere};
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