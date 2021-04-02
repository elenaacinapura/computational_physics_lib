#ifndef __VERLET_H__
#define __VERLET_H__

void verlet_1D(double *x, double *v, double dt, double acc(double, void *), void *param);

void verlet_3D(double x[], double v[], double a[], double dt, void calculate_acc(double[], double[], void *),
	       void *param);

void verlet_multibody(int N, double *x, double *v, double *a, double dt, void calculate_acc(double *, double *, void *),
		      void *param);

#endif