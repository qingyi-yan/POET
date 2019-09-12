#define _TH_1 2
#include <omp.h>

void vmult_1(const int M,const int N,const double alpha,const double* val,const int n_rows,const double* src,const int incX,const double beta,double* dst,const int incY,int* rowstart,int* col) {
   int row;int j;
   /*@;BEGIN(_decl1=DeclStmt)@*/double _dst_cp_0;
   omp_set_num_threads(_TH_1);
   #pragma omp  parallel  
    {
    /*@;BEGIN(Nest1=Nest)@*/#pragma omp  for private(row,j,_dst_cp_0)
    for (row=0; row<n_rows; row+=1)
      {
         _dst_cp_0 = dst[row];
         /*@;BEGIN(Nest2=Nest)@*/for (j=rowstart[row]; j<rowstart[row+1]; j+=1)
           {
              _dst_cp_0 = _dst_cp_0+val[j]*src[col[j]];
           }
         dst[row] = _dst_cp_0;
      }
    }
   
}
