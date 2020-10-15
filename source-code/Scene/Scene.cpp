//
// Created by ellio on 14-10-2020.
//

#include "Scene.h"
#include <string>

Scene::Scene(TriangleCollection triangleCollection, Camera camera) :
        triangleCollection(triangleCollection),
        camera(camera) {}

void Scene::render(string fileName) {
    Picture picture = camera.takePicture(triangleCollection);
    picture.writeToFile(fileName);
}
