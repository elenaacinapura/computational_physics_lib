#include <linear_algebra/blas_wrappers.h>

#include <assert.h>
#include <cblas.h>

void vec_copy (int N, double src[], double dest[]){
	cblas_dcopy(N, (double *)src, 1, (double *)dest, 1);
}

void mat_vec_mul(int m, int n, double *M, double *v, double *res) {
	assert(m > 0 && n > 0);
	cblas_dgemv(CblasRowMajor, CblasNoTrans, m, n, 1, M, n, v, 1, 0, res, 1);
}

void mat_mat_mul(int m, int n, int k, double *M1, double *M2, double *res) {
	assert(m > 0 && n > 0 && k > 0);
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, M1, m, M2, k, 0, res, m);
}
