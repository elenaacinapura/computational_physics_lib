#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include <differential_eq/verlet.h>
}

namespace {
    TEST (Verlet, Verlet_2D) {
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
    
	return RUN_ALL_TESTS();
}