#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#define _TH_1 2
#include <omp.h>

#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
void jacobi7_3(const int nx,const int ny,int nz,const double alpha,double* A0,const int timesteps,const double* B,const int ldb,double* Anext,const int ldc) {
   double fac;
   double* temp_ptr;
   int i;int j;int k;int t;
   fac = 6.0/(A0[0]*A0[0]);
   double* l0;double* lnext;
   int k_bk_1;
   int j_bk_2;
   int i_bk_3;
   /*@;BEGIN(Nest2_group3=Nest)@*/for (k_bk_1=1; k_bk_1<nz-1+16*timesteps; k_bk_1+=8)
     {
        omp_set_num_threads(_TH_1);
        #pragma omp  parallel  
         {
         /*@;BEGIN(Nest1=Nest)@*/#pragma omp  for private(t,k,j,i,l0,lnext,j_bk_2,i_bk_3)
         for (t=max(0,(16+(k_bk_1-(nz-1)))/16); t<min(timesteps,(15+k_bk_1)/16); t+=1)
           {
              /*@;BEGIN(Nest3=Nest)@*/for (j_bk_2=1; j_bk_2<-1+ny; j_bk_2+=32)
                {
                   /*@;BEGIN(Nest4=Nest)@*/for (i_bk_3=1; i_bk_3<-1+nx; i_bk_3+=32)
                     {
                        for (k=0; k<min(8,16*t+(-k_bk_1+(-1+nz))); k+=1)
                          {
                             for (j=0; j<min(32,-j_bk_2+(-1+ny)); j+=1)
                               {
                                  for (i=0; i<min(32,-i_bk_3+(-1+nx)); i+=1)
                                    {
                                       if (t%2==0) 
                                         {
                                            l0 = A0;
                                            lnext = Anext;
                                         }
                                       else 
                                         {
                                            lnext = A0;
                                            l0 = Anext;
                                         }
                                       lnext[Index3D(nx,ny,i_bk_3+i,j_bk_2+j,k+(k_bk_1+-16*t))] = -(l0[Index3D(nx,ny,i_bk_3+i,j_bk_2+j,k+(k_bk_1+-16*t))]*fac)+(l0[Index3D(nx,ny,-1+(i_bk_3+i),j_bk_2+j,k+(k_bk_1+-16*t))]+(l0[Index3D(nx,ny,1+(i_bk_3+i),j_bk_2+j,k+(k_bk_1+-16*t))]+(l0[Index3D(nx,ny,i_bk_3+i,-1+(j_bk_2+j),k+(k_bk_1+-16*t))]+(l0[Index3D(nx,ny,i_bk_3+i,1+(j_bk_2+j),k+(k_bk_1+-16*t))]+(l0[Index3D(nx,ny,i_bk_3+i,j_bk_2+j,1+(k+(k_bk_1+-16*t)))]+l0[Index3D(nx,ny,i_bk_3+i,j_bk_2+j,-1+(k+(k_bk_1+-16*t)))])))));
                                    }
                               }
                          }
                     }
                }
           }
         }
        
     }
}
