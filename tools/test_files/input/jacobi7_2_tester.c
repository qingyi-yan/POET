#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void jacobi7_2(const int nx,const int ny,int nz,const double alpha,double * A0,const int timesteps,const double * B,const int ldb,double * Anext,const int ldc) 
;
/* macro for the value of routine parameter */

#ifndef TIME
#define TIME 20
#endif

#ifndef SIZE
#define SIZE 100
#endif
#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
void jacobi7_2_ref(const int nx,const int ny,int nz,const double alpha,double * A0,const int timesteps,const double * B,const int ldb,double * Anext,const int ldc) 
{
   double fac;
   double* temp_ptr;
   int i,j,k,t;
   fac = 6.0/(A0[0]*A0[0]);
   double* l0,* lnext;
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

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
  /* Declaring parameters of the routine */
  int nx;
  int ny;
  int nz;
  double alpha;
  double* A0_comp;
  double* A0;
  int timesteps;
  double* B;
  int ldb;
  double* Anext_comp;
  double* Anext;
  int ldc;
  double* Anext_buf;
  int Anext_size;
  double* A0_buf;
  int A0_size;
  double* A0_comp_buf;
  int A0_comp_size;
  double* Anext_comp_buf;
  int Anext_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  ldc = 0;
  ldb = 0;
  B = 0;
  timesteps = TIME;
  alpha = rand();;
  nz = SIZE;
  ny = SIZE;
  nx = SIZE;
  Anext_size=Index3D(nx,ny,nx-1,ny-1,nz-1+1);
  Anext_buf = (double*)calloc(Anext_size, sizeof(double));
  A0_size=Index3D(nx,ny,nx-1,ny-1,nz-1);
  A0_buf = (double*)calloc(A0_size, sizeof(double));
  A0_comp_size=Index3D(nx,ny,nx-1,ny-1,nz-1);
  A0_comp_buf = (double*)calloc(A0_comp_size, sizeof(double));
  Anext_comp_size=Index3D(nx,ny,nx-1,ny-1,nz-1+1);
  Anext_comp_buf = (double*)calloc(Anext_comp_size, sizeof(double));
  for (__pt_i0=0; __pt_i0<Anext_size; ++__pt_i0)
  {
    Anext_buf[__pt_i0] = rand();; 
  }
  Anext = Anext_buf;
  for (__pt_i0=0; __pt_i0<A0_size; ++__pt_i0)
  {
    A0_buf[__pt_i0] = rand();; 
  }
  A0 = A0_buf;
  for (__pt_i0=0; __pt_i0<A0_comp_size; ++__pt_i0)
  {
    A0_comp_buf[__pt_i0] = rand();; 
  }
  A0_comp = A0_comp_buf;
  for (__pt_i0=0; __pt_i0<Anext_comp_size; ++__pt_i0)
  {
    Anext_comp_buf[__pt_i0] = rand();; 
  }
  Anext_comp = Anext_comp_buf;
  for (__pt_i0=0; __pt_i0<A0_size; ++__pt_i0)
  {
    A0_comp_buf[__pt_i0] = A0_buf[__pt_i0];
  }
  for (__pt_i0=0; __pt_i0<Anext_size; ++__pt_i0)
  {
    Anext_comp_buf[__pt_i0] = Anext_buf[__pt_i0];
  }
  jacobi7_2 (nx,ny,nz,alpha,A0_comp,timesteps,B,ldb,Anext_comp,ldc);
  
  jacobi7_2_ref (nx,ny,nz,alpha,A0,timesteps,B,ldb,Anext,ldc);
  
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<Index3D(nx,ny,nx-1,ny-1,nz-1); ++__pt_i0)
  {
    if(A0_comp_buf[__pt_i0] != A0_buf[__pt_i0]) {
      diff_flag = 1;
      printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
          A0_comp_buf[__pt_i0], __pt_i0, A0_buf[__pt_i0],
      	fabs(A0_comp_buf[__pt_i0]-A0_buf[__pt_i0]));
    }
    /*else {
      printf("Identical output at index %d\n", __pt_i0);
    } */
  }
  if(diff_flag) {
    printf("Output differs\n");
  }else {
    printf("Output is identical\n");
  }
  }
  return(0);
}
