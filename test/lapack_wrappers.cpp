#include <gtest/gtest.h>

extern "C" {
#include <cblas-openblas.h>
#include <complex.h>
#include <linear_algebra/array_routines.h>
#include <linear_algebra/lapack_wrappers.h>
}

namespace {


TEST(LapackWrappers, DiagSymm) {
	int dim = 2;
    _Complex double M[2][2] = {{0, -I*1.0}, {I*1.0, 0}};
    _Complex double res_eigvec [2][2];
    double res_eigval [2];
    int info = diag_symm_complex(dim, (_Complex double *) M, (_Complex double *) res_eigvec, (double *) res_eigval);
    ASSERT_EQ(info, 0);
    fprint_mat_complex(stdout, (_Complex double *) res_eigvec, dim, dim);
    fprint_mat(stdout, (double *) res_eigval, 1, dim);
}
} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}