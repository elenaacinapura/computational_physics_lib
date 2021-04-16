#ifndef __ARRAY_ROUTINES_H__
#define __ARRAY_ROUTINES_H__

#include <stdio.h>

/**
 * @brief Print multidimentional array to specified output.
 * 
 * Print an array with size nrows*ncols to the specified output.
 * 
 * @param file FILE pointer to the intended output file. To print to standard output, type stdout.
 * @param A Pointer to the multidimentional array
 * @param nrows Number of rows of the multidimentional array. It must be >= 0.
 * @param ncols Number of columns of the multidimentional array. It must be >= 0.
 * 
 * @return
 */
void fprint_mat(FILE *file, const double *A, int nrows, int ncols);

/**
 * @brief Copy a multimentional array.
 * 
 * Copy a multimentional array from src to dest.
 * 
 * @param nrows Number of rows of the multidimentional array. It must be >= 0.
 * @param ncols Number of columns of the multidimentional array. It must be >= 0.
 * @param src Pointer to the source array that must be copied.
 * @param dest Pointer to the destination array where src must be copied.
 * 
 * @return
 */
void mat_copy(int nrows, int ncols, const double* src, double* dest);

#endif