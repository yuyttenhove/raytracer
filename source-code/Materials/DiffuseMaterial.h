//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_DIFFUSEMATERIAL_H
#define RAYTRACER_DIFFUSEMATERIAL_H


#include "Material.h"


class DiffuseMaterial : public Material {

    double albedo;

public:
    DiffuseMaterial(double albedo);

    bool bounceRay(Ray &ray, const Vector3D &normal, const Vector3D &interSectionPoint) override;

    virtual string getExportString() override;

};


#endif //RAYTRACER_DIFFUSEMATERIAL_H
