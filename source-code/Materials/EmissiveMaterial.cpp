//
// Created by ellio on 14-10-2020.
//

#include "EmissiveMaterial.h"


EmissiveMaterial::EmissiveMaterial(double intensity) : intensity(intensity) {}

bool EmissiveMaterial::isLightSource() {
    return true;
}
