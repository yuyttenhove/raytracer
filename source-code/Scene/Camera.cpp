//
// Created by ellio on 14-10-2020.
//

#include "Camera.h"
#include "../util/MatrixUtils.h"
#include <vector>

Picture Camera::takePicture(TriangleCollection triangleCollection) {

    vector<vector<double>> intensityValues = MatrixUtils::initializeMatrixZero(height, width);
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            Vector3D vectorToPixel = getVecToPixel(i, j);
            Ray ray = Ray(vectorToPixel, origin);
            intensityValues[height - j - 1][i] = rayIntensityCalculator.calculateIntensityRay(ray, &triangleCollection);
        }
    }

    return Picture(intensityValues);
}

Vector3D Camera::getVecToPixel(int i, int j) {
    double scaleFactor = 2. / (width);
    double x = scaleFactor * (i + 0.5) - 1;
    double y = scaleFactor * (j + 0.5 - (double) height / 2);
    return Vector3D(x, y, 1).normalize();
}

Camera::Camera(int width, int height, const RayIntensityCalculator &rayIntensityCalculator) :
        width(width),
        height(height),
        rayIntensityCalculator(rayIntensityCalculator) {}
