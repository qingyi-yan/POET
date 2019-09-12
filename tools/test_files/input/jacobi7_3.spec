include=#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
routine = void jacobi7_3(const int nx,const int ny,int nz,const double alpha,double* A0,const int timesteps,const double* B,const int ldb,double* Anext,const int ldc) {
   double fac;
   double* temp_ptr;
   int i;int j;int k;int t;
   fac = 6.0/(A0[0]*A0[0]);
   double* l0;double* lnext;
   for (t=0; t<timesteps; t+=1)
     {
        for (k=1; k<nz-1; k+=1)
          {
             for (j=1; j<ny-1; j+=1)
               {
                  for (i=1; i<nx-1; i+=1)
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
                       lnext[Index3D(nx,ny,i,j,k)] = l0[Index3D(nx,ny,i,j,k+1)]+l0[Index3D(nx,ny,i,j,k-1)]+l0[Index3D(nx,ny,i,j+1,k)]+l0[Index3D(nx,ny,i,j-1,k)]+l0[Index3D(nx,ny,i+1,j,k)]+l0[Index3D(nx,ny,i-1,j,k)]-l0[Index3D(nx,ny,i,j,k)]*fac;
                    }
               }
          }
     }
}

init = {
  ldc = 0;
  ldb = 0;
  B = 0;
  timesteps = Macro(SIZE,200);
  alpha = RANDOM;
  nz = Macro(SIZE,200);
  ny = Macro(SIZE,200);
  nx = Macro(SIZE,200);
  Anext = Vector(double,RANDOM,flush|align(16),Index3D(nx,ny,nx-1,ny-1,nz-1));
  A0 = Vector(double,RANDOM,flush|align(16),Index3D(nx,ny,nx-1,ny-1,nz-1));
};
returns(Anext,A0);
flop = "2+7*(nx-1)*(ny-1)*(nz-1)*timesteps";
