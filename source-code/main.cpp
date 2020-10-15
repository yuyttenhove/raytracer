#include "util/Vector3D.h"
#include "Geometry/Triangle.h"
#include "Geometry/MeshCollection.h"
#include "Scene/Camera.h"
#include "Scene/Scene.h"
#include "Materials/EmissiveMaterial.h"
#include "Geometry/Mesh.h"
#include "Materials/ReflectiveMaterial.h"

using namespace std;

int main() {

    string saveLocation = "C:\\Users\\ellio\\CLionProjects\\raytracer\\source-code\\output\\result.txt";
    int numberOfRaysPerBounce = 5;
    int bounceDepth = 5;
    int width = 1000;
    int height = 1000;


    // mesh 1
    EmissiveMaterial emissiveMaterial1 = EmissiveMaterial(1.0);
    Mesh emissiveMesh1 = Mesh(&emissiveMaterial1);
    Triangle triangle1 = Triangle(&emissiveMesh1, {-2, 2, 4}, {0, -0.5, 4}, {2, 2, 6});
    emissiveMesh1.addTriangle(&triangle1);

    // mesh2
    EmissiveMaterial emissiveMaterial2 = EmissiveMaterial(0.5);
    Mesh emissiveMesh2 = Mesh(&emissiveMaterial2);
    Triangle triangle2 = Triangle(&emissiveMesh2, {-1, 2, 5}, {1, 0, 5}, {3, 2, 5});
    emissiveMesh2.addTriangle(&triangle2);

    ReflectiveMaterial reflectiveMaterial = ReflectiveMaterial(0.5);
    Mesh reflectiveMesh = Mesh(&reflectiveMaterial);
    Triangle reflectiveTriangle = Triangle(&reflectiveMesh, {0, -0.5, -5000}, {5000, -0.5, 5000}, {-5000, -0.5, 5000});
    reflectiveMesh.addTriangle(&reflectiveTriangle);

    vector<Mesh *> meshes{&emissiveMesh1, &emissiveMesh2, &reflectiveMesh};
    MeshCollection meshCollection = MeshCollection(meshes);

    Scene scene = Scene(&meshCollection, width, height, numberOfRaysPerBounce, bounceDepth);
    scene.render(saveLocation);


    return 0;

}
