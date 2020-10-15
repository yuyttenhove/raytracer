//
// Created by ellio on 14-10-2020.
//

#include "Scene.h"
#include <string>

Scene::Scene(MeshCollection meshCollection, Camera camera) :
        meshCollection(meshCollection),
        camera(camera) {}

void Scene::render(string fileName) {
    Picture picture = camera.takePicture(&meshCollection);
    picture.writeToFile(fileName);
}
