//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_EMISSIVEMATERIAL_H
#define RAYTRACER_EMISSIVEMATERIAL_H


#include "Material.h"

class EmissiveMaterial : public Material {

public:
    EmissiveMaterial(double intensity);

    bool isLightSource() override;

private:

    double intensity;


};


#endif //RAYTRACER_EMISSIVEMATERIAL_H
