#ifndef __ZEROS_H__
#define __ZEROS_H__

#ifndef EPS
#define EPS 1e-5
#endif

/**
 * @brief Find the zero of function f starting from "guess" x_0
 * 
 * @param f Function whose zero is to be calculated
 * @param x_0 Initial guess 
 * @param param Pointer to the struct of parameters of function f
 * 
 * @return The zero of function f
 */
double zero_newton (double f (double, void *), double x_0, void *param);

#endif