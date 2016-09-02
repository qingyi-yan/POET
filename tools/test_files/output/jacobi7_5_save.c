#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#define _NB_2 1
#define _TH_1 2
#include <omp.h>

#define _NB_1 1
#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
void jacobi7(const int nx,const int ny,int nz,const double alpha,double* A0,const int timesteps,const double* B,const int ldb,double* Anext,const int ldc) {
   double fac;
   double* temp_ptr;
   int i;int j;int k;int t;
   fac = 6.0/(A0[0]*A0[0]);
   int k_bk_1;
   int k_bk_2;
   /*@;BEGIN(Nest1=Nest)@*/for (t=0; t<timesteps; t+=1) 
     {
        omp_set_num_threads(_TH_1);
        #pragma omp  parallel  
         {
         /*@;BEGIN(Nest2_group3=Nest)@*/#pragma omp  for private(k,j,i,k_bk_1,k_bk_2)
         for (k_bk_1=1; k_bk_1<nz-1; k_bk_1+=_NB_1) 
           {
              /*@;BEGIN(Nest2=Nest)@*/for (k_bk_2=0; k_bk_2<min(_NB_1,-k_bk_1+(-1+nz)); k_bk_2+=_NB_2) 
                {
                   for (k=0; k<min(_NB_2,min(_NB_1-k_bk_2,-k_bk_2+(-k_bk_1+(-1+nz)))); k+=1) 
                     {
                        /*@;BEGIN(Nest3=Nest)@*/for (j=1; j<-1+ny; j+=1) 
                          {
                             /*@;BEGIN(Nest4=Nest)@*/for (i=1; i<-1+nx; i+=1) 
                               {
                                  Anext[Index3D(nx,ny,i,j,k_bk_1+(k_bk_2+k))] = -(A0[Index3D(nx,ny,i,j,k_bk_1+(k_bk_2+k))]*fac)+(A0[Index3D(nx,ny,-1+i,j,k_bk_1+(k_bk_2+k))]+(A0[Index3D(nx,ny,1+i,j,k_bk_1+(k_bk_2+k))]+(A0[Index3D(nx,ny,i,-1+j,k_bk_1+(k_bk_2+k))]+(A0[Index3D(nx,ny,i,1+j,k_bk_1+(k_bk_2+k))]+(A0[Index3D(nx,ny,i,j,1+(k_bk_1+(k_bk_2+k)))]+A0[Index3D(nx,ny,i,j,-1+(k_bk_1+(k_bk_2+k)))])))));
                               }
                          }
                     }
                }
           }
         }
        
        temp_ptr = A0;
        A0 = Anext;
        Anext = temp_ptr;
     }
};
