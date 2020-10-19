//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "../Geometry/MeshCollection.h"
#include "Camera.h"

class Scene {

    Camera *camera;

public:
    Scene(MeshCollection *meshCollection, World *world, int width, int height, int numberOfRaysPerBounce,
          int bounceDepth);

    void render(string fileName);
};


#endif //RAYTRACER_SCENE_H
