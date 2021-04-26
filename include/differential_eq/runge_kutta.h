#ifndef __RUNGE_KUTTA_H__
#define __RUNGE_KUTTA_H__

/**
 * @brief Runge-Kutta-4 step
 * 
 * Calculate x(t + dt) satisfying the given differential equation using Runge-Kutta-4
 * 
 * @param x_curr Value of x(t)
 * @param t_curr Current value of time
 * @param dt Infinitesimal increment in time
 * @param f Function that appears in dx/dt = f(x(t), t)
 * @param param Pointer to the parameters struct of f
 * 
 * @return x(t + dt)
 */
double RK4(double x_curr, double t_curr, double dt, double f(double, double, void *), void *param);

#endif
