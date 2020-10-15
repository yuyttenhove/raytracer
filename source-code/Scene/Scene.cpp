//
// Created by ellio on 14-10-2020.
//

#include "Scene.h"
#include <string>

void Scene::render(string fileName) {
    Picture picture = camera->takePicture();
    picture.writeToFile(fileName);
}

Scene::Scene(MeshCollection *meshCollection, int width, int height, int numberOfRaysPerBounce, int bounceDepth) {
    RayIntensityCalculator rayIntensityCalculator = RayIntensityCalculator(
            numberOfRaysPerBounce,
            bounceDepth,
            meshCollection
    );

    camera = new Camera(width, height, rayIntensityCalculator);
}
