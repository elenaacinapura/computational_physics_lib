/** 
 * @file 
 * Integration of function - typesafe version.
 */ 

#ifndef __INTEGRATE_H__
#define __INTEGRATE_H__

/**
 * High-level struct that contains the parameters of a function to be evaluated.
 */
struct Fn_parameter {
	int type;   /**< A unique identifier tag for the function parameter type */
	void *data; /**< Pointer to the actual parameters of the function; the actual pointed type depends on the type
		       value and is to be determined at runtime*/
};

void integrate_param_free(struct Fn_parameter *p);

/**
 * @brief Trapezoidal integration
 *
 * Evaluate the definite integral of the function f between the given limits.
 * @param f Function to evaluate
 * @param low Lower integration limit
 * @param high Higher integration limit
 * @param density Point density
 * @param param Pointer to the high-level struct Fn_parameters for the function f, properly allocated.
 *
 * @return The value of the integral of f between low and high
 * @see Fn_parameter
 */
double integrate(double (*f)(double, struct Fn_parameter), double low, double high, int density,
		 struct Fn_parameter *param);

#endif /* __INTEGRATE_H__ */