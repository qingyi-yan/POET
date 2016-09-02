
routine=void ATL_dgemvN_a1_x1_bX_y1(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) ;

init={
M=Macro(MS,100);
N=Macro(NS,100);
lda=MS;
alpha=1;
beta=1;
incX=1;
incY=1;
A=Matrix(double, M, N, RANDOM, flush);
X=Vector(double, RANDOM, flush,M);
Y=Vector(double, 0, flush,M);
} ;
returns(Y);

flop="2*M*N + M";
