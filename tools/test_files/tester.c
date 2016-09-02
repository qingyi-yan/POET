#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif

#ifdef LDA 
#define SPARSE_DECL , int* rowstart, int* cols
#define SPARSE_ARG , rowstart, cols
#else
#define SPARSE_DECL
#define SPARSE_ARG
#endif


/* Collect multiple testing samples */
#ifndef MT
#define MT 2
#endif

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

/* routine to test*/
void CALL(const int M,const int N,DIM3_decl const double alpha,const double* A,const int lda,const double* B,const int ldb, BETA_DECL double* C,const int ldc SPARSE_DECL) 
;
/* macro for the value of routine parameter */
#ifndef MS
#define MS 72
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 72
#endif
/* macro for the value of routine parameter */
#ifndef KS
#define KS 72
#endif

#include <orig.c>

/* macro for the value of routine parameter */
#ifndef MS
#define MS 72
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 72
#endif
/* macro for the value of routine parameter */
#ifndef KS
#define KS 72
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
  int K;
  int i;
  int t1,t2;
  double alpha;
  double* A;
  int lda;
  double* B;
  int ldb;
  double beta;
  double* C_comp;
  double* C;
  int ldc;
  double* A_buf;
  int A_size;
  double* B_buf;
  int B_size;
  double* C_buf;
  int C_size;
  double* C_comp_buf;
  int C_comp_size;
  /* for sparse matrices */
  int* rowstart;
  int* cols;

  
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
  rowstart = calloc(lda+1, sizeof(int));
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
  ldc = MS;
  alpha = 1;
  beta = 2;
#if DIM <= 3 
  A_size=M*K;
#elif DIM == 4
  A_size=M*K*N;
#endif
  A_buf = calloc(A_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = rand();; 
  }
  A = A_buf;
#ifdef LDB
  B_size = LDB;
  ldb = LDB;
#else
  ldb = KS;
  B_size=K*N;
#endif
#if DIM <= 3
  B_buf = calloc(B_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<B_size; ++__pt_i0)
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
#ifdef LDC
  C_size = LDC;
#elif DIM <= 3
  C_size=M*N;
#elif DIM == 4
  C_size=M*N*K;
#endif
  C_buf = calloc(C_size, sizeof(double));
  C_comp_size=C_size;
  C_comp_buf = calloc(C_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<C_size; ++__pt_i0)
  {
    C_buf[__pt_i0] = rand(); 
  }
  C = C_buf;
  for (__pt_i0=0; __pt_i0<C_comp_size; ++__pt_i0)
  {
    C_comp_buf[__pt_i0] = C_buf[__pt_i0]; 
  }
  C_comp = C_comp_buf;
  /* Multiple Testings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {

#if DIM == 4
/* restore A to its original values */
  for (__pt_i0=0; __pt_i0<B_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = B_buf[__pt_i0];
  }
#endif

    for (__pt_i0=0; __pt_i0<C_size; ++__pt_i0)
    {
      C_comp_buf[__pt_i0] = C_buf[__pt_i0];
    }

    CALL (M,N,DIM3 alpha,A,lda,B,ldb,BETA C_comp,ldc SPARSE_ARG);
#if DIM == 4
/* restore A to its original values */
  for (__pt_i0=0; __pt_i0<B_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = B_buf[__pt_i0];
  }
#endif
    
    CALL_orig (M,N,DIM3 alpha,A,lda,B,ldb,BETA C,ldc SPARSE_ARG);
    
    {
    int diff_flag = 0;
    for (__pt_i0=0; __pt_i0<C_size; ++__pt_i0)
    {
      double diff = fabs((C_comp_buf[__pt_i0] - C_buf[__pt_i0]) / C_buf[__pt_i0]);
      if (diff > 0.01) {
        diff_flag = 1;
        printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
            C_comp_buf[__pt_i0], __pt_i0, C_buf[__pt_i0], diff);
      }
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
