#include <stdlib.h>
#include "chfac.h"

void chlskyfac(double *a,int NMAX)
{
  double sqrt(double );
  double fabs(double );
  int i;
  int j;
  int k;
{
/*@; BEGIN(nest1=Nest) @*/
    for (k = 0; k <= -1 + NMAX; k += 1) 
/*@; BEGIN(body1=Stmt) @*/
{
      arr_ref_a(a,k,k) = sqrt((fabs((arr_ref_a(a,k,k)))));
      if (k <= NMAX + -2) {
/*@; BEGIN(nest4=Nest) @*/
        for (i = 1 + k; i <= -1 + NMAX; i += 1) {
          arr_ref_a(a,i,k) = arr_ref_a(a,i,k) * 1.0 / arr_ref_a(a,k,k);
        }
/*@; BEGIN(nest3=Nest) @*/
        for (j = 1 + k; j <= -1 + NMAX; j += 1) {
/*@; BEGIN(nest2=Nest) @*/
          for (i = j; i <= -1 + NMAX; i += 1) {
            arr_ref_a(a,i,j) = arr_ref_a(a,i,j) - arr_ref_a(a,i,k) * arr_ref_a(a,j,k);
          }
        }
      }
       else {
      }
    }
  }
}
