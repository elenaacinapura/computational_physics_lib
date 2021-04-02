#include <stdio.h>
#include <math.h>
#include "sqrt-babylon.h"

int main () {
    double x = 2.0;
    printf("sqrt(%.5lf) = %.5lf\n", x, sqrt_babylon(x));
}