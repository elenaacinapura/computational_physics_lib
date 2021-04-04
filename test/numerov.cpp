#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include <numerov.h>
}

namespace {
    TEST (Numerov, T_coeff) {
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
    
	return RUN_ALL_TESTS();
}