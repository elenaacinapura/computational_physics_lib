#include <stdio.h>
#include <math.h>
#include "integrate.h"

//struct with parameters of function f
typedef struct Param_f {	
	double a;
} Param_f;

// my function - a gaussian!
double f (double x, void *p) {		
	Param_f *param = (Param_f *) p;		// I create a struct of the right type (Param_f and assign the content of p to it)
	double a = param->a;	// just to avoid writing param-> every time
	return a*exp(-x*x);
}

int main () {
	Param_f p_f = {1.0};	// quick way for intializing a struct (for more parameter, separate them with comma)

	double I = integrate(f, -50.0, 50.0, 100, &p_f);

	//output the result
	printf("Integral of the gaussian from -inf to inf\n");
	printf("Expected value: %lf\n", p_f.a*sqrt(	M_PI));
	printf("Obtained value: %lf\n", I);

}
