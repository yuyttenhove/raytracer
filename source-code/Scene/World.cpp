//
// Created by yolan on 19/10/20.
//

#include "World.h"

World::World(double intensity) : intensity(intensity) {}

double World::getIntensity(Vector3D direction) {
    return intensity;
}
