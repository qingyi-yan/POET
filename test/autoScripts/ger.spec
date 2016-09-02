include=
#include "./out_dger.c"

routine=
void dger(const int M, const int N,
          const double alpha, const double *X, const int incX,
          const double *Y, const int incY,
          double* A, const int lda)
{

   int i, j;

   for (j = 0; j < N; j += 1)
   {
     for (i = 0; i < M; i += 1)
      {
         A[j*lda+i] = A[j*lda+i] + X[i] * Y[j*incY];
      }
   }
}

init={ 
M=Macro(MS,72);
N=Macro(NS,72);
alpha=1;
A=Matrix(double, M, N, 2,);
lda=MS;
Y=Vector(double, N, RANDOM,);
incX=1;
X=Vector(double, M, RANDOM,);
incY=1;
} ; 

returns(A);
