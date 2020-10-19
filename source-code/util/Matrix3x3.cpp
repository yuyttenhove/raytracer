//
// Created by ellio on 15-10-2020.
//

#include "Matrix3x3.h"
#include "MatrixUtils.h"

Matrix3x3::Matrix3x3() {
    matrix = MatrixUtils::initializeMatrixZero(3, 3);
}

Matrix3x3::Matrix3x3(double theta, Vector3D axis) : Matrix3x3(sin(theta), cos(theta), axis){}

Matrix3x3::Matrix3x3(double sineTheta, double cosineTheta, Vector3D axis) {
    matrix = MatrixUtils::initializeMatrixZero(3, 3);

    if (axis.length() < 0.0001) {
        matrix[0][0] = 1.0;
        matrix[1][1] = 1.0;
        matrix[2][2] = 1.0;
    } else {
        double ux = axis.getX();
        double uy = axis.getY();
        double uz = axis.getZ();

        double oneMinusCosineTheta = 1 - cosineTheta;
        matrix[0][0] = (ux * ux * oneMinusCosineTheta) + cosineTheta;
        matrix[0][1] = (ux * uy * oneMinusCosineTheta) - (uz * sineTheta);
        matrix[0][2] = (ux * uz * oneMinusCosineTheta) + (uy * sineTheta);

        matrix[1][0] = (uy * ux * oneMinusCosineTheta) + (uz * sineTheta);
        matrix[1][1] = (uy * uy * oneMinusCosineTheta) + cosineTheta;
        matrix[1][2] = (uy * uz * oneMinusCosineTheta) - (ux * sineTheta);

        matrix[2][0] = (uz * ux * oneMinusCosineTheta) - (uy * sineTheta);
        matrix[2][1] = (uz * uy * oneMinusCosineTheta) + (ux * sineTheta);
        matrix[2][2] = (uz * uz * oneMinusCosineTheta) + cosineTheta;
    }

}

Vector3D Matrix3x3::dot(Vector3D vec) {

    double vx = vec.getX();
    double vy = vec.getY();
    double vz = vec.getZ();

    double newVx = matrix[0][0] * vx + matrix[0][1] * vy + matrix[0][2] * vz;
    double newVy = matrix[1][0] * vx + matrix[1][1] * vy + matrix[1][2] * vz;
    double newVz = matrix[2][0] * vx + matrix[2][1] * vy + matrix[2][2] * vz;

    return {newVx, newVy, newVz};
}

void Matrix3x3::setElement(int i, int j, double value) {
    matrix[i][j] = value;
}
