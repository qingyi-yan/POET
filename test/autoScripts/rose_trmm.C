
int max2(int a0,int a1)
{
  return a0 > a1?a0 : a1;
}
#include "trmm.h"

void strmm(int m,int n,float alpha,int lda,int ldb,float beta,float *a,float *b)
{
  int i;
  int j;
  int l;
/*@; BEGIN(nest1=Nest) @*/
  for (j = 0; j <= max2(-1 + n,-1 + m); j += 1) {
/*@; BEGIN(nest3=Nest) @*/
    for (l = 0; l <= -1 + m; l += 1) 
/*@; BEGIN(body1=Stmt) @*/
{
      if (j <= -1 + n) {
        arr_ref_b(b,l,j) = beta * arr_ref_b(b,l,j);
      }
       else {
      }
      if (j <= -1 + m) {
/*@; BEGIN(nest2=Nest) @*/
        for (i = 0; i <= -1 + l; i += 1) {
          arr_ref_b(b,i,j) = alpha * arr_ref_b(b,l,j) * arr_ref_a(a,i,l);
        }
        arr_ref_b(b,l,j) = alpha * arr_ref_b(b,l,j);
      }
       else {
      }
    }
  }
}
