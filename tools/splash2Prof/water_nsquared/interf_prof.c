unsigned long _if_9_1=0;
unsigned long _if_9_0=0;
unsigned long _if_8_1=0;
unsigned long _if_8_0=0;
unsigned long _if_7_1=0;
unsigned long _if_7_0=0;
unsigned long _if_6_1=0;
unsigned long _if_6_0=0;
unsigned long _if_5_1=0;
unsigned long _if_5_0=0;
unsigned long _if_4_1=0;
unsigned long _if_4_0=0;
unsigned long _if_3_1=0;
unsigned long _if_3_0=0;
unsigned long _var_index_0=0;
unsigned long _var_array_0[100];
unsigned long _if_2_1=0;
unsigned long _if_2_0=0;
unsigned long _if_1_1=0;
unsigned long _if_1_0=0;
unsigned long _if_0_1=0;
unsigned long _if_0_0=0;
void INTERF(long  DEST,double* VIR,long  ProcID) {
   long  mol;long  comp;long  dir;long  icomp;
   long  comp_last;long  half_mol;
   long  KC;long  K;
   double YL[15];double XL[15];double ZL[15];double RS[15];double FF[15];double RL[15];
   double FTEMP;
   double LVIR=0.0;
   double* temp_p;
   {
      long  ct1;long  ct2;long  ct3;
      
      for (ct1=0; ct1<NMOL; ct1+=1) 
        {
           
           for (ct2=0; ct2<NDIR; ct2+=1) 
             {
                
                for (ct3=0; ct3<NATOM; ct3+=1) 
                  {
                     PFORCES[ProcID][ct1][ct2][ct3] = 0;
                  }
             }
        }
   }
   half_mol = NMOL/2;
   
   for (mol=StartMol[ProcID]; mol<StartMol[ProcID+1]; mol+=1) 
     {
        comp_last = mol+half_mol;
        _if_2_0++;
        if (NMOL%2==0)  
          {
             _if_2_1++;
             _if_0_0++;
             if (half_mol<=mol&&mol%2==0)  
               {
                  _if_0_1++;
                  comp_last--;
               }
             _if_1_0++;
             if (mol<half_mol&&comp_last%2==1)  
               {
                  _if_1_1++;
                  comp_last--;
               }
          }
        
        for (icomp=mol+1; icomp<1+comp_last; icomp+=1) 
          {
             comp = icomp;
             _if_3_0++;
             if (comp>NMOL1)  
               {
                  _if_3_1++;
                  {
                      unsigned long _index;
                      for (_index = 0; _index < _var_index_0; _index++) {
                          if (_var_array_0[_index] == NMOL)
                              break;
                      }
                      if (_index == _var_index_0) {
                          _var_array_0[_var_index_0] = NMOL;
                          _var_index_0++;
                          if (_var_index_0 > 100)
                              printf("[Profile Error] Array Overflow: _var_array_0\n");
                      }
                  }
                  comp = comp%NMOL;
               }
             CSHIFT(VAR[mol].F[DISP][XDIR],VAR[comp].F[DISP][XDIR],VAR[mol].VM[XDIR],VAR[comp].VM[XDIR],XL,BOXH,BOXL);
             CSHIFT(VAR[mol].F[DISP][YDIR],VAR[comp].F[DISP][YDIR],VAR[mol].VM[YDIR],VAR[comp].VM[YDIR],YL,BOXH,BOXL);
             CSHIFT(VAR[mol].F[DISP][ZDIR],VAR[comp].F[DISP][ZDIR],VAR[mol].VM[ZDIR],VAR[comp].VM[ZDIR],ZL,BOXH,BOXL);
             KC = 0;
             
             for (K=0; K<9; K+=1) 
               {
                  RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                  _if_4_0++;
                  if (RS[K]>CUT2)  
                    {
                       _if_4_1++;
                       KC++;
                    }
               }
             _if_9_0++;
             if (KC!=9)  
               {
                  _if_9_1++;
                  
                  for (K=0; K<14; K+=1) 
                    {
                       FF[K] = 0.0;
                    }
                  _if_5_0++;
                  if (RS[0]<CUT2)  
                    {
                       _if_5_1++;
                       FF[0] = QQ4/(RS[0]*sqrt(RS[0]))+REF4;
                       LVIR = LVIR+FF[0]*RS[0];
                    }
                  
                  for (K=1; K<5; K+=1) 
                    {
                       _if_6_0++;
                       if (RS[K]<CUT2)  
                         {
                            _if_6_1++;
                            FF[K] = -QQ2/(RS[K]*sqrt(RS[K]))-REF2;
                            LVIR = LVIR+FF[K]*RS[K];
                         }
                       _if_7_0++;
                       if (RS[K+4]<=CUT2)  
                         {
                            _if_7_1++;
                            RL[K+4] = sqrt(RS[K+4]);
                            FF[K+4] = QQ/(RS[K+4]*RL[K+4])+REF1;
                            LVIR = LVIR+FF[K+4]*RS[K+4];
                         }
                    }
                  _if_8_0++;
                  if (KC==0)  
                    {
                       _if_8_1++;
                       RS[9] = XL[9]*XL[9]+YL[9]*YL[9]+ZL[9]*ZL[9];
                       RL[9] = sqrt(RS[9]);
                       FF[9] = AB1*exp(-B1*RL[9])/RL[9];
                       LVIR = LVIR+FF[9]*RS[9];
                       
                       for (K=10; K<14; K+=1) 
                         {
                            FTEMP = AB2*exp(-B2*RL[K-5])/RL[K-5];
                            FF[K-5] = FF[K-5]+FTEMP;
                            LVIR = LVIR+FTEMP*RS[K-5];
                            RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                            RL[K] = sqrt(RS[K]);
                            FF[K] = (AB3*exp(-B3*RL[K])-AB4*exp(-B4*RL[K]))/RL[K];
                            LVIR = LVIR+FF[K]*RS[K];
                         }
                    }
                  UPDATE_FORCES(mol,comp,XL,YL,ZL,FF,ProcID);
               }
          }
     }
}
void main() {
   printf("\n\n=============================================\n\n");
   printf("Profiling Information:\n\n");
   {
       unsigned long _index;
       printf("[Var Value] Var: NMOL, Value: ");
       for (_index = 0; _index < _var_index_0; _index++) {
           printf("%ld  ", _var_array_0[_index]);
       }
       printf("\n");
   }
   printf("[If Taken Rate] Index: 0, Rate: %f%%\n", ((double)_if_0_1)/((double)_if_0_0)*100);
   printf("[If Taken Rate] Index: 1, Rate: %f%%\n", ((double)_if_1_1)/((double)_if_1_0)*100);
   printf("[If Taken Rate] Index: 2, Rate: %f%%\n", ((double)_if_2_1)/((double)_if_2_0)*100);
   printf("[If Taken Rate] Index: 3, Rate: %f%%\n", ((double)_if_3_1)/((double)_if_3_0)*100);
   printf("[If Taken Rate] Index: 4, Rate: %f%%\n", ((double)_if_4_1)/((double)_if_4_0)*100);
   printf("[If Taken Rate] Index: 5, Rate: %f%%\n", ((double)_if_5_1)/((double)_if_5_0)*100);
   printf("[If Taken Rate] Index: 6, Rate: %f%%\n", ((double)_if_6_1)/((double)_if_6_0)*100);
   printf("[If Taken Rate] Index: 7, Rate: %f%%\n", ((double)_if_7_1)/((double)_if_7_0)*100);
   printf("[If Taken Rate] Index: 8, Rate: %f%%\n", ((double)_if_8_1)/((double)_if_8_0)*100);
   printf("[If Taken Rate] Index: 9, Rate: %f%%\n", ((double)_if_9_1)/((double)_if_9_0)*100);
   printf("\n=============================================\n\n\n");
}
extern unsigned long _if_9_1; 
extern unsigned long _if_9_0; 
extern unsigned long _if_8_1; 
extern unsigned long _if_8_0; 
extern unsigned long _if_7_1; 
extern unsigned long _if_7_0; 
extern unsigned long _if_6_1; 
extern unsigned long _if_6_0; 
extern unsigned long _if_5_1; 
extern unsigned long _if_5_0; 
extern unsigned long _if_4_1; 
extern unsigned long _if_4_0; 
extern unsigned long _if_3_1; 
extern unsigned long _if_3_0; 
extern unsigned long _var_index_0; 
extern unsigned long _var_array_0[100]; 
extern unsigned long _if_2_1; 
extern unsigned long _if_2_0; 
extern unsigned long _if_1_1; 
extern unsigned long _if_1_0; 
extern unsigned long _if_0_1; 
extern unsigned long _if_0_0; 
