#include <physics/lennard_jones.h>

#include <assert.h>
#include <math.h>


double lj_potential(double r, void *p) {
	assert(r > 0.0);
	return 4 * (pow(r, -12) - pow(r, -6));
}

double lj_force_common_part(double r, void *p) {
    assert(r > 0.0);
	return 24 * (2 * pow(r, -14) - pow(r, -8));
}