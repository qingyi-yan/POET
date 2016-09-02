routine=
void dger(const int M, const int N,
          const double alpha, const double *X, const int incX,
          const double *Y, const int incY,
          double* A, const int lda);

init={ 
M=Macro(MS,72);
N=Macro(NS,72);
alpha=1;
A=Matrix(double, M, N, 0,);
lda=MS;
Y=Vector(double, N, RANDOM,);
incX=1;
X=Vector(double, M, RANDOM,);
incY=1;
} ; 

flop="2*M*N";

