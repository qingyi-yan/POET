#include <math.h>
#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

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

  int t1, t2, t3, t4, t5, t6, t7, t8;
 register int lbv, ubv;
if ((N0 >= 5) && (N1 >= 5) && (N2 >= 5) && (TS >= 1)) {
  for (t1=ceild(-N0-4,8);t1<=floord(TS-2,4);t1++) {
    for (t2=max(t1,-t1-1);t2<=min(min(floord(-2*t1+TS-1,2),floord(4*t1+N0,4)),floord(N0+2*TS-5,8));t2++) {
      for (t3=max(max(0,ceild(t1+t2-1,2)),ceild(8*t2-N0-1,8));t3<=min(min(min(floord(N1+2*TS-5,8),floord(8*t2+N1+1,8)),floord(4*t1+4*t2+N1+3,8)),floord(8*t1+N1+N0+1,8));t3++) {
        for (t4=max(max(max(0,ceild(t1+t2-15,16)),ceild(8*t2-N0-57,64)),ceild(8*t3-N1-57,64));t4<=min(min(min(min(floord(N2+2*TS-5,64),floord(8*t2+N2+1,64)),floord(8*t3+N2+1,64)),floord(4*t1+4*t2+N2+3,64)),floord(8*t1+N2+N0+1,64));t4++) {
          for (t5=max(max(max(max(max(0,ceild(8*t2-N0+3,2)),ceild(8*t3-N1+3,2)),ceild(64*t4-N2+3,2)),2*t1+2*t2),4*t1+1);t5<=min(min(min(min(min(floord(8*t1+N0+4,2),TS-1),4*t2+2),4*t3+2),32*t4+30),2*t1+2*t2+3);t5++) {
            for (t6=max(max(8*t2,2*t5+2),-8*t1+4*t5-7);t6<=min(min(-8*t1+4*t5,8*t2+7),2*t5+N0-3);t6++) {
              for (t7=max(8*t3,2*t5+2);t7<=min(8*t3+7,2*t5+N1-3);t7++) {
                lbv=max(64*t4,2*t5+2);
                ubv=min(64*t4+63,2*t5+N2-3);
#pragma ivdep
#pragma vector always
                for (t8=lbv;t8<=ubv;t8++) {
                  u[(t5 + 2) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] = (((((((((((((((((((c[2][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6) - 2][(-2*t5+t7)][(-2*t5+t8)]) + (c[1][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6) - 1][(-2*t5+t7)][(-2*t5+t8)])) + (c[0][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)])) + (c[3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6) + 1][(-2*t5+t7)][(-2*t5+t8)])) + (c[4][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6) + 2][(-2*t5+t7)][(-2*t5+t8)])) + (c[6][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7) - 2][(-2*t5+t8)])) + (c[5][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7) - 1][(-2*t5+t8)])) + (c[7][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7) + 1][(-2*t5+t8)])) + (c[8][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7) + 2][(-2*t5+t8)])) + (c[10][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8) - 2])) + (c[9][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8) - 1])) + (c[11][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8) + 1])) + (c[12][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8) + 2])) * divvar) * divvar) * divvar) * divvar) + (u[(t5 + 1) % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * 2)) + (u[t5 % 3][(-2*t5+t6)][(-2*t5+t7)][(-2*t5+t8)] * (-1)));;
                }
              }
            }
          }
        }
      }
    }
  }
}

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

