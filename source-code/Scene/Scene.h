//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_SCENE_H
#define RAYTRACER_SCENE_H


#include "../Geometry/MeshCollection.h"
#include "Camera.h"

class Scene {

    Camera *camera;

    bool smoothen;

public:
    Scene(MeshCollection *meshCollection, int width, int height, bool smoothen, int bounceDepth);

    void render(string fileName, int numberOfSamples, bool msaa=true);
};


#endif //RAYTRACER_SCENE_H
