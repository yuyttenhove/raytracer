//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "../util/Picture.h"
#include "../Geometry/MeshCollection.h"
#include "../RayUtils/RayIntensityCalculator.h"

class Camera {
    int width;
    int height;
    Vector3D origin = {0, 0, 0};
    RayIntensityCalculator rayIntensityCalculator;


private:
    Vector3D getVecToPixel(int i, int j);

    void printProgress(int row, int column);

public:
    Camera(int width, int height, const RayIntensityCalculator &rayIntensityCalculator);

    Picture takePicture();

};


#endif //RAYTRACER_CAMERA_H
