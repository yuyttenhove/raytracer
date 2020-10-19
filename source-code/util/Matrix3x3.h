//
// Created by ellio on 15-10-2020.
//

#ifndef RAYTRACER_MATRIX3X3_H
#define RAYTRACER_MATRIX3X3_H

#include <vector>
#include "Vector3D.h"

using namespace std;

class Matrix3x3 {

    vector<vector<double>> matrix;

public:
    Matrix3x3();

    Matrix3x3(double theta, Vector3D axis);

    Matrix3x3(double sineTheta, double cosineTheta, Vector3D axis);

    void setElement(int i, int j, double value);

    Vector3D dot(Vector3D vec);

};


#endif //RAYTRACER_MATRIX3X3_H
