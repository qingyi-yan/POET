
void INTERF(long  DEST,double* VIR,long  ProcID) {
   curr_box = my_boxes[ProcID];
   /*@;BEGIN(Nest2=Nest)@*/while (curr_box)  
     {
        i = curr_box->coord[XDIR];
        j = curr_box->coord[YDIR];
        k = curr_box->coord[ZDIR];
        
        /*@;BEGIN(Nest3=Nest)@*/for (XBOX=i-1; XBOX<2+i; XBOX+=1) 
          {
             /*@;BEGIN(Nest4=Nest)@*/for (YBOX=j-1; YBOX<2+j; YBOX+=1) 
               {
                  /*@;BEGIN(Nest5=Nest)@*/for (ZBOX=k-1; ZBOX<2+k; ZBOX+=1) 
                    {
                       if (BOX_PER_SIDE==2&&(((((XBOX<0||XBOX==2)||YBOX<0)||YBOX==2)||ZBOX<0)||ZBOX==2))  
                         {
                            continue;
                         }
                       X_NUM = XBOX;
                       Y_NUM = YBOX;
                       Z_NUM = ZBOX;
                       if (X_NUM==-1)  
                         {
                            X_NUM = X_NUM+BOX_PER_SIDE;
                         }
                       else 
                         {
                            if (X_NUM>=BOX_PER_SIDE)  
                              {
                                 X_NUM = X_NUM-BOX_PER_SIDE;
                              }
                         }
                       if (Y_NUM==-1)  
                         {
                            Y_NUM = Y_NUM+BOX_PER_SIDE;
                         }
                       else 
                         {
                            if (Y_NUM>=BOX_PER_SIDE)  
                              {
                                 Y_NUM = Y_NUM-BOX_PER_SIDE;
                              }
                         }
                       if (Z_NUM==-1)  
                         {
                            Z_NUM = Z_NUM+BOX_PER_SIDE;
                         }
                       else 
                         {
                            if (Z_NUM>=BOX_PER_SIDE)  
                              {
                                 Z_NUM = Z_NUM-BOX_PER_SIDE;
                              }
                         }
                       if (((X_NUM==i&&Y_NUM==j)&&Z_NUM==k)&&((XBOX!=i||YBOX!=j)||ZBOX!=k))  
                         {
                            continue;
                         }
                       neighbor_ptr = BOX[X_NUM][Y_NUM][Z_NUM].list;
                       while (neighbor_ptr)  
                         {
                            curr_ptr = BOX[i][j][k].list;
                            while (curr_ptr)  
                              {
                                 if (curr_ptr==neighbor_ptr)  
                                   {
                                      curr_ptr = curr_ptr->next_mol;
                                      continue;
                                   }
                                 {
                                    double* XA=curr_ptr->mol.F[DISP][XDIR];
                                    double* XB=neighbor_ptr->mol.F[DISP][XDIR];
                                    double XMA=curr_ptr->mol.VM[XDIR];
                                    double XMB=neighbor_ptr->mol.VM[XDIR];
                                    
                                    /*@;BEGIN(Stmt1=Stmt)@*/XL[0] = XMA-XMB;
                                    /*@;BEGIN(Stmt2=Stmt)@*/XL[1] = XMA-XB[0]; 
                                    /*@;BEGIN(Stmt3=Stmt)@*/XL[2] = XMA-XB[2];
                                    /*@;BEGIN(Stmt4=Stmt)@*/XL[3] = XA[0]-XMB;
                                    /*@;BEGIN(Stmt5=Stmt)@*/XL[4] = XA[2]-XMB;
                                    /*@;BEGIN(Stmt6=Stmt)@*/XL[5] = XA[0]-XB[0];
                                    /*@;BEGIN(Stmt7=Stmt)@*/XL[6] = XA[0]-XB[2];
                                    /*@;BEGIN(Stmt8=Stmt)@*/XL[7] = XA[2]-XB[0];
                                    /*@;BEGIN(Stmt9=Stmt)@*/XL[8] = XA[2]-XB[2];
                                    
                                    
                                    
                                    
                                    
                                    /*@;BEGIN(Stmt10=Stmt)@*/if (fabs(XL[0])>BOXH)  
                                      {
                                         XL[0] = XL[0]-(XL[0]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt11=Stmt)@*/if (fabs(XL[1])>BOXH)  
                                      {
                                         XL[1] = XL[1]-(XL[1]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt12=Stmt)@*/if (fabs(XL[2])>BOXH)  
                                      {
                                         XL[2] = XL[2]-(XL[2]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt13=Stmt)@*/if (fabs(XL[3])>BOXH)  
                                      {
                                         XL[3] = XL[3]-(XL[3]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt14=Stmt)@*/if (fabs(XL[4])>BOXH)  
                                      {
                                         XL[4] = XL[4]-(XL[4]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt15=Stmt)@*/if (fabs(XL[5])>BOXH)  
                                      {
                                         XL[5] = XL[5]-(XL[5]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt16=Stmt)@*/if (fabs(XL[6])>BOXH)  
                                      {
                                         XL[6] = XL[6]-(XL[6]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt17=Stmt)@*/if (fabs(XL[7])>BOXH)  
                                      {
                                         XL[7] = XL[7]-(XL[7]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt18=Stmt)@*/if (fabs(XL[8])>BOXH)  
                                      {
                                         XL[8] = XL[8]-(XL[8]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                 }
                                 {
                                    double* XA;
                                    XA = curr_ptr->mol.F[DISP][YDIR];
                                    double* XB;
                                    XB = neighbor_ptr->mol.F[DISP][YDIR];
                                    double XMA;
                                    XMA = curr_ptr->mol.VM[YDIR];
                                    double XMB;
                                    XMB = neighbor_ptr->mol.VM[YDIR];
                                    
                                    /*@;BEGIN(Stmt19=Stmt)@*/YL[0] = XMA-XMB;
                                    /*@;BEGIN(Stmt20=Stmt)@*/YL[1] = XMA-XB[0];
                                    /*@;BEGIN(Stmt21=Stmt)@*/YL[2] = XMA-XB[2];
                                    /*@;BEGIN(Stmt22=Stmt)@*/YL[3] = XA[0]-XMB;
                                    /*@;BEGIN(Stmt23=Stmt)@*/YL[4] = XA[2]-XMB;
                                    /*@;BEGIN(Stmt24=Stmt)@*/YL[5] = XA[0]-XB[0];
                                    /*@;BEGIN(Stmt25=Stmt)@*/YL[6] = XA[0]-XB[2];
                                    /*@;BEGIN(Stmt26=Stmt)@*/YL[7] = XA[2]-XB[0];
                                    /*@;BEGIN(Stmt27=Stmt)@*/YL[8] = XA[2]-XB[2];
                                    
                                    
                                    
                                    
                                    
                                    /*@;BEGIN(Stmt28=Stmt)@*/if (fabs(YL[0])>BOXH)  
                                      {
                                         YL[0] = YL[0]-(YL[0]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt29=Stmt)@*/if (fabs(YL[1])>BOXH)  
                                      {
                                         YL[1] = YL[1]-(YL[1]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt30=Stmt)@*/if (fabs(YL[2])>BOXH)  
                                      {
                                         YL[2] = YL[2]-(YL[2]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt31=Stmt)@*/if (fabs(YL[3])>BOXH)  
                                      {
                                         YL[3] = YL[3]-(YL[3]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt32=Stmt)@*/if (fabs(YL[4])>BOXH)  
                                      {
                                         YL[4] = YL[4]-(YL[4]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt33=Stmt)@*/if (fabs(YL[5])>BOXH)  
                                      {
                                         YL[5] = YL[5]-(YL[5]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt34=Stmt)@*/if (fabs(YL[6])>BOXH)  
                                      {
                                         YL[6] = YL[6]-(YL[6]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt35=Stmt)@*/if (fabs(YL[7])>BOXH)  
                                      {
                                         YL[7] = YL[7]-(YL[7]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt36=Stmt)@*/if (fabs(YL[8])>BOXH)  
                                      {
                                         YL[8] = YL[8]-(YL[8]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                 }
                                 {
                                    double* XA;
                                    XA = curr_ptr->mol.F[DISP][ZDIR];
                                    double* XB;
                                    XB = neighbor_ptr->mol.F[DISP][ZDIR];
                                    double XMA;
                                    XMA = curr_ptr->mol.VM[ZDIR];
                                    double XMB;
                                    XMB = neighbor_ptr->mol.VM[ZDIR];
                                    
                                    /*@;BEGIN(Stmt37=Stmt)@*/ZL[0] = XMA-XMB;
                                    /*@;BEGIN(Stmt38=Stmt)@*/ZL[1] = XMA-XB[0];
                                    /*@;BEGIN(Stmt39=Stmt)@*/ZL[2] = XMA-XB[2];
                                    /*@;BEGIN(Stmt40=Stmt)@*/ZL[3] = XA[0]-XMB;
                                    /*@;BEGIN(Stmt41=Stmt)@*/ZL[4] = XA[2]-XMB;
                                    /*@;BEGIN(Stmt42=Stmt)@*/ZL[5] = XA[0]-XB[0];
                                    /*@;BEGIN(Stmt43=Stmt)@*/ZL[6] = XA[0]-XB[2];
                                    /*@;BEGIN(Stmt44=Stmt)@*/ZL[7] = XA[2]-XB[0];
                                    /*@;BEGIN(Stmt45=Stmt)@*/ZL[8] = XA[2]-XB[2];
                                    
                                    
                                    
                                    
                                    
                                    /*@;BEGIN(Stmt46=Stmt)@*/if (fabs(ZL[0])>BOXH)  
                                      {
                                         ZL[0] = ZL[0]-(ZL[0]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt47=Stmt)@*/if (fabs(ZL[1])>BOXH)  
                                      {
                                         ZL[1] = ZL[1]-(ZL[1]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt48=Stmt)@*/if (fabs(ZL[2])>BOXH)  
                                      {
                                         ZL[2] = ZL[2]-(ZL[2]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt49=Stmt)@*/if (fabs(ZL[3])>BOXH)  
                                      {
                                         ZL[3] = ZL[3]-(ZL[3]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt50=Stmt)@*/if (fabs(ZL[4])>BOXH)  
                                      {
                                         ZL[4] = ZL[4]-(ZL[4]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt51=Stmt)@*/if (fabs(ZL[5])>BOXH)  
                                      {
                                         ZL[5] = ZL[5]-(ZL[5]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt52=Stmt)@*/if (fabs(ZL[6])>BOXH)  
                                      {
                                         ZL[6] = ZL[6]-(ZL[6]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt53=Stmt)@*/if (fabs(ZL[7])>BOXH)  
                                      {
                                         ZL[7] = ZL[7]-(ZL[7]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                    /*@;BEGIN(Stmt54=Stmt)@*/if (fabs(ZL[8])>BOXH)  
                                      {
                                         ZL[8] = ZL[8]-(ZL[8]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                      }
                                 }
                                 KC = 0;
                                 /*@;BEGIN(Nest8=Nest)@*/for (K=0; K<9; K+=1) 
                                   {
                                      RS[K] = XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                                      if (RS[K]>CUT2)  
                                        {
                                           KC++;
                                        }
                                   }
                                 if (KC!=9)  
                                   {
                                      /*@;BEGIN(Nest9=Nest)@*/for (K=0; K<14; K+=1) 
                                        {
                                           FF[K] = 0.0;
                                        }
                                      if (RS[0]<CUT2)  
                                        {
                                           FF[0] = QQ4/(RS[0]*sqrt(RS[0]))+REF4;
                                           LVIR = LVIR+FF[0]*RS[0];
                                        }
                                      /*@;BEGIN(Nest10=Nest)@*/for (K=1; K<5; K+=1) 
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
                                                /*@;BEGIN(Stmt55=Stmt)@*/LVIR = LVIR+FF[K+4]*RS[K+4];
                                             }
                                        }
                                      if (KC==0)  
                                        {
                                           {
                                              double* XA=curr_ptr->mol.F[DISP][XDIR];
                                              double* XB=neighbor_ptr->mol.F[DISP][XDIR];
                                              double XMA=curr_ptr->mol.VM[XDIR];
                                              double XMB=neighbor_ptr->mol.VM[XDIR];
                                              long  I;
                                              XL[9] = XA[1]-XB[1];
                                              XL[10] = XA[1]-XB[0];
                                              XL[11] = XA[1]-XB[2];
                                              XL[12] = XA[0]-XB[1];
                                              XL[13] = XA[2]-XB[1];
                                              for (I=9; I<14; I+=1) 
                                                {
                                                   if (fabs(XL[I])>BOXH)  
                                                     {
                                                        XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                                     }
                                                }
                                              XA = curr_ptr->mol.F[DISP][YDIR];
                                              XB = neighbor_ptr->mol.F[DISP][YDIR];
                                              XMA = curr_ptr->mol.VM[YDIR];
                                              XMB = neighbor_ptr->mol.VM[YDIR];
                                              YL[9] = XA[1]-XB[1];
                                              YL[10] = XA[1]-XB[0];
                                              YL[11] = XA[1]-XB[2];
                                              YL[12] = XA[0]-XB[1];
                                              YL[13] = XA[2]-XB[1];
                                              for (I=9; I<14; I+=1) 
                                                {
                                                   if (fabs(YL[I])>BOXH)  
                                                     {
                                                        YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                                     }
                                                }
                                              XA = curr_ptr->mol.F[DISP][ZDIR];
                                              XB = neighbor_ptr->mol.F[DISP][ZDIR];
                                              XMA = curr_ptr->mol.VM[ZDIR];
                                              XMB = neighbor_ptr->mol.VM[ZDIR];
                                              ZL[9] = XA[1]-XB[1];
                                              ZL[10] = XA[1]-XB[0];
                                              ZL[11] = XA[1]-XB[2];
                                              ZL[12] = XA[0]-XB[1];
                                              ZL[13] = XA[2]-XB[1];
                                              for (I=9; I<14; I+=1) 
                                                {
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
                                           /*@;BEGIN(Nest11=Nest)@*/for (K=10; K<14; K+=1) 
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
                                      UPDATE_FORCES(curr_ptr,DEST,XL,YL,ZL,FF);
                                   }
                                 curr_ptr = curr_ptr->next_mol;
                              }
                            neighbor_ptr = neighbor_ptr->next_mol;
                         }
                    }
               }
          }
        curr_box = curr_box->next_box;
     }
}
