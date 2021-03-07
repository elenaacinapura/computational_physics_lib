#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "integrate.h"

// define the function to integrate
double f (double x) {
    return exp(-pow(x, 2));
}

int main () {
    double low = -50.0;
    double high = 50.0;
    double I = integrate(f, low, high, 10000);
    printf("%lf\n", I);
}