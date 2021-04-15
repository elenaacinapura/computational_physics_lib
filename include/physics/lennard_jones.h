#ifndef __LENNARD_JONES_H__
#define __LENNARD_jONES_H__

/**
 * Struct with the parameters for the Lennard-Jones potential. It's empty.
 */
struct Struct_Lj {
} Struct_Lj;

/**
 * An instance of a Struct_Lj. It must be used every time the Lennard-Jones functions are used.
 */
struct Struct_Lj struct_lj;



/**
 * @brief Calculate the Lennard-Jones potential
 * 
 * @param r Value of polar radius
 * @param p Unused pointer, allows the function to be given as field of other functions
 * 
 * @return Value of the V(r)
 */
double lj_potential(double r, void *p);

/**
 * @brief Calculate the Lennard-Jones partial force. 
 * 
 * To obtain the full force along the i-th component, multiply the result of this function by the i-th coordinate.
 * 
 * @param r Value of polar radius
 * @param p Unused pointer, allows the function to be given as field of other functions
 * 
 * @return Value of the common partial force
 */
double lj_force_common_part(double r, void *p);

#endif