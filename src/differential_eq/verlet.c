#include <differential_eq/verlet.h>

void verlet_1D(double *x, double *v, double dt, double acc(double, void *), void *param) {
	*v += dt / 2 * acc(*x, param);
	*x += dt * *v;
	*v += dt / 2 * acc(*x, param);
}

void verlet_2D(double x[], double v[], double a[], double dt, void calculate_acc(double[], double[], void *),
	       void *param) {
	for (int i = 0; i < 2; i++) {
		v[i] += dt / 2 * a[i];
		x[i] += dt * v[i];
	}
	calculate_acc(x, a, param);
	for (int i = 0; i < 2; i++) {
		v[i] += dt / 2 * a[i];
	}
}

void verlet_3D(double x[], double v[], double a[], double dt, void calculate_acc(double[], double[], void *),
	       void *param) {
	for (int i = 0; i < 3; i++) {
		v[i] += dt / 2 * a[i];
		x[i] += dt * v[i];
	}
	calculate_acc(x, a, param);
	for (int i = 0; i < 3; i++) {
		v[i] += dt / 2 * a[i];
	}
}

void verlet_multibody_3D(int N, double x[][3], double v[][3], double a[][3], double dt,
		      void calculate_acc(double[][3], double[][3], void *), void *param) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			v[i][j] += dt / 2 * a[i][j];
			x[i][j] += dt * v[i][j];
		}
	}
	calculate_acc(x, a, param);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) {
			v[i][j] += dt / 2 * a[i][j];
		}
	}
}

void verlet_multibody_2D(int N, double x[][2], double v[][2], double a[][2], double dt,
			 void calculate_acc(double[][2], double[][2], void *), void *param) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			v[i][j] += dt / 2 * a[i][j];
			x[i][j] += dt * v[i][j];
		}
	}
	calculate_acc(x, a, param);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2; j++) {
			v[i][j] += dt / 2 * a[i][j];
		}
	}
}