
void INTERF(long  DEST,double* VIR,long  ProcID) {
   curr_box = my_boxes[ProcID];
   /*Nest2*/while (curr_box)  
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
                       /*Nest6*/while (neighbor_ptr)  
                         {
                            curr_ptr = BOX[i][j][k].list;
                            /*Nest7*/while (curr_ptr)  
                              {
                                 if (curr_ptr==neighbor_ptr)  
                                   {
                                      curr_ptr = curr_ptr->next_mol;
                                      continue;
                                   }
                                 {
                                    double XMB=neighbor_ptr->mol.VM[XDIR];
                                    /*@;BEGIN(Stmt1=Stmt)@*/long  I;
                                    XL[0] = curr_ptr->mol.VM[XDIR]-XMB;
                                    XL[1] = curr_ptr->mol.VM[XDIR]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[2] = curr_ptr->mol.VM[XDIR]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[3] = curr_ptr->mol.F[DISP][XDIR][0]-XMB;
                                    XL[4] = curr_ptr->mol.F[DISP][XDIR][2]-XMB;
                                    XL[5] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[6] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    XL[7] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    XL[8] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    /*@;BEGIN(Stmt2=Stmt)@*/XL[9] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    /*@;BEGIN(Stmt3=Stmt)@*/XL[10] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][0];
                                    /*@;BEGIN(Stmt4=Stmt)@*/XL[11] = curr_ptr->mol.F[DISP][XDIR][1]-neighbor_ptr->mol.F[DISP][XDIR][2];
                                    /*@;BEGIN(Stmt5=Stmt)@*/XL[12] = curr_ptr->mol.F[DISP][XDIR][0]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    /*@;BEGIN(Stmt6=Stmt)@*/XL[13] = curr_ptr->mol.F[DISP][XDIR][2]-neighbor_ptr->mol.F[DISP][XDIR][1];
                                    /*@;BEGIN(Nest1_1=Nest)@*/for (I=0; I<14; I+=1) 
                                      {
                                         if (fabs(XL[I])>BOXH)  
                                           {
                                              XL[I] = XL[I]-(XL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
                                      }
                                 }
                                 {
                                    double XMB=neighbor_ptr->mol.VM[YDIR];
                                    /*@;BEGIN(Stmt7=Stmt)@*/long  I;
                                    YL[0] = curr_ptr->mol.VM[YDIR]-XMB;
                                    YL[1] = curr_ptr->mol.VM[YDIR]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[2] = curr_ptr->mol.VM[YDIR]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[3] = curr_ptr->mol.F[DISP][YDIR][0]-XMB;
                                    YL[4] = curr_ptr->mol.F[DISP][YDIR][2]-XMB;
                                    YL[5] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[6] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    YL[7] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    YL[8] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    /*@;BEGIN(Stmt8=Stmt)@*/YL[9] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    /*@;BEGIN(Stmt9=Stmt)@*/YL[10] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][0];
                                    /*@;BEGIN(Stmt10=Stmt)@*/YL[11] = curr_ptr->mol.F[DISP][YDIR][1]-neighbor_ptr->mol.F[DISP][YDIR][2];
                                    /*@;BEGIN(Stmt11=Stmt)@*/YL[12] = curr_ptr->mol.F[DISP][YDIR][0]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    /*@;BEGIN(Stmt12=Stmt)@*/YL[13] = curr_ptr->mol.F[DISP][YDIR][2]-neighbor_ptr->mol.F[DISP][YDIR][1];
                                    /*@;BEGIN(Nest1_2=Nest)@*/for (I=0; I<14; I+=1) 
                                      {
                                         if (fabs(YL[I])>BOXH)  
                                           {
                                              YL[I] = YL[I]-(YL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
                                      }
                                 }
                                 {
                                    double XMB=neighbor_ptr->mol.VM[ZDIR];
                                    /*@;BEGIN(Stmt13=Stmt)@*/long  I;
                                    ZL[0] = curr_ptr->mol.VM[ZDIR]-XMB;
                                    ZL[1] = curr_ptr->mol.VM[ZDIR]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[2] = curr_ptr->mol.VM[ZDIR]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[3] = curr_ptr->mol.F[DISP][ZDIR][0]-XMB;
                                    ZL[4] = curr_ptr->mol.F[DISP][ZDIR][2]-XMB;
                                    ZL[5] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[6] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    ZL[7] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    ZL[8] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    /*@;BEGIN(Stmt14=Stmt)@*/ZL[9] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    /*@;BEGIN(Stmt15=Stmt)@*/ZL[10] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][0];
                                    /*@;BEGIN(Stmt16=Stmt)@*/ZL[11] = curr_ptr->mol.F[DISP][ZDIR][1]-neighbor_ptr->mol.F[DISP][ZDIR][2];
                                    /*@;BEGIN(Stmt17=Stmt)@*/ZL[12] = curr_ptr->mol.F[DISP][ZDIR][0]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    /*@;BEGIN(Stmt18=Stmt)@*/ZL[13] = curr_ptr->mol.F[DISP][ZDIR][2]-neighbor_ptr->mol.F[DISP][ZDIR][1];
                                    /*@;BEGIN(Nest1_3=Nest)@*/for (I=0; I<14; I+=1) 
                                      {
                                         if (fabs(ZL[I])>BOXH)  
                                           {
                                              ZL[I] = ZL[I]-(ZL[I]<0?(BOXL<0?BOXL:-BOXL):(BOXL<0?-BOXL:BOXL));
                                           }
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
                                                LVIR = LVIR+FF[K+4]*RS[K+4];
                                             }
                                        }
                                      if (KC==0)  
                                        {
                                           /*@;BEGIN(Stmt19=Stmt)@*/RS[9] = XL[9]*XL[9]+YL[9]*YL[9]+ZL[9]*ZL[9];
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
