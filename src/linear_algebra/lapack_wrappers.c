#include <linear_algebra/array_routines.h>
#include <linear_algebra/lapack_wrappers.h>

#include <assert.h>
#include <complex.h>
#include <stdlib.h>

void dsyev_(char *jobz, char *uplo, int *n, double *m, int *lda, double *w, double *work, int *lwork, int *info);

void zheev_(char *jobz, char *uplo, int *n, _Complex double(*m), int *lda, double *w, _Complex double(*work),
	    int *lwork, double *rwork, int *info);

void dstedc_(char *compz, int *n, double *D, double *E, double *Z, int *ldz, double *work, int *lwork, int *iwork,
	     int *liwork, int *info);

/*-----------------------------------------------------------------------------------------------------------------*/
int diagonalize_symm(const int dim, double *M, double *res_eigvec, double *res_eigval) {
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
	dsyev_(&JOBZ, &UPLO, &LDA, res_eigvec, &LDA, res_eigval, &tmp, &LWORK, &INFO);

	LWORK = (int)(tmp);
	WORK = (double *)malloc(LWORK * sizeof(double));

	/* call to the LAPACK subroutine */
	dsyev_(&JOBZ, &UPLO, &LDA, res_eigvec, &LDA, res_eigval, WORK, &LWORK, &INFO);

	free(WORK);
	return INFO;
}

int diagonalize_tridiag_double(const int dim, double *diag, double *subdiag, double *res_eigvec, double *res_eigval) {
	assert(dim >= 0);
	mat_copy(1, dim, diag, res_eigval);
	double subdiag_copy[dim - 1];
	mat_copy(1, dim - 1, subdiag, subdiag_copy);

	char COMPZ = 'I';
	int N = dim;
	int LDZ = dim;

	double *WORK;
	double tmpwork; /* optimal LWORK */
	int LWORK = -1; /* query */
	int *IWORK;
	int tmpiwork;	 /* optimal LIWORK */
	int LIWORK = -1; /* query */
	int INFO;

	dstedc_(&COMPZ, &N, res_eigval, subdiag_copy, res_eigvec, &LDZ, &tmpwork, &LWORK, &tmpiwork, &LIWORK, &INFO);

	LWORK = (int)tmpwork;
	WORK = (double *)malloc(LWORK * sizeof(double));
	LIWORK = tmpiwork;
	IWORK = (int *)malloc(LIWORK * sizeof(int));

	dstedc_(&COMPZ, &N, res_eigval, subdiag_copy, res_eigvec, &LDZ, WORK, &LWORK, IWORK, &LIWORK, &INFO);

	free(WORK);
	free(IWORK);

	return INFO;
}


int diagonalize_herm(const int dim, _Complex double(*M), _Complex double(*res_eigvec), double *res_eigval) {
	mat_copy_complex(dim, dim, M, res_eigvec);

	char JOBZ = 'V'; /* eigenvalues and eigenvectors */
	char UPLO = 'L'; /* lower triangular FORTRAN = upper triangular C */
	int LDA = dim;
	double *RWORK;
	complex double *WORK;
	int LWORK;
	int INFO;
	double complex tmp = 0.0;
	double tmp1 = 0.0;

	/* get the optimal work array size */
	LWORK = -1;
	zheev_(&JOBZ, &UPLO, &LDA, res_eigvec, &LDA, res_eigval, &tmp, &LWORK, &tmp1, &INFO);

	LWORK = (int)(tmp);
	WORK = (complex double *)malloc(LWORK * sizeof(complex double));
	RWORK = (double *)malloc(LWORK * sizeof(double));

	/* call to the LAPACK subroutine */
	zheev_(&JOBZ, &UPLO, &LDA, res_eigvec, &LDA, res_eigval, WORK, &LWORK, RWORK, &INFO);

	free(WORK);
	free(RWORK);
	return INFO;
}