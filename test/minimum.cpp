#include <cmath>
#include <gtest/gtest.h>
#include <random>

extern "C" {
#include <minimum.h>
}

struct Param {
	double a;
};

double f(double x, void *p) {
	return (x-1.0) * (x-1.0);
}

namespace {
TEST(Minimum, RightResult) {
	struct Param p = {1.0};
	ASSERT_NEAR(minimum(f, -1.0, 1.0, &p), 0.0, 1e-4);
}
} // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}