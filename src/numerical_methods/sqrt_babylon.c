#include <assert.h>
#include <math.h>

#include <numerical_methods/sqrt_babylon.h>

double sqrt_babylon(double x) {
	assert(isfinite(x));
	assert(x >= 0.0);

	if (x == 0.0) {
		return 0.0;
	}

	double x_next = x / 2.0; /* starting value for calculation */
	double x_0;	 /* current value in iteration */
	do {
		x_0 = x_next;
		x_next = 0.5 * (x_0 + x / x_0);
	} while (fabs(x_next - x_0) > EPS);

	return x_next;
}