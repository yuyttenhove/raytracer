#include <iostream>
#include "util/Vector3D.h"

using namespace std;

int main() {

    int
    Vector3D vector3D = Vector3D(1, 2, 3);

    cout << vector3D.getX() << " " << vector3D.getY() << " " << vector3D.getZ() << endl;

    cout << "Hello, World!" << endl;
    int i = 0;
    return 0;
}
