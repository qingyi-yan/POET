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

Pochoir_Boundary_1D(stencil_bv,u,t,i0)
  double val;

  if(t%2 == 0) {
    val = 1+(i0*0.1);
  } else {
    val = 2+(i0*0.1);
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

  Pochoir_Array_1D(double) u(N0);
  Pochoir_Shape_1D stencil_shape[] = {{1,0}, {0,-2}, {0,-1}, {0,1}, {0,2}};
  Pochoir_1D stencil(stencil_shape);

  Pochoir_Kernel_1D(stencil_fn,t,i0)
  u(t+1,i0) = -0.083 * u(t,i0-2) + 1.33 * u(t,i0-1) + -2.5 * u(t,i0) + 1.33 * u(t,i0+1) + -0.083 * u(t,i0+2);
  Pochoir_Kernel_End

  u.Register_Boundary(stencil_bv);
  stencil.Register_Array(u);
  
  unsigned i0,i,t,l;


  for (i0=0; i0<N0; i0+=1)
    {
       
       u(0,i0) = rand();
       u(1,i0) = rand();
    }

  benchInit();
  benchBeginStencil();

  stencil.Run(TS, stencil_fn);

  benchEndStencil();
  benchSetEnv();
  benchSetDomain(1,4,0);
  benchSetProblemSize(N0, 0, 0, TS);
  benchSetArithProps(4, 0, 5, 0);
  benchSetMemProps(1, 1);
  benchSetMatProps(2, 1);
  benchSetFpSize(sizeof(double));
  benchFinalize();

  return 0;
}

