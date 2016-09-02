#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <sys/time.h>

#include "util.h"

#define TIME 1

#ifdef TIME
#define IF_TIME(foo) foo;
#else
#define IF_TIME(foo)
#endif

#ifndef NMAX
#define NMAX 500
#endif 
static double a[NMAX][NMAX], b[NMAX][NMAX];

void strsm(long N) {
	int i,j,k;

/*@; BEGIN(nest1=MM_pat2[type="double"]) @*/
	for (i=0; i<N; i++) {
	   for (j=0; j<N; j++) {
              b[j][i] /= a[i][i];
	      for (k=i+2; k<N; k++) {
                b[j][k] -= a[i][k] * b[j][i];
            }
        }
    }
}

double rtclock()
{
    struct timezone Tzp;
    struct timeval Tp;
    int stat;
    stat = gettimeofday (&Tp, &Tzp);
    if (stat != 0) printf("Error return from gettimeofday: %d",stat);
    return(Tp.tv_sec + Tp.tv_usec*1.0e-6);
}



int main()
{
    double t_start, t_end;
    long N=NMAX;
    int i,j;

    IF_TIME(t_start = rtclock());
    strsm(N);
    IF_TIME(t_end = rtclock());

    IF_TIME(fprintf(stderr, "%0.6lfs\n", t_end - t_start));

    if (fopen(".test", "r")) {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                fprintf(stdout, "%lf ",  b[i][j]);
            }
            fprintf(stdout, "\n");
        }
    }

    return 0;
}
