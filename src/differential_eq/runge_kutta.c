#include <differential_eq/runge_kutta.h>

double RK4(double x_curr, double t_curr, double dt, double f(double, double, void *), void *param) {
    double K1 = f(x_curr, t_curr, param);
    double K2 = f(x_curr + 0.5*dt*K1, t_curr + 0.5*dt, param);
    double K3 = f(x_curr + 0.5*dt*K2, t_curr + 0.5*dt, param);
    double K4 = f(x_curr + dt*K3, t_curr + dt, param);

    return x_curr + dt/6* (K1 + 2*K2 + 2*K3 + K4);
}