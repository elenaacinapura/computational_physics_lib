#include "integrate.h"
#include <math.h>
#include <stdio.h>

double integrate (double f (double, void *), double low, double high, int density, void *param) {
    int n = (int)ceil((high - low) * density);  //number of points
    double dx = (high - low) / (n + 1);         // increment in integration variable
    double I = 0;

	for (int i = 1; i < n; i++) { 
		double x1 = low + dx*(i);
		double x2 = x1 + dx;             
		I += f((x1 + x2)/2.0, param);
	}

	return I *= dx;
}