void dcopy(const int N, const int M, const double alpha, const double *X, const int incx, double *Y, const int incy, double *A, const lda) 
{
	int i;

  /*@; BEGIN(nest1=MM_pat[type="double"]) @*/
	for (i = 0; i < N; i += 1) {
		Y[i] = X[i];
	}
}
