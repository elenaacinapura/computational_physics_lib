#include <numerical_methods/derivative.h>

#include <assert.h>
#include <math.h>

double derivative (double f (double, void *), double x, void *p) {
    assert(isfinite(x));
    return 0.5 / EPS * (f(x + EPS, p) - f(x - EPS, p));
}

double derivate_best(double f(double,void*), double x0, double dx, void *p){
    return ( -f(x0+2*dx,p) + 8*f(x0+dx,p) -8*f(x0-dx,p) + f(x0-2*dx,p) ) / (12*dx);
}
