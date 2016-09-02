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
#define MT 10
#endif

#ifndef RANDSEED
#define RANDSEED 1
#endif

/* routine to measure performance of*/
void dgemm_test(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) ;
/* macro for the value of routien parameter */
#ifndef MS
#define MS 540
#endif
/* macro for the value of routien parameter */
#ifndef NS
#define NS 540
#endif
/* macro for the value of routien parameter */
#ifndef KS
#define KS 540
#endif

int main(int argc, char **argv) 
{
  
  /* arrays for storing results of multiple timings */
  double __timer_diff[MT];
  
  /* induction variable for Multiple timing */
  int __pt_MT_ivar;
  
  double __timer_min,__timer_avg,__timer_max;
  
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
  int K;
  double alpha;
  double* A;
  int lda;
  double* B;
  int ldb;
  double beta;
  double* C;
  int ldc;
  double* A_buf;
  int A_size; 
  double* B_buf;
  int B_size; 
  double* C_buf;
  int C_size; 
  
  /* parameter initializations */
  srand(RANDSEED); 
  M = MS;
  N = NS;
  K = KS;
  lda = M;
  ldb = N;
  ldc = K;
  alpha = 1;
  beta = 1;
  A_size=M*K; 
  A_buf = calloc(A_size, sizeof(double));
  B_size=K*N; 
  B_buf = calloc(B_size, sizeof(double));
  C_size=M*N; 
  C_buf = calloc(C_size, sizeof(double));
  #define DO_FLUSH 1
  __pt_flush_buffer = malloc(CacheSZ * sizeof(double));
  
  for(__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0) {
    __pt_flush_buffer[__pt_i0] = ((__pt_i0 % 3) == 2) ? -1 : __pt_i0 % 2;
  }
  
  /* Multiple Timings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    srand(RANDSEED);
    for (__pt_i0=0; __pt_i0<A_size ; ++__pt_i0)
    {
      A_buf[__pt_i0] = rand();; 
    }
    A = A_buf;
    for (__pt_i0=0; __pt_i0<B_size ; ++__pt_i0)
    {
      B_buf[__pt_i0] = rand();; 
    }
    B = B_buf;
    for (__pt_i0=0; __pt_i0<C_size ; ++__pt_i0)
    {
      C_buf[__pt_i0] = rand();; 
    }
    C = C_buf;
    /* code to flush the cache */
    __pt_flush_bufferVal = 0;
    for (__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0)
      __pt_flush_bufferVal += __pt_flush_buffer[__pt_i0];
    assert(__pt_flush_bufferVal < 10);
    
    /* Timer start */
    __timer_begin = GetWallTime();
    dgemm_test (M,N,K,alpha,A,lda,B,ldb,beta,C,ldc);
    /* Timer end */
    __timer_end = GetWallTime();
    /* result of a single timing */
    __timer_diff[__pt_MT_ivar] = __timer_end-__timer_begin;
  }
  /* flops of computation */
  __pt_flops = M*N*K + M*N;
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
  
  printf("mt: %d\n", MT);
  printf("Random Seed: %d\n", RANDSEED); 
  return(0);
}
