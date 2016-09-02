void test(int n, const double *a, const double *b, double *c, double *d, double *e, double *f)
{
  double temp1,temp2;
  int i;

/*@; BEGIN(Nest1=Nest)@*/  for (i = 0; i < n; i++) {
    c[i] = a[i] - b[i];
    e[i] = a[i] * c[i];
    temp1 = a[i] / e[i];
    temp2 = a[i] + e[i];
/*@; BEGIN(ExpStmt1=ExpStmt)@*/
    d[i] = temp1 * b[i];
    f[i] = temp2 / c[i];
  }
}
