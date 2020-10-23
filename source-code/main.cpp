#define _USE_MATH_DEFINES

#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Geometry/MeshGenerator.h"
#include "Geometry/MeshTransformer.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "Geometry/Mesh.h"
#include "Materials/ReflectiveMaterial.h"
#include "util/Matrix3x3.h"
#include "Materials/DiffuseMaterial.h"
#include "windows.h"
#include "SystemSpecificConstants.h"
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

int main() {

    int numberOfRaysPerBounce = 5;
    int bounceDepth = 3;
    int width = 500;
    int height = 500;
    bool smoothen = false;


    auto start = chrono::steady_clock::now();

    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(1.0);
    Mesh emissiveMesh2 = Mesh(&emissiveMaterial2);
    Triangle triangle2 = Triangle(&emissiveMesh2, {-10, 2, 0}, {10, 2, 0}, {0, 2, 10});
    emissiveMesh2.addTriangle(&triangle2);

    DiffuseMaterial diffuseMaterial = DiffuseMaterial(.7);
    Mesh *cube = MeshGenerator::generateUnitCube(&diffuseMaterial);
    MeshTransformer::rotateMesh(cube, M_PI_4, {0, 0, 1});
    MeshTransformer::translateMesh(cube, {3, 0, -1});

    // floor
    DiffuseMaterial diffuseMaterial3 = DiffuseMaterial(.9);
    Mesh floor = Mesh(&diffuseMaterial3);
    floor.addTriangle(new Triangle(&floor, {0, -1, -100}, {-100, -1, 100}, {100, -1, 100}));

    vector<Mesh *> meshes{&emissiveMesh2, cube};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, smoothen, numberOfRaysPerBounce, bounceDepth);

    // voeg een file toe met de naam "SystemSpecificConstants.h" op het zelfde niveau als main.cpp, zet hier een
    // "const string SAVE_ADDRESS = "C:\\Users\\ellio\\CLionProjects\\raytracer\\source-code\\output\\resuult.txt";"
    // waarbij u juist pad staat
    // VOEG DIT FILE NIET TOE AAN GIT, DIT ZOU VANZELF IN ORDE MOETEN ZIJN WANT T STAAT IN DE GITIGNORE, MAAR LET TOCH OP
    scene.render(SAVE_ADDRESS);

    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Elapsed time in seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";

    return 0;
}