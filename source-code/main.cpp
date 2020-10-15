#include <iostream>
#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "Geometry/Mesh.h"

using namespace std;

int main() {

    string saveLocation = "C:\\Users\\ellio\\CLionProjects\\raytracer\\source-code\\output\\result.txt";
    int numberOfRaysPerBounce = 5;
    int bounceDepth = 5;
    int width = 1000;
    int height = 1000;


    EmissiveMaterial emissiveMaterial = EmissiveMaterial(1.0);
    Mesh mesh = Mesh(&emissiveMaterial);

    Triangle triangle1 = Triangle(&mesh, {-2, 2, 5}, {0, 0, 5}, {2, 2, 5});
    Triangle triangle2 = Triangle(&mesh, {-4, 2, 5}, {1, 0, 5}, {3, 2, 5});

    vector<Triangle *> triangles{&triangle1, &triangle2};
    mesh.addTriangles(triangles);

    vector<Mesh *> meshes{&mesh};
    MeshCollection triangleCollection = MeshCollection(meshes);

    const RayIntensityCalculator &calculator = RayIntensityCalculator(numberOfRaysPerBounce, bounceDepth);
    Camera camera = Camera(width, height, calculator);

    Scene scene = Scene(triangleCollection, camera);
    scene.render(saveLocation);


    return 0;

}
