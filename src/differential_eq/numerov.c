#include <differential_eq/numerov.h>

double complex numerov_1D (double x, complex double psi_curr, complex double psi_prec, double dx, double F (double, void *), void *param) {
    return (psi_curr * (2.0 + 5.0/6 * dx*dx * F(x, param)) - psi_prec * (1 - dx*dx / 12.0 * F(x - dx, param)))/(1 - dx*dx/12.0 * F(x + dx, param));
}

void execute_numerov_complex (double x[], complex double psi[], int dim, double dx, double F (double, void *), void *p) {
    int i = 2; 
    while (i < dim) {
        complex double psi_curr = numerov_1D(x[i-1], psi[i-1], psi[i-2], dx, F, p);
        psi[i] = psi_curr;
        x[i] = x[i-1] + dx;
        i++;
    }
}