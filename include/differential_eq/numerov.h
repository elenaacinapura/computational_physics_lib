#ifndef __NUMEROV_H__
#define __NUMEROV_H__

#include <complex.h>

/**
 * @brief Step of the numerov algorithm to solve schrodinger equation.
 * 
 * Performs the discrete step of the numerov algorithm to solve psi''(x) = F(x, param)*psi(x).
 * The initial conditions of psi_prec and psi_curr should be some known psi(x_0) and psi(x_0 + dx).
 * 
 * @param x Pointer to the current value of the independent variable
 * @param psi_curr Pointer to the current value of psi(x)
 * @param psi_prec Pointer to the value of psi(x - dx)
 * @param dx Increment in the x variable
 * @param F Function F in the equation psi''(x) = F(x)*psi(x)
 * @param param Pointer to the struct with the parameters of F
 * 
 * @return
 */
double complex numerov_1D (double x, complex double psi_curr, complex double psi_prec, double dx, double F (double, void *), void *param);

/**
 * @brief Execute the numerov algorithm and fill e vector with the value of the wave function.
 * 
 * @param x Array to store the values of the independent variable. The first two elements should be already initialized.
 * @param psi Array to store the values of the wave function. The first two elements should be already initialized.
 * @param dim Dimension of the array x and psi.
 * @param F Function F in the equation psi''(x) = F(x)*psi(x).
 * @param param Pointer to the struct with the parameters of F.
 * 
 * @return
 */
void execute_numerov (double x[], complex double psi[], int dim, double dx, double F (double, void *), void *p);

#endif