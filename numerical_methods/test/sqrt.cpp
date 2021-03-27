#include <gtest/gtest.h>
#include <cmath>
#include <random>

extern "C" {
#include <sqrt_babylon.h>
}

namespace {
TEST(Sqrt, Sanity1) {
    ASSERT_NEAR(sqrt_babylon(4.0), 2.0, EPS);
}
TEST(Sqrt, Sanity2) {
    ASSERT_NEAR(sqrt_babylon(0.0), 0.0, EPS);
}
TEST(Sqrt, AgainstMath) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 1e20);
    
    for (int i = 0; i<100; i++) {
        double v = dis(gen);
        ASSERT_NEAR(sqrt_babylon(v), sqrt(v), EPS);
    }
}
TEST(Sqrt, LessThanZero) {
    ASSERT_DEATH(sqrt_babylon(-1.0), "");
}
}; // namespace

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}