#include <math.h>
#include "zeros-newton.h"

const double eps = 1e-5;

double zero_newton (double f (double, void *p), double x_0, void *param) {
    /* Calculate zero of function f, starting from "guess" x_0 */
    double x_curr = x_0;
    double x_next = x_0 - f(x_curr, param) * 2*eps / (f(x_curr + eps, param) - f (x_curr - eps, param));
    double x_prev;
    do {
        x_prev = x_curr;
        x_curr = x_next;
        x_next = x_curr - (x_curr - x_prev)/(f(x_curr, param) - f(x_prev, param)) * f(x_curr, param);
    } while (fabs(x_next - x_curr)/fabs(x_next + x_curr) > eps);
    return x_next;
}