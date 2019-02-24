#include "sizedistribution.h"
#include "cii/assert.h"
#include "cii/mem.h"

#define T SizeDistribution_T

struct T {
    int n;
    double *cdf_diameters;
    double *pdf_diameters;

    double *volume_cdf;
    double *volume_pdf;

    double *number_cdf;
    double *number_pdf;
};

T _sd_new(int);

T sd_from_volume_cdf(int n, double *diameters, double *cdf) {

    assert((int)(n > 2));
    assert(diameters);
    assert(cdf);

    T sd = _sd_new(n);

    for (int i = 0; i < sd->n; i++) {
        *(sd->cdf_diameters + i) = *(diameters + i);
        *(sd->volume_cdf + i) = *(cdf + i);
    }

    return sd;
}

int sd_ndiameters(T sd) { return sd->n; }

void sd_cdf_diameters(T sd, double *diameters) {

    for (int i = 0; i < sd->n; i++)
        *(diameters + i) = *(sd->cdf_diameters + i);
}

void sd_volume_cdf(T sd, double *cdf) {

    for (int i = 0; i < sd->n; i++)
        *(cdf + i) = *(sd->volume_cdf + i);
}

void sd_free(T sd) {
    Mem_free(sd->cdf_diameters, __FILE__, __LINE__);
    Mem_free(sd->pdf_diameters, __FILE__, __LINE__);
    Mem_free(sd->volume_cdf, __FILE__, __LINE__);
    Mem_free(sd->volume_pdf, __FILE__, __LINE__);
    FREE(sd);
}

T _sd_new(int n) {

    T sd;
    NEW(sd);

    sd->n = n;
    sd->cdf_diameters = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);
    sd->pdf_diameters = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);
    sd->volume_cdf = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);
    sd->volume_pdf = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);

    return sd;
}
