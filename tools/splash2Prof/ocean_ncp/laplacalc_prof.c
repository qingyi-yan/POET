void laplacalc(double x[IMAX][JMAX],double z[IMAX][JMAX],long  firstrow,long  lastrow,long  firstcol,long  lastcol,long  numrows,long  numcols) {
   {
       if ((&x[0][0] >= &z[0][0] && &x[0][0] <= &z[IMAX][JMAX]) ||
           (&x[IMAX][JMAX] >= &z[0][0] && &x[IMAX][JMAX] <= &z[IMAX][JMAX]) ||
           (&z[0][0] >= &x[0][0] && &z[0][0] <= &x[IMAX][JMAX]) ||
           (&z[IMAX][JMAX] >= &x[0][0] && &z[IMAX][JMAX] <= &x[IMAX][JMAX])) {
           printf("[Profile Conflict] Array Overlap. Array1: x, Array2: z\n");
           exit(-1);
       }
   }
   
   for (iindex=firstcol; iindex<1+lastcol; iindex+=1) 
     {
        
        for (i=firstrow; i<1+lastrow; i+=1) 
          {
             z[i][iindex] = factlap*(x[i+1][iindex]+x[i-1][iindex]+x[i][iindex+1]+x[i][iindex-1]-4.*x[i][iindex]);
          }
     }
}
void main() {
   printf("\n\n=============================================\n\n");
   printf("Profiling Information:\n\n");
   printf("[Func Para] No overlap between two arrays x and z in function laplacalc\n");
   printf("\n=============================================\n\n\n");
}
