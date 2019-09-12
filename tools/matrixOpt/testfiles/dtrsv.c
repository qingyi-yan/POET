void dtrsv(const int M,const int N,const double alpha,const double *A,const int lda, double *X,const int incX,const double beta,const double *Y,const int incY)
{
   int i,j;
  /*@; BEGIN(nest1=MM_pat[type="double"]) @*/
   for (i = 0; i < M; i += 1)
   {                                                     
     for (j = 0; j < i; j += 1)
     { 							
         X[i] -= A[j*lda+i] * Y[j];
     }      						
	 X[i] = Y[i] / A[i*lda+i];
   } 							
}
