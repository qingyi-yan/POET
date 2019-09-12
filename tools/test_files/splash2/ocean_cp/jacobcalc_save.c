#include <stdlib.h>
void jacobcalc(double*** x,double*** y,double*** z,long pid,long firstrow,long lastrow,long firstcol,long lastcol) {
   double _t1b_cp_0;
   double _t1b_cp_1_0;
   double _t1d_cp_0;
   double _t1d_cp_1_0;
   double _t1d_cp_2_0;
   double _t1a_cp_0;
   double _t1e_cp_0;
   double _t1e_cp_1_0;
   double _t1e_cp_2_0;
   double* t1c_array;
   t1c_array=(double*)malloc((1+lastcol-firstcol)*sizeof(double));
   /*@;BEGIN(Nest1=Nest)@*/for (i=firstrow; i<1+lastrow; i+=1)
     {
        ip1 = i+1;
        im1 = i-1;
        t1a = (double*)(t2a[i]);
        t1b = (double*)(t2b[i]);
        t1c = (double*)(t2c[i]);
        t1d = (double*)(t2b[ip1]);
        t1e = (double*)(t2b[im1]);
        t1f = (double*)(t2a[ip1]);
        t1g = (double*)(t2a[im1]);
        for (iindex=firstcol; iindex<1+lastcol; iindex+=1)
          {
             _t1e_cp_2_0 = t1e[1+iindex];
             _t1e_cp_1_0 = t1e[iindex];
             _t1e_cp_0 = t1e[-1+iindex];
             _t1a_cp_0 = t1a[iindex];
             _t1d_cp_2_0 = t1d[1+iindex];
             _t1d_cp_1_0 = t1d[iindex];
             _t1d_cp_0 = t1d[-1+iindex];
             _t1b_cp_1_0 = t1b[1+iindex];
             _t1b_cp_0 = t1b[-1+iindex];
             f1 = (_t1b_cp_0+_t1d_cp_0-_t1b_cp_1_0-_t1d_cp_2_0)*(t1f[iindex]-_t1a_cp_0);
             f2 = (_t1e_cp_0+_t1b_cp_0-_t1e_cp_2_0-_t1b_cp_1_0)*(_t1a_cp_0-t1g[iindex]);
             f3 = (_t1d_cp_1_0+_t1d_cp_2_0-_t1e_cp_1_0-_t1e_cp_2_0)*(t1a[iindex+1]-_t1a_cp_0);
             f4 = (_t1d_cp_0+_t1d_cp_1_0-_t1e_cp_0-_t1e_cp_1_0)*(_t1a_cp_0-t1a[iindex-1]);
             f5 = (_t1d_cp_1_0-_t1b_cp_1_0)*(t1f[iindex+1]-_t1a_cp_0);
             f6 = (_t1b_cp_0-_t1e_cp_1_0)*(_t1a_cp_0-t1g[iindex-1]);
             f7 = (_t1b_cp_1_0-_t1e_cp_1_0)*(t1g[iindex+1]-_t1a_cp_0);
             f8 = (_t1d_cp_1_0-_t1b_cp_0)*(_t1a_cp_0-t1f[iindex-1]);
             t1c_array[iindex] = factjacob*(f1+f2+f3+f4+f5+f6+f7+f8);
          }
        for (iindex=firstcol; iindex<1+lastcol; iindex+=1)
          {
             t1c[iindex] = t1c_array[iindex];
          }
     }
   free(t1c_array);
}
