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

using namespace std;

int main() {


    string saveLocation = "C:\\Users\\ellio\\CLionProjects\\raytracer\\source-code\\output\\result.txt";
    int numberOfRaysPerBounce = 50;
    int bounceDepth = 2;
    int width = 500;
    int height = 500;



    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(1.0);
    Mesh emissiveMesh2 = Mesh(&emissiveMaterial2);
    Triangle triangle2 = Triangle(&emissiveMesh2, {-1, 2, 5}, {1, 0, 5}, {3, 2, 5});
    emissiveMesh2.addTriangle(&triangle2);

    DiffuseMaterial diffuseMaterial = DiffuseMaterial(1.0);
    Mesh diffuseMesh = Mesh(&diffuseMaterial);
    Triangle diffuseTriangle = Triangle(&diffuseMesh, {0, -0.5, -5000}, {5000, -0.5, 5000}, {-5000, -0.5, 5000});
    diffuseMesh.addTriangle(&diffuseTriangle);


    vector<Mesh *> meshes{&emissiveMesh2, &diffuseMesh};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, numberOfRaysPerBounce, bounceDepth);
    scene.render(saveLocation);


    return 0;

}
