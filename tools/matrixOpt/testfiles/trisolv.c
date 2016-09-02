
void trisolv(const int M,const int N,const int K,const double alpha,const double *L,const int lda,const double *B1,const int ldb1,const double beta,double *B,const int ldb)
{
    long i,j,k;

/*@; BEGIN(nest1=MM_pat[type="double"]) @*/
    for (i=0;i<N;i++) {
        for (j=0;j<N;j++) {
            for (k=0;k<j;k++) {
                B[j*ldb+i]=B[j*ldb+i]-L[j*lda+k]*B[k*ldb+i];  
            }
            B[j*ldb+i]=B[j*ldb+i]/L[j*lda+j]; 
        } 
    } 
}

