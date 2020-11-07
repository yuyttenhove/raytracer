//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_REFLECTIVEMATERIAL_H
#define RAYTRACER_REFLECTIVEMATERIAL_H


#include "../RayUtils/Ray.h"
#include "../Geometry/Triangle.h"
#include "../RayUtils/RayIntensityCalculator.h"
#include "../MeshCollectionExporter/ExportStrings.h"
#include "Material.h"

class ReflectiveMaterial : public Material {

    double shininess;

public:
    ReflectiveMaterial(double shininess);

    double calculateIntensity(
            Ray *ray,
            Triangle *triangle,
            RayIntensityCalculator *rayIntensityCalculator,
            Vector3D *interSectionPoint
    ) override;

    string getExportString() override;

};


#endif //RAYTRACER_REFLECTIVEMATERIAL_H
