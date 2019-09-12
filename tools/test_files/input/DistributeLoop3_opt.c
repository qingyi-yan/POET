#include <stdlib.h>
void test(int n,const double* a,const double* b,double* c,double* d,double* e,double* f) {
   double temp1;double temp2;
   int i;
   
   double* temp2_array;
   temp2_array=(double*)malloc((n-0)*sizeof(double));
   double* temp1_array;
   temp1_array=(double*)malloc((n-0)*sizeof(double));
   for (i=0; i<n; i+=1)
     {
        c[i] = a[i]-b[i];
        e[i] = a[i]*c[i];
        temp1 = a[i]/e[i];
        temp2 = a[i]+e[i];
        temp1_array[i] = temp1;
        temp2_array[i] = temp2;
     }
   for (i=0; i<n; i+=1)
     {
        temp1 = temp1_array[i];
        temp2 = temp2_array[i];
        /*@;BEGIN(ExpStmt1=ExpStmt)@*/d[i] = temp1*b[i];
        f[i] = temp2/c[i];
     }
   free(temp1_array);
   free(temp2_array);
}
