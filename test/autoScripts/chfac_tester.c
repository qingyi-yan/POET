#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void chlskyfac(double* a,int NMAX) ;
/* macro for the value of routine parameter */
#ifndef NMAX_
#define NMAX_ 100
#endif
void chlskyfac_ref(double* a,int NMAX) {
   extern double sqrt(double) ;
   extern double fabs(double) ;
   int i;
   int j;
   int k;
   for (k=0; k<NMAX; k+=1)
     {
        a[k*NMAX+k] = sqrt(fabs(a[k*NMAX+k]));
        for (i=k+1; i<NMAX; i+=1)
          {
             a[i*NMAX+k] = a[i*NMAX+k]*1.0/a[k*NMAX+k];
          }
        for (j=k+1; j<NMAX; j+=1)
          {
             for (i=j; i<NMAX; i+=1)
               {
                  a[i*NMAX+j] = a[i*NMAX+j]-a[i*NMAX+k]*a[j*NMAX+k];
               }
          }
     }
}

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
  /* Declaring parameters of the routine */
  double* a_comp;
  double* a;
  int NMAX;
  double* a_buf;
  int a_size;
  double* a_comp_buf;
  int a_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  NMAX = NMAX_;
  a_size=NMAX*NMAX;
  a_buf = (double*)calloc(a_size, sizeof(double));
  a_comp_size=NMAX*NMAX;
  a_comp_buf = (double*)calloc(a_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
  {
    a_buf[__pt_i0] = rand();; 
  }
  a = a_buf;
  for (__pt_i0=0; __pt_i0<a_comp_size; ++__pt_i0)
  {
    a_comp_buf[__pt_i0] = rand();; 
  }
  a_comp = a_comp_buf;
  for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
  {
    a_comp_buf[__pt_i0] = a_buf[__pt_i0];
  }
  chlskyfac (a_comp,NMAX);
  
  chlskyfac_ref (a,NMAX);
  
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<NMAX*NMAX; ++__pt_i0)
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
  return(0);
}
