#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CS
#define CS 4098
#endif
#define CacheSZ CS*1024/sizeof(double)

#if DIM>=3
#define DIM3_decl const int K,
#define DIM3 K,
#else
#define DIM3_decl 
#define DIM3 
#endif

#if DIM==1 || DIM == 4
#define BETA
#define BETA_DECL
#else
#define BETA_DECL const double beta,
#define BETA beta,
#endif

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
/* Measure the collective performance of multiple invocations */
#ifndef NREP
#define NREP 50
#endif

#ifndef SIZE
#define SIZE 72
#endif

#ifdef LDA 
#define SPARSE_DECL , int* rowstart, int* cols
#define SPARSE_ARG , rowstart, cols
#else
#define SPARSE_DECL
#define SPARSE_ARG
#endif

/* routine to measure performance of*/
void CALL(const int M,const int N,DIM3_decl const double alpha,const double* A,const int lda,const double* B,const int ldb, BETA_DECL double* C,const int ldc SPARSE_DECL) 
;
/* macro for the value of routien parameter */
#ifndef MS
#define MS SIZE
#endif
/* macro for the value of routien parameter */
#ifndef NS
#define NS SIZE
#endif
/* macro for the value of routien parameter */
#ifndef KS
#define KS SIZE
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
  int A_size, A_rep; 
  double* B_buf;
  int B_size, B_rep; 
  double* C_buf;
  int C_size, C_rep; 
  int* rowstart;
  int* cols;
  int i, t1, t2;
  
  /* parameter initializations */
  srand(RANDSEED);
  M = MS;
  N = NS;
  K = KS;
#ifdef LDA
#ifndef LDB
#define LDB LDA
#endif
#ifndef LDC
#define LDC LDA
#endif
  lda = LDA;
  rowstart = calloc(LDA+1, sizeof(int));
  cols = calloc(M*K,sizeof(int));
  t1 = MS*NS/LDA; t2 = 0;
  if (t1 == 0) t1 = 1;
  rowstart[0] = 0; 
  for (i = 1; i < LDA; i++) {
     t2 = t2 + rand() % t1;
     rowstart[i] = t2;
  }
  rowstart[i]=MS*NS;
  for (i = 0; i < M*K; i++) {
     cols[i] = rand() % LDB;
  }
#elif DIM<=3
  lda = MS;
#elif DIM == 4
#ifdef TIME_STEP
  lda = TIME_STEP;
#else
  lda = 16;
#endif
#endif

#ifdef LDB
  B_size = LDB;
#else
  B_size=K*N;
  ldb = KS;
#endif
#if DIM <= 3
  B_rep=CacheSZ / B_size + 1; 
  B_buf = calloc(B_size*B_rep, sizeof(double));
  for (__pt_i0=0; __pt_i0<B_size *B_rep; ++__pt_i0)
    {
      B_buf[__pt_i0] = rand();; 
    }
  B = B_buf;
#else
  B_size=A_size;
  B_buf = calloc(B_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<B_size; ++__pt_i0)
  {
    B_buf[__pt_i0] = A_buf[__pt_i0];
  }
  B = B_buf;
#endif
  alpha = 1;
  beta = 1;
  A_size=M*K; 
  A_rep=CacheSZ / A_size + 1; 
  A_buf = calloc(A_size*A_rep, sizeof(double));
#ifdef LDC
  C_size = LDC;
  ldc = LDC;
#elif DIM <= 3
  C_size=M*N;
  ldc = MS;
#elif DIM == 4
  C_size=M*N*K;
#endif
  C_rep=CacheSZ / C_size + 1; 
  C_buf = calloc(C_size*C_rep, sizeof(double));
  
  /* Multiple Timings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    srand(RANDSEED);
    for (__pt_i0=0; __pt_i0<A_size *A_rep; ++__pt_i0)
    {
      A_buf[__pt_i0] = rand();; 
    }
    A = A_buf;
    for (__pt_i0=0; __pt_i0<C_size *C_rep; ++__pt_i0)
    {
      C_buf[__pt_i0] = 0; 
    }
    C = C_buf;
    /* Timer start */
    __timer_begin = GetWallTime();
    /* Timing loop */
    for (__pt_NREP_ivar=0; __pt_NREP_ivar<NREP; ++__pt_NREP_ivar) {
      CALL (M,N,DIM3 alpha,A,lda,B,ldb,BETA C,ldc SPARSE_ARG);
      if (__pt_i0 < A_rep-1)
        A += A_size;
      else A = A_buf;
      if (__pt_i0 < B_rep-1)
        B += B_size;
      else B = B_buf;
      if (__pt_i0 < C_rep-1)
        C += C_size;
      else C = C_buf;
    }
    /* Timer end */
    __timer_end = GetWallTime();
    /* result of a single timing */
    __timer_diff[__pt_MT_ivar] = (__timer_end-__timer_begin)/NREP;
  }
  /* flops of computation */
  __pt_flops = FLOP;

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
