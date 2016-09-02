
routine=
void  dgetrf( int m, int n, double* a, int* p );

init={ 
m=Macro(MS,100);
n=Macro(NS,100);
a=Matrix(double, m, n, RANDOM,);
p=Vector(int, n, 0,);
} ; 

flop="m*n*n/2";
