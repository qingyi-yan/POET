
void jacobcalc(double ***x, double ***y, double ***z, long pid, long firstrow, long lastrow, long firstcol, long lastcol)
{
/*@; BEGIN(Nest1=Nest)@*/for (i=firstrow;i<=lastrow;i++) {
     ip1 = i+1;
     im1 = i-1;
     t1a = (double *) t2a[i];
     t1b = (double *) t2b[i];
     t1c = (double *) t2c[i];
     t1d = (double *) t2b[ip1];
     t1e = (double *) t2b[im1];
     t1f = (double *) t2a[ip1];
     t1g = (double *) t2a[im1];
/*@; BEGIN(Nest2=Nest)@*/for (iindex=firstcol;iindex<=lastcol;iindex++) {
       f1 = (t1b[iindex-1]+t1d[iindex-1]-
             t1b[iindex+1]-t1d[iindex+1])*
            (t1f[iindex]-t1a[iindex]);
       f2 = (t1e[iindex-1]+t1b[iindex-1]-
             t1e[iindex+1]-t1b[iindex+1])*
            (t1a[iindex]-t1g[iindex]);
       f3 = (t1d[iindex]+t1d[iindex+1]-
             t1e[iindex]-t1e[iindex+1])*
            (t1a[iindex+1]-t1a[iindex]);
       f4 = (t1d[iindex-1]+t1d[iindex]-
             t1e[iindex-1]-t1e[iindex])*
            (t1a[iindex]-t1a[iindex-1]);
       f5 = (t1d[iindex]-t1b[iindex+1])*
            (t1f[iindex+1]-t1a[iindex]);
       f6 = (t1b[iindex-1]-t1e[iindex])*
            (t1a[iindex]-t1g[iindex-1]);
       f7 = (t1b[iindex+1]-t1e[iindex])*
            (t1g[iindex+1]-t1a[iindex]);
       f8 = (t1d[iindex]-t1b[iindex-1])*
            (t1a[iindex]-t1f[iindex-1]);

/*@; BEGIN(Stmt1=Stmt)@*/t1c[iindex] = factjacob*(f1+f2+f3+f4+f5+f6+f7+f8);
     }
   }
}
