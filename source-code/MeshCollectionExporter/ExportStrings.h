//
// Created by ellio on 6-11-2020.
//

#ifndef RAYTRACER_EXPORTSTRINGS_H
#define RAYTRACER_EXPORTSTRINGS_H

#include <string>

using namespace std;

const string diffuseMaterialExportName = "DIFFUSE";
const string emissiveMaterialExportName = "EMISSIVE";
const string reflectiveMaterialExportName = "REFLECTIVE";

const string meshDelimiter = "\n";
const string materialDelimiter = "&";
const string materialPropertiesDelimiter = "_";
const string trianglesDelimiter = ";";
const string trianglePointDelimiter = "|";
const string xyzDelimiter = ",";

#endif //RAYTRACER_EXPORTSTRINGS_H
