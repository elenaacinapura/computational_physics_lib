#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "trajectory.h"

void trajectory (double fx (double, double, void *p), double fy(double, double, void *p), double m, double x_0, double y_0, double vx_0, double vy_0, double dt, double time_interval, void *param, bool print_output, char output_path[]) {
    /*  Simulate the trajectory of a particle of mass m,
        under forces fx(x, y, params) and fy(x, y, params), 
        with initial position (x_0, y_0) and initial velocity (vx_0, vy_0),
        for a specified time interval and using an infinitesimal time increment dt.
        If specified, it outputs t, x, y, vx and vy on an output csv file 
    */
    // initial conditions
	double x_curr = x_0;
	double y_curr = y_0;
	double vx_curr = vx_0;
	double vy_curr = vy_0;
	double t = 0.0;
    // variables for iteration
	double x_next, y_next, vx_next, vy_next, ax, ay, vx_m, vy_m;
    // output file
	FILE* outf;
	if (print_output) {
		outf = fopen(output_path, "w");
        fprintf(outf, "#t\tx\ty\tvx\tvy\n");
	}
    // simulation
	do {
		// print current values
		if (print_output) {
			fprintf(outf, "%.4e\t%.4e\t%.4e\t%.4e\t%.4e\n", t, x_curr, y_curr, vx_curr, vy_curr);
		}
		// calculate a(t)
		ax = fx(x_curr, y_curr, param)/m;
		ay = fy(x_curr, y_curr, param)/m;
		// calculate v(t+dt/2)
		vx_m = vx_curr + ax * dt / 2;
		vy_m = vy_curr + ay * dt / 2;
		// calculate r(t+dt)
		x_next = x_curr + dt * vx_m;
		y_next = y_curr + dt * vy_m;
		// calculate a(t + dt)
		ax = fx(x_next, y_next, param)/m;
		ay = fy(x_next, y_next, param)/m;
		// calculate v(t+dt)
		vx_next = vx_m + ax * dt / 2;
		vy_next = vy_m + ay * dt / 2;
		// update values
		x_curr = x_next;
		y_curr = y_next;
		vx_curr = vx_next;
		vy_curr = vy_next;
		t += dt;
	} while (t < time_interval);

	if (print_output) {
		fclose(outf);
	}
}