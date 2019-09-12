/*@;BEGIN(Func1=FunctionDecl)@*/void walksub(nodeptr n,real dsq,long ProcessId) {
   real _Local[ProcessId].dr_cp;
   real _Local[ProcessId].dr_cp_1;
   real _Local[ProcessId].dr_cp_2;
   nodeptr* nn;
   leafptr l;
   bodyptr p;
   long i;
   bool xx;
   {
      register nodeptr p=n;
      _Local[ProcessId].dr_cp = Pos(p)[0]-Local[ProcessId].pos0[0];
      _Local[ProcessId].dr_cp_1 = Pos(p)[1]-Local[ProcessId].pos0[1];
      _Local[ProcessId].dr_cp_2 = Pos(p)[2]-Local[ProcessId].pos0[2];
      Local[ProcessId].drsq = _Local[ProcessId].dr_cp*_Local[ProcessId].dr_cp+_Local[ProcessId].dr_cp_1*_Local[ProcessId].dr_cp_1+_Local[ProcessId].dr_cp_2*_Local[ProcessId].dr_cp_2;
      Local[ProcessId].pmem = p;
      xx = tolsq*Local[ProcessId].drsq<dsq;
   }
   if (xx) 
     {
        if (Type(n)==CELL) 
          {
             for (nn=Subp(n); nn<Subp(n)+NSUB; nn+=1)
               {
                  if (*nn!=NULL) 
                    {
                       walksub(*nn,dsq/4.0,ProcessId);
                    }
               }
          }
        else 
          {
             l = (leafptr)n;
             for (i=0; i<l->num_bodies; i+=1)
               {
                  p = Bodyp(l)[i];
                  if (p!=Local[ProcessId].pskip) 
                    {
                       real drabs;
                       real phii;
                       real mor3;
                       vector ai;
                       /*@;BEGIN(Stmt1=StmtBlock)@*/{
                          _Local[ProcessId].dr_cp = Pos(p)[0]-Local[ProcessId].pos0[0];
                          _Local[ProcessId].dr_cp_1 = Pos(p)[1]-Local[ProcessId].pos0[1];
                          _Local[ProcessId].dr_cp_2 = Pos(p)[2]-Local[ProcessId].pos0[2];
                          Local[ProcessId].drsq = _Local[ProcessId].dr_cp*_Local[ProcessId].dr_cp+_Local[ProcessId].dr_cp_1*_Local[ProcessId].dr_cp_1+_Local[ProcessId].dr_cp_2*_Local[ProcessId].dr_cp_2;
                       }
                       Local[ProcessId].drsq = Local[ProcessId].drsq+epssq;
                       drabs = sqrt((double)(Local[ProcessId].drsq));
                       mor3 = Mass(p)/(drabs*Local[ProcessId].drsq);
                       phii = mor3*Local[ProcessId].drsq;
                       Local[ProcessId].phi0 = Local[ProcessId].phi0-phii;
                       ai[0] = _Local[ProcessId].dr_cp*mor3;
                       ai[1] = _Local[ProcessId].dr_cp_1*mor3;
                       ai[2] = _Local[ProcessId].dr_cp_2*mor3;
                       ADDV(Local[ProcessId].acc0,Local[ProcessId].acc0,ai);
                       if (Type(p)!=BODY) 
                         {
                            Local[ProcessId].mynbcterm++;
                         }
                       else 
                         {
                            Local[ProcessId].myn2bterm++;
                         }
                    }
                  else 
                    {
                       Local[ProcessId].skipself = TRUE;
                    }
               }
          }
     }
   else 
     {
        register nodeptr p=n;
        real drabs;
        real phii;
        real mor3;
        vector ai;
        
        Local[ProcessId].drsq = Local[ProcessId].drsq+epssq;
        drabs = sqrt((double)(Local[ProcessId].drsq));
        mor3 = Mass(p)/(drabs*Local[ProcessId].drsq);
        phii = mor3*Local[ProcessId].drsq;
        Local[ProcessId].phi0 = Local[ProcessId].phi0-phii;
        ai[0] = _Local[ProcessId].dr_cp*mor3;
        ai[1] = _Local[ProcessId].dr_cp_1*mor3;
        ai[2] = _Local[ProcessId].dr_cp_2*mor3;
        ADDV(Local[ProcessId].acc0,Local[ProcessId].acc0,ai);
        if (Type(p)!=BODY) 
          {
             Local[ProcessId].mynbcterm++;
          }
        else 
          {
             Local[ProcessId].myn2bterm++;
          }
     }
}
