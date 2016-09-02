
void gravsub(register nodeptr p, long ProcessId)
{
    real drabs, phii, mor3;
    vector ai;

    if (p != Local[ProcessId].pmem) {
        //SUBV(Local[ProcessId].dr, Pos(p), Local[ProcessId].pos0);
          Local[ProcessId].dr[0] = (Pos(p))[0] - Local[ProcessId].pos0[0];
          Local[ProcessId].dr[1] = (Pos(p))[1] - Local[ProcessId].pos0[1];
          Local[ProcessId].dr[2] = (Pos(p))[2] - Local[ProcessId].pos0[2];
        //DOTVP(Local[ProcessId].drsq, Local[ProcessId].dr, Local[ProcessId].dr);
          Local[ProcessId].drsq = Local[ProcessId].dr[0] * Local[ProcessId].dr[0] +
                                  Local[ProcessId].dr[1] * Local[ProcessId].dr[1] +
                                  Local[ProcessId].dr[2] * Local[ProcessId].dr[2];
    }

    Local[ProcessId].drsq += epssq;
    drabs = sqrt((double) Local[ProcessId].drsq);
    phii = Mass(p) / drabs;
    Local[ProcessId].phi0 -= phii;
    mor3 = phii / Local[ProcessId].drsq;
    //MULVS(ai, Local[ProcessId].dr, mor3);
    ai[0] = Local[ProcessId].dr[0] * mor3;
    ai[1] = Local[ProcessId].dr[1] * mor3;
    ai[2] = Local[ProcessId].dr[2] * mor3;
    ADDV(Local[ProcessId].acc0, Local[ProcessId].acc0, ai);
    if(Type(p) != BODY) {                  /* a body-cell/leaf interaction? */
       Local[ProcessId].mynbcterm++;
    }
    else {                                      /* a body-body interaction  */
       Local[ProcessId].myn2bterm++;
    }
}

void main() {
}
