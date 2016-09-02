#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef CS
#define CS 1000
#endif
#define CacheSZ CS*1024/sizeof(double)


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

/* Collect multiple timing samples */
#ifndef MT
#define MT 3
#endif

#ifndef RANDSEED
#define RANDSEED 1
#endif
/* Measure the collective performance of multiple invocations */
#ifndef NREP
#define NREP 50
#endif

/* routine to measure performance of*/
void jacobi7_3(const int nx,const int ny,int nz,const double alpha,double * A0,const int timesteps,const double * B,const int ldb,double * Anext,const int ldc) 
;
/* macro for the value of routien parameter */
#ifndef SIZE
#define SIZE 200
#endif
/* macro for the value of routien parameter */
#ifndef SIZE
#define SIZE 200
#endif
/* macro for the value of routien parameter */
#ifndef SIZE
#define SIZE 200
#endif
/* macro for the value of routien parameter */
#ifndef SIZE
#define SIZE 200
#endif

#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))
int main(int argc, char **argv) 
{
  
  /* arrays for storing results of multiple timings */
  double __timer_diff[MT];
  
  /* induction variable for Multiple timing */
  int __pt_MT_ivar;
  
  double __timer_min,__timer_avg,__timer_max;
  
  /* induction variable for multiple invocations in a single timing */
  int __pt_NREP_ivar;
  
  /* variables to support cache flushing */
  double* __pt_flush_buffer;
  double __pt_flush_bufferVal;
  
  /* variable for computing MFLOPS */
  double __pt_flops;
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  /*variables to store starting and ending of timing */
  double __timer_begin, __timer_end; 
  
  /* Declaring parameters of the routine */
  int nx;
  int ny;
  int nz;
  double alpha;
  double* A0;
  int timesteps;
  double* B;
  int ldb;
  double* Anext;
  int ldc;
  double* Anext_buf;
  int Anext_size, Anext_rep; 
  double* A0_buf;
  int A0_size, A0_rep; 
  
  /* parameter initializations */
  srand(RANDSEED); 
  ldc = 0;
  ldb = 0;
  B = 0;
  timesteps = SIZE;
  alpha = rand();;
  nz = SIZE;
  ny = SIZE;
  nx = SIZE;
  Anext_size=16*((15+Index3D(nx,ny,nx-1,ny-1,nz-1+1))/16); 
  Anext_rep=CacheSZ / Anext_size + 1; 
  Anext_buf = calloc(Anext_size*Anext_rep, sizeof(double));
  A0_size=16*((15+Index3D(nx,ny,nx-1,ny-1,nz-1))/16); 
  A0_rep=CacheSZ / A0_size + 1; 
  A0_buf = calloc(A0_size*A0_rep, sizeof(double));
  #define DO_FLUSH 1
  __pt_flush_buffer = malloc(CacheSZ * sizeof(double));
  
  for(__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0) {
    __pt_flush_buffer[__pt_i0] = ((__pt_i0 % 3) == 2) ? -1 : __pt_i0 % 2;
  }
  
  /* Multiple Timings */
  for (__pt_MT_ivar=0; __pt_MT_ivar<MT; ++__pt_MT_ivar) {
    srand(RANDSEED);
    for (__pt_i0=0; __pt_i0<Anext_size *Anext_rep; ++__pt_i0)
    {
      Anext_buf[__pt_i0] = rand();; 
    }
    Anext = Anext_buf;
    for (__pt_i0=0; __pt_i0<A0_size *A0_rep; ++__pt_i0)
    {
      A0_buf[__pt_i0] = rand();; 
    }
    A0 = A0_buf;
    /* code to flush the cache */
    __pt_flush_bufferVal = 0;
    for (__pt_i0=0; __pt_i0 < CacheSZ; ++__pt_i0)
      __pt_flush_bufferVal += __pt_flush_buffer[__pt_i0];
    assert(__pt_flush_bufferVal < 10);
    
    /* Timer start */
    __timer_begin = GetWallTime();
    /* Timing loop */
    for (__pt_NREP_ivar=0; __pt_NREP_ivar<NREP; ++__pt_NREP_ivar) {
      jacobi7_3 (nx,ny,nz,alpha,A0,timesteps,B,ldb,Anext,ldc);
      alpha = rand();;
      if (__pt_i0 < Anext_rep-1)
        Anext += Anext_size;
      else Anext = Anext_buf;
      if (__pt_i0 < A0_rep-1)
        A0 += A0_size;
      else A0 = A0_buf;
    }
    /* Timer end */
    __timer_end = GetWallTime();
    /* result of a single timing */
    __timer_diff[__pt_MT_ivar] = (__timer_end-__timer_begin)/NREP;
  }
  /* flops of computation */
  __pt_flops = 2+7*(nx-1)*(ny-1)*(nz-1)*timesteps;
  /* Compute minimum of multiple timings */
  __timer_min=__timer_diff[0];
  __timer_max=__timer_diff[0];
  __timer_avg=__timer_diff[0];
  for (__pt_MT_ivar=1; __pt_MT_ivar<MT; ++__pt_MT_ivar)
  {
    if (__timer_min > __timer_diff[__pt_MT_ivar])
        __timer_min = __timer_diff[__pt_MT_ivar];
    if (__timer_max < __timer_diff[__pt_MT_ivar])
        __timer_max = __timer_diff[__pt_MT_ivar];
    __timer_avg += __timer_diff[__pt_MT_ivar];
  }
  __timer_avg /= MT;
  
  
  /* output timing results */
  for (__pt_MT_ivar=0; __pt_MT_ivar < MT; ++__pt_MT_ivar)
  {
    printf("time in seconds [%d]:  %.15f\n", __pt_MT_ivar, __timer_diff[__pt_MT_ivar]);
  
  }
  printf("Minimum time in seconds:  %.15f\n", __timer_min);
  printf("Maximum time in seconds:  %.15f\n", __timer_max);
  printf("Average time in seconds:  %.15f\n", __timer_avg);
  printf("Maximum MFLOPS: %.15f\n", __pt_flops/__timer_min/1000000); 
  printf("Minimum MFLOPS: %.15f\n", __pt_flops/__timer_max/1000000); 
  printf("Average MFLOPS: %.15f\n", __pt_flops/__timer_avg/1000000); 
  printf("Configuration\n"
         "-------------\n");
  printf("CPU MHZ: 0\n");
  printf("Cache Size: %d\n", CS);
  #ifdef DO_FLUSH
  printf("Cache Flush Method: generic\n");
  #else
  printf("Cache Flush Method: none\n");
  #endif
  printf("ARCH: generic\n");
  printf("nrep: %d\n", NREP);
  printf("mt: %d\n", MT);
  printf("Random Seed: %d\n", RANDSEED); 
  return(0);
}
