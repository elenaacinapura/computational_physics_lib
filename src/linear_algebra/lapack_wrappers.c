#include <linear_algebra/array_routines.h>
#include <linear_algebra/lapack_wrappers.h>
#include <stdlib.h>

void dsyev_(char *jobz, char *uplo, int *n, double *m, int *lda, double *w, double *work, int *lwork, int *info);

int diag_symm(const int dim, const double *M, double *res_eigvec, double *res_eigval) {
	mat_copy(dim, dim, M, res_eigvec);

	char JOBZ = 'V'; /* eigenvalues and eigenvectors */
	char UPLO = 'L'; /* lower triangular FORTRAN = upper triangular C */
	int LDA = dim;
	double *WORK;
	int LWORK;
	int INFO;
	double tmp = 0.0;

	/* get the optimal work array size */
	LWORK = -1;
	dsyev_(&JOBZ,&UPLO,&LDA, (double *)res_eigvec, &LDA, res_eigval, &tmp, &LWORK, &INFO);

	LWORK = (int)(tmp);
	WORK = (double *)malloc(LWORK * sizeof(double));

	/* call to the LAPACK subroutine */
	dsyev_(&JOBZ,&UPLO,&LDA, (double *)res_eigvec, &LDA, res_eigval, WORK, &LWORK, &INFO);

	free(WORK);

	return (INFO);
}