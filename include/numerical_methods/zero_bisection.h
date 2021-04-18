#ifndef __ZERO_BISECTION_H__
#define __ZERO_BISECTION_H__

/**
 * @brief Calculate the zero of a function using the bisection method.
 * 
 * @param f function whose zero is to be calculated.
 * @param low Lower bound for the search of the zero.
 * @param high Higher bound for the seach of the zero
 * @param param Pointer to the parameters struct of f.
 * 
 * @return the value where f has its zero between low and high bounds.
 */
double zero_bisection(double f (double, void *), double low, double high, void *param);

#endif