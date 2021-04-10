#include <minimum.h>
#include <math.h>
#include <stdio.h>

double minimum (double f (double, void *), double low, double high, void *p) {
    

    double x1, x2, x3, x4;
    x1 = low;
    x4 = high;
    while (fabs((x4-x1)/(x4+x1)) > EPS) {
        x2 = x1  + (x4 - x1)/4.0;
        x3 = x2 + (x4 - x1)/2.0;
        if (f(x2, p) < f(x3, p)){
            x4 = x3;
        } else {
            x1 = x2;
        }
        printf("x1 = %lf, x2 = %lf, x3 = %lf, x4 = %lf\n", x1, x2, x3, x4);
    }

    return x1;
}