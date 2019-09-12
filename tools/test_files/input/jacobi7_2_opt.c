#define max(a,b) (((a) < (b))? (b) : (a))
#define min(a,b) (((a) < (b))? (a) : (b))
#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
void jacobi7_2(const int nx,const int ny,int nz,const double alpha,double* A0,const int timesteps,const double* B,const int ldb,double* Anext,const int ldc) {
   double fac;
   double* temp_ptr;
   int i;int j;int k;int t;
   fac = 6.0/(A0[0]*A0[0]);
   double* l0;double* lnext;
   
   /*@;BEGIN(Nest2_group3=Nest)@*/for (k=1; k<nz-1+timesteps; k+=1)
     {
        /*@;BEGIN(Nest1=Nest)@*/for (t=max(0,1+(k-(nz-1))); t<min(timesteps,k); t+=1)
          {
             /*@;BEGIN(Nest3=Nest)@*/for (j=1; j<ny-1; j+=1)
               {
                  /*@;BEGIN(Nest4=Nest)@*/for (i=1; i<nx-1; i+=1)
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
                       lnext[Index3D(nx,ny,i,j,k-t)] = l0[Index3D(nx,ny,i,j,k-t+1)]+l0[Index3D(nx,ny,i,j,k-t-1)]+l0[Index3D(nx,ny,i,j+1,k-t)]+l0[Index3D(nx,ny,i,j-1,k-t)]+l0[Index3D(nx,ny,i+1,j,k-t)]+l0[Index3D(nx,ny,i-1,j,k-t)]-l0[Index3D(nx,ny,i,j,k-t)]*fac;
                    }
               }
          }
     }
}
