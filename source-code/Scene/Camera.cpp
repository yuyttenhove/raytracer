//
// Created by ellio on 14-10-2020.
//

#include "Camera.h"
#include "../util/MatrixUtils.h"
#include "../Geometry/MeshCollection.h"
#include "../util/RandomUtils.h"
#include <vector>

Picture Camera::takePicture(int numberOfSamples, bool msaa) {

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
                Vector3D vectorToPixel = getVecToPixel(i, j, msaa);
                Ray ray = Ray(vectorToPixel, origin);
                totalIntensity += rayIntensityCalculator.calculateIntensityRay(ray);
            }
            intensityValues[height - j - 1][i] = totalIntensity / numberOfSamples;
        }
    }
    return Picture(intensityValues);
}

Vector3D Camera::getVecToPixel(int i, int j, bool randomize) {
    double scaleFactor = 2. / (width);
    double viewingAngleFactor = tan(viewingAngle / 2);
    double y, z;
    if (randomize) {
        y = - viewingAngleFactor * (scaleFactor * (i + RandomUtils::randomUniform()) - 1);
        z = viewingAngleFactor * scaleFactor * (j + RandomUtils::randomUniform() - (double) height / 2);
    } else {
        y = - viewingAngleFactor * (scaleFactor * (i + .5) - 1);
        z = viewingAngleFactor * scaleFactor * (j + .5 - (double) height / 2);
    }
    return Vector3D(1, y, z).normalize();
}

Camera::Camera(int width, int height, double viewingAngle, const RayIntensityCalculator &rayIntensityCalculator) :
        width(width),
        height(height),
        viewingAngle(viewingAngle),
        rayIntensityCalculator(rayIntensityCalculator) {}

void Camera::printProgress(int row, int column) const {
//    cout << "row: " << row << "/" << height << "\t\t" << "column: " << column << "/" << height << endl ;
    cout << "\r" << "row: " << row << "/" << height << "\t\t" << "column: " << column << "/" << height << flush;
}
