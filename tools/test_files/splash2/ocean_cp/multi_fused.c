
void relax(long  k,double* err,long  color,long  my_num) {
   long  i;
   long  j;
   long  iend;
   long  jend;
   long  oddistart;
   long  oddjstart;
   long  evenistart;
   long  evenjstart;
   double a;
   double h;
   double factor;
   double maxerr;
   double newerr;
   double oldval;
   double newval;
   double** t2a;
   double** t2b;
   double* t1a;
   double* t1b;
   double* t1c;
   double* t1d;
   i = 0;
   j = 0;
   *err = 0.0;
   h = lev_res[k];
   evenistart = gp[my_num].eist[k];
   evenjstart = gp[my_num].ejst[k];
   oddistart = gp[my_num].oist[k];
   oddjstart = gp[my_num].ojst[k];
   iend = gp[my_num].rlien[k];
   jend = gp[my_num].rljen[k];
   factor = 4.0-eig2*h*h;
   maxerr = 0.0;
   t2a = (double* *)q_multi[my_num][k];
   t2b = (double* *)rhs_multi[my_num][k];
   if (color==RED_ITER)  
     {
        
        /*@;BEGIN(Nest1=Nest)@*/for (i=oddistart; i<iend; i+=1) 
          {
             t1a = (double*)t2a[i];
             t1b = (double*)t2b[i];
             t1c = (double*)t2a[i-1];
             t1d = (double*)t2a[i+1];
             /*@; BEGIN(Nest2_Nest4=Nest)@*/for (j=(i+1)%2+1; j<jend; j+=2) 
               {
                  a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                  oldval = t1a[j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  t1a[j] = newval;
                  /*@; BEGIN(Stmt1=Stmt)@*/if (fabs(newerr)>maxerr)  
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
        
     }
   else 
     {
        if (color==BLACK_ITER)  
          {
             /*@;BEGIN(Nest5=Nest)@*/for (i=oddistart; i<iend; i+=1) 
               {
                  t1a = (double*)t2a[i];
                  t1b = (double*)t2b[i];
                  t1c = (double*)t2a[i-1];
                  t1d = (double*)t2a[i+1];
                  /*@; BEGIN(Nest6_Nest8=Nest)@*/for (j=i%2+1; j<jend; j+=2) 
                    {
                       a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                       oldval = t1a[j];
                       newval = a/factor;
                       newerr = oldval-newval;
                       t1a[j] = newval;
                       /*@; BEGIN(Stmt2=Stmt)@*/if (fabs(newerr)>maxerr)  
                         {
                            maxerr = fabs(newerr);
                         }
                    }
               }
             
          }
     }
   *err = maxerr;
}
