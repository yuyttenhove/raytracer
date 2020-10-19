//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_PICTURE_H
#define RAYTRACER_PICTURE_H

#include <vector>
#include <string>
#include <utility>

using namespace std;

class Picture {

    vector<vector<double>> pixels;

public:
    const vector<vector<double>> &getPixels() const;

public:
    Picture(const vector<vector<double>> &pixels);

    void writeToFile(string fileName);

    void smoothen();

private:
    vector<pair<int, int>> findNeighbours(int row, int column);

    double averageSmoothen(int row, int column);

    double medianSmoothen(int row, int column);


};


#endif //RAYTRACER_PICTURE_H
