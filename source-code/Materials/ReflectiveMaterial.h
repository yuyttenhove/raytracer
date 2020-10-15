//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_REFLECTIVEMATERIAL_H
#define RAYTRACER_REFLECTIVEMATERIAL_H


#include "../RayUtils/Ray.h"
#include "../Geometry/Triangle.h"
#include "../RayUtils/RayIntensityCalculator.h"
#include "Material.h"

class ReflectiveMaterial : public Material {

    float shininess;

public:
    ReflectiveMaterial(float shininess);

    double calculateIntensity(
            Ray *ray,
            Triangle *triangle,
            RayIntensityCalculator *rayIntensityCalculator,
            Vector3D *interSectionPoint
    ) override;

};


#endif //RAYTRACER_REFLECTIVEMATERIAL_H
