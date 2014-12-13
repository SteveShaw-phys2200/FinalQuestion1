/*
 * Monte Carlo pi calculation
 */
#include <math.h>
#include <gsl/gsl_rng.h>

double mc_se(long m, gsl_rng *r, int n)
{
   double x, y, z, p, q;       /* x,y coordinate, both between 0 and 1  */
   long count = 0L, i;

   for (i = 0; i < m; i++) {
      /* generate random coordinates */
      x = gsl_rng_uniform(r);
      y = gsl_rng_uniform(r);
      z = gsl_rng_uniform(r);
      p = gsl_rng_uniform(r);
      q = gsl_rng_uniform(r);
      /* count when the point lands in the circle */
      if ((pow(fabs(x),n) + pow(fabs(y),n) + pow(fabs(z),n) + pow(fabs(p),n) + pow(fabs(q),n)) <= 1.0) {
         count += 1;
      }
   }

   return((double)count)/((double)m);

} 
