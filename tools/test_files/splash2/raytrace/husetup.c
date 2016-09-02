
VOID	IntersectHuniformPrimlist(intersectPrim, hit, v, r, pid)
INT *intersectPrim;
IRECORD *hit;
VOXEL *v;
RAY	*r;
INT	pid;
	{
	ELEMENT **pptr; 		/* Primitive element list ptr.	     */
	OBJECT	*peParent;		/* Ptr to parent object.	     */
	ELEMENT *pe;			/* Primitive element ptr.	     */
	IRECORD newhit[ISECT_MAX];	/* Hit recorder.		     */
	INT	hitcode,i;
	REAL	t_out;

	t_out = r->ri->t_out;
	hit[0].t = HUGE_REAL;
	pptr = (ELEMENT**)v->cell;

	for (i = 0; i < v->numelements; i++)
		{
		pe	 = pptr[i];
		peParent = pe->parent;
/*@;BEGIN(Stmt1=Stmt)@*/hitcode  = (*peParent->procs->pe_intersect)(r, pe, newhit);

		if (hitcode)
			if (newhit[0].t < hit[0].t && newhit[0].t < t_out)
				hit[0] = newhit[0];
		}

	if (hit[0].t < HUGE_REAL)
		*intersectPrim = TRUE;
	else
		*intersectPrim = FALSE;
	}
