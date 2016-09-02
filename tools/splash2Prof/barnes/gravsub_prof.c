void gravsub(register nodeptr p,long  ProcessId) {
   real drabs;real phii;real mor3;
   vector ai;
   
   if (p!=Local[ProcessId].pmem)  
     {
        Local[ProcessId].dr[0] = Pos(p)[0]-Local[ProcessId].pos0[0];
        Local[ProcessId].dr[1] = Pos(p)[1]-Local[ProcessId].pos0[1];
        Local[ProcessId].dr[2] = Pos(p)[2]-Local[ProcessId].pos0[2];
        Local[ProcessId].drsq = Local[ProcessId].dr[0]*Local[ProcessId].dr[0]+Local[ProcessId].dr[1]*Local[ProcessId].dr[1]+Local[ProcessId].dr[2]*Local[ProcessId].dr[2];
     }
   Local[ProcessId].drsq = Local[ProcessId].drsq+epssq;
   drabs = sqrt((double)Local[ProcessId].drsq);
   phii = Mass(p)/drabs;
   {
       if (Mass(p) != phii * drabs) {
           printf("[Profile Conflict] Fp Var: phii fail the test\n");
           exit(-1);
       }
   }
   Local[ProcessId].phi0 = Local[ProcessId].phi0-phii;
   mor3 = phii/Local[ProcessId].drsq;
   {
       if (phii != mor3 * Local[ProcessId].drsq) {
           printf("[Profile Conflict] Fp Var: mor3 fail the test\n");
           exit(-1);
       }
   }
   ai[0] = Local[ProcessId].dr[0]*mor3;
   ai[1] = Local[ProcessId].dr[1]*mor3;
   ai[2] = Local[ProcessId].dr[2]*mor3;
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
void main() {
   printf("\n\n=============================================\n\n");
   printf("Profiling Information:\n\n");
   printf("[Fp Div] Fp Var: phii pass the test\n");
   printf("[Fp Div] Fp Var: mor3 pass the test\n");
   printf("\n=============================================\n\n\n");
}
