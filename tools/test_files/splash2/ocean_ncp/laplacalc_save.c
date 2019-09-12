void laplacalc(double x[IMAX][JMAX],double z[IMAX][JMAX],long firstrow,long lastrow,long firstcol,long lastcol,long numrows,long numcols) {
   
   /*@;BEGIN(Nest1=Nest)@*/for (i=firstrow; i<1+lastrow; i+=1)
     {
        /*@;BEGIN(Nest2=Nest)@*/for (iindex=firstcol; iindex<1+lastcol; iindex+=1)
          {
             z[i][iindex] = factlap*(x[i+1][iindex]+x[i-1][iindex]+x[i][iindex+1]+x[i][iindex-1]-4.*x[i][iindex]);
          }
     }
}
