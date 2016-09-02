
/*@; BEGIN(Func1=FunctionDecl)@*/INT	TriPeIntersect(RAY *pr, ELEMENT *pe, IRECORD *hit)
	{
	INT	i;
	REAL	Rd_dot_Pn;		
	REAL	Ro_dot_Pn;		
	REAL	q1, q2;
	REAL	tval;			
	VEC3	*v1, *v2, *v3;
	VEC3	e1, e2, e3;
	TRI	*pt;


	pt = (TRI *)pe->data;

	Rd_dot_Pn = VecDot(pt->norm, pr->D);

	if (ABS(Rd_dot_Pn) < RAYEPS)
		return (0);

	Ro_dot_Pn = VecDot(pt->norm, pr->P);

	tval = -(pt->d + Ro_dot_Pn)/Rd_dot_Pn;
	if (tval < RAYEPS)
		return (0);


	v1 = pt->vptr + pt->vindex[0];

	if (pt->vorder == COUNTER_CLOCKWISE)
		{
		v2 = pt->vptr + pt->vindex[2];
		v3 = pt->vptr + pt->vindex[1];
		}
	else
		{
		v2 = pt->vptr + pt->vindex[1];
		v3 = pt->vptr + pt->vindex[2];
		}

/*@;BEGIN(Stmt1=Stmt)@*/e1[0] = (*v2)[0] - (*v1)[0];
/*@;BEGIN(Stmt2=Stmt)@*/e1[1] = (*v2)[1] - (*v1)[1];
/*@;BEGIN(Stmt3=Stmt)@*/e1[2] = (*v2)[2] - (*v1)[2];

/*@;BEGIN(Stmt4=Stmt)@*/e2[0] = (*v3)[0] - (*v2)[0];
/*@;BEGIN(Stmt5=Stmt)@*/e2[1] = (*v3)[1] - (*v2)[1];
/*@;BEGIN(Stmt6=Stmt)@*/e2[2] = (*v3)[2] - (*v2)[2];

/*@;BEGIN(Stmt7=Stmt)@*/e3[0] = (*v1)[0] - (*v3)[0];
/*@;BEGIN(Stmt8=Stmt)@*/e3[1] = (*v1)[1] - (*v3)[1];
/*@;BEGIN(Stmt9=Stmt)@*/e3[2] = (*v1)[2] - (*v3)[2];

	switch (pt->indx)
		{
		case X_NORM:
			q1 = pr->P[1] + tval*pr->D[1];
			q2 = pr->P[2] + tval*pr->D[2];

/*@;BEGIN(Stmt10=Stmt)@*/hit->b1 = e2[1] * (q2 - (*v2)[2]) - e2[2] * (q1 - (*v2)[1]);
/*@;BEGIN(Stmt11=Stmt)@*/if (!INSIDE(hit->b1, pt->norm[0]))
				return (0);

/*@;BEGIN(Stmt12=Stmt)@*/hit->b2 = e3[1] * (q2 - (*v3)[2]) - e3[2] * (q1 - (*v3)[1]);
/*@;BEGIN(Stmt13=Stmt)@*/if (!INSIDE(hit->b2, pt->norm[0]))
				return (0);

/*@;BEGIN(Stmt14=Stmt)@*/hit->b3 = e1[1] * (q2 - (*v1)[2]) - e1[2] * (q1 - (*v1)[1]);
/*@;BEGIN(Stmt15=Stmt)@*/if (!INSIDE(hit->b3, pt->norm[0]))
				return (0);
			break;

		case Y_NORM:
			q1 = pr->P[0] + tval*pr->D[0];
			q2 = pr->P[2] + tval*pr->D[2];

/*@;BEGIN(Stmt16=Stmt)@*/hit->b1 = e2[2] * (q1 - (*v2)[0]) - e2[0] * (q2 - (*v2)[2]);
/*@;BEGIN(Stmt17=Stmt)@*/if (!INSIDE(hit->b1, pt->norm[1]))
				return (0);

/*@;BEGIN(Stmt18=Stmt)@*/hit->b2 = e3[2] * (q1 - (*v3)[0]) - e3[0] * (q2 - (*v3)[2]);
/*@;BEGIN(Stmt19=Stmt)@*/if (!INSIDE(hit->b2, pt->norm[1]))
				return (0);

/*@;BEGIN(Stmt20=Stmt)@*/hit->b3 = e1[2] * (q1 - (*v1)[0]) - e1[0] * (q2 - (*v1)[2]);
/*@;BEGIN(Stmt21=Stmt)@*/if (!INSIDE(hit->b3, pt->norm[1]))
				return (0);
			break;

		case Z_NORM:
			q1 = pr->P[0] + tval*pr->D[0];
			q2 = pr->P[1] + tval*pr->D[1];

/*@;BEGIN(Stmt22=Stmt)@*/hit->b1 = e2[0] * (q2 - (*v2)[1]) - e2[1] * (q1 - (*v2)[0]);
/*@;BEGIN(Stmt23=Stmt)@*/if (!INSIDE(hit->b1, pt->norm[2]))
				return (0);

/*@;BEGIN(Stmt24=Stmt)@*/hit->b2 = e3[0] * (q2 - (*v3)[1]) - e3[1] * (q1 - (*v3)[0]);
/*@;BEGIN(Stmt25=Stmt)@*/if (!INSIDE(hit->b2, pt->norm[2]))
				return (0);

/*@;BEGIN(Stmt26=Stmt)@*/hit->b3 = e1[0] * (q2 - (*v1)[1]) - e1[1] * (q1 - (*v1)[0]);
/*@;BEGIN(Stmt27=Stmt)@*/if (!INSIDE(hit->b3, pt->norm[2]))
				return (0);
			break;
		}


	IsectAdd(hit, tval, pe);
	return (1);
	}
