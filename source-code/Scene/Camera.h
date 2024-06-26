//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "../util/Picture.h"
#include "../RayUtils/RayIntensityCalculator.h"

class Camera {
    int width;
    int height;
    Vector3D origin = {0, 0, 0};
    double viewingAngle;
    RayIntensityCalculator rayIntensityCalculator;


private:
    Vector3D getVecToPixel(int i, int j, bool randomize);

    void printProgress(int row, int column) const;

public:
    Camera(int width, int height, double viewingAngle, const RayIntensityCalculator &rayIntensityCalculator);

    Picture takePicture(int numberOfSamples, bool msaa);

};


#endif //RAYTRACER_CAMERA_H
