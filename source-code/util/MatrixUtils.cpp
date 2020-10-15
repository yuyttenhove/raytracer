//
// Created by ellio on 15-10-2020.
//

#include "MatrixUtils.h"

vector<vector<double>> MatrixUtils::initializeMatrixZero(int numberOfRows, int numberOfColumns) {
    vector<vector<double>> matrix = vector<vector<double>>(numberOfRows);
    for (int i = 0; i < numberOfRows; ++i) {
        matrix[i] = vector<double>(numberOfColumns);
    }
    return matrix;
}
