
/*@;BEGIN(Func1=FunctionDecl)@*/void CSHIFT(double *XA, double *XB, double XMA, double XMB, double *XL, double BOXH, double BOXL)
{
    long I;

    XL[0] = XMA-XMB;
    XL[1] = XMA-XB[0];
    XL[2] = XMA-XB[2];
    XL[3] = XA[0]-XMB;
    XL[4] = XA[2]-XMB;
    XL[5] = XA[0]-XB[0];
    XL[6] = XA[0]-XB[2];
    XL[7] = XA[2]-XB[0];
    XL[8] = XA[2]-XB[2];
    XL[9] = XA[1]-XB[1];
    XL[10] = XA[1]-XB[0];
    XL[11] = XA[1]-XB[2];
    XL[12] = XA[0]-XB[1];
    XL[13] = XA[2]-XB[1];

    for (I = 0; I <  14; I++) {
        if (fabs(XL[I]) > BOXH) {
            XL[I]  =  XL[I] - ((XL[I] < 0 ) ? ( (BOXL < 0) ? BOXL : -BOXL) : ( (BOXL < 0) ? -BOXL : BOXL));
        }
    }
}

/*@;BEGIN(Func2=FunctionDecl)@*/void POTENG(double *POTA, double *POTR, double *PTRF, long ProcID)
{
    LPOTR=0.0;
    LPTRF=0.0;
    curr_box = my_boxes[ProcID];
    while (curr_box) {

        i = curr_box->coord[XDIR];
        j = curr_box->coord[YDIR];
        k = curr_box->coord[ZDIR];

        for (XBOX=i-1; XBOX<=i+1; XBOX++) {
            for (YBOX=j-1; YBOX<=j+1; YBOX++) {
                for (ZBOX=k-1; ZBOX<=k+1; ZBOX++) {

                    X_NUM = XBOX;
                    Y_NUM = YBOX;
                    Z_NUM = ZBOX;

                    if ((BOX_PER_SIDE == 2) && ((XBOX < 0) || (XBOX == 2) ||
                                                (YBOX < 0) || (YBOX == 2) ||
                                                (ZBOX < 0) || (ZBOX == 2)))
                        continue;

                    if (X_NUM == -1)
                        X_NUM += BOX_PER_SIDE;
                    else if (X_NUM >= BOX_PER_SIDE)
                        X_NUM -= BOX_PER_SIDE;
                    if (Y_NUM == -1)
                        Y_NUM += BOX_PER_SIDE;
                    else if (Y_NUM >= BOX_PER_SIDE)
                        Y_NUM -= BOX_PER_SIDE;
                    if (Z_NUM == -1)
                        Z_NUM += BOX_PER_SIDE;
                    else if (Z_NUM >= BOX_PER_SIDE)
                        Z_NUM -= BOX_PER_SIDE;

                    if ((X_NUM == i) && (Y_NUM == j) && (Z_NUM == k) &&
                        ((XBOX != i) || (YBOX != j) || (ZBOX !=k))) {
                        continue;
                    }

                    neighbor_ptr = BOX[X_NUM][Y_NUM][Z_NUM].list;
                    while (neighbor_ptr) {
                        curr_ptr = BOX[i][j][k].list;
                        while (curr_ptr) {

                            if (curr_ptr == neighbor_ptr) {
                                curr_ptr = curr_ptr->next_mol;
                                continue;
                            }

    /*@;BEGIN(Stmt1=Stmt)@*/CSHIFT(curr_ptr->mol.F[DISP][XDIR],neighbor_ptr->mol.F[DISP][XDIR],
                                   curr_ptr->mol.VM[XDIR],neighbor_ptr->mol.VM[XDIR],XL,BOXH,BOXL);
    /*@;BEGIN(Stmt2=Stmt)@*/CSHIFT(curr_ptr->mol.F[DISP][YDIR],neighbor_ptr->mol.F[DISP][YDIR],
                                   curr_ptr->mol.VM[YDIR],neighbor_ptr->mol.VM[YDIR],YL,BOXH,BOXL);
    /*@;BEGIN(Stmt3=Stmt)@*/CSHIFT(curr_ptr->mol.F[DISP][ZDIR],neighbor_ptr->mol.F[DISP][ZDIR],
                                   curr_ptr->mol.VM[ZDIR],neighbor_ptr->mol.VM[ZDIR],ZL,BOXH,BOXL);

                            KC=0;
                            for (K = 0; K < 9; K++) {
                                RS[K]=XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                                if (RS[K] > CUT2)
                                    KC++;
                            } 

                            if (KC != 9) {
                                for (K = 0; K < 9; K++) {
                                    if (RS[K] <= CUT2) {
                                        RL[K]=sqrt(RS[K]);
                                    }
                                    else {
                                        RL[K]=CUTOFF;
                                        RS[K]=CUT2;
                                    }
                                } 

                                LPOTR= LPOTR-QQ2/RL[1]-QQ2/RL[2]-QQ2/RL[3]-QQ2/RL[4]
                                    + QQ/RL[5]+ QQ/RL[6]+ QQ/RL[7]+ QQ/RL[8]
                                        + QQ4/RL[0];

                                LPTRF= LPTRF-REF2*RS[0]-REF1*((RS[5]+RS[6]+RS[7]+RS[8])*0.5
                                                              -RS[1]-RS[2]-RS[3]-RS[4]);

                                if (KC <= 0) {
                                    for (K = 9; K <  14; K++)  {
                                        RL[K]=sqrt(XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K]);
                                    }

                                    LPOTR= LPOTR+A1* exp(-B1*RL[9])
                                        +A2*(exp(-B2*RL[ 5])+exp(-B2*RL[ 6])
                                             +exp(-B2*RL[ 7])+exp(-B2*RL[ 8]))
                                            +A3*(exp(-B3*RL[10])+exp(-B3*RL[11])
                                                 +exp(-B3*RL[12])+exp(-B3*RL[13]))
                                                -A4*(exp(-B4*RL[10])+exp(-B4*RL[11])
                                                     +exp(-B4*RL[12])+exp(-B4*RL[13]));
                                } 
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
