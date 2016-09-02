include=
#define arr_ref(a,i,j) a[(i)*NS+(j)]
#include "./out_dgetrf.c"

routine=
void  dgetrf( int m, int n, double* a, int* p )
{
       double tmp, tmp1;
      int j, i, k;

      for (k = 0; k <  min( m-1, n-1 ); ++k) {
         p[k] = k;
         tmp = dabs(arr_ref(a, k,k));
         for (i = k+1; i < m; ++i) {
           if (dabs(arr_ref(a, i,k)) > tmp) {
             p[k] = i;
             tmp = dabs(arr_ref(a, i,k));
           }
         }
           for (j = k; j < n; ++j) {
                 tmp1 = arr_ref(a, k, j);
                 arr_ref(a, k,j) = arr_ref(a, p[k], j);
                 arr_ref(a, p[k], j) = tmp1;
           }
           for (i = k+1; i < m; ++i)
               arr_ref(a, i,k) = arr_ref(a, i,k) / arr_ref(a, k,k);

           for (j = k+1; j < n; ++j)
              for (i = k+1; i < m; ++i)
                arr_ref(a, i,j) = arr_ref(a, i,j) - arr_ref(a, i,k) * arr_ref(a, k,j);
       }
}


init={ 
m=Macro(MS,100);
n=Macro(NS,100);
a=Matrix(double, m, n, RANDOM,);
p=Vector(int, n, 0,);
} ; 

returns(a);
