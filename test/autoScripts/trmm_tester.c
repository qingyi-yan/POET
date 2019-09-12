#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#ifndef RANDSEED
#define RANDSEED 1
#endif


/* routine to test*/
void strmm(int m,int n,float alpha,int lda,int ldb,float beta,float* a,float* b) ;
/* macro for the value of routine parameter */
#ifndef MS
#define MS 200
#endif
/* macro for the value of routine parameter */
#ifndef NS
#define NS 200
#endif
void strmm_ref(int m,int n,float alpha,int lda,int ldb,float beta,float* a,float* b) {
   int i;int j;int l;
   #define arr_ref_b(b,i,j)   b[(i)*ldb+j]
   #define arr_ref_a(a,i,j)   a[(i)*lda+j]
   {
      for (j=0; j<n; j+=1)
        {
           for (i=0; i<m; i+=1)
             {
                arr_ref_b(b,i,j) = beta*arr_ref_b(b,i,j);
             }
        }
      for (j=0; j<m; j+=1)
        {
           for (l=0; l<m; l+=1)
             {
                for (i=0; i<l; i+=1)
                  {
                     arr_ref_b(b,i,j) = alpha*arr_ref_b(b,l,j)*arr_ref_a(a,i,l);
                  }
             }
        }
      for (j=0; j<m; j+=1)
        {
           for (l=0; l<m; l+=1)
             {
                arr_ref_b(b,l,j) = alpha*arr_ref_b(b,l,j);
             }
        }
   }
}

int main(int argc, char **argv) 
{
  
  /* induction variables */
  int __pt_i0, __pt_i1, __pt_i2;
  
  
  
  /* Declaring parameters of the routine */
  int m;
  int n;
  float alpha;
  int lda;
  int ldb;
  float beta;
  float* a;
  float* b_comp;
  float* b;
  float* a_buf;
  int a_size;
  float* b_buf;
  int b_size;
  float* b_comp_buf;
  int b_comp_size;
  
  /* parameter initializations */
  srand(RANDSEED);
  m = MS;
  n = NS;
  lda = m;
  ldb = n;
  alpha = 1.0;
  a_size=m*m;
  a_buf = (float*)calloc(a_size, sizeof(float));
  b_size=m*n;
  b_buf = (float*)calloc(b_size, sizeof(float));
  b_comp_size=m*n;
  b_comp_buf = (float*)calloc(b_comp_size, sizeof(float));
  for (__pt_i0=0; __pt_i0<a_size; ++__pt_i0)
  {
    a_buf[__pt_i0] = rand();; 
  }
  a = a_buf;
  for (__pt_i0=0; __pt_i0<b_size; ++__pt_i0)
  {
    b_buf[__pt_i0] = rand();; 
  }
  b = b_buf;
  for (__pt_i0=0; __pt_i0<b_comp_size; ++__pt_i0)
  {
    b_comp_buf[__pt_i0] = rand();; 
  }
  b_comp = b_comp_buf;
  for (__pt_i0=0; __pt_i0<b_size; ++__pt_i0)
  {
    b_comp_buf[__pt_i0] = b_buf[__pt_i0];
  }
  strmm (m,n,alpha,lda,ldb,beta,a,b_comp);
  
  strmm_ref (m,n,alpha,lda,ldb,beta,a,b);
  
  {
  int diff_flag = 0;
  for (__pt_i0=0; __pt_i0<m*n; ++__pt_i0)
  {
    if(b_comp_buf[__pt_i0] != b_buf[__pt_i0]) {
      diff_flag = 1;
      printf("Position %d (%f) and Position %d (%f) differ by %.15f\n", __pt_i0,
          b_comp_buf[__pt_i0], __pt_i0, b_buf[__pt_i0],
      	fabs(b_comp_buf[__pt_i0]-b_buf[__pt_i0]));
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
