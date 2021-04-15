#ifndef __BLAS_WRAPPERS_H__
#define __BLAS_WRAPPERS_H__

#include <stdio.h>

void fprint_mat(FILE *file, double *A, int nrows, int ncols);

void mat_copy(int m, int n, double* src, double* dest);

void mat_vec_mul (int m, int n, double *M, double *v, double *res);

void mat_mat_mul(int m, int n, int k, double *M1, double *M2, double *res);


#endif