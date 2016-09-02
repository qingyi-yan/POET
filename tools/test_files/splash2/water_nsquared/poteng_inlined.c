
void POTENG(double* POTA,double* POTR,double* PTRF,long  ProcID) {
   LPOTR = 0.0;
   LPTRF = 0.0;
   half_mol = NMOL/2;
   /*@;BEGIN(Nest8=Nest)@*/for (mol=StartMol[ProcID]; mol<StartMol[ProcID+1]; mol+=1) 
     {
        long  comp_last=mol+half_mol;
        long  icomp;
        if (NMOL%2==0)  
          {
             if (half_mol<=mol&&mol%2==0)  
               {
                  comp_last--;
               }
             if (mol<half_mol&&comp_last%2==1)  
               {
                  comp_last--;
               }
          }
        /*@;BEGIN(Nest9=Nest)@*/for (icomp=mol+1; icomp<1+comp_last; icomp+=1) 
          {
             comp = icomp;
             /*@;BEGIN(Stmt1=Stmt)@*/if (comp>NMOL1)  
               {
                  comp = comp%NMOL;
               }
             {
                /*@;BEGIN(Stmt2=Stmt)@*/double XMB=VAR[comp].VM[XDIR];
                /*@;BEGIN(Stmt3=Stmt)@*/long  I;
                XL[0] = VAR[mol].VM[XDIR]-XMB;
                XL[1] = VAR[mol].VM[XDIR]-VAR[comp].F[DISP][XDIR][0];
                XL[2] = VAR[mol].VM[XDIR]-VAR[comp].F[DISP][XDIR][2];
                XL[3] = VAR[mol].F[DISP][XDIR][0]-XMB;
                XL[4] = VAR[mol].F[DISP][XDIR][2]-XMB;
                XL[5] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][0];
                XL[6] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][2];
                XL[7] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][0];
                XL[8] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt4=Stmt)@*/XL[9] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Stmt5=Stmt)@*/XL[10] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][0];
                /*@;BEGIN(Stmt6=Stmt)@*/XL[11] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt7=Stmt)@*/XL[12] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Stmt8=Stmt)@*/XL[13] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Nest1_1=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(XL[I])>BOXH)  
                       {
                          XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             {
                /*@;BEGIN(Stmt9=Stmt)@*/double XMB=VAR[comp].VM[YDIR];
                /*@;BEGIN(Stmt10=Stmt)@*/long  I;
                YL[0] = VAR[mol].VM[YDIR]-XMB;
                YL[1] = VAR[mol].VM[YDIR]-VAR[comp].F[DISP][YDIR][0];
                YL[2] = VAR[mol].VM[YDIR]-VAR[comp].F[DISP][YDIR][2];
                YL[3] = VAR[mol].F[DISP][YDIR][0]-XMB;
                YL[4] = VAR[mol].F[DISP][YDIR][2]-XMB;
                YL[5] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][0];
                YL[6] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][2];
                YL[7] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][0];
                YL[8] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][2];
                /*@;BEGIN(Stmt11=Stmt)@*/YL[9] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Stmt12=Stmt)@*/YL[10] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][0];
                /*@;BEGIN(Stmt13=Stmt)@*/YL[11] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][2];
                /*@;BEGIN(Stmt14=Stmt)@*/YL[12] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Stmt15=Stmt)@*/YL[13] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Nest1_2=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(YL[I])>BOXH)  
                       {
                          YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             {
                /*@;BEGIN(Stmt16=Stmt)@*/double XMB=VAR[comp].VM[ZDIR];
                /*@;BEGIN(Stmt17=Stmt)@*/long  I;
                ZL[0] = VAR[mol].VM[ZDIR]-XMB;
                ZL[1] = VAR[mol].VM[ZDIR]-VAR[comp].F[DISP][ZDIR][0];
                ZL[2] = VAR[mol].VM[ZDIR]-VAR[comp].F[DISP][ZDIR][2];
                ZL[3] = VAR[mol].F[DISP][ZDIR][0]-XMB;
                ZL[4] = VAR[mol].F[DISP][ZDIR][2]-XMB;
                ZL[5] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][0];
                ZL[6] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][2];
                ZL[7] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][0];
                ZL[8] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][2];
                /*@;BEGIN(Stmt18=Stmt)@*/ZL[9] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Stmt19=Stmt)@*/ZL[10] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][0];
                /*@;BEGIN(Stmt20=Stmt)@*/ZL[11] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][2];
                /*@;BEGIN(Stmt21=Stmt)@*/ZL[12] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Stmt22=Stmt)@*/ZL[13] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Nest1_3=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(ZL[I])>BOXH)  
                       {
                          ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             KC = 0;
             /*@;BEGIN(Nest10=Nest)@*/for (K=0; K<9; K+=1) 
               {
                  RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                  if (RS[K]>CUT2)  
                    {
                       KC = KC+1;
                    }
               }
             if (KC!=9)  
               {
                  /*@;BEGIN(Nest11=Nest)@*/for (K=0; K<9; K+=1) 
                    {
                       if (RS[K]<=CUT2)  
                         {
                            RL[K] = sqrt(RS[K]);
                         }
                       else 
                         {
                            RL[K] = CUTOFF;
                            RS[K] = CUT2;
                         }
                    }
                  LPOTR = LPOTR-QQ2/RL[1]-QQ2/RL[2]-QQ2/RL[3]-QQ2/RL[4]+QQ/RL[5]+QQ/RL[6]+QQ/RL[7]+QQ/RL[8]+QQ4/RL[0];
                  LPTRF = LPTRF-REF2*RS[0]-REF1*((RS[5]+RS[6]+RS[7]+RS[8])*0.5-RS[1]-RS[2]-RS[3]-RS[4]);
                  if (KC<=0)  
                    {
                       /*@;BEGIN(Nest12=Nest)@*/for (K=9; K<14; K+=1) 
                         {
                            RL[K] = sqrt(XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K]);
                         }
                       LPOTR = LPOTR+A1*exp(-B1*RL[9])+A2*(exp(-B2*RL[5])+exp(-B2*RL[6])+exp(-B2*RL[7])+exp(-B2*RL[8]))+A3*(exp(-B3*RL[10])+exp(-B3*RL[11])+exp(-B3*RL[12])+exp(-B3*RL[13]))-A4*(exp(-B4*RL[10])+exp(-B4*RL[11])+exp(-B4*RL[12])+exp(-B4*RL[13]));
                    }
               }
          }
     }
}
