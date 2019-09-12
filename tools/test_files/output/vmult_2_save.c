#define _TH_1 2
#include <omp.h>

void vmult_2(const int M,const int N,const double alpha,const double* val,const int n_rows,const double* src,const int incX,const double beta,double* dst,const int incY,int* rowstart,int* col) {
   int row;
   
   omp_set_num_threads(_TH_1);
   #pragma omp  parallel  
    {
    /*@;BEGIN(Nest1=Nest)@*/#pragma omp  for private(row)
    for (row=0; row<n_rows; row+=1)
      {
         double* val_ptr=val+rowstart[row];
         int* col_ptr=col+rowstart[row];
         double s=dst[row];
         double* val_end_of_row=val+rowstart[row+1];
         while (val_ptr!=val_end_of_row)
           {
              s = s+*val_ptr++*src[*col_ptr++];
           }
         dst[row] = s;
      }
    }
   
}
