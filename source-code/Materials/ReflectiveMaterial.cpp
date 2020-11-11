//
// Created by ellio on 15-10-2020.
//

#include "ReflectiveMaterial.h"

ReflectiveMaterial::ReflectiveMaterial(double shininess) : shininess(shininess) {}

bool ReflectiveMaterial::bounceRay(Ray &ray, const Vector3D &normal, const Vector3D &interSectionPoint) {
    Vector3D direction = ray.getDirection();
    Vector3D reflectedDirection = direction - 2 * (direction.dot(normal)) * normal;

    ray.bounce(reflectedDirection, interSectionPoint, shininess * ray.getIntensity());
    return true;
}

string ReflectiveMaterial::getExportString() {
    return reflectiveMaterialExportName + materialPropertiesDelimiter + to_string(shininess);
}
