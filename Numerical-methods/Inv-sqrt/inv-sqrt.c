#include <math.h>
#include "inv-sqrt.h"

const double eps = 1e-5;

double inv_sqrt (double x) {
    /* Calculate inverse of square root with the Newton-Raphson method */
    double x_next = x/2.0;
    double x_curr;
    do {
        x_curr = x_next;
        x_next = 1.5 * x_curr - 0.5 * x * pow(x_curr, 3);
    } while (fabs(x_curr - x_next) > eps);
    return x_curr;
}