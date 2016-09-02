#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CS
#define CS 4098
#endif
#define CacheSZ CS*1024/sizeof(double)

long long GetCycleCount();
double GetWallTime() {
  static long long start = 0;
  static const double SPC = 1.0 / (2160*1.0E6);
  long long t0;
  if (start) {
    t0 = GetCycleCount() - start;
    return (SPC * t0);
  }
  start = GetCycleCount();
  return(0.0);
} 

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
  /* variable for storing results of a single timing */
  double __timer_diff;
  
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
  __timer_diff = __timer_end-__timer_begin;
  /* flops of computation */
  __pt_flops = M*N*K + M*N;
  
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
  printf("ARCH: x86\n");
  
  return(0);
}
