#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void dgemvN(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) ;
/* macro for the value of routine parameter */
#ifndef SIZE
#define SIZE 200
#endif
void dgemvN_ref(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) {
   int i;
   int j;
   for (i=0; i<M; i+=1)
     {
        Y[i] = beta*Y[i];
        for (j=0; j<N; j+=1)
          {
             Y[i] = Y[i]+A[j*lda+i]*X[j];
          }
     }
}

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
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
  double* X_buf;
  int X_size;
  double* A_buf;
  int A_size;
  double* Y_buf;
  int Y_size;
  double* Y_comp_buf;
  int Y_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  incY = 0;
  beta = rand();;
  incX = 0;
  lda = SIZE;
  alpha = rand();;
  N = SIZE;
  M = SIZE;
  X_size=N;
  X_buf = (double*)calloc(X_size, sizeof(double));
  A_size=N*lda+M;
  A_buf = (double*)calloc(A_size, sizeof(double));
  Y_size=M;
  Y_buf = (double*)calloc(Y_size, sizeof(double));
  Y_comp_size=M;
  Y_comp_buf = (double*)calloc(Y_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<X_size; ++__pt_i0)
  {
    X_buf[__pt_i0] = rand();; 
  }
  X = X_buf;
  for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = rand();; 
  }
  A = A_buf;
  for (__pt_i0=0; __pt_i0<Y_size; ++__pt_i0)
  {
    Y_buf[__pt_i0] = rand();; 
  }
  Y = Y_buf;
  for (__pt_i0=0; __pt_i0<Y_comp_size; ++__pt_i0)
  {
    Y_comp_buf[__pt_i0] = rand();; 
  }
  Y_comp = Y_comp_buf;
  for (__pt_i0=0; __pt_i0<Y_size; ++__pt_i0)
  {
    Y_comp_buf[__pt_i0] = Y_buf[__pt_i0];
  }
  dgemvN (M,N,alpha,A,lda,X,incX,beta,Y_comp,incY);
  
  dgemvN_ref (M,N,alpha,A,lda,X,incX,beta,Y,incY);
  
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
  return(0);
}
