#include <numerical_methods/derivative.h>

#include <assert.h>
#include <math.h>

double derivative (double f (double, void *), double x, void *p) {
    assert(isfinite(x));
    return 0.5 / EPS * (f(x + EPS, p) - f(x - EPS, p));
}
