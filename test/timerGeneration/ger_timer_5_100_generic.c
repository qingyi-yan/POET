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

/* Collect multiple timing samples */
#ifndef MT
#define MT 5
#endif

#ifndef RANDSEED
#define RANDSEED 1
#endif
/* Measure the collective performance of multiple invocations */
#ifndef NREP
#define NREP 100
#endif

/* routine to measure performance of*/
void ATL_dger1_a1_x1_yX(const int M,const int N,const double alpha,const double* X,const int incX,const double* Y,const int incY,double* A,const int lda) ;
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
  
  /* arrays for storing results of multiple timings */
  double __timer_diff[MT];
  
  /* induction variable for Multiple timing */
  int __pt_MT_ivar;
  
  double __timer_min,__timer_avg,__timer_max;
  
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
  double* X;
  int incX;
  double* Y;
  int incY;
  double* A;
  int lda;
  double* X_buf;
  int X_size, X_rep; 
  double* Y_buf;
  int Y_size, Y_rep; 
  double* A_buf;
  int A_size, A_rep; 
  
  /* parameter initializations */
  srand(RANDSEED); 
  M = MS;
  N = NS;
  lda = M;
  incY = 1;
  incX = 1;
  alpha = 1;
  X_size=M; 
  X_rep=CacheSZ / X_size + 1; 
  X_buf = calloc(X_size*X_rep, sizeof(double));
  Y_size=N; 
  Y_rep=CacheSZ / Y_size + 1; 
  Y_buf = calloc(Y_size*Y_rep, sizeof(double));
  A_size=M*N; 
  A_rep=CacheSZ / A_size + 1; 
  A_buf = calloc(A_size*A_rep, sizeof(double));
  #define DO_FLUSH 1
  __pt_flush_buffer = malloc(CacheSZ * sizeof(double));
  
  for(__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0) {
    __pt_flush_buffer[__pt_i0] = ((__pt_i0 % 3) == 2) ? -1 : __pt_i0 % 2;
  }
  
  /* Multiple Timings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    srand(RANDSEED);
    for (__pt_i0=0; __pt_i0<X_size *X_rep; ++__pt_i0)
    {
      X_buf[__pt_i0] = rand();; 
    }
    X = X_buf;
    for (__pt_i0=0; __pt_i0<Y_size *Y_rep; ++__pt_i0)
    {
      Y_buf[__pt_i0] = rand();; 
    }
    Y = Y_buf;
    for (__pt_i0=0; __pt_i0<A_size *A_rep; ++__pt_i0)
    {
      A_buf[__pt_i0] = rand();; 
    }
    A = A_buf;
    /* code to flush the cache */
    __pt_flush_bufferVal = 0;
    for (__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0)
      __pt_flush_bufferVal += __pt_flush_buffer[__pt_i0];
    assert(__pt_flush_bufferVal < 10);
    
    /* Timer start */
    __timer_begin = GetWallTime();
    /* Timing loop */
    for (__pt_NREP_ivar=0; __pt_NREP_ivar<NREP; ++__pt_NREP_ivar) {
      ATL_dger1_a1_x1_yX (M,N,alpha,X,incX,Y,incY,A,lda);
      if (__pt_i0 < X_rep-1)
        X += X_size;
      else X = X_buf;
      if (__pt_i0 < Y_rep-1)
        Y += Y_size;
      else Y = Y_buf;
      if (__pt_i0 < A_rep-1)
        A += A_size;
      else A = A_buf;
    }
    /* Timer end */
    __timer_end = GetWallTime();
    /* result of a single timing */
    __timer_diff[__pt_MT_ivar] = (__timer_end-__timer_begin)/NREP;
  }
  /* flops of computation */
  __pt_flops = 2*M*N;
  /* Compute minimum of multiple timings */
  __timer_min=__timer_diff[0];
  __timer_max=__timer_diff[0];
  __timer_avg=__timer_diff[0];
  for (__pt_MT_ivar=1; __pt_MT_ivar<MT; ++__pt_MT_ivar)
  {
    if (__timer_min > __timer_diff[__pt_MT_ivar])
        __timer_min = __timer_diff[__pt_MT_ivar];
    if (__timer_max < __timer_diff[__pt_MT_ivar])
        __timer_max = __timer_diff[__pt_MT_ivar];
    __timer_avg += __timer_diff[__pt_MT_ivar];
  }
  __timer_avg /= MT;
  
  
  /* output timing results */
  for (__pt_MT_ivar=0; __pt_MT_ivar < MT; ++__pt_MT_ivar)
  {
    printf("time in seconds [%d]:  %.15f\n", __pt_MT_ivar, __timer_diff[__pt_MT_ivar]);
  
  }
  printf("Minimum time in seconds:  %.15f\n", __timer_min);
  printf("Maximum time in seconds:  %.15f\n", __timer_max);
  printf("Average time in seconds:  %.15f\n", __timer_avg);
  printf("Maximum MFLOPS: %.15f\n", __pt_flops/__timer_min/1000000); 
  printf("Minimum MFLOPS: %.15f\n", __pt_flops/__timer_max/1000000); 
  printf("Average MFLOPS: %.15f\n", __pt_flops/__timer_avg/1000000); 
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
  printf("mt: %d\n", MT);
  printf("Random Seed: %d\n", RANDSEED); 
  return(0);
}
