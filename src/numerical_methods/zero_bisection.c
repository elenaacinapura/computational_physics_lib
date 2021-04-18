#include <numerical_methods/zero_bisection.h>
#include <assert.h>
#include <math.h>

double zero_bisection(double f (double, void *), double low, double high, void *param){
    assert(low < high);
    assert(isfinite(low) && isfinite(high));
    assert(f(low, param) * f(high, param) < 0.0);

    while (fabs(high - low)/(fabs(high + low) > EPS)) {
        double mid = (high + low) / 2.0;
        if (f(mid, param) == 0.0) {
            return mid;
        }
        if (f(low, param) * f(mid, param) < 0.0) {
            high = mid;
        } else {
            low = mid;
        }
    }
    return low;
}