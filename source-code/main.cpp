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
#include "World/WorldHdri.h"
#include <cmath>
#include <random>

using namespace std;

int main() {


    string saveLocation = "/home/yolan/dev/raytracer/source-code/output/result.txt";
    int numberOfRaysPerBounce = 50;
    int bounceDepth = 2;
    int width = 500;
    int height = 500;


    // world
    string hdri_filename = "/home/yolan/dev/raytracer/source-code/World/sunflowers_4k.png";
    WorldHdri world = WorldHdri(hdri_filename);

//    // light
//    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
//    Mesh emissiveMesh = Mesh(&emissiveMaterial);
//    Triangle triangle2 = Triangle(&emissiveMesh, {1, -1, 1}, {1, 5, 3}, {1, -1, 5});
//    emissiveMesh.addTriangle(&triangle2);
//
//    // floor
//    DiffuseMaterial diffuseMaterial = DiffuseMaterial(.75);
//    Mesh diffuseMesh = Mesh(&diffuseMaterial);
//    Triangle diffuseTriangle = Triangle(&diffuseMesh, {-100, 0, -1}, {100, 100, -1}, {100, 100, -1});
//    diffuseMesh.addTriangle(&diffuseTriangle);
//
//
//    vector<Mesh *> meshes{&emissiveMesh, &diffuseMesh};
//    MeshCollection meshCollection = MeshCollection(meshes);

    vector<Mesh *> meshes{};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, &world, width, height, numberOfRaysPerBounce, bounceDepth);
    scene.render(saveLocation);


    return 0;

}
