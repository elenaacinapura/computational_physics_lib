#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "trajectory.h"

typedef struct Param_f {
    double g;
    double m;
} Param_f;

double fx (double x, double y, void *p) {
    return 0;
}
double fy (double x, double y, void *p) {
    Param_f *param = (Param_f *) p;
    double g = param->g;
    double m = param->m;
    return -m*g;
}

int main () {
    trajectory(fx, fy, 1.0, 0.0, 0.0, 1.0, 10.0, 1e-2, 1e3, &(Param_f){9.8, 1.0}, 1, "Output_trajectory/trajectory.csv");
}