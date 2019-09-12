#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#include <omp.h>

#define _NB_1 1
void dger(const int M,const int N,const double alpha,const double* X,const int incX,const double* Y,const int incY,double* A,const int lda) {
   int i;
   int j;
   int j_bk_1;
   int j_bk_2;
   int i_bk_3;
   double _X_cp_0;
   double _Y_cp_0;
   double _Y_cp_1;
   double _Y_cp_2;
   double _Y_cp_3;
   omp_set_num_threads(16);
   #pragma omp  parallel  
    {
    /*@;BEGIN(nest1_group3=Nest)@*/#pragma omp  for private(i,j,j_bk_1,j_bk_2,i_bk_3,_X_cp_0,_Y_cp_0,_Y_cp_1,_Y_cp_2,_Y_cp_3)
    for (j_bk_1=0; j_bk_1<N; j_bk_1+=_NB_1)
      {
         /*@;BEGIN(nest1_group2=Nest)@*/for (j_bk_2=0; j_bk_2<-31+min(_NB_1,N-j_bk_1); j_bk_2+=32)
           {
              /*@;BEGIN(nest2_group2=Nest)@*/for (i_bk_3=0; i_bk_3<-31+M; i_bk_3+=32)
                {
                   /*@;BEGIN(nest1=Nest)@*/for (j=0; j<32; j+=4)
                     {
                        _Y_cp_0 = Y[j_bk_1*incY+(j_bk_2*incY+j*incY)];
                        _Y_cp_1 = Y[j_bk_1*incY+(j_bk_2*incY+(incY+j*incY))];
                        _Y_cp_2 = Y[j_bk_1*incY+(j_bk_2*incY+(2*incY+j*incY))];
                        _Y_cp_3 = Y[j_bk_1*incY+(j_bk_2*incY+(3*incY+j*incY))];
                        /*@;BEGIN(nest2=Nest)@*/for (i=0; i<32; i+=4)
                          {
                             _X_cp_0 = X[i_bk_3+i];
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))]+_X_cp_0*_Y_cp_0;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(lda+j*lda))))]+_X_cp_0*_Y_cp_1;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(2*lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(2*lda+j*lda))))]+_X_cp_0*_Y_cp_2;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(3*lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(3*lda+j*lda))))]+_X_cp_0*_Y_cp_3;
                             _X_cp_0 = X[i_bk_3+(1+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i))))]+_X_cp_0*_Y_cp_0;
                             A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))] = A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))]+_X_cp_0*_Y_cp_1;
                             A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))] = A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))]+_X_cp_0*_Y_cp_2;
                             A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))] = A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i)))))]+_X_cp_0*_Y_cp_3;
                             _X_cp_0 = X[i_bk_3+(2+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i))))]+_X_cp_0*_Y_cp_0;
                             A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))] = A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))]+_X_cp_0*_Y_cp_1;
                             A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))] = A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))]+_X_cp_0*_Y_cp_2;
                             A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))] = A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i)))))]+_X_cp_0*_Y_cp_3;
                             _X_cp_0 = X[i_bk_3+(3+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i))))]+_X_cp_0*_Y_cp_0;
                             A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))] = A[j*lda+(lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))]+_X_cp_0*_Y_cp_1;
                             A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))] = A[j*lda+(2*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))]+_X_cp_0*_Y_cp_2;
                             A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))] = A[j*lda+(3*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i)))))]+_X_cp_0*_Y_cp_3;
                          }
                     }
                }
              if (i_bk_3<M) 
                {
                   for (j=0; j<32; j+=4)
                     {
                        _Y_cp_0 = Y[j_bk_1*incY+(j_bk_2*incY+j*incY)];
                        _Y_cp_1 = Y[j_bk_1*incY+(j_bk_2*incY+(incY+j*incY))];
                        _Y_cp_2 = Y[j_bk_1*incY+(j_bk_2*incY+(2*incY+j*incY))];
                        _Y_cp_3 = Y[j_bk_1*incY+(j_bk_2*incY+(3*incY+j*incY))];
                        for (i=0; i<M-i_bk_3; i+=1)
                          {
                             _X_cp_0 = X[i_bk_3+i];
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))]+_X_cp_0*_Y_cp_0;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(lda+j*lda))))]+_X_cp_0*_Y_cp_1;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(2*lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(2*lda+j*lda))))]+_X_cp_0*_Y_cp_2;
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(3*lda+j*lda))))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+(3*lda+j*lda))))]+_X_cp_0*_Y_cp_3;
                          }
                     }
                }
           }
         if (j_bk_2<min(_NB_1,N-j_bk_1)) 
           {
              for (i_bk_3=0; i_bk_3<-31+M; i_bk_3+=32)
                {
                   for (j=0; j<min(_NB_1-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                     {
                        _Y_cp_0 = Y[j_bk_1*incY+(j_bk_2*incY+j*incY)];
                        for (i=0; i<32; i+=4)
                          {
                             _X_cp_0 = X[i_bk_3+i];
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))]+_X_cp_0*_Y_cp_0;
                             _X_cp_0 = X[i_bk_3+(1+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(1+i))))]+_X_cp_0*_Y_cp_0;
                             _X_cp_0 = X[i_bk_3+(2+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(2+i))))]+_X_cp_0*_Y_cp_0;
                             _X_cp_0 = X[i_bk_3+(3+i)];
                             A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i))))] = A[j*lda+(j_bk_2*lda+(j_bk_1*lda+(i_bk_3+(3+i))))]+_X_cp_0*_Y_cp_0;
                          }
                     }
                }
              if (i_bk_3<M) 
                {
                   for (j=0; j<min(_NB_1-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                     {
                        _Y_cp_0 = Y[j_bk_1*incY+(j_bk_2*incY+j*incY)];
                        for (i=0; i<M-i_bk_3; i+=1)
                          {
                             _X_cp_0 = X[i_bk_3+i];
                             A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))] = A[i+(i_bk_3+(j_bk_1*lda+(j_bk_2*lda+j*lda)))]+_X_cp_0*_Y_cp_0;
                          }
                     }
                }
           }
      }
    }
   
}
