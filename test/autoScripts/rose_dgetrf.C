
int min2(int a,int b)
{
  return a < b?a : b;
}

double dabs(double a)
{
  return a < 0?-a : a;
}
#include "arrayAccess.h"

void dgetrf(int m,int n,double *a,int *p)
{
  double tmp;
  double tmp1;
  int j;
  int i;
  int k;
  for (k = 0; k <= min2(m + -2,n + -2); k += 1) {
    p[k] = k;
  }
/*@; BEGIN(nest1=Nest) @*/
  for (k = 0; k <= min2(m + -2,n + -2); k += 1) 
/*@; BEGIN(body1=Stmt) @*/
{
    tmp = dabs((arr_ref(a,k,k)));
    for (i = 1 + k; i <= -1 + m; i += 1) {
      if (dabs((arr_ref(a,i,k))) > tmp) {
        p[k] = i;
        tmp = dabs((arr_ref(a,i,k)));
      }
    }
    tmp1 = arr_ref(a,k,k);
    arr_ref(a,k,k) = arr_ref(a,p[k],k);
    arr_ref(a,p[k],k) = tmp1;
/*@; BEGIN(nest2=Nest) @*/
    for (j = 1 + k; j <= -1 + n; j += 1) {
      tmp1 = arr_ref(a,k,j);
      arr_ref(a,k,j) = arr_ref(a,p[k],j);
      arr_ref(a,p[k],j) = tmp1;
    }
/*@; BEGIN(nest5=Nest) @*/
    for (i = 1 + k; i <= -1 + m; i += 1) {
      arr_ref(a,i,k) = arr_ref(a,i,k) / arr_ref(a,k,k);
    }
/*@; BEGIN(nest3=Nest) @*/
    for (j = 1 + k; j <= -1 + n; j += 1) {
/*@; BEGIN(nest4=Nest) @*/
      for (i = 1 + k; i <= -1 + m; i += 1) {
        arr_ref(a,i,j) = arr_ref(a,i,j) - arr_ref(a,i,k) * arr_ref(a,k,j);
      }
    }
  }
}
