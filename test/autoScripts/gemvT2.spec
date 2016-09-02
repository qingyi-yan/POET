routine=
void dgemvT(const int M, const int N, const double alpha, const double *A, const int lda, const double *X, const int incX, const double beta, double *Y, const int incY);

init={ 
M=Macro(MS,72);
N=Macro(NS,72);
alpha=1;
A=Matrix(double, M, N, RANDOM,);
lda=MS;
X=Vector(double, N, RANDOM,);
incX=1;
beta=1;
Y=Vector(double, M, 1,);
incY=1;
} ; 

flop="2*M*N+M*N";

