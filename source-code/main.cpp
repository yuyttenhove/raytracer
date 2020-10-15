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


    // mesh 1
    EmissiveMaterial emissiveMaterial1 = EmissiveMaterial(1.0);
    Mesh mesh1 = Mesh(&emissiveMaterial1);
    Triangle triangle1 = Triangle(&mesh1, {-2, 2, 4}, {0, 0, 4}, {2, 2, 6});
    mesh1.addTriangle(&triangle1);

    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(0.5);
    Mesh mesh2 = Mesh(&emissiveMaterial2);
    Triangle triangle2 = Triangle(&mesh2, {-1, 2, 5}, {1, 0, 5}, {3, 2, 5});
    mesh2.addTriangle(&triangle2);

    vector<Mesh *> meshes{&mesh1, &mesh2};
    MeshCollection meshCollection = MeshCollection(meshes);

    const RayIntensityCalculator &calculator = RayIntensityCalculator(numberOfRaysPerBounce, bounceDepth);
    Camera camera = Camera(width, height, calculator);

    Scene scene = Scene(meshCollection, camera);
    scene.render(saveLocation);


    return 0;

}
