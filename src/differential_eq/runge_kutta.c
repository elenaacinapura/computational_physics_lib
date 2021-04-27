#include <differential_eq/runge_kutta.h>

double RK4(double x, double t, double dt, double f(double, double, void *), void *param) {
	double K1 = f(x, t, param);
	double K2 = f(x + 0.5 * dt * K1, t + 0.5 * dt, param);
	double K3 = f(x + 0.5 * dt * K2, t + 0.5 * dt, param);
	double K4 = f(x + dt * K3, t + dt, param);

	return x + dt / 6.0 * (K1 + 2.0 * K2 + 2.0 * K3 + K4);
}