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
void dger(const int M,const int N,const double alpha,const double* X,const int incX,const double* Y,const int incY,double* A,const int lda) 
;
/* macro for the value of routine parameter */
#ifndef MS
#define MS 72
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 72
#endif
void dger_ref(const int M,const int N,const double alpha,const double* X,const int incX,const double* Y,const int incY,double* A,const int lda) 
{
   int i,j;
   for (j=0; j<N; j+=1) 
     for (i=0; i<M; i+=1) 
       A[j*lda+i] = A[j*lda+i]+X[i]*Y[j*incY];
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
  double* X;
  int incX;
  double* Y;
  int incY;
  double* A_comp;
  double* A;
  int lda;
  double* A_buf;
  int A_size;
  double* Y_buf;
  int Y_size;
  double* X_buf;
  int X_size;
  double* A_comp_buf;
  int A_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  M = MS;
  N = NS;
  alpha = 1;
  A_size=M*N;
  A_buf = calloc(A_size, sizeof(double));
  lda = MS;
  Y_size=N;
  Y_buf = calloc(Y_size, sizeof(double));
  incX = 1;
  X_size=M;
  X_buf = calloc(X_size, sizeof(double));
  incY = 1;
  A_comp_size=M*N;
  A_comp_buf = calloc(A_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = 2; 
  }
  A = A_buf;
  for (__pt_i0=0; __pt_i0<Y_size; ++__pt_i0)
  {
    Y_buf[__pt_i0] = rand();; 
  }
  Y = Y_buf;
  for (__pt_i0=0; __pt_i0<X_size; ++__pt_i0)
  {
    X_buf[__pt_i0] = rand();; 
  }
  X = X_buf;
  for (__pt_i0=0; __pt_i0<A_comp_size; ++__pt_i0)
  {
    A_comp_buf[__pt_i0] = 2; 
  }
  A_comp = A_comp_buf;
  /* Multiple Testings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
    {
      A_comp_buf[__pt_i0] = A_buf[__pt_i0];
    }
    dger (M,N,alpha,X,incX,Y,incY,A_comp,lda);
    
    dger_ref (M,N,alpha,X,incX,Y,incY,A,lda);
    
    {
    int diff_flag = 0;
    for (__pt_i0=0; __pt_i0<M*N; ++__pt_i0)
    {
      if(A_comp_buf[__pt_i0] != A_buf[__pt_i0]) {
        diff_flag = 1;
        printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
            A_comp_buf[__pt_i0], __pt_i0, A_buf[__pt_i0],
        	fabs(A_comp_buf[__pt_i0]-A_buf[__pt_i0]));
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
