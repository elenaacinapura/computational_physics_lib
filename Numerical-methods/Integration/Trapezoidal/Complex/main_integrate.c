#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "integrate.h"




int main() {
	double a = 2.0;
    struct Fn_parameter f_param = param_f_alloc(a); // very easy to create the general struct "Fn_parameters" for f
	double low, high, h, I;
	low = -5.0;
	high = 5.0;
    int n = 100;

	printf("I = %lf\n", integrate(&f, low, high, n, &f_param));     // remember that f and its struct should be passed by reference
	printf("Expected I = %lf\n", sqrt(M_PI*a));

	param_free(&f_param); // very important, you are using dynamic memory
}