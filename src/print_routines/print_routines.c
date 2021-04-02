#include <print_routines.h>

#include <stdio.h>

void fprint_double (FILE *file, double d) {
	fprintf(file, "%lf\t", d);
}

void fprint_mat (FILE *file, double *m, int n_rows, int n_cols) {
	for (int i = 0; i < n_rows; i++) {
		for (int j = 0; j < n_cols; j++) {
			fprintf(file, "%lf\t", *(m + i*n_cols + j));
		}
		fprintf(file, "\n");
	}
	fprintf(file, "\n");
}