unsigned long _nest_index_index_5=0;
unsigned long _nest_index_array_5[100];
unsigned long _nest_index_index_4=0;
unsigned long _nest_index_array_4[100];
unsigned long _nest_index_index_3=0;
unsigned long _nest_index_array_3[100];
unsigned long _nest_index_index_2=0;
unsigned long _nest_index_array_2[100];
unsigned long _nest_index_index_1=0;
unsigned long _nest_index_array_1[100];
unsigned long _nest_index_index_0=0;
unsigned long _nest_index_array_0[100];
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
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_3; _index++) {
                if (_nest_index_array_3[_index] == jend)
                    break;
            }
            if (_index == _nest_index_index_3) {
                _nest_index_array_3[_nest_index_index_3] = jend;
                _nest_index_index_3++;
                if (_nest_index_index_3 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_3\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_2; _index++) {
                if (_nest_index_array_2[_index] == evenjstart)
                    break;
            }
            if (_index == _nest_index_index_2) {
                _nest_index_array_2[_nest_index_index_2] = evenjstart;
                _nest_index_index_2++;
                if (_nest_index_index_2 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_2\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_1; _index++) {
                if (_nest_index_array_1[_index] == iend)
                    break;
            }
            if (_index == _nest_index_index_1) {
                _nest_index_array_1[_nest_index_index_1] = iend;
                _nest_index_index_1++;
                if (_nest_index_index_1 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_1\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_0; _index++) {
                if (_nest_index_array_0[_index] == evenistart)
                    break;
            }
            if (_index == _nest_index_index_0) {
                _nest_index_array_0[_nest_index_index_0] = evenistart;
                _nest_index_index_0++;
                if (_nest_index_index_0 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_0\n");
            }
        }
        
        for (i=evenistart; i<iend; i+=2) 
          {
             t1a = (double*)t2a[i];
             t1b = (double*)t2b[i];
             t1c = (double*)t2a[i-1];
             t1d = (double*)t2a[i+1];
             
             for (j=evenjstart; j<jend; j+=2) 
               {
                  a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                  oldval = t1a[j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  t1a[j] = newval;
                  
                  if (fabs(newerr)>maxerr)  
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_3; _index++) {
                if (_nest_index_array_3[_index] == jend)
                    break;
            }
            if (_index == _nest_index_index_3) {
                _nest_index_array_3[_nest_index_index_3] = jend;
                _nest_index_index_3++;
                if (_nest_index_index_3 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_3\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_5; _index++) {
                if (_nest_index_array_5[_index] == oddjstart)
                    break;
            }
            if (_index == _nest_index_index_5) {
                _nest_index_array_5[_nest_index_index_5] = oddjstart;
                _nest_index_index_5++;
                if (_nest_index_index_5 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_5\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_1; _index++) {
                if (_nest_index_array_1[_index] == iend)
                    break;
            }
            if (_index == _nest_index_index_1) {
                _nest_index_array_1[_nest_index_index_1] = iend;
                _nest_index_index_1++;
                if (_nest_index_index_1 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_1\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_4; _index++) {
                if (_nest_index_array_4[_index] == oddistart)
                    break;
            }
            if (_index == _nest_index_index_4) {
                _nest_index_array_4[_nest_index_index_4] = oddistart;
                _nest_index_index_4++;
                if (_nest_index_index_4 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_4\n");
            }
        }
        
        for (i=oddistart; i<iend; i+=2) 
          {
             t1a = (double*)t2a[i];
             t1b = (double*)t2b[i];
             t1c = (double*)t2a[i-1];
             t1d = (double*)t2a[i+1];
             
             for (j=oddjstart; j<jend; j+=2) 
               {
                  a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                  oldval = t1a[j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  t1a[j] = newval;
                  
                  if (fabs(newerr)>maxerr)  
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
     }
   
   else if (color==BLACK_ITER)  
     {
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_3; _index++) {
                if (_nest_index_array_3[_index] == jend)
                    break;
            }
            if (_index == _nest_index_index_3) {
                _nest_index_array_3[_nest_index_index_3] = jend;
                _nest_index_index_3++;
                if (_nest_index_index_3 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_3\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_5; _index++) {
                if (_nest_index_array_5[_index] == oddjstart)
                    break;
            }
            if (_index == _nest_index_index_5) {
                _nest_index_array_5[_nest_index_index_5] = oddjstart;
                _nest_index_index_5++;
                if (_nest_index_index_5 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_5\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_1; _index++) {
                if (_nest_index_array_1[_index] == iend)
                    break;
            }
            if (_index == _nest_index_index_1) {
                _nest_index_array_1[_nest_index_index_1] = iend;
                _nest_index_index_1++;
                if (_nest_index_index_1 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_1\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_0; _index++) {
                if (_nest_index_array_0[_index] == evenistart)
                    break;
            }
            if (_index == _nest_index_index_0) {
                _nest_index_array_0[_nest_index_index_0] = evenistart;
                _nest_index_index_0++;
                if (_nest_index_index_0 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_0\n");
            }
        }
        
        for (i=evenistart; i<iend; i+=2) 
          {
             t1a = (double*)t2a[i];
             t1b = (double*)t2b[i];
             t1c = (double*)t2a[i-1];
             t1d = (double*)t2a[i+1];
             
             for (j=oddjstart; j<jend; j+=2) 
               {
                  a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                  oldval = t1a[j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  t1a[j] = newval;
                  
                  if (fabs(newerr)>maxerr)  
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_3; _index++) {
                if (_nest_index_array_3[_index] == jend)
                    break;
            }
            if (_index == _nest_index_index_3) {
                _nest_index_array_3[_nest_index_index_3] = jend;
                _nest_index_index_3++;
                if (_nest_index_index_3 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_3\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_2; _index++) {
                if (_nest_index_array_2[_index] == evenjstart)
                    break;
            }
            if (_index == _nest_index_index_2) {
                _nest_index_array_2[_nest_index_index_2] = evenjstart;
                _nest_index_index_2++;
                if (_nest_index_index_2 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_2\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_1; _index++) {
                if (_nest_index_array_1[_index] == iend)
                    break;
            }
            if (_index == _nest_index_index_1) {
                _nest_index_array_1[_nest_index_index_1] = iend;
                _nest_index_index_1++;
                if (_nest_index_index_1 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_1\n");
            }
        }
        {
            unsigned long _index;
            for (_index = 0; _index < _nest_index_index_4; _index++) {
                if (_nest_index_array_4[_index] == oddistart)
                    break;
            }
            if (_index == _nest_index_index_4) {
                _nest_index_array_4[_nest_index_index_4] = oddistart;
                _nest_index_index_4++;
                if (_nest_index_index_4 > 100)
                    printf("[Profile Error] Array Overflow: _nest_index_array_4\n");
            }
        }
        
        for (i=oddistart; i<iend; i+=2) 
          {
             t1a = (double*)t2a[i];
             t1b = (double*)t2b[i];
             t1c = (double*)t2a[i-1];
             t1d = (double*)t2a[i+1];
             
             for (j=evenjstart; j<jend; j+=2) 
               {
                  a = t1a[j+1]+t1a[j-1]+t1c[j]+t1d[j]-t1b[j];
                  oldval = t1a[j];
                  newval = a/factor;
                  newerr = oldval-newval;
                  t1a[j] = newval;
                  
                  if (fabs(newerr)>maxerr)  
                    {
                       maxerr = fabs(newerr);
                    }
               }
          }
     }
   *err = maxerr;
}
void main() {
   printf("\n\n=============================================\n\n");
   printf("Profiling Information:\n\n");
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: evenistart, Value: ");
       for (_index = 0; _index < _nest_index_index_0; _index++) {
           printf("%ld  ", _nest_index_array_0[_index]);
       }
       printf("\n");
   }
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: iend, Value: ");
       for (_index = 0; _index < _nest_index_index_1; _index++) {
           printf("%ld  ", _nest_index_array_1[_index]);
       }
       printf("\n");
   }
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: evenjstart, Value: ");
       for (_index = 0; _index < _nest_index_index_2; _index++) {
           printf("%ld  ", _nest_index_array_2[_index]);
       }
       printf("\n");
   }
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: jend, Value: ");
       for (_index = 0; _index < _nest_index_index_3; _index++) {
           printf("%ld  ", _nest_index_array_3[_index]);
       }
       printf("\n");
   }
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: oddistart, Value: ");
       for (_index = 0; _index < _nest_index_index_4; _index++) {
           printf("%ld  ", _nest_index_array_4[_index]);
       }
       printf("\n");
   }
   {
       unsigned long _index;
       printf("[Nest Index Value] Index: oddjstart, Value: ");
       for (_index = 0; _index < _nest_index_index_5; _index++) {
           printf("%ld  ", _nest_index_array_5[_index]);
       }
       printf("\n");
   }
   printf("\n=============================================\n\n\n");
}
extern unsigned long _nest_index_index_5; 
extern unsigned long _nest_index_array_5[100]; 
extern unsigned long _nest_index_index_4; 
extern unsigned long _nest_index_array_4[100]; 
extern unsigned long _nest_index_index_3; 
extern unsigned long _nest_index_array_3[100]; 
extern unsigned long _nest_index_index_2; 
extern unsigned long _nest_index_array_2[100]; 
extern unsigned long _nest_index_index_1; 
extern unsigned long _nest_index_array_1[100]; 
extern unsigned long _nest_index_index_0; 
extern unsigned long _nest_index_array_0[100]; 
