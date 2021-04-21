#ifndef __BLAS_WRAPPERS_H__
#define __BLAS_WRAPPERS_H__

void vec_copy (int N, double src[], double dest[]);

void mat_vec_mul(int nrows, int ncols, double *M, double *v, double *res);

void mat_mat_mul(int nrows1, int ncols2, int ncols1_nrows2, double *M1, double *M2, double *res);


#endif