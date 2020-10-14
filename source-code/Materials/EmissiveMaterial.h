//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_EMISSIVEMATERIAL_H
#define RAYTRACER_EMISSIVEMATERIAL_H


#include "Material.h"

class EmissiveMaterial : public Material {

    double intensity;

    double calculateIntensity(Ray ray) override;


};


#endif //RAYTRACER_EMISSIVEMATERIAL_H
