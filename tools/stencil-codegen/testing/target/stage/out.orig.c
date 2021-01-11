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

  double (*u)[N0][N1][N2]=(double*)malloc(3*(N2*(N1*(N0*sizeof (double)))));
  double (*c)[N0][N1][N2]=(double*)malloc(13*(N2*(N1*(N0*sizeof (double)))));;
  
  unsigned i0,i1,i2,i,t,l;
  int tnew;int tm1;int tm2; 

  double divvar=(double)(1/(floor(fmod(rand(),1))+2));

  srand(RANDSEED);

  for (i0=0; i0<N0; i0+=1)
    {
       for (i1=0; i1<N1; i1+=1)
         {
            for (i2=0; i2<N2; i2+=1)
              {
                 
                 u[0][i0][i1][i2] = rand();
                 u[1][i0][i1][i2] = rand();
                 u[2][i0][i1][i2] = rand();
                 for (l=0; l<13; l+=1)
                   {
                      c[l][i0][i1][i2] = (double)fmod((double)rand(),2);
                   }
              }
         }
    }

  benchInit();
  benchBeginStencil();

#pragma scop
  for (t = 0; t < TS; t++) {
    
    tnew = (t+(3-1)) % 3;
    tm1 = (t+(3-1-1)) % 3;
    tm2 = (t+(3-1-2)) % 3; 

    for (i0=2; i0<-2+N0; i0+=1)
      {
         for (i1=2; i1<-2+N1; i1+=1)
           {
              for (i2=2; i2<-2+N2; i2+=1)
                {
                   u[tnew][i0][i1][i2] = ((((c[2][i0][i1][i2]*u[tm1][-2+i0][i1][i2]+(c[1][i0][i1][i2]*u[tm1][-1+i0][i1][i2])+(c[0][i0][i1][i2]*u[tm1][i0][i1][i2])+(c[3][i0][i1][i2]*u[tm1][1+i0][i1][i2])+(c[4][i0][i1][i2]*u[tm1][2+i0][i1][i2])+(c[6][i0][i1][i2]*u[tm1][i0][-2+i1][i2])+(c[5][i0][i1][i2]*u[tm1][i0][-1+i1][i2])+(c[7][i0][i1][i2]*u[tm1][i0][1+i1][i2])+(c[8][i0][i1][i2]*u[tm1][i0][2+i1][i2])+(c[10][i0][i1][i2]*u[tm1][i0][i1][-2+i2])+(c[9][i0][i1][i2]*u[tm1][i0][i1][-1+i2])+(c[11][i0][i1][i2]*u[tm1][i0][i1][1+i2])+(c[12][i0][i1][i2]*u[tm1][i0][i1][2+i2]))*divvar)*divvar)*divvar)*divvar+(u[tm1][i0][i1][i2]*2)+(u[tm2][i0][i1][i2]*-1);
                }
           }
      }
  }
#pragma endscop

  benchEndStencil();
  benchSetEnv();
  benchSetDomain(3,4,2);
  benchSetProblemSize(N0, N1, N2, TS);
  benchSetArithProps(14, 0, 19, 0);
  benchSetMemProps(24, 1);
  benchSetMatProps(1, 1); //Fix for (long distance mats, immediate mats)
  benchSetFpSize(sizeof(double));
  benchFinalize();

  free(u);
  free(c);

  return EXIT_SUCCESS;
}

