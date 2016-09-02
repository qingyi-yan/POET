void dsyrk(const int M,const int N,const int K,const double alpha,const double *A,const int lda,const double *B,const int ldb,const double beta,double *C,const int ldc)
{
  int i; 
  int j;
  int k;
  /*@; BEGIN(nest1=MM_pat[type="double"]) @*/
  for (j = 0; j < N; j += 1) {
	  for (i = 0; i < N; i +=1 ) {
		  for (k = 0; k < N; k += 1) {
			  C[j*ldc+i] += A[k*lda+i]*A[k*lda+j];
		  }
	  }
  }
}



