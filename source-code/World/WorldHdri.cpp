//
// Created by yolan on 19/10/20.
//

#include "WorldHdri.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>


WorldHdri::WorldHdri(const string& filename) {
    hdriImage = loadHdri(filename);
}

cv::Mat WorldHdri::loadHdri(const string& filename) {
    cv::Mat img =  cv::imread(filename, cv::IMREAD_GRAYSCALE);
    cv::imshow("Display window", img);
    cv::waitKey(0);
    return img;
}

double WorldHdri::getIntensity(Vector3D direction) {
    direction = direction.normalize();
    double cosTheta = direction.getZ();
    double phi = atan2(direction.getY(), direction.getX());
    phi = phi > 0 ? phi : phi + M_PI;
    double rel_x = phi / (2 * M_PI);
    double rel_y = (1 - cosTheta) / 2;
    int row = (int)round(rel_y * hdriImage.rows);
    int col = (int)round(rel_x * hdriImage.cols);
    return (double)hdriImage.at<uchar>(row, col) / 255;
}
