
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
            XL[I]  =  XL[I] - ((XL[I] < 0) ? ((BOXL < 0) ? BOXL : -BOXL) : ((BOXL < 0) ? -BOXL : BOXL));
        }
    }
}


/*@;BEGIN(Func2=FunctionDecl)@*/void POTENG(double *POTA, double *POTR, double *PTRF, long ProcID)
{
    LPOTR=0.0;
    LPTRF=0.0;
    half_mol = NMOL/2;
    for (mol = StartMol[ProcID]; mol < StartMol[ProcID+1]; mol++) {
        long comp_last = mol + half_mol;
        long icomp;
        if (NMOL%2 == 0) {
            if ((half_mol <= mol) && (mol%2 == 0)) {
                comp_last--;
            }
            if ((mol < half_mol) && (comp_last%2 == 1)) {
                comp_last--;
            }
        }
        for (icomp = mol+1; icomp <= comp_last; icomp++) {
            comp = icomp;
            if (comp > NMOL1) comp = comp%NMOL;
            /*@;BEGIN(Stmt1=Stmt)@*/CSHIFT(VAR[mol].F[DISP][XDIR],VAR[comp].F[DISP][XDIR],
                   VAR[mol].VM[XDIR], VAR[comp].VM[XDIR],XL,BOXH,BOXL);
            /*@;BEGIN(Stmt2=Stmt)@*/CSHIFT(VAR[mol].F[DISP][YDIR],VAR[comp].F[DISP][YDIR],
                   VAR[mol].VM[YDIR], VAR[comp].VM[YDIR],YL,BOXH,BOXL);
            /*@;BEGIN(Stmt3=Stmt)@*/CSHIFT(VAR[mol].F[DISP][ZDIR],VAR[comp].F[DISP][ZDIR],
                   VAR[mol].VM[ZDIR], VAR[comp].VM[ZDIR],ZL,BOXH,BOXL);
            KC=0;
            for (K = 0; K < 9; K++) {
                RS[K]=XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                if (RS[K] > CUT2)
                    KC=KC+1;
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
                    +QQ /RL[5]+QQ /RL[6]+QQ /RL[7]+QQ /RL[8]
                        +QQ4/RL[0];
                LPTRF= LPTRF-REF2*RS[0]-REF1*((RS[5]+RS[6]+RS[7]+RS[8])*0.5
                                              -RS[1]-RS[2]-RS[3]-RS[4]);

                if (KC <= 0) {
                    for (K = 9; K <  14; K++) {
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
        }
    }
}
