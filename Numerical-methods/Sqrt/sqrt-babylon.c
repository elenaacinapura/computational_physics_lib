#include <math.h>

const double eps = 1e-5;

double sqrt_babylon (double x) {
    double x_next = x/2.0;     // starting value for calculation
    double x_0;                // will be the current value in iteration
    do {
        x_0 = x_next;
        x_next = 0.5 * (x_0 + x/x_0);
        
    } while (fabs(x_next - x_0) > eps);

    return x_next;
}