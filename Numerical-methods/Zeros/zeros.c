#include <math.h>
#include "zeros.h"

const double eps = 1e-5;

double zero (double (*f) (double), double x_0) {
    /* Calculate zero of function f, starting from "guess" x_0 */
    double x_next = x_0;
    double x_curr = x_0 - 0.1*x_0;
    double x_prev;
    do {
        x_prev = x_curr;
        x_curr = x_next;
        x_next = x_curr - (x_curr - x_prev)/((*f)(x_curr) - (*f)(x_prev)) * f(x_curr);
    } while (fabs(x_next - x_curr) > eps);
    return x_next;
}