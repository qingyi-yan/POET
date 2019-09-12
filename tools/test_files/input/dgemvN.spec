
routine = void dgemvN(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) {
   int i;int j;
   for (i=0; i<M; i+=1)
     {
        Y[i] = beta*Y[i];
        for (j=0; j<N; j+=1)
          {
             Y[i] = Y[i]+A[j*lda+i]*X[j];
          }
     }
}

init = {
  incY = 0;
  beta = RANDOM;
  incX = 0;
  lda = Macro(SIZE,200);
  alpha = RANDOM;
  N = Macro(SIZE,200);
  M = Macro(SIZE,200);
  X = Vector(double,RANDOM,flush|align(16),N);
  A = Vector(double,RANDOM,flush|align(16),N*lda+M);
  Y = Vector(double,RANDOM,flush|align(16),M);
};
returns(Y);
flop = "M+2*N*M";
