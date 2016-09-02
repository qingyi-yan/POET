
void dger(const int M,const int N,const double alpha,const double *X,const int incX,const double *Y,const int incY,double *A,const int lda)
{
  int i;
  int j;
  /*@; BEGIN(nest1=MM_pat[type="double"]) @*/
  for (j = 0; j <= -1 + N; j += 1) {
    for (i = 0; i <= -1 + M; i += 1) {
      A[(j * lda) + i] = (A[(j * lda) + i] + (X[i] * Y[j * incY]));
    }
  }
}
