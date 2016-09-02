/*void dgemm_1(double *a,double *b, double *c, double beta, int n) */
void dgemm_1(const int M,const int n,const int K,const double alpha,const double *a,const int lda,const double *b,const int ldb,const double beta,double *c,const int ldc)
{
  int i,j,k;
/*@;BEGIN(Nest1=Nest)@*/  for (j = 0; j < n; j ++)
  for (i = 0; i < n; i ++) 
     c[j*n+i] = beta*c[j*n+i];  
/*@;BEGIN(Nest2=Nest)@*/  for (k = 0; k < n; k ++)
/*@;BEGIN(Nest4=Nest)@*/  for (j = 0; j < n; j ++) 
/*@;BEGIN(Nest3=Nest)@*/  for (i = 0; i < n; i ++) 
    c[j*n+i] += 
           a[k*n+i] * b[j*n+k];
}

