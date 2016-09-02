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
void dgemm_test(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) 
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
void dgemm_test_ref(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) 
{
   int i,j,l;
   for (j=0; j<N; j+=1) 
     for (i=0; i<M; i+=1) 
       {
          C[j*ldc+i] = beta*C[j*ldc+i];
          for (l=0; l<K; l+=1) 
            C[j*ldc+i] = C[j*ldc+i]+alpha*A[l*lda+i]*B[j*ldb+l];
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
  
  /* parameter initializations */
  srand(RANDSEED);
  M = MS;
  N = NS;
  K = KS;
  lda = MS;
  ldb = KS;
  ldc = MS;
  alpha = 1;
  beta = 1;
  A_size=M*K;
  A_buf = calloc(A_size, sizeof(double));
  B_size=K*N;
  B_buf = calloc(B_size, sizeof(double));
  C_size=M*N;
  C_buf = calloc(C_size, sizeof(double));
  C_comp_size=M*N;
  C_comp_buf = calloc(C_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<A_size; ++__pt_i0)
  {
    A_buf[__pt_i0] = rand();; 
  }
  A = A_buf;
  for (__pt_i0=0; __pt_i0<B_size; ++__pt_i0)
  {
    B_buf[__pt_i0] = rand();; 
  }
  B = B_buf;
  for (__pt_i0=0; __pt_i0<C_size; ++__pt_i0)
  {
    C_buf[__pt_i0] = 0; 
  }
  C = C_buf;
  for (__pt_i0=0; __pt_i0<C_comp_size; ++__pt_i0)
  {
    C_comp_buf[__pt_i0] = 0; 
  }
  C_comp = C_comp_buf;
  /* Multiple Testings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    for (__pt_i0=0; __pt_i0<C_size; ++__pt_i0)
    {
      C_comp_buf[__pt_i0] = C_buf[__pt_i0];
    }
    dgemm_test (M,N,K,alpha,A,lda,B,ldb,beta,C_comp,ldc);
    
    dgemm_test_ref (M,N,K,alpha,A,lda,B,ldb,beta,C,ldc);
    
    {
    int diff_flag = 0;
    for (__pt_i0=0; __pt_i0<M*N; ++__pt_i0)
    {
      if(C_comp_buf[__pt_i0] != C_buf[__pt_i0]) {
        diff_flag = 1;
        printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
            C_comp_buf[__pt_i0], __pt_i0, C_buf[__pt_i0],
        	fabs(C_comp_buf[__pt_i0]-C_buf[__pt_i0]));
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
