#ifndef __BLAS_WRAPPERS_H__
#define __BLAS_WRAPPERS_H__

#include <stdio.h>

void vec_copy (int N, double src[], double dest[]);

void mat_vec_mul (int m, int n, double *M, double *v, double *res);

void mat_mat_mul(int m, int n, int k, double *M1, double *M2, double *res);


#endif