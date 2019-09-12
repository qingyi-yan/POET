#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#define _TH_1 2
#include <omp.h>

void dgemvT(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) {
   int i;
   int j;
   int i_bk_1;
   int i_bk_2;
   int j_bk_3;
   omp_set_num_threads(_TH_1);
   #pragma omp  parallel  
    {
    /*@;BEGIN(nest1_group3=Nest)@*/#pragma omp  for private(i,j,i_bk_1,i_bk_2,j_bk_3)
    for (i_bk_1=0; i_bk_1<M; i_bk_1+=256)
      {
         /*@;BEGIN(nest1_group2=Nest)@*/for (i_bk_2=0; i_bk_2<-31+min(256,M-i_bk_1); i_bk_2+=32)
           {
              if ((j_bk_3=0)<-31+N) 
                {
                   for (i=0; i<32; i+=4)
                     {
                        j = 0;
                          {
                             Y[i_bk_1+(i_bk_2+i)] = beta*Y[i_bk_1+(i_bk_2+i)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = beta*Y[i_bk_1+(i_bk_2+(1+i))];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(2+i))] = beta*Y[i_bk_1+(i_bk_2+(2+i))];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(2*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(3+i))] = beta*Y[i_bk_1+(i_bk_2+(3+i))];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(3*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                          }
                        for (j=4; j<32; j+=4)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(2*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(3*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                          }
                     }
                }
              /*@;BEGIN(nest2_group2=Nest)@*/for (j_bk_3=32; j_bk_3<-31+N; j_bk_3+=32)
                {
                   /*@;BEGIN(nest1=Nest)@*/for (i=0; i<32; i+=4)
                     {
                        /*@;BEGIN(nest2=Nest)@*/for (j=0; j<32; j+=4)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(2*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(3*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j)))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i*lda+(lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[i*lda+(2*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[i*lda+(3*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j)))))]*X[j_bk_3+(3+j)];
                          }
                     }
                }
              if (j_bk_3<N) 
                {
                   for (i=0; i<32; i+=4)
                     {
                        for (j=0; j<N-j_bk_3; j+=1)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(2+i))] = Y[i_bk_1+(i_bk_2+(2+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(2*lda+i*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(3+i))] = Y[i_bk_1+(i_bk_2+(3+i))]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+(3*lda+i*lda))))]*X[j_bk_3+j];
                          }
                     }
                }
           }
         if (i_bk_2<min(256,M-i_bk_1)) 
           {
              if ((j_bk_3=0)<-31+N) 
                {
                   for (i=0; i<min(256-i_bk_2,-i_bk_2+(M-i_bk_1)); i+=1)
                     {
                        j = 0;
                          {
                             Y[i_bk_1+(i_bk_2+i)] = beta*Y[i_bk_1+(i_bk_2+i)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                          }
                        for (j=4; j<32; j+=4)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                          }
                     }
                }
              for (j_bk_3=32; j_bk_3<-31+N; j_bk_3+=32)
                {
                   for (i=0; i<min(256-i_bk_2,-i_bk_2+(M-i_bk_1)); i+=1)
                     {
                        for (j=0; j<32; j+=4)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(1+j))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(2+j))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i*lda+(i_bk_2*lda+(i_bk_1*lda+(j_bk_3+(3+j))))]*X[j_bk_3+(3+j)];
                          }
                     }
                }
              if (j_bk_3<N) 
                {
                   for (i=0; i<min(256-i_bk_2,-i_bk_2+(M-i_bk_1)); i+=1)
                     {
                        for (j=0; j<N-j_bk_3; j+=1)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[j+(j_bk_3+(i_bk_1*lda+(i_bk_2*lda+i*lda)))]*X[j_bk_3+j];
                          }
                     }
                }
           }
      }
    }
   
}
