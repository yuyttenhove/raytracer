#define _USE_MATH_DEFINES

#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "Geometry/Mesh.h"
#include "Materials/ReflectiveMaterial.h"
#include "util/Matrix3x3.h"
#include "Materials/DiffuseMaterial.h"
#include <cmath>
#include <random>
#include <chrono>

using namespace std;

int main() {


    string saveLocation = "C:\\Users\\ellio\\CLionProjects\\raytracer\\source-code\\output\\result.txt";
    int numberOfRaysPerBounce = 20;
    int bounceDepth = 2;
    int width = 1920;
    int height = 1080;
    bool smoothen = true;


    auto start = chrono::steady_clock::now();

    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(1.0);
    Mesh emissiveMesh2 = Mesh(&emissiveMaterial2);
    Triangle triangle2 = Triangle(&emissiveMesh2, {0, -5000, 1.99}, {5000, -5000, 1.99}, {0, 5000, 1.99});
    emissiveMesh2.addTriangle(&triangle2);

    DiffuseMaterial diffuseMaterial = DiffuseMaterial(1.0);
    Mesh diffuseMesh = Mesh(&diffuseMaterial);
    Triangle diffuseTriangle = Triangle(&diffuseMesh, {2, -2, 2.01}, {-2, -2, 2.01}, {0, 2, 2.01});
    diffuseMesh.addTriangle(&diffuseTriangle);


    vector<Mesh *> meshes{&emissiveMesh2, &diffuseMesh};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, smoothen, numberOfRaysPerBounce, bounceDepth);
    scene.render(saveLocation);

    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Elapsed time in seconds : "
         << chrono::duration_cast<chrono::seconds>(end - start).count()
         << " sec";


    return 0;

}
