
routine = void ATL_dger1_a1_x1_yX(const int M,const int N,const double alpha,const double* X,const int incX,const double* Y,const int incY,double* A,const int lda) ;

init = {
M = Macro(MS,100);
N = Macro(NS,100);
lda = M;
incY = 1;
incX = 1;
alpha = 1;
X = Vector(double, RANDOM, flush, M);
Y = Vector(double, RANDOM, flush, N);
A = Matrix(double, M, N, RANDOM, flush);
};

flop = "2*M*N";

