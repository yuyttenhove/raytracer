//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_DIFFUSEMATERIAL_H
#define RAYTRACER_DIFFUSEMATERIAL_H


#include "Material.h"
#include <cmath>
#include "../MeshCollectionExporter/ExportStrings.h"
#include "../util/HalveUnitSphereVectorGenerator.h"
#include "../util/Matrix3x3.h"


class DiffuseMaterial : public Material {

    double albedo;

public:
    DiffuseMaterial(double albedo);

    double calculateIntensity(
            Ray *ray,
            Triangle *triangle,
            RayIntensityCalculator *rayIntensityCalculator,
            Vector3D *interSectionPoint
    ) override;

    virtual string getExportString() override;


};


#endif //RAYTRACER_DIFFUSEMATERIAL_H
