#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
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

#ifndef TS
#define TS 100
#endif

int main(int argc, char ** argv) 
{
#ifndef N0
#define N0 100
#endif
  float* A, *A_tmp;
  float* B, *B_tmp;
  unsigned i0,i,t;
  double __timer_begin, __timer_end, __timer_diff, __pt_flops;

  unsigned stencil_size = N0;
  A = calloc(stencil_size,sizeof(float));
  B = calloc(stencil_size,sizeof(float));
  srand(RANDSEED);
  for (i=0; i<stencil_size; ++i)
  {
      A[i] = rand();;
      B[i] = rand();;
  }

  __timer_begin = GetWallTime();
  for (t = 0; t < TS; t++) {
      if (t%2 == 0) 
           { A_tmp = A; B_tmp = B; }
      else { A_tmp = B; B_tmp = A; }
      for (i0=1; i0<-1+N0; i0+=1)
        {
           B_tmp[i0] = A_tmp[-1+i0]+(A_tmp[i0]+A_tmp[1+i0])/3;
        }
  }
  __timer_end = GetWallTime();
  __timer_diff = (__timer_end-__timer_begin);
  __pt_flops = 3 * TS;
  __pt_flops =  __pt_flops * N0;
  __pt_flops = __pt_flops / __timer_diff;
  printf("time in seconds:  %.15f\n", __timer_diff);
  printf("MFLOPS:  %.15f\n", __pt_flops/1000000);
  return 0;
}
