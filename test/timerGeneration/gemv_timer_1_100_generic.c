#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CS
#define CS 4098
#endif
#define CacheSZ CS*1024/sizeof(double)


#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
double GetWallTime(void)
   {
      struct timeval tp;
      static long start=0, startu;
      if (!start)
      {
         gettimeofday(&tp, NULL);
         start = tp.tv_sec;
         startu = tp.tv_usec;
         return(0.0);
      }
      gettimeofday(&tp, NULL);
      return( ((double) (tp.tv_sec - start)) + (tp.tv_usec-startu)/1000000.0 );
   }
/* Measure the collective performance of multiple invocations */
#ifndef NREP
#define NREP 100
#endif

/* routine to measure performance of*/
void ATL_dgemvN_a1_x1_bX_y1(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) ;
/* macro for the value of routien parameter */
#ifndef MS
#define MS 100
#endif
/* macro for the value of routien parameter */
#ifndef NS
#define NS 100
#endif

int main(int argc, char **argv) 
{
  /* variable for storing results of a single timing */
  double __timer_diff;
  
  /* induction variable for multiple invocations in a single timing */
  int __pt_NREP_ivar;
  
  /* variables to support cache flushing */
  double* __pt_flush_buffer;
  double __pt_flush_bufferVal;
  
  /* variable for computing MFLOPS */
  double __pt_flops;
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  /*variables to store starting and ending of timing */
  double __timer_begin, __timer_end; 
  
  /* Declaring parameters of the routine */
  int M;
  int N;
  double alpha;
  double* A;
  int lda;
  double* X;
  int incX;
  double beta;
  double* Y;
  int incY;
  double* A_buf;
  int A_size, A_rep; 
  double* X_buf;
  int X_size, X_rep; 
  double* Y_buf;
  int Y_size, Y_rep; 
  
  /* parameter initializations */
  
  M = MS;
  N = NS;
  lda = MS;
  alpha = 1;
  beta = 1;
  incX = 1;
  incY = 1;
  A_size=M*N; 
  A_rep=CacheSZ / A_size + 1; 
  A_buf = calloc(A_size*A_rep, sizeof(double));
  X_size=M; 
  X_rep=CacheSZ / X_size + 1; 
  X_buf = calloc(X_size*X_rep, sizeof(double));
  Y_size=M; 
  Y_rep=CacheSZ / Y_size + 1; 
  Y_buf = calloc(Y_size*Y_rep, sizeof(double));
  #define DO_FLUSH 1
  __pt_flush_buffer = malloc(CacheSZ * sizeof(double));
  
  for(__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0) {
    __pt_flush_buffer[__pt_i0] = ((__pt_i0 % 3) == 2) ? -1 : __pt_i0 % 2;
  }
  
  for (__pt_i0=0; __pt_i0<A_size *A_rep; ++__pt_i0)
  {
    A_buf[__pt_i0] = rand();; 
  }
  A = A_buf;
  for (__pt_i0=0; __pt_i0<X_size *X_rep; ++__pt_i0)
  {
    X_buf[__pt_i0] = rand();; 
  }
  X = X_buf;
  for (__pt_i0=0; __pt_i0<Y_size *Y_rep; ++__pt_i0)
  {
    Y_buf[__pt_i0] = 0; 
  }
  Y = Y_buf;
  /* code to flush the cache */
  __pt_flush_bufferVal = 0;
  for (__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0)
    __pt_flush_bufferVal += __pt_flush_buffer[__pt_i0];
  assert(__pt_flush_bufferVal < 10);
  
  /* Timer start */
  __timer_begin = GetWallTime();
  /* Timing loop */
  for (__pt_NREP_ivar=0; __pt_NREP_ivar<NREP; ++__pt_NREP_ivar) {
    ATL_dgemvN_a1_x1_bX_y1 (M,N,alpha,A,lda,X,incX,beta,Y,incY);
    if (__pt_i0 < A_rep-1)
      A += A_size;
    else A = A_buf;
    if (__pt_i0 < X_rep-1)
      X += X_size;
    else X = X_buf;
    if (__pt_i0 < Y_rep-1)
      Y += Y_size;
    else Y = Y_buf;
  }
  /* Timer end */
  __timer_end = GetWallTime();
  /* result of a single timing */
  __timer_diff = (__timer_end-__timer_begin)/NREP;
  /* flops of computation */
  __pt_flops = 2*M*N + M;
  
  /* output timing results */
  printf("time in seconds: %.15f\n", __timer_diff);
  printf("MFLOPS: %.15f\n", __pt_flops/__timer_diff/1000000); 
  
  printf("Configuration\n"
         "-------------\n");
  printf("CPU MHZ: 2160\n");
  printf("Cache Size: %d\n", CS);
  #ifdef DO_FLUSH
  printf("Cache Flush Method: generic\n");
  #else
  printf("Cache Flush Method: none\n");
  #endif
  printf("ARCH: generic\n");
  printf("nrep: %d\n", NREP);
  return(0);
}
