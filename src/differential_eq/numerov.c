#include <differential_eq/numerov.h>

double complex numerov_1D (double x, complex double psi_curr, complex double psi_prec, double dx, double F (double, void *), void *param) {
    return (psi_curr * (2.0 + 5.0/6 * dx*dx * F(x, param)) - psi_prec * (1 - dx*dx / 12.0 * F(x - dx, param)))/(1 - dx*dx/12.0 * F(x + dx, param));
}