#include <cmath>
#include <gtest/gtest.h>
#include <random>

extern "C" {
#include <numerical_methods/minimum.h>
#include <numerical_methods/derivative.h>
#include <numerical_methods/zero_bisection.h>
}

struct Param {
	double a;
};

double f_min(double x, void *p) {
	return (x-1.0) * (x-1.0);
}

double f_zero_bisec(double x, void *p) {
	return (x-2.0);
}

double f_der(double x, void *p) {
    return 2*x;
}

namespace {
TEST(Numerical, Minimum) {
	struct Param p = {1.0};
	ASSERT_NEAR(minimum(f_min, -1.0, 1.0, &p), 1.0, 1e-4);
}
TEST(Numerical, ZeroBisection) {
	struct Param p = {1.0};
    double res = zero_bisection(f_zero_bisec, -1.0, 3.0, &p);
	ASSERT_NEAR(res , 2.0, 1e-4);
}
TEST(Numerical, Derivative) {
    struct Param p = {1.0};
    double res = derivative(f_der, 5.0, &p);
    ASSERT_NEAR(res, 2.0, 1e-4);
}
} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}