
void dgemvT(const int M,const int N,const double alpha,const double *A,const int lda,const double *X,const int incX,const double beta,double *Y,const int incY)
{
  int i;
  int j;
/*@; BEGIN(nest1=Nest) @*/
  for (i = 0; i <= -1 + M; i += 1) {
    Y[i] = beta * Y[i];
/*@; BEGIN(nest2=Nest) @*/
    for (j = 0; j <= -1 + N; j += 1) {
      Y[i] += A[i * lda + j] * X[j];
    }
  }
}
