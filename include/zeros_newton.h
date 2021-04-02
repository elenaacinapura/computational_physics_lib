#ifndef __ZEROS_H__
#define __ZEROS_H__

#ifndef EPS
#define EPS 1e-5
#endif

double zero_newton (double f (double, void *p), double x_0, void *param);

#endif