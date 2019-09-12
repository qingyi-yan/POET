#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#include <omp.h>

void dgemvN(const int M,const int N,const double alpha,const double* A,const int lda,const double* X,const int incX,const double beta,double* Y,const int incY) {
   int i;int j;
   int i_bk_1;
   int i_bk_2;
   int j_bk_3;
   omp_set_num_threads(2);
   #pragma omp  parallel  
    {
    /*@;BEGIN(nest1_group3=Nest)@*/#pragma omp  for private(i,j,i_bk_1,i_bk_2,j_bk_3)
    for (i_bk_1=0; i_bk_1<M; i_bk_1+=256)
      {
         /*@;BEGIN(nest1_group2=Nest)@*/for (i_bk_2=0; i_bk_2<-31+min(256,M-i_bk_1); i_bk_2+=32)
           {
              if ((j_bk_3=0)<-31+N) 
                {
                   for (i=0; i<32; i+=2)
                     {
                        j = 0;
                          {
                             Y[i_bk_1+(i_bk_2+i)] = beta*Y[i_bk_1+(i_bk_2+i)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = beta*Y[i_bk_1+(i_bk_2+(1+i))];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda))))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda)))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda)))))]*X[j_bk_3+(2+j)];
                          }
                        for (j=3; j<32; j+=3)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda))))]*X[j_bk_3+j];
                             /*Unroll Check*/if (1+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                                  Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda)))))]*X[j_bk_3+(1+j)];
                               }
                             /*Unroll Check*/if (2+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                                  Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda)))))]*X[j_bk_3+(2+j)];
                               }
                          }
                     }
                }
              /*@;BEGIN(nest2_group2=Nest)@*/for (j_bk_3=32; j_bk_3<-31+N; j_bk_3+=32)
                {
                   /*@;BEGIN(nest1=Nest)@*/for (i=0; i<32; i+=2)
                     {
                        /*@;BEGIN(nest2=Nest)@*/for (j=0; j<32; j+=3)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda))))]*X[j_bk_3+j];
                             /*Unroll Check*/if (1+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                                  Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda)))))]*X[j_bk_3+(1+j)];
                               }
                             /*Unroll Check*/if (2+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                                  Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda)))))]*X[j_bk_3+(2+j)];
                               }
                          }
                     }
                }
              if (j_bk_3<N) 
                {
                   for (i=0; i<32; i+=2)
                     {
                        for (j=0; j<N-j_bk_3; j+=1)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+(1+i))] = Y[i_bk_1+(i_bk_2+(1+i))]+A[i+(1+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda))))]*X[j_bk_3+j];
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
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                          }
                        for (j=3; j<32; j+=3)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             /*Unroll Check*/if (1+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                               }
                             /*Unroll Check*/if (2+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                               }
                          }
                     }
                }
              for (j_bk_3=32; j_bk_3<-31+N; j_bk_3+=32)
                {
                   for (i=0; i<min(256-i_bk_2,-i_bk_2+(M-i_bk_1)); i+=1)
                     {
                        for (j=0; j<32; j+=3)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                             /*Unroll Check*/if (1+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(lda+j*lda))))]*X[j_bk_3+(1+j)];
                               }
                             /*Unroll Check*/if (2+j<32) 
                               {
                                  Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+(2*lda+j*lda))))]*X[j_bk_3+(2+j)];
                               }
                          }
                     }
                }
              if (j_bk_3<N) 
                {
                   for (i=0; i<min(256-i_bk_2,-i_bk_2+(M-i_bk_1)); i+=1)
                     {
                        for (j=0; j<N-j_bk_3; j+=1)
                          {
                             Y[i_bk_1+(i_bk_2+i)] = Y[i_bk_1+(i_bk_2+i)]+A[i+(i_bk_2+(i_bk_1+(j_bk_3*lda+j*lda)))]*X[j_bk_3+j];
                          }
                     }
                }
           }
      }
    }
   
}
