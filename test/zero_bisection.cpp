#include <cmath>
#include <gtest/gtest.h>

extern "C" {
#include <numerical_methods/zero_bisection.h>
}

double f(double x, void *p) {
	return (x-2.0);
}

struct Param {
};

namespace {
TEST(Zero_bisection, RightResult) {
	struct Param p = {};
    double res = zero_bisection(f, -1.0, 3.0, &p);
	ASSERT_NEAR(res , 2.0, 1e-4);
}
} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}