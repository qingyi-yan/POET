void POTENG(double* POTA,double* POTR,double* PTRF,long  ProcID) {
   LPOTR = 0.0;
   LPTRF = 0.0;
   half_mol = NMOL/2;
   double _VAR_comp_F_DISP_XDIR;
   double _VAR_comp_F_DISP_XDIR_1;
   double _VAR_comp_F_DISP_XDIR_2;
   double _VAR_comp_F_DISP_YDIR;
   double _VAR_comp_F_DISP_YDIR_1;
   double _VAR_comp_F_DISP_YDIR_2;
   double _VAR_comp_F_DISP_ZDIR;
   double _VAR_comp_F_DISP_ZDIR_1;
   double _VAR_comp_F_DISP_ZDIR_2;
   double _VAR_mol_F_DISP_XDIR;
   double _VAR_mol_F_DISP_XDIR_1;
   double _VAR_mol_F_DISP_XDIR_2;
   double _VAR_mol_F_DISP_YDIR;
   double _VAR_mol_F_DISP_YDIR_1;
   double _VAR_mol_F_DISP_YDIR_2;
   double _VAR_mol_F_DISP_ZDIR;
   double _VAR_mol_F_DISP_ZDIR_1;
   double _VAR_mol_F_DISP_ZDIR_2;
   double _VAR_mol_VM;
   double _VAR_mol_VM_1;
   double _VAR_mol_VM_2;
   int _loop_invariant_0=(NMOL%2==0);
   /*@;BEGIN(Nest8=Nest)@*/for (mol=StartMol[ProcID]; mol<StartMol[ProcID+1]; mol+=1) 
     {
        long  comp_last=mol+half_mol;
        long  icomp;
        if (_loop_invariant_0)  
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
        _VAR_mol_F_DISP_XDIR = VAR[mol].F[DISP][XDIR][0];
        _VAR_mol_F_DISP_XDIR_1 = VAR[mol].F[DISP][XDIR][1];
        _VAR_mol_F_DISP_XDIR_2 = VAR[mol].F[DISP][XDIR][2];
        _VAR_mol_F_DISP_YDIR = VAR[mol].F[DISP][YDIR][0];
        _VAR_mol_F_DISP_YDIR_1 = VAR[mol].F[DISP][YDIR][1];
        _VAR_mol_F_DISP_YDIR_2 = VAR[mol].F[DISP][YDIR][2];
        _VAR_mol_F_DISP_ZDIR = VAR[mol].F[DISP][ZDIR][0];
        _VAR_mol_F_DISP_ZDIR_1 = VAR[mol].F[DISP][ZDIR][1];
        _VAR_mol_F_DISP_ZDIR_2 = VAR[mol].F[DISP][ZDIR][2];
        _VAR_mol_VM = VAR[mol].VM[XDIR];
        _VAR_mol_VM_1 = VAR[mol].VM[YDIR];
        _VAR_mol_VM_2 = VAR[mol].VM[ZDIR];
        /*@;BEGIN(Nest9=Nest)@*/for (icomp=mol+1; icomp<1+comp_last; icomp+=1) 
          {
             comp = icomp;
             /*@;BEGIN(Stmt1=ExpStmt)@*/comp = comp&NMOL1;
             {
                _VAR_comp_F_DISP_XDIR = VAR[comp].F[DISP][XDIR][0];
                _VAR_comp_F_DISP_XDIR_2 = VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt2=DeclStmt)@*/double XMB=VAR[comp].VM[XDIR];
                
                XL[0] = _VAR_mol_VM-XMB;
                XL[1] = _VAR_mol_VM-_VAR_comp_F_DISP_XDIR;
                XL[2] = _VAR_mol_VM-_VAR_comp_F_DISP_XDIR_2;
                XL[3] = _VAR_mol_F_DISP_XDIR-XMB;
                XL[4] = _VAR_mol_F_DISP_XDIR_2-XMB;
                XL[5] = _VAR_mol_F_DISP_XDIR-_VAR_comp_F_DISP_XDIR;
                XL[6] = _VAR_mol_F_DISP_XDIR-_VAR_comp_F_DISP_XDIR_2;
                XL[7] = _VAR_mol_F_DISP_XDIR_2-_VAR_comp_F_DISP_XDIR;
                XL[8] = _VAR_mol_F_DISP_XDIR_2-_VAR_comp_F_DISP_XDIR_2;
                
                
                
                
                
                
             }
             {
                _VAR_comp_F_DISP_YDIR = VAR[comp].F[DISP][YDIR][0];
                _VAR_comp_F_DISP_YDIR_2 = VAR[comp].F[DISP][YDIR][2];
                /*@;BEGIN(Stmt9=DeclStmt)@*/double XMB=VAR[comp].VM[YDIR];
                
                YL[0] = _VAR_mol_VM_1-XMB;
                YL[1] = _VAR_mol_VM_1-_VAR_comp_F_DISP_YDIR;
                YL[2] = _VAR_mol_VM_1-_VAR_comp_F_DISP_YDIR_2;
                YL[3] = _VAR_mol_F_DISP_YDIR-XMB;
                YL[4] = _VAR_mol_F_DISP_YDIR_2-XMB;
                YL[5] = _VAR_mol_F_DISP_YDIR-_VAR_comp_F_DISP_YDIR;
                YL[6] = _VAR_mol_F_DISP_YDIR-_VAR_comp_F_DISP_YDIR_2;
                YL[7] = _VAR_mol_F_DISP_YDIR_2-_VAR_comp_F_DISP_YDIR;
                YL[8] = _VAR_mol_F_DISP_YDIR_2-_VAR_comp_F_DISP_YDIR_2;
                
                
                
                
                
                
             }
             {
                _VAR_comp_F_DISP_ZDIR = VAR[comp].F[DISP][ZDIR][0];
                _VAR_comp_F_DISP_ZDIR_2 = VAR[comp].F[DISP][ZDIR][2];
                /*@;BEGIN(Stmt16=DeclStmt)@*/double XMB=VAR[comp].VM[ZDIR];
                /*@;BEGIN(Stmt17=DeclStmt)@*/long  I;
                ZL[0] = _VAR_mol_VM_2-XMB;
                ZL[1] = _VAR_mol_VM_2-_VAR_comp_F_DISP_ZDIR;
                ZL[2] = _VAR_mol_VM_2-_VAR_comp_F_DISP_ZDIR_2;
                ZL[3] = _VAR_mol_F_DISP_ZDIR-XMB;
                ZL[4] = _VAR_mol_F_DISP_ZDIR_2-XMB;
                ZL[5] = _VAR_mol_F_DISP_ZDIR-_VAR_comp_F_DISP_ZDIR;
                ZL[6] = _VAR_mol_F_DISP_ZDIR-_VAR_comp_F_DISP_ZDIR_2;
                ZL[7] = _VAR_mol_F_DISP_ZDIR_2-_VAR_comp_F_DISP_ZDIR;
                ZL[8] = _VAR_mol_F_DISP_ZDIR_2-_VAR_comp_F_DISP_ZDIR_2;
                
                
                
                
                
                /*@;BEGIN(Nest1_3=Nest)@*/for (I=0; I<9; I+=1) 
                  {
                     /*@;BEGIN(Nest1_1=Nest)@*/if (fabs(XL[I])>BOXH)  
                       {
                          XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                     /*@;BEGIN(Nest1_2=Nest)@*/if (fabs(YL[I])>BOXH)  
                       {
                          YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
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
                       _VAR_comp_F_DISP_XDIR_1 = VAR[comp].F[DISP][XDIR][1];
                       _VAR_comp_F_DISP_YDIR_1 = VAR[comp].F[DISP][YDIR][1];
                       _VAR_comp_F_DISP_ZDIR_1 = VAR[comp].F[DISP][ZDIR][1];
                       {
                          XL[9] = _VAR_mol_F_DISP_XDIR_1-_VAR_comp_F_DISP_XDIR_1;
                          XL[10] = _VAR_mol_F_DISP_XDIR_1-_VAR_comp_F_DISP_XDIR;
                          XL[11] = _VAR_mol_F_DISP_XDIR_1-_VAR_comp_F_DISP_XDIR_2;
                          XL[12] = _VAR_mol_F_DISP_XDIR-_VAR_comp_F_DISP_XDIR_1;
                          XL[13] = _VAR_mol_F_DISP_XDIR_2-_VAR_comp_F_DISP_XDIR_1;
                          YL[9] = _VAR_mol_F_DISP_YDIR_1-_VAR_comp_F_DISP_YDIR_1;
                          YL[10] = _VAR_mol_F_DISP_YDIR_1-_VAR_comp_F_DISP_YDIR;
                          YL[11] = _VAR_mol_F_DISP_YDIR_1-_VAR_comp_F_DISP_YDIR_2;
                          YL[12] = _VAR_mol_F_DISP_YDIR-_VAR_comp_F_DISP_YDIR_1;
                          YL[13] = _VAR_mol_F_DISP_YDIR_2-_VAR_comp_F_DISP_YDIR_1;
                          long  I;
                          ZL[9] = _VAR_mol_F_DISP_ZDIR_1-_VAR_comp_F_DISP_ZDIR_1;
                          ZL[10] = _VAR_mol_F_DISP_ZDIR_1-_VAR_comp_F_DISP_ZDIR;
                          ZL[11] = _VAR_mol_F_DISP_ZDIR_1-_VAR_comp_F_DISP_ZDIR_2;
                          ZL[12] = _VAR_mol_F_DISP_ZDIR-_VAR_comp_F_DISP_ZDIR_1;
                          ZL[13] = _VAR_mol_F_DISP_ZDIR_2-_VAR_comp_F_DISP_ZDIR_1;
                          for (I=9; I<14; I+=1) 
                            {
                               /*@;BEGIN(Nest1_1=Nest)@*/if (fabs(XL[I])>BOXH)  
                                 {
                                    XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                               /*@;BEGIN(Nest1_2=Nest)@*/if (fabs(YL[I])>BOXH)  
                                 {
                                    YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                               if (fabs(ZL[I])>BOXH)  
                                 {
                                    ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                            }
                       }
                       for (K=9; K<14; K+=1) 
                         {
                            RL[K] = sqrt(XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K]);
                         }
                       LPOTR = LPOTR+A1*exp(-B1*RL[9])+A2*(exp(-B2*RL[5])+exp(-B2*RL[6])+exp(-B2*RL[7])+exp(-B2*RL[8]))+A3*(exp(-B3*RL[10])+exp(-B3*RL[11])+exp(-B3*RL[12])+exp(-B3*RL[13]))-A4*(exp(-B4*RL[10])+exp(-B4*RL[11])+exp(-B4*RL[12])+exp(-B4*RL[13]));
                    }
               }
          }
     }
};
