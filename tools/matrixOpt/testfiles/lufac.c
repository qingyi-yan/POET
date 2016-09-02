void lufac(int M, int N, int K, double alpha, double *A, int lda, double *L, int LDB, double beta, double *U, int LDC) {
	int i;
	int j;
	int k;

/*@; BEGIN(nest1=MM_pat[type="double"]) @*/
	for (k=0; k<N; k+=1) {
		for (i=k+1; i<N; i+=1) {
			A[k*N+i] = A[k*N+i]/A[k*N+k];
			for (j=k+1; j<N; j+=1) {
				A[j*N+i] = A[j*N+i] - A[k*N+i] * A[j*N+k];
			}
		}
	}
}
