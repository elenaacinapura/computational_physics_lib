#include <numerical_methods/fft_radial.h>
#include <gsl/gsl_fft_complex.h>
#include <linear_algebra/blas_wrappers.h>
#include <math.h>

void fft_radial_forward (double f[], int N, double R) {
    double dr = R/N;
    double tmp [2*N];
    double f_0 = 0.0;   /* Value of the transform in k=0 */

    /* Multiply by r and fill tmp*/
    for (int n = 0; n < N; n++) {
        double r = n * dr;
        f_0 += 2.0 * r*r * f[n];
        tmp[2*n] = f[n] * r;
        tmp[2*n + 1] = 0.0;
    }

    /* Transform */
    gsl_fft_complex_radix2_forward(tmp, 1, N);

    /* Take imaginary value and divide by K = pi*k/R */
    for (int k = 1; k < N; k++) {
        f[k] =  -R/(M_PI * k) * tmp[2*k + 1];
    }  

    /* Assign the value for k=0 */ 
    f[0] = f_0;
}    

void fft_radial_inverse (double f[], int N, double R) {

    double f_0 = 0.0;   /* Value of the antitransform in n=0 */
    double tmp [2*N];
    /* Multiply by k */
    for (int i = 0; i < N; i++) {
        double k = M_PI * i / R;
        f_0 += 1.0/N * k*k * f[i];
        tmp[2*i] = k * f[i];
        tmp[2*i + 1] = 0.0;
    }

    /* Transform  (I don't need to use the antitransform here)*/
    gsl_fft_complex_radix2_forward(tmp, 1, N);

    /* Take imaginary value and divide by r = n*R/N */
    for (int n = 1; n < N; n++) {
        f[n] =  -1.0/N * tmp[2*n + 1];
        f[n] *= N / (n * R);
    }  
    /* Assign the value for n=0 */ 
    f[0] = f_0;
}
