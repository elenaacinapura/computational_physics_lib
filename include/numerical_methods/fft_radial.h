#ifndef __FFT_RADIAL_H__
#define __FFT_RADIAL_H__

/**
 * @brief Perform the radial fourier transform via FFT
 * 
 * Overwrite the function vector with the values of the radial transform.
 * 
 * @param f N-dimensional array containing the values of the radial function to be transformed
 * @param N number of points considered for the transform.
 * @param R [0, R) is the chosen interval of periodicity for the function f.
 * 
 * @return
 */
void fft_radial_forward (double f[], int N, double R);

/**
 * @brief Perform the inverse radial fourier transform via FFT
 * 
 * Overwrite the function vector with the values of the inverse radial transform.
 * 
 * @param f N-dimensional array containing the values of the radial function to be antitransformed
 * @param N number of points considered for the antitransform.
 * @param R [0, R) is the chosen interval of periodicity for the function f.
 * 
 * @return
 */
void fft_radial_inverse (double f[], int N, double R);


#endif