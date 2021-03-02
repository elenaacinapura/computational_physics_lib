#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "integrate.h"


struct Fn_parameter param_f_alloc (double a) {
    /* Allocator of the struct Fn_parameter for the function type "f". It assigns the fields "type" and "*data" */
	struct Fn_parameter p;
	struct Param_f *data = malloc(sizeof(struct Param_f));
	data->a = a;

	p.type = PTYPE_F;
	p.data = data;

	return p;
}

double integrate (double (*f) (double, struct Fn_parameter), double low, double high, int n, struct Fn_parameter *p) {
    /* Integrate function f between limits "low" and "high", using n points to apply the trapezoidal rule.
    You should pass the pointer to general struct "Fn_parameters" for the function f, properly allocated. */
    double h = (high - low) / (n - 1);
    double x_k[n];
	for (int i = 0; i < n; i++) {
		x_k[i] = low + h * i;
	}

	double I = (*f)(x_k[0], *p) / 2 + (*f)(x_k[n - 1], *p) / 2;
	for (int i = 1; i < n - 1; i++) {
		I += (*f)(x_k[i], *p);
	}
	I *= h;
}

void param_free(struct Fn_parameter *p) {
        free(p->data);
}    

/* define your function f. Here it's a gaussian */
double f(double x, struct Fn_parameter param) {
    assert(param.type == PTYPE_F);      // check for correct type
    struct Param_f *p = (struct Param_f *)(param.data);     // *p will contain the parameters of f 
	return exp(-pow(x, 2)/(p->a));      // use the parameters of f!
}
