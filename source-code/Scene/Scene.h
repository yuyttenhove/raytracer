//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "../Geometry/MeshCollection.h"
#include "Camera.h"

class Scene {

    MeshCollection meshCollection;
    Camera camera;

public:
    Scene(MeshCollection meshCollection, Camera camera);

    void render(string fileName);
};


#endif //RAYTRACER_SCENE_H
