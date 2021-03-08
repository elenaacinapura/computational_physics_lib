#include <stdio.h>
#include <math.h>
#include "inv-sqrt.h"

int main () {
    double x = 2.0;
    printf("1/sqrt(%.4lf) = %.4lf\n", x, inv_sqrt(x));
}