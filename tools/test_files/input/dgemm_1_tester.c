#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void dgemm_1(const int M,const int n,const int K,const double alpha,const double* a,const int lda,const double* b,const int ldb,const double beta,double* c,const int ldc) ;
/* macro for the value of routine parameter */
#ifndef SIZE
#define SIZE 200
#endif
void dgemm_1_ref(const int M,const int n,const int K,const double alpha,const double* a,const int lda,const double* b,const int ldb,const double beta,double* c,const int ldc) {
   int i;
   int j;
   int k;
   for (j=0; j<n; j+=1)
     {
        for (i=0; i<n; i+=1)
          {
             c[j*n+i] = beta*c[j*n+i];
          }
     }
   for (k=0; k<n; k+=1)
     {
        for (j=0; j<n; j+=1)
          {
             for (i=0; i<n; i+=1)
               {
                  c[j*n+i] = c[j*n+i]+a[k*n+i]*b[j*n+k];
               }
          }
     }
}

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
  /* Declaring parameters of the routine */
  int M;
  int n;
  int K;
  double alpha;
  double* a;
  int lda;
  double* b;
  int ldb;
  double beta;
  double* c_comp;
  double* c;
  int ldc;
  double* b_buf;
  int b_size;
  double* a_buf;
  int a_size;
  double* c_buf;
  int c_size;
  double* c_comp_buf;
  int c_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  ldc = 0;
  ldb = 0;
  lda = 0;
  alpha = rand();;
  K = 0;
  M = 0;
  beta = rand();;
  n = SIZE;
  b_size=n*n+n;
  b_buf = (double*)calloc(b_size, sizeof(double));
  a_size=n*n+n;
  a_buf = (double*)calloc(a_size, sizeof(double));
  c_size=n*n+n;
  c_buf = (double*)calloc(c_size, sizeof(double));
  c_comp_size=n*n+n;
  c_comp_buf = (double*)calloc(c_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<b_size; ++__pt_i0)
  {
    b_buf[__pt_i0] = rand();; 
  }
  b = b_buf;
  for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
  {
    a_buf[__pt_i0] = rand();; 
  }
  a = a_buf;
  for (__pt_i0=0; __pt_i0<c_size; ++__pt_i0)
  {
    c_buf[__pt_i0] = rand();; 
  }
  c = c_buf;
  for (__pt_i0=0; __pt_i0<c_comp_size; ++__pt_i0)
  {
    c_comp_buf[__pt_i0] = rand();; 
  }
  c_comp = c_comp_buf;
  for (__pt_i0=0; __pt_i0<c_size; ++__pt_i0)
  {
    c_comp_buf[__pt_i0] = c_buf[__pt_i0];
  }
  dgemm_1 (M,n,K,alpha,a,lda,b,ldb,beta,c_comp,ldc);
  
  dgemm_1_ref (M,n,K,alpha,a,lda,b,ldb,beta,c,ldc);
  
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<n*n+n; ++__pt_i0)
  {
    if(c_comp_buf[__pt_i0] != c_buf[__pt_i0]) {
      diff_flag = 1;
      printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
          c_comp_buf[__pt_i0], __pt_i0, c_buf[__pt_i0],
      	fabs(c_comp_buf[__pt_i0]-c_buf[__pt_i0]));
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
