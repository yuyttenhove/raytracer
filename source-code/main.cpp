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
#include "SystemSpecificConstants.h"
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

int main() {

    int numberOfRaysPerBounce = 5;
    int bounceDepth = 3;
    int width = 1000;
    int height = 1000;
    bool smoothen = false;


    auto start = chrono::steady_clock::now();

    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(1.0);
    Mesh *circle = MeshGenerator::generateUnitCircle(&emissiveMaterial2);

    MeshTransformer::rotateMesh(circle, M_PI_2, {0, -1, 0});
    MeshTransformer::translateMesh(circle, {5, 0, 0});

    vector<Mesh *> meshes{circle};
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