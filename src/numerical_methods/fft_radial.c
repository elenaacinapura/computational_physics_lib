#include <numerical_methods/fft_radial.h>
#include <gsl/gsl_fft_complex.h>
#include <linear_algebra/blas_wrappers.h>
#include <math.h>

void fft_radial_forward (double f[], int N, double R) {
    double dr = R/N;

    double f_0 = 0.0;   /* Value of the transform in k=0 */
    /* Multiply by r */
    for (int n = 0; n < N; n++) {
        double r = n * dr;
        f_0 += 2.0 * r*r * f[2*n];
        f[2*n] *= r;
        f[2*n + 1] *= r;
    }
    /* Copy f to temp vector */
    double tmp [2*N];
    vec_copy(2*N, f, tmp);
    /* Transform */
    gsl_fft_complex_radix2_forward(tmp, 1, N);
    /* Take imaginary value and divide by K = pi*k/R */
    for (int k = 1; k < N; k++) {
        f[2*k] =  -R/(M_PI * k) * tmp[2*k + 1];
    }  
    /* Assign the value for k=0 */ 
    f[0] = f_0;
}    
