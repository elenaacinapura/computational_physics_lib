#include <linear_algebra/array_routines.h>

#include <assert.h>
#include <cblas.h>
#include <stdio.h>

void fprint_mat(FILE *file, const double *A, int nrows, int ncols) {
	assert(nrows >= 0 && ncols >= 0);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			fprintf(file, "%lf\t", *(A + i * ncols + j));
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}

void mat_copy(int nrows, int ncols, const double *src, double *dest) {
	assert(nrows >= 0 && ncols >= 0);
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			*(dest + i * ncols + j) = *(src + i * ncols + j);
		}
	}
}