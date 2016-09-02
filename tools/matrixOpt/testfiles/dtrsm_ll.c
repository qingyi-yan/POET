
void dtrsm_ll(const int M,const int N,const int K,const double alpha,const double *A,const int lda,const double *B1,const int ldb1,const double beta,double *B,const int ldb)
{
    long i,j,k;

	/*@; BEGIN(nest1=MM_pat[type="double"]) @*/
	for (j=0; j<N; j++) {
		for (i=0; i<N; i++) {
			for (k=0; k<i; k++) {
				B[j*ldb+i]=B[j*ldb+i] - A[k*lda+i] * B[j*ldb+k];  
			}
			B[j*ldb+i]=B[j*ldb+i]/A[i*lda+i]; 
		} 
	} 
}

