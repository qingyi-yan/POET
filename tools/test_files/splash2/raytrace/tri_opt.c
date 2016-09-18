/*@;BEGIN(Func1=FunctionDecl)@*/INT TriPeIntersect(RAY* pr,ELEMENT* pe,IRECORD* hit) {
   REAL _v1;
   REAL _v1_1;
   REAL _v1_2;
   REAL _v2;
   REAL _v2_1;
   REAL _v2_2;
   REAL _v3;
   REAL _v3_1;
   REAL _v3_2;
   INT i;
   REAL Rd_dot_Pn;
   REAL Ro_dot_Pn;
   REAL q1;REAL q2;
   REAL tval;
   VEC3* v1;VEC3* v2;VEC3* v3;
   VEC3 e1;VEC3 e2;VEC3 e3;
   TRI* pt;
   pt = (TRI*)(pe->data);
   Rd_dot_Pn = VecDot(pt->norm,pr->D);
   if (ABS(Rd_dot_Pn)<RAYEPS)  
     {
        return 0;
     }
   Ro_dot_Pn = VecDot(pt->norm,pr->P);
   tval = -(pt->d+Ro_dot_Pn)/Rd_dot_Pn;
   if (tval<RAYEPS)  
     {
        return 0;
     }
   v1 = pt->vptr+pt->vindex[0];
   if (pt->vorder==COUNTER_CLOCKWISE)  
     {
        v2 = pt->vptr+pt->vindex[2];
        v3 = pt->vptr+pt->vindex[1];
     }
   else  
     {
        v2 = pt->vptr+pt->vindex[1];
        v3 = pt->vptr+pt->vindex[2];
     }
   
   
   
   
   
   
   
   
   
   switch (pt->indx)
   {
     case X_NORM:
       q1 = pr->P[1]+tval*pr->D[1];
       q2 = pr->P[2]+tval*pr->D[2];
       _v2_1 = (*v2)[1];
       _v2_2 = (*v2)[2];
       _v3_1 = (*v3)[1];
       _v3_2 = (*v3)[2];
       e2[1] = _v3_1-_v2_1;
       e2[2] = _v3_2-_v2_2;
       /*@;BEGIN(Stmt10=ExpStmt)@*/hit->b1 = e2[1]*(q2-_v2_2)-e2[2]*(q1-_v2_1);
       /*@;BEGIN(Stmt11=Nest)@*/if (!INSIDE(hit->b1,pt->norm[0]))  
         {
            return 0;
         }
       _v1_1 = (*v1)[1];
       _v1_2 = (*v1)[2];
       e3[1] = _v1_1-_v3_1;
       e3[2] = _v1_2-_v3_2;
       /*@;BEGIN(Stmt12=ExpStmt)@*/hit->b2 = e3[1]*(q2-_v3_2)-e3[2]*(q1-_v3_1);
       /*@;BEGIN(Stmt13=Nest)@*/if (!INSIDE(hit->b2,pt->norm[0]))  
         {
            return 0;
         }
       e1[1] = _v2_1-_v1_1;
       e1[2] = _v2_2-_v1_2;
       /*@;BEGIN(Stmt14=ExpStmt)@*/hit->b3 = e1[1]*(q2-_v1_2)-e1[2]*(q1-_v1_1);
       /*@;BEGIN(Stmt15=Nest)@*/if (!INSIDE(hit->b3,pt->norm[0]))  
         {
            return 0;
         }
       break;
     case Y_NORM:
       q1 = pr->P[0]+tval*pr->D[0];
       q2 = pr->P[2]+tval*pr->D[2];
       _v2 = (*v2)[0];
       _v2_2 = (*v2)[2];
       _v3 = (*v3)[0];
       _v3_2 = (*v3)[2];
       e2[0] = _v3-_v2;
       e2[2] = _v3_2-_v2_2;
       /*@;BEGIN(Stmt16=ExpStmt)@*/hit->b1 = e2[2]*(q1-_v2)-e2[0]*(q2-_v2_2);
       /*@;BEGIN(Stmt17=Nest)@*/if (!INSIDE(hit->b1,pt->norm[1]))  
         {
            return 0;
         }
       _v1 = (*v1)[0];
       _v1_2 = (*v1)[2];
       e3[0] = _v1-_v3;
       e3[2] = _v1_2-_v3_2;
       /*@;BEGIN(Stmt18=ExpStmt)@*/hit->b2 = e3[2]*(q1-_v3)-e3[0]*(q2-_v3_2);
       /*@;BEGIN(Stmt19=Nest)@*/if (!INSIDE(hit->b2,pt->norm[1]))  
         {
            return 0;
         }
       e1[0] = _v2-_v1;
       e1[2] = _v2_2-_v1_2;
       /*@;BEGIN(Stmt20=ExpStmt)@*/hit->b3 = e1[2]*(q1-_v1)-e1[0]*(q2-_v1_2);
       /*@;BEGIN(Stmt21=Nest)@*/if (!INSIDE(hit->b3,pt->norm[1]))  
         {
            return 0;
         }
       break;
     case Z_NORM:
       q1 = pr->P[0]+tval*pr->D[0];
       q2 = pr->P[1]+tval*pr->D[1];
       _v2 = (*v2)[0];
       _v2_1 = (*v2)[1];
       _v3 = (*v3)[0];
       _v3_1 = (*v3)[1];
       e2[0] = _v3-_v2;
       e2[1] = _v3_1-_v2_1;
       /*@;BEGIN(Stmt22=ExpStmt)@*/hit->b1 = e2[0]*(q2-_v2_1)-e2[1]*(q1-_v2);
       /*@;BEGIN(Stmt23=Nest)@*/if (!INSIDE(hit->b1,pt->norm[2]))  
         {
            return 0;
         }
       _v1 = (*v1)[0];
       _v1_1 = (*v1)[1];
       e3[0] = _v1-_v3;
       e3[1] = _v1_1-_v3_1;
       /*@;BEGIN(Stmt24=ExpStmt)@*/hit->b2 = e3[0]*(q2-_v3_1)-e3[1]*(q1-_v3);
       /*@;BEGIN(Stmt25=Nest)@*/if (!INSIDE(hit->b2,pt->norm[2]))  
         {
            return 0;
         }
       e1[0] = _v2-_v1;
       e1[1] = _v2_1-_v1_1;
       /*@;BEGIN(Stmt26=ExpStmt)@*/hit->b3 = e1[0]*(q2-_v1_1)-e1[1]*(q1-_v1);
       if (!INSIDE(hit->b3,pt->norm[2]))  
         {
            return 0;
         }
       break;
   }
   IsectAdd(hit,tval,pe);
   return 1;
}
