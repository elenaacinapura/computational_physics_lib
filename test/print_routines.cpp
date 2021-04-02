#include <gtest/gtest.h>
#include <stdio.h>

extern "C" {
#include <print_routines.h>
}

namespace {
    TEST (Print, PrintDouble) {
        FILE *output;
        output = fopen("print_routines_output.txt", "w");
        fprint_double(output, 2.03);
    }
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
    
	return RUN_ALL_TESTS();
}