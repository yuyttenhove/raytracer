#include <iostream>
#include "util/Vector3D.h"

using namespace std;

int main() {

    Vector3D vec = Vector3D(5, 4, 3);
    Vector3D vec1 = Vector3D(10, 20, 30);
    double a = 5.5;
    cout << vec.normalize() << endl;
    cout << vec.normalize().length() << endl;

}
