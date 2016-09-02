/* pre-transformations: 1. eliminate pointer arithmetics; 2. normalize loops using index variables */
void vmult_1(const int M,const int N,const double alpha,const double *val,const int n_rows,const double *src,const int incX,const double beta,double *dst,const int incY, int* rowstart, int* col)
{
   int row, j;
   /*@;BEGIN(Nest1=Nest)@*/for (row=0; row<n_rows; ++row) {
      /*@;BEGIN(Nest2=Nest)@*/for (j = rowstart[row]; j < rowstart[row+1]; j++) {
         dst[row] += val[j] * src[col[j]];
      }  
   }
}
