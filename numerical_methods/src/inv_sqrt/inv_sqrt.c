#include <assert.h>
#include <math.h>

#include <inv_sqrt.h>

double inv_sqrt (double x) {
    assert(isfinite(x));
    assert(x > 0.0);

    /* Calculate inverse of square root with the Newton-Raphson method */
    double x_next = x/2.0;
    double x_curr;
    do {
        x_curr = x_next;
        x_next = 1.5 * x_curr - 0.5 * x * pow(x_curr, 3);
    } while (fabs(x_curr - x_next) > EPS);
    return x_curr;
}