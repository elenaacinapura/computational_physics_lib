#ifndef __INTEGRATE_PARAM_NOTYPESAFE_H__
#define __INTEGRATE_PARAM_NOTYPESAFE_H__

double integrate (double f (double, void *p), double low, double high, int density, void *param);

#endif