void dswap(const int N, const int M, const double alpha, double *X, const int incx, double *Y, const int incy, double *A, const lda) 
{
	int i;
	double tmp;

  /*@; BEGIN(nest1=MM_pat[type="double"]) @*/
	for (i = 0; i < N; i += 1) {
		tmp = Y[i];
		Y[i] = X[i];
		X[i] = tmp;
	}
}
