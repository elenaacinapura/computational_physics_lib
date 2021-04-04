#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include <verlet.h>
}

namespace {
    TEST (Verlet, Verlet_2D) {
        verlet_1D()
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
    
	return RUN_ALL_TESTS();
}