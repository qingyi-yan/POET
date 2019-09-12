void ATL_USERMM(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) {
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
                  C[j*ldc+i] = C[j*ldc+i]+alpha*A[i*lda+l]*B[j*ldb+l];
               }
          }
     }
}
