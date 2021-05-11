#include <gsl/gsl_fft_complex.h>
#include <linear_algebra/blas_wrappers.h>
#include <math.h>
#include <numerical_methods/fft_radial.h>

void fft_radial_forward(double f[], int N, double R) {
	int M = 2 * N;
	double C_bar[2 * M];
	double f_0 = 0.0; /* Value of the transform in k=0 */

	/* Multiply by r and fill C_bar*/
	for (int n = 0; n < M; n++) {
		if (n < N) {
			double r = n * R / N;
			f_0 += 2.0 * r * r * f[n];
			C_bar[2 * n] = f[n] * r;
			C_bar[2 * n + 1] = 0.0;
		}
		if (n == N) {
			C_bar[2 * n] = 0.0;
			C_bar[2 * n + 1] = 0.0;
		}
		if (n > N) {
			C_bar[2 * n] = -C_bar[2 * (2 * N - n)];
			C_bar[2 * n + 1] = 0.0;
		}
	}

	/* Transform */
	gsl_fft_complex_radix2_forward(C_bar, 1, M);

	/* Take imaginary value and divide by K = pi*k/R */
	for (int k = 1; k < N; k++) {
		f[k] = -R / (M_PI * k) * C_bar[2 * k + 1];
	}

	/* Assign the value for k=0 */
	f[0] = f_0;
}

void fft_radial_inverse(double f[], int N, double R) {
	int M = 2 * N;
	double C_bar[2 * M];
	double f_0 = 0.0; /* Value of the antitransform in n=0 */

	/* Multiply by k and fill C_bar*/
	for (int i = 0; i < M; i++) {
		if (i < N) {
			double k = M_PI * (double)(i) / R;
			f_0 += 1.0 / N * k * k * f[i];
			C_bar[2 * i] = k * f[i];
			C_bar[2 * i + 1] = 0.0;
		}
		if (i == 0) {
			C_bar[2 * i] = 0.0;
			C_bar[2 * i + 1] = 0.0;
		}
		if (i > N) {
			C_bar[2 * i] = -C_bar[2 * (2 * N - i)];
			C_bar[2 * i + 1] = 0.0;
		}
	}

	/* Transform  (I don't need to use the antitransform here) */
	gsl_fft_complex_radix2_forward(C_bar, 1, M);

	/* Take imaginary value and divide by r = n*R/N */
	for (int n = 1; n < N; n++) {
		f[n] = -1.0 / M * C_bar[2 * n + 1];
		f[n] *= (double)(N) / (n * R);
	}
	/* Assign the value for n=0 */
	f[0] = f_0;
}
