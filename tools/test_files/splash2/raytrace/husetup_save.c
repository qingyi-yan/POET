VOID IntersectHuniformPrimlist(intersectPrim,hit,v,r,pid) INT* intersectPrim;IRECORD* hit;VOXEL* v;RAY* r;INT pid;{
   ELEMENT** pptr;
   OBJECT* peParent;
   ELEMENT* pe;
   IRECORD newhit[ISECT_MAX];
   INT hitcode;INT i;
   REAL t_out;
   t_out = r->ri->t_out;
   hit[0].t = HUGE_REAL;
   pptr = (ELEMENT**)(v->cell);
   for (i=0; i<v->numelements; i+=1)
     {
        pe = pptr[i];
        peParent = pe->parent;
        
        __builtin_prefetch((const char*)(r->P), 0, 1);
        __builtin_prefetch((const char*)(r->D), 0, 1);
        __builtin_prefetch((const char*)(pe->data), 0, 1);
        hitcode = (*peParent->procs->pe_intersect)(r,pe,newhit);
        if (hitcode) 
          {
             if (newhit[0].t<hit[0].t&&newhit[0].t<t_out) 
               {
                  hit[0] = newhit[0];
               }
          }
     }
   if (hit[0].t<HUGE_REAL) 
     {
        *intersectPrim = TRUE;
     }
   else 
     {
        *intersectPrim = FALSE;
     }
}
