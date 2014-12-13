/* 
 * Monte Carlo calculation Pi
 */
#include <stdio.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <gsl/gsl_statistics.h>
     
/* mc_pi.c */
double mc_se (long m, gsl_rng *r, int n);

#define POINTS 10524288     /* 2^19, initial number of random points to generate */
#define NEXP 64           /* number of experiments for each value of points */


int main(void) {
    double se[NEXP];      /* calculated values of se */
    gsl_rng *r;
    int n;
    unsigned long seed = 1UL;
    
     
    /* allocate random number generator */
    r = gsl_rng_alloc(gsl_rng_taus2);

    /* seed the random number generator */
    gsl_rng_set(r, seed);

       	for (n = 1; n < 10; n++) {
            /* calculate pi using Monte Carlo algorithm */
            se[n] = 2*2*2*2*2 * mc_se(POINTS, r, n);
			printf("%d  %15f\n",n , se[n]);
        }
 

    gsl_rng_free(r);

    return(0);
}
