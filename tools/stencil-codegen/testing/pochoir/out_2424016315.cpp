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

Pochoir_Boundary_2D(stencil_bv,u,t,i0,i1)
  double val;

  if(t%2 == 0) {
    val = 1+(i0*0.1)+(i1*0.01);
  } else {
    val = 2+(i0*0.1)+(i1*0.01);
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
  double divvar=(double)(floor(fmod(rand(),1))+2);

  srand(RANDSEED);

  Pochoir_Array_2D(double) u(N0, N1);
  Pochoir_Shape_2D stencil_shape[] = {{1,0,0}, {0,-2,0}, {0,-1,0}, {0,1,0}, {0,2,0}, {0,0,-2}, {0,0,-1}, {0,0,1}, {0,0,2}, {0,0,0}, {-1,0,0}};
  Pochoir_2D stencil(stencil_shape);

  Pochoir_Kernel_2D(stencil_fn,t,i0,i1)
  u(t+1,i0,i1) = ((((-0.083 * u(t,i0-2,i1) + 1.33 * u(t,i0-1,i1) + -2.5 * u(t,i0,i1) + 1.33 * u(t,i0+1,i1) + -0.083 * u(t,i0+2,i1) + -0.083 * u(t,i0,i1-2) + 1.33 * u(t,i0,i1-1) + -2.5 * u(t,i0,i1) + 1.33 * u(t,i0,i1+1) + -0.083 * u(t,i0,i1+2)) / divvar) / divvar) / divvar) / divvar + 2*u(t,i0,i1) + -1*u(t+-1,i0,i1);
  Pochoir_Kernel_End

  u.Register_Boundary(stencil_bv);
  stencil.Register_Array(u);
  
  unsigned i1,i0,i,t,l;


  for (i1=0; i1<N1; i1+=1)
    {
       for (i0=0; i0<N0; i0+=1)
         {
            
            u(0,i0,i1) = rand();
            u(1,i0,i1) = rand();
            u(2,i0,i1) = rand();
         }
    }

  benchInit();
  benchBeginStencil();

  stencil.Run(TS, stencil_fn);

  benchEndStencil();
  benchSetEnv();
  benchSetDomain(2,4,2);
  benchSetProblemSize(N0, N1, 0, TS);
  benchSetArithProps(10, 0, 11, 4);
  benchSetMemProps(7, 1);
  benchSetMatProps(3, 1);
  benchSetFpSize(sizeof(double));
  benchFinalize();

  return 0;
}

