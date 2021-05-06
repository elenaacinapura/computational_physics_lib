#include <assert.h>
#include <math.h>
#include <stdlib.h>

#include <numerical_methods/integrate_typesafe.h>

double integrate(double f(double, struct Fn_parameter), double low, double high, int density,
		 struct Fn_parameter *param) {
	assert(density > 0);
	assert(isfinite(low) && isfinite(high));
	assert(low <= high);

	int n = (int)ceil((high - low) * density); /* number of points */
	double dx = (high - low) / (n + 1);	   /* increment in integration variable */
	double integral = 0;

	for (int i = 1; i < n; i++) {
		double x1 = low + dx * (i);
		double x2 = x1 + dx;
		integral += f((x1 + x2) / 2.0, *param);
	}

	return integral *= dx;
}

void integrate_param_free(struct Fn_parameter *p) {
	assert(p->data != NULL);

	free(p->data);
	p->data = NULL;
}
