
/*@; BEGIN(FunctionDecl1=FunctionDecl)@*/ bool subdivp(register nodeptr p, real dsq, long ProcessId)
{
   //SUBV(Local[ProcessId].dr, Pos(p), Local[ProcessId].pos0);
   Local[ProcessId].dr[0] = (Pos(p))[0] - Local[ProcessId].pos0[0];
   Local[ProcessId].dr[1] = (Pos(p))[1] - Local[ProcessId].pos0[1];
   Local[ProcessId].dr[2] = (Pos(p))[2] - Local[ProcessId].pos0[2];
   //DOTVP(Local[ProcessId].drsq, Local[ProcessId].dr, Local[ProcessId].dr);
   Local[ProcessId].drsq = Local[ProcessId].dr[0] * Local[ProcessId].dr[0] +
                           Local[ProcessId].dr[1] * Local[ProcessId].dr[1] +
                           Local[ProcessId].dr[2] * Local[ProcessId].dr[2];
   Local[ProcessId].pmem = p;
   return (tolsq * Local[ProcessId].drsq < dsq);
}

/*@; BEGIN(FunctionDecl2=FunctionDecl)@*/ void gravsub(register nodeptr p, long ProcessId)
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
/*@; BEGIN(Stmt4=Stmt)@*/phii = Mass(p) / drabs;
/*@; BEGIN(Stmt5=Stmt)@*/Local[ProcessId].phi0 -= phii;
/*@; BEGIN(Stmt6=Stmt)@*/mor3 = phii / Local[ProcessId].drsq;
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

void walksub(nodeptr n, real dsq, long ProcessId)
{
   nodeptr* nn;
   leafptr l;
   bodyptr p;
   long i;

   bool xx;
/*@; BEGIN(Stmt1=Stmt)@*/  xx = subdivp(n, dsq, ProcessId);
   if (xx) {
      if (Type(n) == CELL) {
         for (nn = Subp(n); nn < Subp(n) + NSUB; nn++) {
            if (*nn != NULL) {
               walksub(*nn, dsq / 4.0, ProcessId);
            }
         }
      }
      else {
         l = (leafptr) n;
         for (i = 0; i < l->num_bodies; i++) {
            p = (Bodyp(l))[i];
            if (p != Local[ProcessId].pskip) {
/*@; BEGIN(Stmt2=Stmt)@*/gravsub(p, ProcessId);
            }
            else {
               Local[ProcessId].skipself = TRUE;
            }
         }
      }
   }
   else {
/*@; BEGIN(Stmt3=Stmt)@*/gravsub(n, ProcessId);
   }
}
