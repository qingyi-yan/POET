void INTERF(long  DEST,double* VIR,long  ProcID) {
   long  mol;
   long  comp;
   long  dir;
   long  icomp;
   long  comp_last;
   long  half_mol;
   long  KC;
   long  K;
   double YL[15];
   double XL[15];
   double ZL[15];
   double RS[15];
   double FF[15];
   double RL[15];
   double FTEMP;
   double LVIR=0.0;
   double* temp_p;
   {
      long  ct1;
      long  ct2;
      long  ct3;
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
   /*@;BEGIN(Nest2=Nest)@*/for (mol=StartMol[ProcID]; mol<StartMol[ProcID+1]; mol+=1) 
     {
        comp_last = mol+half_mol;
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
        /*@;BEGIN(Nest3=Nest)@*/for (icomp=mol+1; icomp<1+comp_last; icomp+=1) 
          {
             comp = icomp;
             /*@;BEGIN(Stmt23=ExpStmt)@*/comp = comp&NMOL1;
             {
                _VAR_comp_F_DISP_XDIR = VAR[comp].F[DISP][XDIR][0];
                _VAR_comp_F_DISP_XDIR_2 = VAR[comp].F[DISP][XDIR][2];
                /*@;BEGIN(Stmt1=DeclStmt)@*/double XMB=VAR[comp].VM[XDIR];
                
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
                /*@;BEGIN(Stmt8=DeclStmt)@*/double XMB=VAR[comp].VM[YDIR];
                
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
                /*@;BEGIN(Stmt15=DeclStmt)@*/double XMB=VAR[comp].VM[ZDIR];
                /*@;BEGIN(Stmt16=DeclStmt)@*/long  I;
                ZL[0] = _VAR_mol_VM_2-XMB;
                ZL[1] = _VAR_mol_VM_2-_VAR_comp_F_DISP_ZDIR;
                ZL[2] = _VAR_mol_VM_2-_VAR_comp_F_DISP_ZDIR_2;
                ZL[3] = _VAR_mol_F_DISP_ZDIR-XMB;
                ZL[4] = _VAR_mol_F_DISP_ZDIR_2-XMB;
                ZL[5] = _VAR_mol_F_DISP_ZDIR-_VAR_comp_F_DISP_ZDIR;
                ZL[6] = _VAR_mol_F_DISP_ZDIR-_VAR_comp_F_DISP_ZDIR_2;
                ZL[7] = _VAR_mol_F_DISP_ZDIR_2-_VAR_comp_F_DISP_ZDIR;
                ZL[8] = _VAR_mol_F_DISP_ZDIR_2-_VAR_comp_F_DISP_ZDIR_2;
                
                
                
                
                
                /*@;BEGIN(Nest13=Nest)@*/for (I=0; I<9; I+=1) 
                  {
                     /*@;BEGIN(Nest11=Nest)@*/if (fabs(XL[I])>BOXH)  
                       {
                          XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                       }
                     /*@;BEGIN(Nest12=Nest)@*/if (fabs(YL[I])>BOXH)  
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
                               /*@;BEGIN(Nest11=Nest)@*/if (fabs(XL[I])>BOXH)  
                                 {
                                    XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                               /*@;BEGIN(Nest12=Nest)@*/if (fabs(YL[I])>BOXH)  
                                 {
                                    YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                               if (fabs(ZL[I])>BOXH)  
                                 {
                                    ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                 }
                            }
                       }
                       RS[9] = XL[9]*XL[9]+YL[9]*YL[9]+ZL[9]*ZL[9];
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
};
