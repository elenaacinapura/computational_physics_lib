#include <linear_algebra/array_routines.h>
#include <linear_algebra/lapack_wrappers.h>

#include <complex.h>
#include <stdlib.h>

void zheev_(char *jobz, char *uplo, int *n, _Complex double (*m), int *lda, double *w, _Complex double (*work), int *lwork, double *rwork, int *info);

int diag_symm_complex(const int dim, _Complex double (*M), _Complex double (*res_eigvec), double *res_eigval) {
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
	zheev_(&JOBZ,&UPLO,&LDA, res_eigvec, &LDA, res_eigval, &tmp, &LWORK, &tmp1, &INFO);

	LWORK = (int)(tmp);
	WORK = (complex double *)malloc(LWORK * sizeof(complex double));
    RWORK = (double *)malloc(LWORK * sizeof(double));

	/* call to the LAPACK subroutine */
	zheev_(&JOBZ,&UPLO,&LDA, res_eigvec, &LDA, res_eigval, WORK, &LWORK, RWORK, &INFO);

	free(WORK);
    free(RWORK);
	return (INFO);
}