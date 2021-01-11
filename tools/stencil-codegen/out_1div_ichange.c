#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>
#include <sys/resource.h>

#include <stencil_config.h>

double GetWallTime(void)
   {
      struct timeval tp;
      static long start=0, startu;
      if (!start)
      {
         gettimeofday(&tp, NULL);
         start = tp.tv_sec;
         startu = tp.tv_usec;
         return(0.0);
      }
      gettimeofday(&tp, NULL);
      return( ((double) (tp.tv_sec - start)) + (tp.tv_usec-startu)/1000000.0 );
   }

#ifndef RANDSEED
#define RANDSEED 1
#endif

int main(int argc, char ** argv) 
{
  if (argc != 5) {
    printf ("Wrong number of parameters.\n", argv[0]);
    exit (-1);
  }

  int N0 = atoi (argv[1]); 
  int N1 = atoi (argv[2]);
  int N2 = atoi (argv[3]);
  int TS = atoi (argv[4]);

  double (*u)[N0][N1]=(double*)malloc(2*(N1*(N0*sizeof (double))));;
  
  unsigned i1,i0,i,t,l;
  int tnew;int tm1; 

  double divvar=(double)(floor(fmod(rand(),1))+2);

  srand(RANDSEED);

  for (i1=0; i1<N1; i1+=1)
    {
       for (i0=0; i0<N0; i0+=1)
         {
            
            u[0][i0][i1] = rand();
            u[1][i0][i1] = rand();
         }
    }

  benchInit();
  benchBeginStencil();

#pragma scop
  for (t = 0; t < TS; t++) {
    
    tnew = (t+(2-1)) % 2;
    tm1 = (t+(2-1-1)) % 2; 

    for (i0=1; i0<-1+N0; i0+=1) {
      for (i1=1; i1<-1+N1; i1+=1) {
        u[tnew][i0][i1] = (1*u[tm1][-1+i0][i1]+(-2*u[tm1][i0][i1])+(1*u[tm1][1+i0][i1])+(1*u[tm1][i0][-1+i1])+(-2*u[tm1][i0][i1])+(1*u[tm1][i0][1+i1]))/divvar/divvar+(u[tm1][i0][i1]*1);
      }
    }
  }
#pragma endscop

  benchEndStencil();
  benchSetEnv();
  benchSetDomain(2,2,1);
  benchSetProblemSize(N0, N1, 0, TS);
  benchSetArithProps(5, 0, 6, 2);
  benchSetMemProps(4, 1);
  benchSetMatProps(0, 1); //Fix for (long distance mats, immediate mats)
  benchSetFpSize(sizeof(double));
  benchFinalize();

  free(u);
  

  return EXIT_SUCCESS;
}

