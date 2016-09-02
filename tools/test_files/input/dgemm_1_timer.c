#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CS
#define CS 1000
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
#define MT 3
#endif

#ifndef RANDSEED
#define RANDSEED 1
#endif
/* Measure the collective performance of multiple invocations */
#ifndef NREP
#define NREP 50
#endif

/* routine to measure performance of*/
void dgemm_1(const int M,const int n,const int K,const double alpha,const double* a,const int lda,const double* b,const int ldb,const double beta,double* c,const int ldc) ;
/* macro for the value of routien parameter */
#ifndef SIZE
#define SIZE 200
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
  int n;
  int K;
  double alpha;
  double* a;
  int lda;
  double* b;
  int ldb;
  double beta;
  double* c;
  int ldc;
  double* b_buf;
  int b_size, b_rep; 
  double* a_buf;
  int a_size, a_rep; 
  double* c_buf;
  int c_size, c_rep; 
  
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
  b_size=16*((15+(n*n+n))/16); 
  b_rep=CacheSZ / b_size + 1; 
  b_buf = calloc(b_size*b_rep, sizeof(double));
  a_size=16*((15+(n*n+n))/16); 
  a_rep=CacheSZ / a_size + 1; 
  a_buf = calloc(a_size*a_rep, sizeof(double));
  c_size=16*((15+(n*n+n))/16); 
  c_rep=CacheSZ / c_size + 1; 
  c_buf = calloc(c_size*c_rep, sizeof(double));
  #define DO_FLUSH 1
  __pt_flush_buffer = malloc(CacheSZ * sizeof(double));
  
  for(__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0) {
    __pt_flush_buffer[__pt_i0] = ((__pt_i0 % 3) == 2) ? -1 : __pt_i0 % 2;
  }
  
  /* Multiple Timings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    srand(RANDSEED);
    for (__pt_i0=0; __pt_i0<b_size *b_rep; ++__pt_i0)
    {
      b_buf[__pt_i0] = rand();; 
    }
    b = b_buf;
    for (__pt_i0=0; __pt_i0<a_size *a_rep; ++__pt_i0)
    {
      a_buf[__pt_i0] = rand();; 
    }
    a = a_buf;
    for (__pt_i0=0; __pt_i0<c_size *c_rep; ++__pt_i0)
    {
      c_buf[__pt_i0] = rand();; 
    }
    c = c_buf;
    /* code to flush the cache */
    __pt_flush_bufferVal = 0;
    for (__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0)
      __pt_flush_bufferVal += __pt_flush_buffer[__pt_i0];
    assert(__pt_flush_bufferVal < 10);
    
    /* Timer start */
    __timer_begin = GetWallTime();
    /* Timing loop */
    for (__pt_NREP_ivar=0; __pt_NREP_ivar<NREP; ++__pt_NREP_ivar) {
      dgemm_1 (M,n,K,alpha,a,lda,b,ldb,beta,c,ldc);
      alpha = rand();;
      beta = rand();;
      if (__pt_i0 < b_rep-1)
        b += b_size;
      else b = b_buf;
      if (__pt_i0 < a_rep-1)
        a += a_size;
      else a = a_buf;
      if (__pt_i0 < c_rep-1)
        c += c_size;
      else c = c_buf;
    }
    /* Timer end */
    __timer_end = GetWallTime();
    /* result of a single timing */
    __timer_diff[__pt_MT_ivar] = (__timer_end-__timer_begin)/NREP;
  }
  /* flops of computation */
  __pt_flops = n*n+2*n*n*n;
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
  printf("CPU MHZ: 0\n");
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
