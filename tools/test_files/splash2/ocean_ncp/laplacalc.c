
void laplacalc(double x[IMAX][JMAX], double z[IMAX][JMAX], long firstrow, long lastrow, long firstcol, long lastcol, long numrows, long numcols)
{
/*@;BEGIN(Nest1=Nest)@*/for (iindex=firstcol;iindex<=lastcol;iindex++) {
/*@;BEGIN(Nest2=Nest)@*/  for (i=firstrow;i<=lastrow;i++) {
       z[i][iindex] = factlap*(x[i+1][iindex]+x[i-1][iindex]+x[i][iindex+1]+
                              x[i][iindex-1]-4.*x[i][iindex]);
     }
   }
}
