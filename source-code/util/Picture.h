//
// Created by ellio on 14-10-2020.
//

#ifndef RAYTRACER_PICTURE_H
#define RAYTRACER_PICTURE_H

#include <vector>
#include <string>

using namespace std;

class Picture {

    vector<vector<double>> pixels;

public:
    void writeToFile(string fileName);

};


#endif //RAYTRACER_PICTURE_H
