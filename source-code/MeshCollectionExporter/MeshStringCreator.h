//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_MESHSTRINGCREATOR_H
#define RAYTRACER_MESHSTRINGCREATOR_H

#include <string>
#include "../Geometry/Mesh.h"

using namespace std;

class MeshStringCreator {

public:
    static string generateMeshString(Mesh *mesh);

    static string generateTriangleString(Triangle *triangle);

};


#endif //RAYTRACER_MESHSTRINGCREATOR_H
