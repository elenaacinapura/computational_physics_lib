#ifndef __TRAJECTORY_H__
#define __TRAJECTORY_H__

#include <stdbool.h>

void trajectory (double fx (double, double, void *p), double fy(double, double, void *p), double m, double x_0, double y_0, double vx_0, double vy_0, double dt, double time_interval, void *param, bool print_output, char output_path[]);

#endif