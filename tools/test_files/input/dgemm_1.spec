
routine = void dgemm_1(const int M,const int n,const int K,const double alpha,const double* a,const int lda,const double* b,const int ldb,const double beta,double* c,const int ldc) {
   int i;int j;int k;
   for (j=0; j<n; j+=1)
     {
        for (i=0; i<n; i+=1)
          {
             c[j*n+i] = beta*c[j*n+i];
          }
     }
   for (k=0; k<n; k+=1)
     {
        for (j=0; j<n; j+=1)
          {
             for (i=0; i<n; i+=1)
               {
                  c[j*n+i] = c[j*n+i]+a[k*n+i]*b[j*n+k];
               }
          }
     }
}

init = {
  ldc = 0;
  ldb = 0;
  lda = 0;
  alpha = RANDOM;
  K = 0;
  M = 0;
  beta = RANDOM;
  n = Macro(SIZE,200);
  b = Vector(double,RANDOM,flush|align(16),n*n+n);
  a = Vector(double,RANDOM,flush|align(16),n*n+n);
  c = Vector(double,RANDOM,flush|align(16),n*n+n);
};
returns(c);
flop = "n*n+2*n*n*n";
