
void INTERF(long DEST, double *VIR, long ProcID)
{
    long mol, comp, dir, icomp;
    long comp_last, half_mol;
    long    KC, K;
    double YL[15], XL[15], ZL[15], RS[15], FF[15], RL[15]; 
    double  FTEMP;
    double LVIR = 0.0;
    double *temp_p;

    { 
        long ct1,ct2,ct3;

        for (ct1 = 0; ct1<NMOL; ct1++)
            for (ct2 = 0; ct2<NDIR; ct2++)
                for (ct3 = 0; ct3<NATOM; ct3++)
                    PFORCES[ProcID][ct1][ct2][ct3] = 0;

    }

    half_mol = NMOL/2;
    for (mol = StartMol[ProcID]; mol < StartMol[ProcID+1]; mol++) {
        comp_last = mol + half_mol;
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

            CSHIFT(VAR[mol].F[DISP][XDIR],VAR[comp].F[DISP][XDIR],
                   VAR[mol].VM[XDIR],VAR[comp].VM[XDIR],XL,BOXH,BOXL);
            CSHIFT(VAR[mol].F[DISP][YDIR],VAR[comp].F[DISP][YDIR],
                   VAR[mol].VM[YDIR],VAR[comp].VM[YDIR],YL,BOXH,BOXL);
            CSHIFT(VAR[mol].F[DISP][ZDIR],VAR[comp].F[DISP][ZDIR],
                   VAR[mol].VM[ZDIR],VAR[comp].VM[ZDIR],ZL,BOXH,BOXL);

            KC=0;
            for (K = 0; K < 9; K++) {
                RS[K]=XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                if (RS[K] > CUT2)
                    KC++;
            }

            if (KC != 9) {
                for (K = 0; K < 14; K++)
                    FF[K]=0.0;
                if (RS[0] < CUT2) {
                    FF[0]=QQ4/(RS[0]*sqrt(RS[0]))+REF4;
                    LVIR = LVIR + FF[0]*RS[0];
                }
                for (K = 1; K < 5; K++) {
                    if (RS[K] < CUT2) {
                        FF[K]= -QQ2/(RS[K]*sqrt(RS[K]))-REF2;
                        LVIR = LVIR + FF[K]*RS[K];
                    }
                    if (RS[K+4] <= CUT2) {
                        RL[K+4]=sqrt(RS[K+4]);
                        FF[K+4]=QQ/(RS[K+4]*RL[K+4])+REF1;
                        LVIR = LVIR + FF[K+4]*RS[K+4];
                    }
                }
                if (KC == 0) {
                    RS[9]=XL[9]*XL[9]+YL[9]*YL[9]+ZL[9]*ZL[9];
                    RL[9]=sqrt(RS[9]);
                    FF[9]=AB1*exp(-B1*RL[9])/RL[9];
                    LVIR = LVIR + FF[9]*RS[9];
                    for (K = 10; K < 14; K++) {
                        FTEMP=AB2*exp(-B2*RL[K-5])/RL[K-5];
                        FF[K-5]=FF[K-5]+FTEMP;
                        LVIR= LVIR+FTEMP*RS[K-5];
                        RS[K]=XL[K]*XL[K]+YL[K]*YL[K]+ZL[K]*ZL[K];
                        RL[K]=sqrt(RS[K]);
                        FF[K]=(AB3*exp(-B3*RL[K])-AB4*exp(-B4*RL[K]))/RL[K];
                        LVIR = LVIR + FF[K]*RS[K];
                    }
                }

                UPDATE_FORCES(mol, comp, XL, YL, ZL, FF, ProcID);

            }
        }
    }
}

void main(){
}
