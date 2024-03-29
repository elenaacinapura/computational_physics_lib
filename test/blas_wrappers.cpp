#include <gtest/gtest.h>

extern "C" {
#include <cblas-openblas.h>
#include <linear_algebra/array_routines.h>
#include <linear_algebra/blas_wrappers.h>
}

namespace {
TEST(BlasWrappers, VecCopy) {
	int n = 3;
	double v[3] = {2, 3, 4};
	double res[n];
	vec_copy(n, v, res);
	double expected[3] = {2, 3, 4};
	for (int i = 0; i < n; ++i) {
		EXPECT_EQ(res[i], expected[i]) << "Vectors res and expected differ at index " << i;
	}
}

TEST(BlasWrappers, MatVecMul) {
	int nrows = 2;
	int ncols = 3;
	double M[nrows][ncols] = {{2, 3, 4}, {5, 6, 7}};
	double v[3] = {1, 0, 0};
	double res[nrows];
	mat_vec_mul(nrows, ncols, (double *)M, v, res);
	double expected[3] = {2, 5};
	for (int i = 0; i < nrows; ++i) {
		EXPECT_EQ(res[i], expected[i]) << "Vectors res and expected differ at index " << i;
	}
}

TEST(BlasWrappers, MatMatMul) {
	int n = 3;
	double M1[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
	double M2[3][3] = {{2, 3, 6}, {3, 8, 4}, {8, 3, 1}};
	double res[n][n];
	double expected[3][3];
	mat_copy(3, 3, (double *)M2, (double *)expected);
	mat_mat_mul(n, n, n, (double *)M1, (double *)M2, (double *)res);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; j++) {
			EXPECT_EQ(res[i][j], expected[i][j])
			    << "Vectors res and expected differ at index " << i << " " << j;
		}
	}
}
} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}