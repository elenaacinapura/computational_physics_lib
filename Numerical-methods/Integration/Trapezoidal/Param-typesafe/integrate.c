#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "integrate.h"


double integrate (double (*f) (double, struct Fn_parameter), double low, double high, int density, struct Fn_parameter *param) {
    /* Integrate function f between limits "low" and "high" with point density n
    *param is the pointer to high-level struct "Fn_parameters" for the function f, properly allocated. */

    int n = (int)ceil((high - low) * density);  //number of points
    double dx = (high - low) / (n + 1);         // increment in integration variable
    double I = 0;

	for (int i = 1; i < n; i++) { 
		double x1 = low + dx*(i);
		double x2 = x1 + dx;             
		I += f((x1 + x2)/2.0, *param);
	}

	return I *= dx;
}

void param_free(struct Fn_parameter *p) {
        free(p->data);
}    


