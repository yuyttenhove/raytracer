//
// Created by yuyttenh on 11/11/20.
//

#include <cstdlib>
#include "RandomUtils.h"

double RandomUtils::randomUniform(double minimum, double maximum) {
    return minimum + (maximum - minimum) * rand() / (RAND_MAX + 1.);
}
