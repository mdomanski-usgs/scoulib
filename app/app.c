#include "mem.h"
#include <scoulib/sizedistribution.h>
#include <stdio.h>

SizeDistribution_T init_sd();

int main() {
    SizeDistribution_T sd = init_sd();

    int n = sd_ndiameters(sd);
    double *cdf_diameters = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);
    double *cdf = Mem_calloc(n, sizeof(double), __FILE__, __LINE__);

    sd_cdf_diameters(sd, cdf_diameters);
    sd_volume_cdf(sd, cdf);

    for (int i = 0; i < n; i++) {
        printf("%f\t%f\n", cdf_diameters[i], cdf[i]);
    }

    sd_free(sd);
    FREE(cdf);
    FREE(cdf_diameters);
}

SizeDistribution_T init_sd() {
    int n = 3;
    double diameters[] = {0.1, 0.2, 0.3};
    double cdf[] = {0.25, 0.5, 1};
    SizeDistribution_T sd = sd_from_volume_cdf(n, diameters, cdf);
    return sd;
}
