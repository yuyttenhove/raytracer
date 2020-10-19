//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_WORLDHDRI_H
#define RAYTRACER_WORLDHDRI_H


#include <vector>
#include <string>
#include <opencv2/core.hpp>
#include "World.h"

using namespace std;

class WorldHdri : public World {
    cv::Mat hdriImage;

public:
    WorldHdri(const string& filename);

    static cv::Mat loadHdri(const string& filename);

    double getIntensity(Vector3D direction) override;
};


#endif //RAYTRACER_WORLDHDRI_H
