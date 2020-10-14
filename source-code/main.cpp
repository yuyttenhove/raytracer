#include <iostream>
#include "util/Vector3D.h"
#include "Geometry/Triangle.h"

using namespace std;

int main() {

    Vector3D vec1 = Vector3D(5, 13, 78);
    Vector3D vec2 = Vector3D(1, 2, 3);

    Triangle triangle = Triangle(nullptr, vec1, vec2, vec1);
    cout << triangle.getNormal() << endl;
    cout << triangle.getNormal().length() << endl;

}
