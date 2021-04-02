#ifndef __PRINT_ROUTINES_H__
#define __PRINT_ROUTINES_H__

#include <stdio.h>

void fprint_double (FILE *file, double d);

void fprint_mat (FILE *file, double *m, int n_rows, int n_cols);

#endif