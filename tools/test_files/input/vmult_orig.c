void vmult_2(const int M,const int N,const double alpha,const double *val,const int n_rows,const double *src,const int incX,const double beta,double *dst,const int incY, int* rowstart, int* col)
{
   int row;
   double *val_ptr = val + rowstart[row];
   int *col_ptr = col+rowstart[row];
   /*@;BEGIN(Nest1=Nest)@*/for (row=0; row<n_rows; ++row) {
      double s = *dst;
      double * val_end_of_row = val+rowstart[row+1];
      while (val_ptr != val_end_of_row) {
         s += (*val_ptr++) * src[*col_ptr++];
      }
      *dst++ = s;
   }  
}
