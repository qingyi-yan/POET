unsigned long _var_index_0=0;
unsigned long _var_array_0[100];
VOID	IntersectHuniformPrimlist(intersectPrim, hit, v, r, pid)
INT*intersectPrim;
IRECORD*hit;
VOXEL*v;
RAY*r;
INT	pid;
{
ELEMENT**pptr;
OBJECT*peParent;
ELEMENT*pe;
IRECORD newhit[ISECT_MAX];
INT	hitcode,i;
REAL	t_out;
t_out = r->ri->t_out;
hit[0].t = HUGE_REAL;
pptr = (ELEMENT* *)v->cell;

for (i=0; i<v->numelements; i+=1) 
  {
     pe = pptr[i];
     peParent = pe->parent;
     {
         unsigned long _index;
         for (_index = 0; _index < _var_index_0; _index++) {
             if (_var_array_0[_index] == *peParent->procs->pe_intersect)
                 break;
         }
         if (_index == _var_index_0) {
             _var_array_0[_var_index_0] = *peParent->procs->pe_intersect;
             _var_index_0++;
             if (_var_index_0 > 100)
                 printf("[Profile Error] Array Overflow: _var_array_0\n");
         }
     }
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
void main() {
   printf("\n\n=============================================\n\n");
   printf("Profiling Information:\n\n");
   {
       unsigned long _index;
       printf("[Var Value] Var: *peParent->procs->pe_intersect, Value: ");
       for (_index = 0; _index < _var_index_0; _index++) {
           printf("%ld  ", _var_array_0[_index]);
       }
       printf("\n");
   }
   printf("\n=============================================\n\n\n");
}
extern unsigned long _var_index_0; 
extern unsigned long _var_array_0[100]; 
