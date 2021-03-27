#include <math.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <integration/param_typesafe/integrate.h>

/*---------------------------------------------------------*/
/* Structs and functions for function f */

struct Param_f {
	/* struct with parameters of "f" */
    double a;
};

struct Fn_parameter param_f_alloc (double a) {
    /* Allocator of the struct Fn_parameter for the function type "f". It assigns the fields "type" and "*data" */
	struct Fn_parameter p;
	struct Param_f *data = malloc(sizeof(struct Param_f));
	data->a = a;

	p.type = PTYPE_F;
	p.data = data;

	return p;
}

double f(double x, struct Fn_parameter param) {
	/* Definition of function "f" */
    assert(param.type == PTYPE_F);      // check for correct type
    struct Param_f *p = (struct Param_f *)(param.data);     // *p will contain the parameters of f 
	return exp(-pow(x, 2)/(p->a));      // use the parameters of f!
}

/*---------------------------------------------------------*/



int main() {
	double a = 2.0;
    struct Fn_parameter f_param = param_f_alloc(a); // create the high-level struct "Fn_parameters" for f

	printf("Integral of the gaussian");
	printf("I = %lf\n", integrate(f, -50.0, 50.0, 100, &f_param));
	printf("Expected I = %lf\n", sqrt(M_PI*a));

	param_free(&f_param); // very important, you are using dynamic memory
}