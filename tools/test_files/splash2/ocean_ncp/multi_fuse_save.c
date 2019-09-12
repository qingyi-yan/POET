void relax(long k,double* err,long color,long my_num) {
   long i;
   long j;
   long iend;
   long jend;
   long oddistart;
   long oddjstart;
   long evenistart;
   long evenjstart;
   long oddiendst;
   long eveniendst;
   long oddjendst;
   long evenjendst;
   double a;
   double h;
   double factor;
   double maxerr;
   double newerr;
   double oldval;
   double newval;
   i = 0;
   j = 0;
   *err = 0.0;
   h = lev_res[k];
   evenistart = gp[my_num].eist[k];
   evenjstart = gp[my_num].ejst[k];
   oddistart = gp[my_num].oist[k];
   oddjstart = gp[my_num].ojst[k];
   eveniendst = gp[my_num].eiest[k];
   evenjendst = gp[my_num].ejest[k];
   oddiendst = gp[my_num].oiest[k];
   oddjendst = gp[my_num].ojest[k];
   iend = gp[my_num].rel_start_y[k]+gp[my_num].rel_num_y[k];
   jend = gp[my_num].rel_start_x[k]+gp[my_num].rel_num_x[k];
   factor = 4.0-eig2*h*h;
   maxerr = 0.0;
   if (color==RED_ITER) 
     {
        
        /*@;BEGIN(Nest1=Nest)@*/for (i=oddistart; i<iend; i+=1)
          {
             for (j=(i+1)%2+1; j<jend; j+=2)
               {
                  a = multi->q_multi[k][i][j+1]+multi->q_multi[k][i][j-1]+multi->q_multi[k][i-1][j]+multi->q_multi[k][i+1][j]-multi->rhs_multi[k][i][j];
                  oldval = multi->q_multi[k][i][j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  multi->q_multi[k][i][j] = newval;
                  if (fabs(newerr)>maxerr) 
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
        
     }
   else if (color==BLACK_ITER) 
     {
        /*@;BEGIN(Nest5=Nest)@*/for (i=oddistart; i<iend; i+=1)
          {
             for (j=i%2+1; j<jend; j+=2)
               {
                  a = multi->q_multi[k][i][j+1]+multi->q_multi[k][i][j-1]+multi->q_multi[k][i-1][j]+multi->q_multi[k][i+1][j]-multi->rhs_multi[k][i][j];
                  oldval = multi->q_multi[k][i][j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  multi->q_multi[k][i][j] = newval;
                  if (fabs(newerr)>maxerr) 
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
        
     }
   *err = maxerr;
}
