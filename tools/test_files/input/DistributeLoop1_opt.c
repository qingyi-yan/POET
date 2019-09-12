#include <stdlib.h>
void test(int n,const double* a,const double* b,double* c,double* d,double* e,double* f) {
   int i;
   
   for (i=0; i<n; i+=1)
     {
        c[i] = a[i]-b[i];
        e[i] = a[i]*c[i];
     }
   for (i=0; i<n; i+=1)
     {
        /*@;BEGIN(ExpStmt1=ExpStmt)@*/d[i] = a[i]*b[i];
        f[i] = f[i]+b[i];
     }
}
