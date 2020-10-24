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

    int numberOfRaysPerBounce = 50;
    int bounceDepth = 3;
    int width = 1000;
    int height = 1000;
    bool smoothen = false;


    auto start = chrono::steady_clock::now();

    // mesh2
    DiffuseMaterial diffuseMaterial = DiffuseMaterial(1.0);
    Mesh *piramid = MeshGenerator::generateSphere(&diffuseMaterial, 4);
    MeshTransformer::rotateMesh(piramid, -M_PI_4, {0, 1, 0});
    MeshTransformer::translateMesh(piramid, {5, 0, 0});

    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh emissiveMesh = Mesh(&emissiveMaterial);
    Triangle triangle = Triangle(&emissiveMesh, {-1, 5000, -5000}, {-1, 0, 5000}, {-1, 0, -5000});
    emissiveMesh.addTriangle(&triangle);

    vector<Mesh *> meshes{piramid, &emissiveMesh};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, smoothen, numberOfRaysPerBounce, bounceDepth);

    scene.render(SAVE_ADDRESS);

    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Elapsed time in seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";

    return 0;
}