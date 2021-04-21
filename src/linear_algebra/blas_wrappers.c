#include <linear_algebra/blas_wrappers.h>

#include <assert.h>
#include <cblas-openblas.h>
#include <math.h>

void vec_copy (int N, double src[], double dest[]){
	cblas_dcopy(N, (double *)src, 1, (double *)dest, 1);
}

void mat_vec_mul(int nrows, int ncols, double *M, double *v, double *res) {
	assert(nrows > 0 && ncols > 0);
	cblas_dgemv(CblasRowMajor, CblasNoTrans, nrows, ncols, 1, M, ncols, v, 1, 0, res, 1);
}

void mat_mat_mul(int nrows1, int ncols2, int ncols1_nrows2, double *M1, double *M2, double *res) {
	assert(nrows1 > 0 && ncols2 > 0 && ncols1_nrows2 > 0);
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, nrows1, ncols2, ncols1_nrows2, 1, M1, nrows1, M2, ncols1_nrows2, 0, res, nrows1);
}

