include=
#include "./out_dgemm_test.c"

routine=
void dgemm_test(const int M, const int N, const int K, 
          const double alpha, const double *A, const int lda, 
          const double *B, const int ldb, const double beta, 
          double *C, const int ldc) 			
{ 								

   int i,j,l;     						
   for (j = 0; j < N; j += 1) 					
   { 	                                  		
      for (i = 0; i < M; i += 1)  				
      { 							
         C[j*ldc+i] = beta * C[j*ldc+i]; 			 
         for (l = 0; l < K; l +=1) 				
         { 							
            C[j*ldc+i] += alpha * A[l*lda+i]*B[j*ldb+l];
         }      						
     }      							
   } 								
}  								

init={ 
M=Macro(MS,72);
N=Macro(NS,72);
K=Macro(KS,72);
lda=MS;
ldb=KS;
ldc=MS;
alpha=1;
beta=1;
A=Matrix(double, M, K, RANDOM,);
B=Matrix(double, K, N, RANDOM,);
C=Matrix(double, M, N, 0,);
} ; 

returns(C);
