
routine = void chlskyfac(double* a,int NMAX)
{
  extern double sqrt(double);
  extern double fabs(double);
int i;
int j;
int k;
for (k=0; k<NMAX; k+=1)
{
  a[k*NMAX+k] = sqrt(fabs(a[k*NMAX+k]));
  for (i=k+1; i<NMAX; i+=1)
  {
    a[i*NMAX+k] = a[i*NMAX+k]*1.0/a[k*NMAX+k];
  }
  for (j=k+1; j<NMAX; j+=1)
  {
    for (i=j; i<NMAX; i+=1)
    {
      a[i*NMAX+j] = a[i*NMAX+j]-(a[i*NMAX+k]*a[j*NMAX+k]);
    }
  }
}
}

init = {
  NMAX = Macro(NMAX_,100);
  a = Matrix(double,NMAX,NMAX,RANDOM,flush);
};
returns(a);
flop="(NMAX*NMAX*NMAX)/3";
