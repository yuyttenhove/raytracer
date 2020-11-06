//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_MATERIAL_H
#define RAYTRACER_MATERIAL_H


#include "../RayUtils/Ray.h"
#include "../Geometry/Triangle.h"
#include "../RayUtils/RayIntensityCalculator.h"

class Material {

public:

    virtual double calculateIntensity(
            Ray *ray,
            Triangle *triangle,
            RayIntensityCalculator *rayIntensityCalculator,
            Vector3D *interSectionPoint
    ) = 0;

    virtual string getExportString() = 0;
};


#endif //RAYTRACER_MATERIAL_H
