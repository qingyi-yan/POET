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
void dgemvT(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) 
;
/* macro for the value of routine parameter */
#ifndef MS
#define MS 72
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 72
#endif
void dgemvT_ref(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) 
{
   int i,j;
   for (i=0; i<M; i+=1) 
     {
        Y[i] = beta*Y[i];
        for (j=0; j<N; j+=1) 
          Y[i] = Y[i]+A[i*lda+j]*X[j];
     }
}
/* macro for the value of routine parameter */
#ifndef MS
#define MS 72
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 72
#endif

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  /* induction variable for Multiple testing */
  int __pt_MT_ivar;
  
  
  /* Declaring parameters of the routine */
  int M;
  int N;
  double alpha;
  double* A;
  int lda;
  double* X;
  int incX;
  double beta;
  double* Y_comp;
  double* Y;
  int incY;
  double* A_buf;
  int A_size;
  double* X_buf;
  int X_size;
  double* Y_buf;
  int Y_size;
  double* Y_comp_buf;
  int Y_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  M = MS;
  N = NS;
  alpha = 1;
  A_size=M*N;
  A_buf = calloc(A_size, sizeof(double));
  lda = MS;
  X_size=N;
  X_buf = calloc(X_size, sizeof(double));
  incX = 1;
  beta = 1;
  Y_size=M;
  Y_buf = calloc(Y_size, sizeof(double));
  incY = 1;
  Y_comp_size=M;
  Y_comp_buf = calloc(Y_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = rand();; 
  }
  A = A_buf;
  for (__pt_i0=0; __pt_i0<X_size; ++__pt_i0)
  {
    X_buf[__pt_i0] = rand();; 
  }
  X = X_buf;
  for (__pt_i0=0; __pt_i0<Y_size; ++__pt_i0)
  {
    Y_buf[__pt_i0] = 1; 
  }
  Y = Y_buf;
  for (__pt_i0=0; __pt_i0<Y_comp_size; ++__pt_i0)
  {
    Y_comp_buf[__pt_i0] = 1; 
  }
  Y_comp = Y_comp_buf;
  /* Multiple Testings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    for (__pt_i0=0; __pt_i0<Y_size; ++__pt_i0)
    {
      Y_comp_buf[__pt_i0] = Y_buf[__pt_i0];
    }
    dgemvT (M,N,alpha,A,lda,X,incX,beta,Y_comp,incY);
    
    dgemvT_ref (M,N,alpha,A,lda,X,incX,beta,Y,incY);
    
    {
    int diff_flag = 0;
    for (__pt_i0=0; __pt_i0<M; ++__pt_i0)
    {
      if(Y_comp_buf[__pt_i0] != Y_buf[__pt_i0]) {
        diff_flag = 1;
        printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
            Y_comp_buf[__pt_i0], __pt_i0, Y_buf[__pt_i0],
        	fabs(Y_comp_buf[__pt_i0]-Y_buf[__pt_i0]));
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
