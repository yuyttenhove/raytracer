//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../RayUtils/Ray.h"

class Material {

public:
    virtual bool isLightSource() = 0;
};


#endif //RAYTRACER_MATERIAL_H
