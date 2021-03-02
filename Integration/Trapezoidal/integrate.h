#ifndef __INTEGRATE_H__
#define __INTEGRATE_H__

#define PTYPE_F 1000

struct Fn_parameter{
    /* High-level struct that will be passed to every function */
	int type;        // will contain a unique identifier for the function
	void *data;      // will become another struct with the actual parameters of the function
};

/*---------------------------------------------------------*/
/* Write here the structs with the parameters
   of the specific functions you will need */

struct Param_f {
    double a;
};

/*---------------------------------------------------------*/

struct Fn_parameter param_f_alloc (double a);

void param_free(struct Fn_parameter *p);

double integrate (double (*f) (double, struct Fn_parameter), double low, double high, int n, struct Fn_parameter *p);

double f(double x, struct Fn_parameter param);

#endif /* __INTEGRATE_H__ */