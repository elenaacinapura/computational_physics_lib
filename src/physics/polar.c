#include <physics/polar.h>

#include <assert.h>
#include <math.h>

double r_polar(double x, double y, double z) {
	return sqrt(x * x + y * y + z * z);
}