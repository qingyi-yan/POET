#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* Collect multiple testing samples */
#ifndef MT
#define MT 2
#endif


/* routine to test*/
void dgetrf(int m,int n,double* a,int* p) 
;
/* macro for the value of routine parameter */
#ifndef MS
#define MS 100
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 100
#endif
#define arr_ref(a,i,j) a[(i)*NS+(j)]
#include "./out_dgetrf.c"
void dgetrf_ref(int m,int n,double* a,int* p) 
{
   double tmp,tmp1;
   int j,i,k;
   for (k = 0; k<min(m-1,n-1); ++k) 
     {
        p[k] = k;
        tmp = dabs(arr_ref(a,k,k));
        for (i = k+1; i<m; ++i) 
          if (dabs(arr_ref(a,i,k))>tmp)  
            {
               p[k] = i;
               tmp = dabs(arr_ref(a,i,k));
            }
        for (j = k; j<n; ++j) 
          {
             tmp1 = arr_ref(a,k,j);
             arr_ref(a,k,j) = arr_ref(a,p[k],j);
             arr_ref(a,p[k],j) = tmp1;
          }
        for (i = k+1; i<m; ++i) 
          arr_ref(a,i,k) = arr_ref(a,i,k)/arr_ref(a,k,k);
        for (j = k+1; j<n; ++j) 
          for (i = k+1; i<m; ++i) 
            arr_ref(a,i,j) = arr_ref(a,i,j)+-arr_ref(a,i,k)*arr_ref(a,k,j);
     }
}
/* macro for the value of routine parameter */
#ifndef MS
#define MS 100
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 100
#endif

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  /* induction variable for Multiple testing */
  int __pt_MT_ivar;
  
  
  /* Declaring parameters of the routine */
  int m;
  int n;
  double* a_comp;
  double* a;
  int* p;
  double* a_buf;
  int a_size;
  int* p_buf;
  int p_size;
  double* a_comp_buf;
  int a_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  m = MS;
  n = NS;
  a_size=m*n;
  a_buf = calloc(a_size, sizeof(double));
  p_size=n;
  p_buf = calloc(p_size, sizeof(int));
  a_comp_size=m*n;
  a_comp_buf = calloc(a_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
  {
    a_buf[__pt_i0] = rand();; 
  }
  a = a_buf;
  for (__pt_i0=0; __pt_i0<p_size; ++__pt_i0)
  {
    p_buf[__pt_i0] = 0; 
  }
  p = p_buf;
  for (__pt_i0=0; __pt_i0<a_comp_size; ++__pt_i0)
  {
    a_comp_buf[__pt_i0] = rand();; 
  }
  a_comp = a_comp_buf;
  /* Multiple Testings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
    {
      a_comp_buf[__pt_i0] = a_buf[__pt_i0];
    }
    dgetrf (m,n,a_comp,p);
    
    dgetrf_ref (m,n,a,p);
    
    {
    int diff_flag = 0;
    for (__pt_i0=0; __pt_i0<m*n; ++__pt_i0)
    {
      if(a_comp_buf[__pt_i0] != a_buf[__pt_i0]) {
        diff_flag = 1;
        printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
            a_comp_buf[__pt_i0], __pt_i0, a_buf[__pt_i0],
        	fabs(a_comp_buf[__pt_i0]-a_buf[__pt_i0]));
      }
      /*else {
        printf("Identical output at index %d\n", __pt_i0);
      } */
    }
    if(diff_flag) {
      printf("Output differs\n");
    }else {
      printf("Output is identical\n");
    }
    }
  }
  return(0);
}