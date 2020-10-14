//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_VECTOR3D_H
#define RAYTRACER_VECTOR3D_H


class Vector3D {

    int x;
    int y;
    int z;

public:
    Vector3D(int x, int y, int z);

public:
    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getZ() const;

    void setZ(int z);

};


#endif //RAYTRACER_VECTOR3D_H
