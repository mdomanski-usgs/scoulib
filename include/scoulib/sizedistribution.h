#ifndef SIZEDISTRIBUTION_INCLUDED
#define SIZEDISTRIBUTION_INCLUDED

#define T SizeDistribution_T

typedef struct T *T;

extern T sd_from_volume_cdf(int n, double *diameters, double *cdf);
extern int sd_ndiameters(T);
extern void sd_cdf_diameters(T sd, double *diameters);
extern void sd_volume_cdf(T sd, double *diameters);
extern void sd_free(T);

#undef T
#endif
