//
// Created by ellio on 14-10-2020.
//

#include "Camera.h"
#include "../util/MatrixUtils.h"
#include "../Geometry/MeshCollection.h"
#include "../util/RandomUtils.h"
#include <vector>

Picture Camera::takePicture(int numberOfSamples) {

    vector<vector<double>> intensityValues = MatrixUtils::initializeMatrixZero(height, width);
    int counter = 0;

    for (int j = 0; j < height; ++j) {
        for (int i = 0; i < width; ++i) {
            counter++;
            if (counter % 1000 == 0) {
                printProgress(j, i);
            }
            double totalIntensity = 0;
            for (int s = 0; s < numberOfSamples; ++s){
                Vector3D vectorToPixel = getVecToPixel(i, j);
                Ray ray = Ray(vectorToPixel, origin);
                totalIntensity += rayIntensityCalculator.calculateIntensityRay(&ray);
            }
            intensityValues[height - j - 1][i] = totalIntensity / numberOfSamples;
        }
    }
    return Picture(intensityValues);
}

Vector3D Camera::getVecToPixel(int i, int j) {
    double scaleFactor = 2. / (width);
    double y = -(scaleFactor * (i + RandomUtils::randomUniform()) - 1);
    double z = scaleFactor * (j + RandomUtils::randomUniform() - (double) height / 2);
    return Vector3D(1, y, z).normalize();
}

Camera::Camera(int width, int height, const RayIntensityCalculator &rayIntensityCalculator) :
        width(width),
        height(height),
        rayIntensityCalculator(rayIntensityCalculator) {}

void Camera::printProgress(int row, int column) const {
//    cout << "row: " << row << "/" << height << "\t\t" << "column: " << column << "/" << height << endl ;
    cout << "\r" << "row: " << row << "/" << height << "\t\t" << "column: " << column << "/" << height << flush;
}
