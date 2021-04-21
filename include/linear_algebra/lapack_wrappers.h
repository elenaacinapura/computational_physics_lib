#ifndef __LAPACK_WAPPERS_H__
#define __LAPACK_WAPPERS_H__

#include <complex.h>

int diag_symm_complex(const int dim,  _Complex double (*M), _Complex double (*res_eigvec), double *res_eigval);
#endif