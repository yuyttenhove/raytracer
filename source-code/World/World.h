//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_WORLD_H
#define RAYTRACER_WORLD_H

#include "../util/Vector3D.h"

class World {
public:
    virtual double getIntensity(Vector3D direction) = 0;
};

#endif //RAYTRACER_WORLD_H
