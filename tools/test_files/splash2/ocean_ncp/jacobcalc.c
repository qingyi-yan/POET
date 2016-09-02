
void jacobcalc(double x[IMAX][JMAX], double y[IMAX][JMAX], double z[IMAX][JMAX], long pid, long firstrow, long lastrow, long firstcol, long lastcol, long numrows, long numcols)
{
/*@;BEGIN(Nest1=Nest)@*/for (iindex=firstcol;iindex<=lastcol;iindex++) {
/*@;BEGIN(Nest2=Nest)@*/  for (i=firstrow;i<=lastrow;i++) {
       f1 = (y[i][iindex-1]+y[i+1][iindex-1]-y[i][iindex+1]-y[i+1][iindex+1])*
            (x[i+1][iindex]-x[i][iindex]);
       f2 = (y[i-1][iindex-1]+y[i][iindex-1]-y[i-1][iindex+1]-y[i][iindex+1])*
            (x[i][iindex]-x[i-1][iindex]);
       f3 = (y[i+1][iindex]+y[i+1][iindex+1]-y[i-1][iindex]-y[i-1][iindex+1])*
            (x[i][iindex+1]-x[i][iindex]);
       f4 = (y[i+1][iindex-1]+y[i+1][iindex]-y[i-1][iindex-1]-y[i-1][iindex])*
            (x[i][iindex]-x[i][iindex-1]);
       f5 = (y[i+1][iindex]-y[i][iindex+1])*(x[i+1][iindex+1]-x[i][iindex]);
       f6 = (y[i][iindex-1]-y[i-1][iindex])*(x[i][iindex]-x[i-1][iindex-1]);
       f7 = (y[i][iindex+1]-y[i-1][iindex])*(x[i-1][iindex+1]-x[i][iindex]);
       f8 = (y[i+1][iindex]-y[i][iindex-1])*(x[i][iindex]-x[i+1][iindex-1]);

       z[i][iindex] = factjacob*(f1+f2+f3+f4+f5+f6+f7+f8);
     }
   }
}
