#ifndef __LAPACK_WAPPERS_H__
#define __LAPACK_WAPPERS_H__

#include <complex.h>

int diagonalize_symm(const int dim, double *M, double *res_eigvec, double *res_eigval);

int diagonalize_tridiag_double(const int dim, double *diag, double *subdiag, double *res_eigvec, double *res_eigval);

int diagonalize_herm(const int dim, _Complex double(*M), _Complex double(*res_eigvec), double *res_eigval);

#endif