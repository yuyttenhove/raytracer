//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_WORLDCONSTANTINTENSITY_H
#define RAYTRACER_WORLDCONSTANTINTENSITY_H


#include "World.h"

class WorldConstantIntensity : public World {
    double intensity;

public:
    WorldConstantIntensity(double intensity);

    double getIntensity(Vector3D direction) override;
};


#endif //RAYTRACER_WORLDCONSTANTINTENSITY_H
