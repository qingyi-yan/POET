#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#define _TH_1 2
#include <omp.h>

void dgemm_test(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) {
   int i;
   int j;
   int l;
   int j_bk_1;
   int j_bk_2;
   int i_bk_3;
   int l_bk_4;
   double _C_cp_0_0;
   double _C_cp_1_0;
   double _C_cp_2_0;
   double _C_cp_3_0;
   double _A_cp_0_0;
   double _B_cp_0_0;
   double _B_cp_1_0;
   double _B_cp_2_0;
   double _B_cp_3_0;
   omp_set_num_threads(_TH_1);
   #pragma omp  parallel  
    {
    /*@;BEGIN(nest1_group3=Nest)@*/#pragma omp  for private(l,i,j,j_bk_1,j_bk_2,i_bk_3,l_bk_4,_C_cp_0_0,_C_cp_1_0,_C_cp_2_0,_C_cp_3_0,_A_cp_0_0,_B_cp_0_0,_B_cp_1_0,_B_cp_2_0,_B_cp_3_0)
    for (j_bk_1=0; j_bk_1<N; j_bk_1+=256)
      {
         /*@;BEGIN(nest1_group2=Nest)@*/for (j_bk_2=0; j_bk_2<-31+min(256,N-j_bk_1); j_bk_2+=32)
           {
              for (i_bk_3=0; i_bk_3<-31+M; i_bk_3+=32)
                {
                   if ((l_bk_4=0)<-31+K) 
                     {
                        for (j=0; j<32; j+=4)
                          {
                             for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  l = 0;
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = beta*_C_cp_0_0;
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = beta*_C_cp_1_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = beta*_C_cp_2_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = beta*_C_cp_3_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  for (l=1; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                   for (l_bk_4=32; l_bk_4<-31+K; l_bk_4+=32)
                     {
                        /*@;BEGIN(nest1=Nest)@*/for (j=0; j<32; j+=4)
                          {
                             /*@;BEGIN(nest3=Nest)@*/for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  /*@;BEGIN(nest2=Nest)@*/for (l=0; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                   if (l_bk_4<K) 
                     {
                        for (j=0; j<32; j+=4)
                          {
                             for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  for (l=0; l<K-l_bk_4; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                }
              if (i_bk_3<M) 
                {
                   if ((l_bk_4=0)<-31+K) 
                     {
                        for (j=0; j<32; j+=4)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  l = 0;
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = beta*_C_cp_0_0;
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = beta*_C_cp_1_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = beta*_C_cp_2_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = beta*_C_cp_3_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  for (l=1; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                   for (l_bk_4=32; l_bk_4<-31+K; l_bk_4+=32)
                     {
                        for (j=0; j<32; j+=4)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  for (l=0; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                   if (l_bk_4<K) 
                     {
                        for (j=0; j<32; j+=4)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  _C_cp_1_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))];
                                  _C_cp_2_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))];
                                  _C_cp_3_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))];
                                  for (l=0; l<K-l_bk_4; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _B_cp_1_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+ldb))))];
                                       _B_cp_2_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+2*ldb))))];
                                       _B_cp_3_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+(j*ldb+3*ldb))))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                       _C_cp_1_0 = _C_cp_1_0+alpha*_A_cp_0_0*_B_cp_1_0;
                                       _C_cp_2_0 = _C_cp_2_0+alpha*_A_cp_0_0*_B_cp_2_0;
                                       _C_cp_3_0 = _C_cp_3_0+alpha*_A_cp_0_0*_B_cp_3_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+ldc))))] = _C_cp_1_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+2*ldc))))] = _C_cp_2_0;
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+(j*ldc+3*ldc))))] = _C_cp_3_0;
                               }
                          }
                     }
                }
           }
         if (j_bk_2<min(256,N-j_bk_1)) 
           {
              for (i_bk_3=0; i_bk_3<-31+M; i_bk_3+=32)
                {
                   if ((l_bk_4=0)<-31+K) 
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  l = 0;
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = beta*_C_cp_0_0;
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  for (l=1; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                   for (l_bk_4=32; l_bk_4<-31+K; l_bk_4+=32)
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  for (l=0; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                   if (l_bk_4<K) 
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<32; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  for (l=0; l<K-l_bk_4; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                }
              if (i_bk_3<M) 
                {
                   if ((l_bk_4=0)<-31+K) 
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  l = 0;
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = beta*_C_cp_0_0;
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  for (l=1; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                   for (l_bk_4=32; l_bk_4<-31+K; l_bk_4+=32)
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  for (l=0; l<32; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                   if (l_bk_4<K) 
                     {
                        for (j=0; j<min(256-j_bk_2,-j_bk_2+(N-j_bk_1)); j+=1)
                          {
                             for (i=0; i<M-i_bk_3; i+=1)
                               {
                                  _C_cp_0_0 = C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))];
                                  for (l=0; l<K-l_bk_4; l+=1)
                                    {
                                       _B_cp_0_0 = B[l+(l_bk_4+(j_bk_1*ldb+(j_bk_2*ldb+j*ldb)))];
                                       _A_cp_0_0 = A[i+(i_bk_3+(l_bk_4*lda+l*lda))];
                                       _C_cp_0_0 = _C_cp_0_0+alpha*_A_cp_0_0*_B_cp_0_0;
                                    }
                                  C[i+(i_bk_3+(j_bk_1*ldc+(j_bk_2*ldc+j*ldc)))] = _C_cp_0_0;
                               }
                          }
                     }
                }
           }
      }
    }
   
}
