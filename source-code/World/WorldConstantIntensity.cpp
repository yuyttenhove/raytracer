//
// Created by yolan on 19/10/20.
//

#include "WorldConstantIntensity.h"

WorldConstantIntensity::WorldConstantIntensity(double intensity) : intensity(intensity) {}

double WorldConstantIntensity::getIntensity(Vector3D direction) {
    return intensity;
}
