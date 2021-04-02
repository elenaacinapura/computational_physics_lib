#include <lennard_jones.h>

#include <assert.h>
#include <math.h>

/**
 * @brief Calculate polar radius 
 * 
 * @param x x coordinate
 * @param y y coordinate
 * @param z z coordinate
 * 
 * @return sqrt(x * x + y * y + z * z)
 */
double r_polar(double x, double y, double z) {
	return sqrt(x * x + y * y + z * z);
}

/**
 * @brief Calculate the Lennard-Jones potential
 * 
 * @param r value of polar radius
 * @param p unused pointer, allows the function to be given as field of other functions
 * 
 * @return Value of the V(r)
 */
double lj_potential(double r, void *p) {
	assert(r > 0.0);
	return 4 * (pow(r, -12) - pow(r, -6));
}

/**
 * @brief Calculate the Lennard-Jones partial force. To obtain the full force, multiply the i-th component by the i-th coordinate.
 * 
 * @param r value of polar radius
 * @param p unused pointer, allows the function to be given as field of other functions
 * 
 * @return Value of the common partial force
 */
double lj_force_common_part(double r, void *p) {
    assert(r > 0.0);
	return 24 * (2 * pow(r, -14) - pow(r, -8));
}