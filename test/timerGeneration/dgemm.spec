
routine = void dgemm_test(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) {
   int i;
   int j;
   int l;
   for (j=0; j<N; j+=1)
     {
        for (i=0; i<M; i+=1)
          {
             C[j*ldc+i] = beta*C[j*ldc+i];
             for (l=0; l<K; l+=1)
               {
                  C[j*ldc+i] = C[j*ldc+i]+alpha*A[l*lda+i]*B[j*ldb+l];
               }
          }
     }
}

init = {
  ldc = Macro(SIZE,200);
  beta = RANDOM;
  ldb = Macro(SIZE,200);
  lda = Macro(SIZE,200);
  alpha = RANDOM;
  K = Macro(SIZE,200);
  N = Macro(SIZE,200);
  M = Macro(SIZE,200);
  B = Vector(double,RANDOM,flush|align(16),N*ldb+K);
  A = Vector(double,RANDOM,flush|align(16),K*lda+M);
  C = Vector(double,RANDOM,flush|align(16),N*ldc+M);
};
returns(C);
flop = "M*N+3*K*M*N";
