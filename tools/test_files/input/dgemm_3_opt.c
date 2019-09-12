
#include <SSE3Dnow.h>

void dgemm_test(const int M,const int N,const int K,const double alpha,const double* A,const int lda,const double* B,const int ldb,const double beta,double* C,const int ldc) {
   int i;
   int j;
   int l;
   
   /*@;BEGIN(nest1=Nest)@*/for (j=0; j<N; j+=1)
     {
        vec_splat(&beta,reg4);
        vec_splat(&alpha,reg2);
        /*@;BEGIN(nest3=Nest)@*/for (i=0; i<M; i+=1)
          {
             vec_mov_mr_1(C+(j*ldc+i),reg6);
             vec_mul_rr(reg4,reg6);
             vec_red(reg6,reg7);
             vec_mov_rm_1(reg6,C+(j*ldc+i));
             /*@;BEGIN(nest2=Nest)@*/for (l=0; l<-1+K; l+=2)
               {
                  vec_mov_mr_1(C+(j*ldc+i),reg6);
                  vec_mov_mr(A+(l+lda*i),reg0);
                  vec_mul_rr(reg2,reg0);
                  vec_mov_rr(reg0,reg3);
                  vec_mov_mr(B+(j*ldb+l),reg1);
                  vec_mul_rr(reg3,reg1);
                  vec_add_rr(reg1,reg6);
                  vec_red(reg6,reg7);
                  vec_mov_rm_1(reg6,C+(j*ldc+i));
               }
             for (l=l; l<K; l+=1)
               {
                  vec_mov_mr_1(C+(j*ldc+i),reg6);
                  vec_mov_mr_1(A+(l+lda*i),reg0);
                  vec_mul_rr(reg2,reg0);
                  vec_mov_rr(reg0,reg3);
                  vec_mov_mr_1(B+(j*ldb+l),reg1);
                  vec_mul_rr(reg3,reg1);
                  vec_add_rr(reg1,reg6);
                  vec_red(reg6,reg7);
                  vec_mov_rm_1(reg6,C+(j*ldc+i));
               }
          }
     }
}
