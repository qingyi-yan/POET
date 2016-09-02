
routine=void ATL_USERMM(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) ;

init={ 
M=Macro(MS,72);
N=Macro(NS,72);
K=Macro(KS,72);
lda=MS;
ldb=KS;
ldc=MS;
alpha=1;
beta=1;
A=Matrix(double, M, K, RANDOM, flush|align(16));
B=Matrix(double, K, N, RANDOM, flush|align(16));
C=Matrix(double, M, N, RANDOM, flush|align(16));
} ; 

flop="2*M*N*K+M*N";

