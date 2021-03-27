#include <assert.h>
#include <math.h>

#include <zeros_newton.h>

double zero_newton (double f (double, void *p), double x_0, void *param) {
    assert(isfinite(x_0));

    /* Calculate zero of function f, starting from "guess" x_0 */
    double x_curr = x_0;
    double x_next = x_0 - f(x_curr, param) * 2*EPS / (f(x_curr + EPS, param) - f (x_curr - EPS, param));
    double x_prev;
    do {
        x_prev = x_curr;
        x_curr = x_next;
        x_next = x_curr - (x_curr - x_prev)/(f(x_curr, param) - f(x_prev, param)) * f(x_curr, param);
    } while (fabs(x_next - x_curr)/fabs(x_next + x_curr) > EPS);
    return x_next;
}