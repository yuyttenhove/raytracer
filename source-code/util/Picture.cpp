//
// Created by ellio on 14-10-2020.
//

#include "Picture.h"
#include <fstream>

void Picture::writeToFile(string fileName) {

    ofstream myfile;
    myfile.open(fileName);
    for (const auto &row:pixels) {
        for (auto pixel:row) {
            myfile << pixel << "\t";
        }
        myfile << "\n";
    }
    myfile.close();

}

Picture::Picture(const vector<vector<double>> &pixels) : pixels(pixels) {}
