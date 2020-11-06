//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_EMISSIVEMATERIAL_H
#define RAYTRACER_EMISSIVEMATERIAL_H


#include "Material.h"
#include "../MeshExporter/MaterialsExportNames.h"

class EmissiveMaterial : public Material {

    double intensity;

public:

    EmissiveMaterial(double intensity);

    double calculateIntensity(
            Ray *ray,
            Triangle *triangle,
            RayIntensityCalculator *rayIntensityCalculator,
            Vector3D *interSectionPoint
    ) override;

    string getExportString() override;
};


#endif //RAYTRACER_EMISSIVEMATERIAL_H
