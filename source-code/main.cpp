#define _USE_MATH_DEFINES

#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "SystemSpecificConstants.h"
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

    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh emissiveMesh = Mesh(&emissiveMaterial);
    Triangle triangle = Triangle(&emissiveMesh, {10, 0, 5}, {10, 5, -5}, {10, 0, -5});
    emissiveMesh.addTriangle(&triangle);

    vector<Mesh *> meshes{&emissiveMesh};
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