//
// Created by ellio on 14-10-2020.
//

#include "Scene.h"
#include <string>

void Scene::render(string fileName, int numberOfSamples, bool msaa) {
    Picture picture = camera->takePicture(numberOfSamples, msaa);
    if (smoothen) {
        picture.smoothen();
    }
    picture.writeToFile(fileName);
}

Scene::Scene(MeshCollection *meshCollection, int width, int height, bool smoothen, int bounceDepth)
: smoothen(smoothen)
{
    RayIntensityCalculator rayIntensityCalculator = RayIntensityCalculator(bounceDepth, meshCollection);
    camera = new Camera(width, height, rayIntensityCalculator);
}
