#ifndef __PRINT_ROUTINES_H__
#define __PRINT_ROUTINES_H__

#include <stdio.h>

/**
 * @brief Print a double to a specified file, followed by a tab.
 * 
 * @param file The file handler of type FILE for the ouput file. If you want to print to terminal, use stdout
 * @param d The double to be printed to file
 * 
 * @return
 */
void fprint_double (FILE *file, double d);

/**
 * @brief Print a matrix to a specified file, using tab as the separator.
 * 
 * @param file The file handler of type FILE for the ouput file. If you want to print to terminal, use stdout
 * @param m Matrix to be printed on file
 * @param n_rows Number of rows (first dimension)
 * @param n_cols Number of columns (second dimension)
 * 
 * @return
 */
void fprint_mat (FILE *file, double *m, int n_rows, int n_cols);

#endif