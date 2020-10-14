//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_CAMERA_H
#define RAYTRACER_CAMERA_H


#include "../util/Picture.h"
#include "../Geometry/TriangleCollection.h"

class Camera {
    int width;
    int height;

public:
    Picture takePicture(TriangleCollection triangleCollection);
};


#endif //RAYTRACER_CAMERA_H
