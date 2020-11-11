//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_EMISSIVEMATERIAL_H
#define RAYTRACER_EMISSIVEMATERIAL_H


#include "Material.h"
#include "../MeshCollectionExporter/ExportStrings.h"

class EmissiveMaterial : public Material {

    double intensity;

public:

    EmissiveMaterial(double intensity);

    bool bounceRay(Ray &ray, const Vector3D &normal, const Vector3D &interSectionPoint) override;

    string getExportString() override;
};


#endif //RAYTRACER_EMISSIVEMATERIAL_H
