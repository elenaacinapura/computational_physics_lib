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
	double M[2][2] = {{0, 1.0}, {1.0, 0}};
	double res_eigvec[2][2];
	double res_eigval[2];
	int info = diagonalize_symm(dim, (double *)M, (double *)res_eigvec, (double *)res_eigval);
	ASSERT_EQ(info, 0);
	fprint_mat(stdout, (double *)res_eigvec, dim, dim);
	fprint_mat(stdout, (double *)res_eigval, 1, dim);
}

TEST(LapackWrappers, DiagHermit) {
	int dim = 2;
	_Complex double M[2][2] = {{0, -I * 1.0}, {I * 1.0, 0}};
	_Complex double res_eigvec[2][2];
	double res_eigval[2];
	int info = diagonalize_herm(dim, (_Complex double *)M, (_Complex double *)res_eigvec, (double *)res_eigval);
	ASSERT_EQ(info, 0);
// 	fprint_mat_complex(stdout, (_Complex double *)res_eigvec, dim, dim);
// 	fprint_mat(stdout, (double *)res_eigval, 1, dim);
// }

TEST(LapackWrappers, DiagTridiag) {
	int n = 1024;
	double L = 5.0;
	double dx = 2.0 * L / (n - 1);
	double *x = (double *)calloc(n, sizeof(double));
	double *d = (double *)calloc(n, sizeof(double));
	double *e = (double *)calloc(n, sizeof(double));
	double *eigval = (double *)calloc(n, sizeof(double));
	double *eigvec = (double *)calloc(n * n, sizeof(double));

	int i, j;

	/* prepare the vectors */
	for (i = 0; i < n; i++) {
		x[i] = -L + i * dx;
		d[i] = 1.0 / (dx * dx) + 0.5 * (x[i] * x[i]);
		e[i] = -0.5 / (dx * dx);
	}

	int info = diagonalize_tridiag_double(n, d, e, eigvec, eigval);
	ASSERT_EQ(info, 0);

	printf("# autovalori: ");
	for (i = 0; i < 10; i++)
		printf("%g ", eigval[i]);
	printf("\n");

	for (i = 0; i < 5; i++) {
		printf("# autovettore %d:\n", i);
		for (j = 0; j < n; j++)
			printf("%g %g\n", x[j], eigvec[n * i + j] / sqrt(dx));
		printf("&\n");
	}
}

} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}