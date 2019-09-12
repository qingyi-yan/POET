/*$ATLAS ROUTINE tomcatv */
/*$ATLAS SIZE 100:300:50 */
/*$ATLAS ARG N          IN     int     $size */
/*$ATLAS ARG X[N][N]    IN     double  $rand */
/*$ATLAS ARG Y[N][N]    IN     double  $rand */
/*$ATLAS ARG AA[N][N]    OUT     double  $rand */
/*$ATLAS ARG DD[N][N]    OUT     double  $rand */
/*$ATLAS ARG D[N][N]    OUT     double  $rand */
/*$ATLAS ARG RX[N][N]    OUT     double  $rand */
/*$ATLAS ARG RY[N][N]    OUT     double  $rand */
/*$ATLAS ARG RXM[N]    OUT     double  $rand */
/*$ATLAS ARG RYM[N]    OUT     double  $rand */
                                                                                
#include "arrayAccess.h"

double max( double a, double b) { return (a < b)? b : a; }
double abs( double a) { return (a < 0)? -a : a; }

void tomcatv( int n, double * x, double* y, double* aa, double* dd, double *d, double* rx, double* ry, double& rxm, double& rym)
{
  int j, i;
  double xx, yy, yx,xy, a, b, c, r;
  double pxx, qxx, pyy, qyy, pxy, qxy;
  double rel = 2.0 / 0.98;
  {
  /*@; BEGIN(nest1=CODE.Nest)@*/ for (j = 1; j < n-1; ++j) {
    for (i = 1; i < n-1; ++i) {
       xx = arr_ref(x,i+1,j) - arr_ref(x,i-1,j);
       yx = arr_ref(y,i+1,j) - arr_ref(y, i-1, j);
       xy = arr_ref(x,i,j+1) - arr_ref(x, i, j-1);
       yy = arr_ref(y,i,j+1) - arr_ref(y,i,j-1);
       a = 0.25 * (xy * xy + yy * yy);
       b  = 0.25  * (xx*xx+yx*yx);
       c  = 0.125 * (xx*xy+yx*yy);
       arr_ref(aa,i,j) = -b;
       arr_ref(dd,i,j) = b+b+a*rel;
       pxx = arr_ref(x,i+1,j)-2.0*arr_ref(x,i,j)+arr_ref(x,i-1,j);
       qxx = arr_ref(y, i+1,j)-2.0*arr_ref(y,i,j)+arr_ref(y,i-1,j);
       pyy = arr_ref(x,i,j+1)-2.0*arr_ref(x,i,j)+arr_ref(x,i,j-1);
       qyy = arr_ref(y,i,j+1)-2.0*arr_ref(y,i,j)+arr_ref(y,i,j-1);
       pxy = arr_ref(x,i+1,j+1)-arr_ref(x,i+1,j-1)-arr_ref(x,i-1,j+1)+arr_ref(x,i-1,j-1);

       qxy = arr_ref(y,i+1,j+1)-arr_ref(y,i+1,j-1)-arr_ref(y,i-1,j+1)+arr_ref(y,i-1,j-1);
       arr_ref(rx,i,j)   = a*pxx+b*pyy-c*pxy;
       arr_ref(ry,i,j)   = a*qxx+b*qyy-c*qxy;
     }
   }
  /*@; BEGIN(nest2=Nest)@*/
   for (j = 1; j < n-1; ++j) {
      for (i = 1; i < n-1; ++i) {
         rxm = max(rxm, abs(arr_ref(rx,i,j)));
         rym = max(rym, abs(arr_ref(ry,i,j)));
      }
   }
   for (i = 1; i < n-1; ++i) {
         arr_ref(d,i,1) = 1.0/arr_ref(dd,i,1);
   }
   for (j = 2; j < n-1; ++j) {
      for (i = 1; i < n-1; ++i) {
            r = arr_ref(aa,i,j)*arr_ref(d,i,j-1);
            arr_ref(d,i,j) = 1.0/(arr_ref(dd,i,j)-arr_ref(aa,i,j-1)*r);
            arr_ref(rx,i,j) = arr_ref(rx,i,j) - arr_ref(rx,i,j-1)*r;
            arr_ref(ry,i,j) = arr_ref(ry,i,j) - arr_ref(ry,i,j-1)*r;
      }
   }
   for (i = 1; i < n-1; ++i) {
      arr_ref(rx,i,n-1) = arr_ref(rx,i,n-1)*arr_ref(d,i,n-1);
      arr_ref(ry,i,n-1) = arr_ref(ry,i,n-1)*arr_ref(d,i,n-1);
   }
   for (j = n-3; j >= 1; --j) {
      for (i = 1; i < n-1; ++i) {
            arr_ref(rx,i,j) = (arr_ref(rx,i,j)-arr_ref(aa,i,j)*arr_ref(rx,i,j+1))*arr_ref(d,i,j);
            arr_ref(ry,i,j) = (arr_ref(ry,i,j)-arr_ref(aa,i,j)*arr_ref(ry,i,j+1))*arr_ref(d,i,j);
      }
   }
   for (j = 1; j < n-1; ++j) {
      for (i = 1; i < n-1; ++i) {
         arr_ref(x,i,j) = arr_ref(x,i,j)+arr_ref(rx,i,j);
         arr_ref(y,i,j) = arr_ref(y,i,j)+arr_ref(ry,i,j);
      }
   }
 }
}
