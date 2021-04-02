#ifndef __INTEGRATE_PARAM_NOTYPESAFE_H__
#define __INTEGRATE_PARAM_NOTYPESAFE_H__

#ifndef EPS
#define EPS 1e-5
#endif

double integrate (double f (double, void *p), double low, double high, int density, void *param);

#endif