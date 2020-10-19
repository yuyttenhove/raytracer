//
// Created by ellio on 14-10-2020.
//

#include "Picture.h"
#include "MatrixUtils.h"
#include <fstream>
#include <algorithm>

void Picture::writeToFile(string fileName) {

    ofstream myfile;
    myfile.open(fileName);
    for (const auto &row:pixels) {
        for (auto pixel:row) {
            myfile << pixel << " ";
        }
        myfile << "\n";
    }
    myfile.close();

}

Picture::Picture(const vector<vector<double>> &pixels) : pixels(pixels) {}

const vector<vector<double>> &Picture::getPixels() const {
    return pixels;
}

void Picture::smoothen() {

    unsigned int maxRow = pixels.size();
    unsigned int maxColumn = pixels[0].size();
    vector<vector<double>> smoothenedValues = MatrixUtils::initializeMatrixZero(maxRow, maxColumn);
    for (int row = 0; row < maxRow; row++) {
        for (int column = 0; column < maxColumn; column++) {
            smoothenedValues[row][column] = medianSmoothen(row, column);
        }
    }
    this->pixels = smoothenedValues;
}

vector<pair<int, int>> Picture::findNeighbours(int row, int column) {

    vector<pair<int, int>> neighbours = vector<pair<int, int>>();

    int maxRow = pixels.size();
    int maxColumn = pixels[0].size();

    if (column < maxColumn - 1) {
        neighbours.emplace_back(row, column + 1);
    }

    if (column != 0) {
        neighbours.emplace_back(row, column - 1);
    }

    if (row != 0) {
        neighbours.emplace_back(row - 1, column);

        if (column != 0) {
            neighbours.emplace_back(row - 1, column - 1);
        }

        if (column < maxColumn - 1) {
            neighbours.emplace_back(row - 1, column + 1);
        }
    }

    if (row < maxRow - 1) {
        neighbours.emplace_back(row + 1, column);

        if (column != 0) {
            neighbours.emplace_back(row + 1, column - 1);
        }

        if (column < maxColumn - 1) {
            neighbours.emplace_back(row + 1, column + 1);
        }
    }
    return neighbours;
}

double Picture::averageSmoothen(int row, int column) {
    double newValue = pixels[row][column] / 2;

    const vector<pair<int, int>> &neighbours = findNeighbours(row, column);
    double newValueFromNeighbours = 0.;
    for (auto neighbour:neighbours) {
        newValueFromNeighbours += pixels[neighbour.first][neighbour.second];
    }

    newValue += newValueFromNeighbours / (neighbours.size() * 2);

    return newValue;
}

double Picture::medianSmoothen(int row, int column) {
    const vector<pair<int, int>> &neighbours = findNeighbours(row, column);

    vector<double> values = vector<double>();
    values.reserve(neighbours.size());
    for (auto neighbour: neighbours) {
        values.push_back(pixels[neighbour.first][neighbour.second]);
    }

    if (column == 400) {
        int i = 0;
    }
    sort(values.begin(), values.end());
    int medianIndex = neighbours.size() / 2;

    return values[medianIndex];
}

