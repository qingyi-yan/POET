
routine=void strmm(int m, int n, float alpha, int lda, int
        ldb, float beta, float *a, float *b)
{
   int i,j,l;
#define arr_ref_b(b,i,j)   b[(i)*ldb+j]
#define arr_ref_a(a,i,j)   a[(i)*lda+j]
   {
    for (j = 0; j < n; j+=1)
        for (i = 0; i < m; i+=1)
            arr_ref_b(b, i,j) = beta*arr_ref_b(b, i,j);
    for (j = 0; j < m; j+=1)
        for (l = 0; l < m; l+=1)
            for (i = 0; i < l; i+=1)
                arr_ref_b(b,i,j)=alpha*arr_ref_b(b, l, j)*arr_ref_a(a, i, l);
    for (j = 0; j < m; j+=1)
        for (l = 0; l < m; l+=1)
            arr_ref_b(b, l, j)=alpha*arr_ref_b(b, l, j);
   }
}


init={ 
m=Macro(MS,200);
n=Macro(NS,200);
lda=m;
ldb=n;
alpha=1.0;
a=Matrix(float, m, m, RANDOM, flush|align(16));
b=Matrix(float, m, n, RANDOM, flush|align(16));
} ; 
returns(b);
flop="m*n+m*m*m/2+m*m";

