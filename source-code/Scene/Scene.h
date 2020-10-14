//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "../Geometry/TriangleCollection.h"
#include "Camera.h"

class Scene {

    TriangleCollection triangleCollection;
    Camera camera;

public:
    Scene(TriangleCollection triangleCollection, Camera camera);

    void render(string fileName);
};


#endif //RAYTRACER_SCENE_H
