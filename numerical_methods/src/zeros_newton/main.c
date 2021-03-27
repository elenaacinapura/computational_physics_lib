#include <stdio.h>
#include <math.h>
#include "zeros-newton.h"

typedef struct Param_f {
    double a;
} Param_f;

double f (double x, void *p) {
    Param_f *param = (Param_f *) p;
    double a = param->a;
    return a * pow (x-a, 2);
}

int main () {
    double a = 1.4;
    Param_f p_f = {a};
    double start = 0.5;
    double zero = zero_newton(f, start, &p_f);
    printf ("The zero of f(x) = (x-%lf)^2, calculated with starting point %.4lf, is %.4lf\n", a, start, zero);
}