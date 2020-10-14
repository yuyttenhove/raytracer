//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "../util/Picture.h"
#include "../Geometry/TriangleCollection.h"
#include "../RayUtils/RayIntensityCalculator.h"

class Camera {
    int width;
    int height;
    Vector3D origin = {0, 0, 0};
    RayIntensityCalculator rayIntensityCalculator;


private:
    Vector3D getVecToPixel(int i, int j);

public:
    Picture takePicture(TriangleCollection triangleCollection);
};


#endif //RAYTRACER_CAMERA_H
