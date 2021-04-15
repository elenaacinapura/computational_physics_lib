#ifndef __MINIMUM_H__
#define __MINIMUM_H__
/**
 * @brief Find minimum of function f between given.
 *
 * Calculate the point where the function f has minimum, restricting the rearch between the given bounds.
 *
 * @param f Function to find minimum of.
 * @param low Lower bound for the search of the minimum.
 * @param high Higher bound for the search of the minimum.
 * @param p Pointer to the parameters struct of function f.
 *
 * @return The point where the function f has minimum.
 */
double minimum(double f(double, void *), double low, double high, void *p);

#endif