
routine= void dgemm_test(const int M, const int N, const int K, 
          const double alpha, const double *A, const int lda, 
          const double *B, const int ldb, const double beta, 
          double *C, const int ldc); 

init={ 
M=Macro(MS,540);
N=Macro(NS,540);
K=Macro(KS,540);
lda=M;
ldb=N;
ldc=K;
alpha=1;
beta=1;
A=Matrix(double, M, K, RANDOM, flush);
B=Matrix(double, K, N, RANDOM, flush);
C=Matrix(double, M, N, RANDOM, flush);
} ; 

flop="M*N*K + M*N";

