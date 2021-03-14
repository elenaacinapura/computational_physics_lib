#include <stdio.h>
#include <math.h>
#include "zeros-newton.h"

double f (double x) {
    return pow (x-1.42, 2);
}

int main () {
    double start = 0.5;
    printf ("The zero of f(x) = (x-1.42)^2, calculated with starting point %.4lf, is %.4lf\n", start, zero(f, start));
}