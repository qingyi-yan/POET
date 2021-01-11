#include <cstdio>
#include <cstddef>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <sys/time.h>
#include <cmath>

#include <stencil_config.h>
#include <pochoir.hpp>

using namespace std;

#ifndef RANDSEED
#define RANDSEED 1
#endif

Pochoir_Boundary_3D(stencil_bv,u,t,i0,i1,i2)
  double val;

  if(t%2 == 0) {
    val = 1+(i0*0.1)+(i1*0.01)+(i2*0.001);
  } else {
    val = 2+(i0*0.1)+(i1*0.01)+(i2*0.001);
  }

  return val;
Pochoir_Boundary_End

int main(int argc, char ** argv) 
{
  if (argc != 5) {
    printf ("Wrong number of parameters.\n");
    exit (-1);
  }

  int N0 = atoi (argv[1]); 
  int N1 = atoi (argv[2]);
  int N2 = atoi (argv[3]);
  int TS = atoi (argv[4]);

  srand(RANDSEED);

  Pochoir_Array_3D(double) u(N0, N1, N2);
  Pochoir_Shape_3D stencil_shape[] = {{1,0,0,0}, {0,-2,0,0}, {0,-1,0,0}, {0,1,0,0}, {0,2,0,0}, {0,0,-2,0}, {0,0,-1,0}, {0,0,1,0}, {0,0,2,0}, {0,0,0,-2}, {0,0,0,-1}, {0,0,0,1}, {0,0,0,2}, {0,0,0,0}, {-1,0,0,0}};
  Pochoir_3D stencil(stencil_shape);

  Pochoir_Kernel_3D(stencil_fn,t,i0,i1,i2)
  u(t+1,i0,i1,i2) = (c[2][i0][i1][i2]*u(t,-2+i0,i1,i2)+(c[1][i0][i1][i2]*u(t,-1+i0,i1,i2))+(c[0][i0][i1][i2]*u(t,i0,i1,i2))+(c[3][i0][i1][i2]*u(t,1+i0,i1,i2))+(c[4][i0][i1][i2]*u(t,2+i0,i1,i2))+(c[6][i0][i1][i2]*u(t,i0,-2+i1,i2))+(c[5][i0][i1][i2]*u(t,i0,-1+i1,i2))+(c[7][i0][i1][i2]*u(t,i0,1+i1,i2))+(c[8][i0][i1][i2]*u(t,i0,2+i1,i2))+(c[10][i0][i1][i2]*u(t,i0,i1,-2+i2))+(c[9][i0][i1][i2]*u(t,i0,i1,-1+i2))+(c[11][i0][i1][i2]*u(t,i0,i1,1+i2))+(c[12][i0][i1][i2]*u(t,i0,i1,2+i2)))*divvar+(2*u(t,i0,i1,i2))+(-1*u(t+-1,i0,i1,i2));
  Pochoir_Kernel_End

  u.Register_Boundary(stencil_bv);
  stencil.Register_Array(u);
  
  unsigned i2,i1,i0,i,t,l;

  double divvar=(double)(1/(floor(fmod(rand(),1))+2));

  for (i2=0; i2<N2; i2+=1)
    {
       for (i1=0; i1<N1; i1+=1)
         {
            for (i0=0; i0<N0; i0+=1)
              {
                 
                 u(0,i0,i1,i2) = rand();
                 u(1,i0,i1,i2) = rand();
                 u(2,i0,i1,i2) = rand();
              }
         }
    }

  benchInit();
  benchBeginStencil();

  stencil.Run(TS, stencil_fn);

  benchEndStencil();
  benchSetEnv();
  benchSetDomain(3,4,2);
  benchSetProblemSize(N0, N1, N2, TS);
  benchSetArithProps(14, 0, 16, 0);
  benchSetMemProps(24, 1);
  benchSetMatProps(3, 1);
  benchSetFpSize(sizeof(double));
  benchFinalize();

  return 0;
}

