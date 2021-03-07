#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double integrate (double (*f)(double), double low, double high, int n) {
    double dx = (high - low) / (n - 1);     // increment in the independent variable
    double x_k[n];                          // points where f will be evaluated
	for (int i = 0; i < n; i++) {           
		x_k[i] = low + dx * i;
		
	}
    
    // trapezoidal rule
	double I = (*f)(x_k[0]) / 2.0 + (*f)(x_k[9]) / 2.0;    
	for (int i = 1; i < n - 1; i++) {                   
		I += (*f)(x_k[i]);
	}

	return I *= dx;
}