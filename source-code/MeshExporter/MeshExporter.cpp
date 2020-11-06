//
// Created by ellio on 6-11-2020.
//

#include <string>
#include "../Geometry/Mesh.h"
#include "../Materials/DiffuseMaterial.h"

using namespace std;

string meshDelimiter = "\n";
string materialDelimiter = ",";
string triangleDelimiter = ";";

enum MaterialsEnum {
    Diffuse, Reflecting
};

int main() {


    return 0;
}

string generateMeshString(Mesh *mesh) {
    mesh->getMaterial();
}

