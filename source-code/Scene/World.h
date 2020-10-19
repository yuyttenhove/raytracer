//
// Created by yolan on 19/10/20.
//

#ifndef RAYTRACER_WORLD_H
#define RAYTRACER_WORLD_H


#include "../util/Vector3D.h"

class World {
    double intensity;

public:
    World(double intensity);

    double getIntensity(Vector3D direction);
};


#endif //RAYTRACER_WORLD_H
