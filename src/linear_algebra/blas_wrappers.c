#include <linear_algebra/blas_wrappers.h>

#include <assert.h>
#include <cblas.h>
#include <stdio.h>

void fprint_mat(FILE *file, double *A, int nrows, int ncols) {
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			fprintf(file, "%lf\t", *(A + i * ncols + j));
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void mat_copy(int m, int n, double *src, double *dest) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			*(dest + i * n + j) = *(src + i * n + j);
		}
	}
}

void mat_vec_mul(int m, int n, double *M, double *v, double *res) {
	assert(m > 0 && n > 0);
	cblas_dgemv(CblasRowMajor, CblasNoTrans, m, n, 1, M, n, v, 1, 0, res, 1);
}

void mat_mat_mul(int m, int n, int k, double *M1, double *M2, double *res) {
	assert(m > 0 && n > 0 && k > 0);
	cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, m, n, k, 1, M1, m, M2, k, 0, res, m);
}
