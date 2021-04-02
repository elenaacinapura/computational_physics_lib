#ifndef __LENNARD_JONES_H__
#define __LENNARD_jONES_H__

struct Struct_Lj {

} VoidStruct;

struct Struct_Lj struct_lj;

double r_polar(double x, double y, double z);

double lj_potential(double r, void *p);

double lj_force_common_part(double r, void *p);

#endif