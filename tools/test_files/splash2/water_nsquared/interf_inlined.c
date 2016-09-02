
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
   /*@;BEGIN(Nest2=Nest)@*/for (mol=StartMol[ProcID]; mol<StartMol[ProcID+1]; mol+=1) 
     {
        comp_last = mol+half_mol;
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
        /*@;BEGIN(Nest3=Nest)@*/for (icomp=mol+1; icomp<1+comp_last; icomp+=1) 
          {
             comp = icomp;
             /*@;BEGIN(Stmt23=Stmt)@*/if (comp>NMOL1)  
               {
                  comp = comp%NMOL;
               }
             {
                /*@;BEGIN(Stmt1=Stmt)@*/double XMB=VAR[comp].VM[XDIR];
                /*@;BEGIN(Stmt2=Stmt)@*/long  I;
                XL[0] = VAR[mol].VM[XDIR]-XMB;
                XL[1] = VAR[mol].VM[XDIR]-VAR[comp].F[DISP][XDIR][0];
                XL[2] = VAR[mol].VM[XDIR]-VAR[comp].F[DISP][XDIR][2];
                XL[3] = VAR[mol].F[DISP][XDIR][0]-XMB;
                XL[4] = VAR[mol].F[DISP][XDIR][2]-XMB;
                XL[5] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][0];
                XL[6] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][2];
                XL[7] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][0];
                XL[8] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt3=Stmt)@*/XL[9] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Stmt4=Stmt)@*/XL[10] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][0];
                /*@;BEGIN(Stmt5=Stmt)@*/XL[11] = VAR[mol].F[DISP][XDIR][1]-VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt6=Stmt)@*/XL[12] = VAR[mol].F[DISP][XDIR][0]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Stmt7=Stmt)@*/XL[13] = VAR[mol].F[DISP][XDIR][2]-VAR[comp].F[DISP][XDIR][1];
                /*@;BEGIN(Nest11=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(XL[I])>BOXH)  
                       {
                          XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             {
                /*@;BEGIN(Stmt8=Stmt)@*/double XMB=VAR[comp].VM[YDIR];
                /*@;BEGIN(Stmt9=Stmt)@*/long  I;
                YL[0] = VAR[mol].VM[YDIR]-XMB;
                YL[1] = VAR[mol].VM[YDIR]-VAR[comp].F[DISP][YDIR][0];
                YL[2] = VAR[mol].VM[YDIR]-VAR[comp].F[DISP][YDIR][2];
                YL[3] = VAR[mol].F[DISP][YDIR][0]-XMB;
                YL[4] = VAR[mol].F[DISP][YDIR][2]-XMB;
                YL[5] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][0];
                YL[6] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][2];
                YL[7] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][0];
                YL[8] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][2];
                /*@;BEGIN(Stmt10=Stmt)@*/YL[9] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Stmt11=Stmt)@*/YL[10] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][0];
                /*@;BEGIN(Stmt12=Stmt)@*/YL[11] = VAR[mol].F[DISP][YDIR][1]-VAR[comp].F[DISP][YDIR][2];
                /*@;BEGIN(Stmt13=Stmt)@*/YL[12] = VAR[mol].F[DISP][YDIR][0]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Stmt14=Stmt)@*/YL[13] = VAR[mol].F[DISP][YDIR][2]-VAR[comp].F[DISP][YDIR][1];
                /*@;BEGIN(Nest12=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(YL[I])>BOXH)  
                       {
                          YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             {
                /*@;BEGIN(Stmt15=Stmt)@*/double XMB=VAR[comp].VM[ZDIR];
                /*@;BEGIN(Stmt16=Stmt)@*/long  I;
                ZL[0] = VAR[mol].VM[ZDIR]-XMB;
                ZL[1] = VAR[mol].VM[ZDIR]-VAR[comp].F[DISP][ZDIR][0];
                ZL[2] = VAR[mol].VM[ZDIR]-VAR[comp].F[DISP][ZDIR][2];
                ZL[3] = VAR[mol].F[DISP][ZDIR][0]-XMB;
                ZL[4] = VAR[mol].F[DISP][ZDIR][2]-XMB;
                ZL[5] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][0];
                ZL[6] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][2];
                ZL[7] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][0];
                ZL[8] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][2];
                /*@;BEGIN(Stmt17=Stmt)@*/ZL[9] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Stmt18=Stmt)@*/ZL[10] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][0];
                /*@;BEGIN(Stmt19=Stmt)@*/ZL[11] = VAR[mol].F[DISP][ZDIR][1]-VAR[comp].F[DISP][ZDIR][2];
                /*@;BEGIN(Stmt20=Stmt)@*/ZL[12] = VAR[mol].F[DISP][ZDIR][0]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Stmt21=Stmt)@*/ZL[13] = VAR[mol].F[DISP][ZDIR][2]-VAR[comp].F[DISP][ZDIR][1];
                /*@;BEGIN(Nest13=Nest)@*/for (I=0; I<14; I+=1) 
                  {
                     if (fabs(ZL[I])>BOXH)  
                       {
                          ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                  }
             }
             KC = 0;
             /*@;BEGIN(Nest4=Nest)@*/for (K=0; K<9; K+=1) 
               {
                  RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                  if (RS[K]>CUT2)  
                    {
                       KC++;
                    }
               }
             if (KC!=9)  
               {
                  /*@;BEGIN(Nest5=Nest)@*/for (K=0; K<14; K+=1) 
                    {
                       FF[K] = 0.0;
                    }
                  if (RS[0]<CUT2)  
                    {
                       FF[0] = QQ4/(RS[0]*sqrt(RS[0]))+REF4;
                       LVIR = LVIR+FF[0]*RS[0];
                    }
                  /*@;BEGIN(Nest6=Nest)@*/for (K=1; K<5; K+=1) 
                    {
                       if (RS[K]<CUT2)  
                         {
                            FF[K] = -QQ2/(RS[K]*sqrt(RS[K]))-REF2;
                            LVIR = LVIR+FF[K]*RS[K];
                         }
                       if (RS[K+4]<=CUT2)  
                         {
                            RL[K+4] = sqrt(RS[K+4]);
                            FF[K+4] = QQ/(RS[K+4]*RL[K+4])+REF1;
                            LVIR = LVIR+FF[K+4]*RS[K+4];
                         }
                    }
                  if (KC==0)  
                    {
                       /*@;BEGIN(Stmt22=Stmt)@*/RS[9] = XL[9]*XL[9]+YL[9]*YL[9]+ZL[9]*ZL[9];
                       RL[9] = sqrt(RS[9]);
                       FF[9] = AB1*exp(-B1*RL[9])/RL[9];
                       LVIR = LVIR+FF[9]*RS[9];
                       /*@;BEGIN(Nest7=Nest)@*/for (K=10; K<14; K+=1) 
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
