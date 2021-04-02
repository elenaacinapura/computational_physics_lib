/** 
 * @file 
 * Integration of function - not typesafe version.
 */ 

#ifndef __INTEGRATE_NOTYPESAFE_H__
#define __INTEGRATE_NOTYPESAFE_H__

#ifndef EPS
#define EPS 1e-5
#endif

/**
 * @brief Trapezoidal integration
 *
 * Evaluate the definite integral of the function f between the given limits.
 * @param f Function to integrate
 * @param low Lower integration limit
 * @param high Higher integration limit
 * @param density Point density
 * @param param Pointer to the struct containing the parameters of f
 *
 * @return The value of the integral of f between low and high
 */
double integrate (double f (double, void *p), double low, double high, int density, void *param);

#endif