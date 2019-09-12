long v_intersect(Patch* patch,Vertex* p,Ray* ray,float t) {
   float px;float py;float pz;
   float nx;float ny;float nz;
   float rx;float ry;float rz;
   float x;float y;float x1;float x2;float x3;float y1;float y2;float y3;
   float a;float b;float c;
   long nc;long sh;long nsh;
   nx = patch->plane_equ.n.x;
   ny = patch->plane_equ.n.y;
   nz = patch->plane_equ.n.z;
   rx = ray->x;
   ry = ray->y;
   rz = ray->z;
   px = p->x;
   py = p->y;
   pz = p->z;
   a = FABS(nx);
   b = FABS(ny);
   c = FABS(nz);
   if (a>b) 
     {
        if (a>c) 
          {
             x = py+t*ry;
             y = pz+t*rz;
             x1 = patch->p1.y;
             y1 = patch->p1.z;
             x2 = patch->p2.y;
             y2 = patch->p2.z;
             x3 = patch->p3.y;
             y3 = patch->p3.z;
          }
     }
   else 
     {
        x = px+t*rx;
        y = py+t*ry;
        x1 = patch->p1.x;
        y1 = patch->p1.y;
        x2 = patch->p2.x;
        y2 = patch->p2.y;
        x3 = patch->p3.x;
        y3 = patch->p3.y;
     }
   else if (b>c) 
     {
        x = px+t*rx;
        y = pz+t*rz;
        x1 = patch->p1.x;
        y1 = patch->p1.z;
        x2 = patch->p2.x;
        y2 = patch->p2.z;
        x3 = patch->p3.x;
        y3 = patch->p3.z;
     }
   else 
     {
        x = px+t*rx;
        y = py+t*ry;
        x1 = patch->p1.x;
        y1 = patch->p1.y;
        x2 = patch->p2.x;
        y2 = patch->p2.y;
        x3 = patch->p3.x;
        y3 = patch->p3.y;
     }
   x1 = x1-x;
   y1 = y1-y;
   x2 = x2-x;
   y2 = y2-y;
   x3 = x3-x;
   y3 = y3-y;
   nc = 0;
   if (y1>=0.0) 
     {
        sh = 1;
     }
   else 
     {
        sh = -1;
     }
   if (y2>=0.0) 
     {
        nsh = 1;
     }
   else 
     {
        nsh = -1;
     }
   if (sh!=nsh) 
     {
        if (x1>=0.0&&x2>=0.0) 
          {
             nc++;
          }
        else if (x1>=0.0||x2>=0.0) 
          {
             if (x1-y1*(x2-x1)/(y2-y1)>0.0) 
               {
                  nc++;
               }
          }
        /*@;BEGIN(Stmt2=ExpStmt)@*/sh = nsh;
     }
   if (y3>=0.0) 
     {
        nsh = 1;
     }
   else 
     {
        nsh = -1;
     }
   if (sh!=nsh) 
     {
        if (x2>=0.0&&x3>=0.0) 
          {
             nc++;
          }
        else if (x2>=0.0||x3>=0.0) 
          {
             if (x2-y2*(x3-x2)/(y3-y2)>0.0) 
               {
                  nc++;
               }
          }
        /*@;BEGIN(Stmt3=ExpStmt)@*/sh = nsh;
     }
   if (y1>=0.0) 
     {
        nsh = 1;
     }
   else 
     {
        nsh = -1;
     }
   if (sh!=nsh) 
     {
        if (x3>=0.0&&x1>=0.0) 
          {
             nc++;
          }
        else if (x3>=0.0||x1>=0.0) 
          {
             if (x1-y1*(x1-x3)/(y1-y3)>0.0) 
               {
                  nc++;
               }
          }
        
     }
   /*@;BEGIN(Stmt1=Nest)@*/if ((nc&0x1)==0) 
     {
        return 0;
     }
   else 
     {
        return 1;
     }
}
/*@;BEGIN(FunctionDecl1=FunctionDecl)@*/long traverse_subtree(Patch* node,Vertex* p,Ray* ray,float r_min,float r_max,long process_id) {
   
   float t;
   long advice;
   /*@;BEGIN(Stmt5=Nest)@*/if (node==0) 
     {
        return 0;
     }
   advice = intersection_type(node,p,ray,&t,r_min,r_max);
   if (advice==POSITIVE_SIDE_FIRST) 
     {
        /*@;BEGIN(Stmt6=Nest)@*/if (node->bsp_positive!=0) 
          {
             if (traverse_subtree(node->bsp_positive,p,ray,r_min,t+VIS_RANGE_MARGIN,process_id)) 
               {
                  return 1;
               }
          }
        if (test_intersection(node,p,ray,t,process_id)) 
          {
             return 1;
          }
        return traverse_subtree(node->bsp_negative,p,ray,t-VIS_RANGE_MARGIN,r_max,process_id);
     }
   else if (advice==NEGATIVE_SIDE_FIRST) 
     {
        /*@;BEGIN(Stmt8=Nest)@*/if (node->bsp_negative!=0) 
          {
             if (traverse_subtree(node->bsp_negative,p,ray,r_min,t+VIS_RANGE_MARGIN,process_id)) 
               {
                  return 1;
               }
          }
        if (test_intersection(node,p,ray,t,process_id)) 
          {
             return 1;
          }
        return traverse_subtree(node->bsp_positive,p,ray,t-VIS_RANGE_MARGIN,r_max,process_id);
     }
   else if (advice==POSITIVE_SUBTREE_ONLY) 
     {
        if (node->bsp_positive==0) 
          {
             return 0;
          }
        else 
          {
             return traverse_subtree(node->bsp_positive,p,ray,r_min,r_max,process_id);
          }
     }
   else if (advice==NEGATIVE_SUBTREE_ONLY) 
     {
        if (node->bsp_negative==0) 
          {
             return 0;
          }
        else 
          {
             return traverse_subtree(node->bsp_negative,p,ray,r_min,r_max,process_id);
          }
     }
   else 
     {
        return 1;
     }
}
