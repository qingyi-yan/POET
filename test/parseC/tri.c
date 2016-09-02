/* #begin poet-gui

Nests: Nest1
UnrollLoop:target=Nest1 factor=4

#end poet-gui */

#define VOID            void
#define FALSE           0
#define TRUE            1
#define HUGE_REAL       1e+32
#define ISECT_MAX       2

#define NAME_LEN        30

#define RAYEPS          1e-07
#define MAX_SUBDIV_LEVEL 3
#define MAX_RAYINFO     (MAX_SUBDIV_LEVEL + 1)

#define VecDot(A, B)    ( A[0]*B[0] + A[1]*B[1] + A[2]*B[2] )

#define ABS(A)                  ( (A) > 0.0 ? (A) : -(A) )

#define IsectAdd(hit, tval, P)  { (hit)->t = tval;  \
                                  (hit)->pelem = P; }

#define X_NORM                  1
#define Y_NORM                  2
#define Z_NORM                  3

#define CLOCKWISE               1
#define COUNTER_CLOCKWISE       2

#define INSIDE(x, a)            (((a) <= 0.0 && (x) >= (a) && (x) <= 0.0) || \
                                ((a)  >  0.0 && (x) >= 0.0 && (x) <= (a)))

typedef		char		CHAR;
typedef		long		INT;
typedef		unsigned long	UINT;
typedef		unsigned long	BOOL;
typedef		long		LONG;
typedef		float		R32;
typedef		double		REAL;
typedef		REAL		VEC3[3];
typedef		VEC3		COLOR;

typedef struct  pprocs
        {
        CHAR        *(*name)();         /* Primitive name.                   */
        VOID        (*print)();         /* Primitive print.                  */
        VOID        (*read)();          /* Read from model file.             */
        VOID        (*binread)();       /* Binary read from model file.      */
        VOID        (*transform)();     /* Transform primitive.              */
        INT         (*intersect)();     /* Intersect object with a ray.      */
        INT         (*pe_intersect)();  /* Intersect primelement with a ray. */
        VOID        (*normal)();        /* Compute normal vector.            */
        VOID        (*normalize)();     /* Data normalization to unit cube.  */
        VOID        (*bbox)();          /* Bounding box constructor.         */
        }
        PPROCS;

typedef struct  surf
        {
        COLOR           fcolor;         /* Front facing color.               */
        COLOR           bcolor;         /* Back facing color.                */
        REAL            kdiff;          /* Diffuse coefficient.              */
        REAL            kspec;          /* Specular coefficient.             */
        REAL            ktran;          /* Transmission coefficient.         */
        REAL            refrindex;      /* Index of refraction.              */
        REAL            kspecn;         /* Specular distribution coeff.      */
        }
        SURF;

typedef struct  bbox
        {
        REAL    dnear[3];
        REAL    dfar[3];
        }
        BBOX;

typedef struct element
        {
        INT             index;
        BBOX            bv;             /* Element bounding volume.          */
        struct object   *parent;        /* Ptr back to parent object.        */
        CHAR            *data;          /* Pointer to data info.             */
        }
        ELEMENT;

typedef struct object
        {
        INT             index;
        CHAR            name[NAME_LEN]; /* Name of object.                   */
        BBOX            bv;             /* Bound volume.                     */
        ELEMENT         *pelem;         /* Pointer to prim element list.     */
        INT             numelements;    /* Number of primitive elements.     */
        PPROCS          *procs;         /* Pointer to primitive procs.       */
        SURF            *surf;          /* Pointer to surface properties.    */
        struct object   *next;          /* Next primitive (linked list).     */
        }
        OBJECT;

typedef struct voxel
        {
        INT             id;             /* id = index1D                      */
        CHAR            *cell;          /* Ptr to grid or ptr to ElemPtr list*/
        CHAR            celltype;       /* 0 => local voxel, 1 => local grid */
                                        /* 2 => GSM voxel, 3 => GSM grid     */
                                        /* 4 => remote voxel, 5 =>remote grid*/
        INT             numelements;    /* Number of elements in voxel.      */
        struct voxel    *next;          /* Hashtable bucket list.            */
        }
        VOXEL;

typedef struct btnode
        {
        ELEMENT **pe;           /* Array of primitive element ptrs in node.  */
        REAL    p[3];           /* Lower left corner of bounding box         */
                                /* of space represented by node.             */
        INT     nprims;         /* # prims in node primElem list.            */
        INT     n[3];           /* Gridsizes for this box.                   */
        INT     i[3];           /* Indices of cell (lower left corner        */
                                /* if not a leaf) in grid.                   */
        INT     axis;           /* subdiv axis, 0,1,2 => x,y,z               */
        INT     totalPrimsAllocated;  /* This is used for garbage allocation.*/
        struct  btnode *btn[2]; /* Ptrs to children.                         */
        }
        BTNODE;

typedef struct grid
        {
        INT             id;
        VOXEL           **hashtable;    /* hashtable[ num_buckets ] is indexed  */
                                        /* by index1D mod num_buckets,          */
                                        /* num_buckets and n, the  # of cells/  */
                                        /* axis, should be relatively prime,    */
                                        /* grids at different  levels may       */
                                        /* have different num_buckets.          */
        UINT            *emptycells;    /* emptycells[ ceil( NumCells           */
                                        /* sizeof(unsigned) ) ], a packed       */
                                        /* array of bits indicating for         */
                                        /* each cell if it is empty,            */
                                        /* 1 => empty,                          */
                                        /* grids at different levels may        */
                                        /* have different NumCells.             */
        ELEMENT         **pepa;         /* prim element pointer list            */
        INT             num_prims;      /* number of prims on prim element      */
                                        /* list                                 */
        INT             indx_inc[3];    /* if n is # of cells per axis,         */
                                        /* NumCells is n**3,                    */
                                        /* indx_inc[0,1,2] = 1, n, n**2;        */
                                        /* inc for index1D.                     */
        INT             num_buckets;    /* # buckets in hashtable               */
        REAL            min[3];         /* cell min boundary, world coord       */
        REAL            cellsize[3];    /* cellsize of voxels in this grid      */
                                        /* in world coord                       */
        INT             subdiv_level;   /* # levels of space subdiv             */
                                        /* to reach this grid,                  */
                                        /* 0 is top level.                      */
        BTNODE          *bintree;       /* root of bintree for this grid        */
        struct grid     *next;          /* grid list                            */
        }
        GRID;

typedef struct  rayinfo
        {
        GRID    *grid;          /* Grid for this rayinfo.                    */
        REAL    d[3];           /* Dist along ray from world coord origin to */
                                /* next voxel boundary.                      */
        INT     entry_plane;    /* Entry plane for current voxel,            */
                                /* (0,1,2) => (x,y,z).                       */
        REAL    t_in;           /* Dist along ray from world coord origin to */
                                /* entry point of current voxel.             */
        INT     exit_plane;     /* Exit plane for current voxel,             */
                                /* (0,1,2) => (x,y,z).                       */
        REAL    t_out;          /* Dist along ray from world coord origin to */
                                /* exit point of current voxel.              */
        REAL    delta[3];       /* Dist along ray between voxel boundaries.  */
        INT     index3D[3];     /* Current cell in cell units wrt grid origin*/
        INT     index1D;        /* Index1D = i + j * n + k * n**2            */
                                /* where  index3D[] = i,j,k and n is the     */
                                /* # of divisions per axis.                  */
        INT     indx_inc1D[3];  /* Including sign of ray direction.          */
        struct  rayinfo *next;  /* Ptr to next structure.                    */
        }
        RAYINFO;

typedef struct  ray
        {
        LONG            id;                     /* Ray id.                   */
        INT             x, y;                   /* Pixel ray is part of.     */
        VEC3            P;                      /* Position (origin).        */
        VEC3            D;                      /* Direction.                */
        INT             level;                  /* Level of ray in ray tree. */
        R32             weight;                 /* Ray weight.               */
        INT             indx_inc3D[3];          /* Incl sign of ray direction*/
        RAYINFO         *ri;                    /* Grid dependent ray info.  */
        INT             ri_indx;
        RAYINFO         rinfo[MAX_RAYINFO + 1];
        }
        RAY;

typedef struct  irecord
        {
        REAL    t;                      /* Line parameter at intersection.   */
        ELEMENT *pelem;                 /* Primitve element.                 */
        REAL    b1;                     /* Barycentric coordinates of        */
        REAL    b2;                     /* intersection for triangles.       */
        REAL    b3;
        }
        IRECORD;

typedef struct  tri
        {
        VEC3    norm;                   /* Face normal.                      */
        REAL    d;                      /* Plane equation D.                 */
        VEC3    *vptr;                  /* Global vertex list pointer.       */
        VEC3    *nptr;                  /* Global normal list pointer.       */
        INT     vindex[3];              /* Index of vertices.                */
        INT     indx;                   /* Normal component max flag.        */
        BOOL    norminterp;             /* Do normal interpolation?          */
        BOOL    vorder;                 /* Vertex order orientation.         */
        }
        TRI;

INT     TriPeIntersect(pr, pe, hit)
RAY     *pr;
ELEMENT *pe;
IRECORD *hit;
{
        INT     i;
        REAL    Rd_dot_Pn;              /* Polygon normal dot ray direction. */
        REAL    Ro_dot_Pn;              /* Polygon normal dot ray origin.    */
        REAL    q1, q2;
        REAL    tval;                   /* Intersection t distance value.    */
        VEC3    *v1, *v2, *v3;          /* Vertex list pointers.             */
        VEC3    e1, e2, e3;             /* Edge vectors.                     */
        TRI     *pt;                    /* Ptr to triangle data.             */

        pt = (TRI *)pe->data;

        Rd_dot_Pn = VecDot(pt->norm, pr->D);

        if (ABS(Rd_dot_Pn) < RAYEPS)           /* Ray is parallel.          */
                return (0);

        Ro_dot_Pn = VecDot(pt->norm, pr->P);

        tval = -(pt->d + Ro_dot_Pn)/Rd_dot_Pn;  /* Intersection distance.    */
        if (tval < RAYEPS)                     /* Intersects behind ray.    */
                return (0);

        /*
         *      This algorithm works for vertices in counter-clockwise order,
         *      so reverse the vertices if they are clockwise.
         */

        v1 = pt->vptr + pt->vindex[0];  /* Compute first vertex pointer.     */

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

        e1[0] = (*v2)[0] - (*v1)[0];
        e1[1] = (*v2)[1] - (*v1)[1];
        e1[2] = (*v2)[2] - (*v1)[2];

        e2[0] = (*v3)[0] - (*v2)[0];
        e2[1] = (*v3)[1] - (*v2)[1];
        e2[2] = (*v3)[2] - (*v2)[2];

        e3[0] = (*v1)[0] - (*v3)[0];
        e3[1] = (*v1)[1] - (*v3)[1];
        e3[2] = (*v1)[2] - (*v3)[2];


        /* Triangle containment. */
        switch (pt->indx)
        {
                case X_NORM:
                        q1 = pr->P[1] + tval*pr->D[1];
                        q2 = pr->P[2] + tval*pr->D[2];

                        hit->b1 = e2[1] * (q2 - (*v2)[2]) - e2[2] * (q1 - (*v2)[1]);
                        if (!INSIDE(hit->b1, pt->norm[0])) 
                                return (0);
                        
			hit->b2 = e3[1] * (q2 - (*v3)[2]) - e3[2] * (q1 - (*v3)[1]);
                        if (!INSIDE(hit->b2, pt->norm[0])) 
                                return (0);

                        hit->b3 = e1[1] * (q2 - (*v1)[2]) - e1[2] * (q1 - (*v1)[1]);
                        if (!INSIDE(hit->b3, pt->norm[0])) 
                                return (0);
                        break;

                case Y_NORM:
                        q1 = pr->P[0] + tval*pr->D[0];
                        q2 = pr->P[2] + tval*pr->D[2];

                        hit->b1 = e2[2] * (q1 - (*v2)[0]) - e2[0] * (q2 - (*v2)[2]);
                        if (!INSIDE(hit->b1, pt->norm[1])) 
                                return (0);
                        
			hit->b2 = e3[2] * (q1 - (*v3)[0]) - e3[0] * (q2 - (*v3)[2]);
                        if (!INSIDE(hit->b2, pt->norm[1])) 
                                return (0);

                        hit->b3 = e1[2] * (q1 - (*v1)[0]) - e1[0] * (q2 - (*v1)[2]);
                        if (!INSIDE(hit->b3, pt->norm[1])) 
                                return (0);
                        break;

                case Z_NORM:
                        q1 = pr->P[0] + tval*pr->D[0];
                        q2 = pr->P[1] + tval*pr->D[1];

                        hit->b1 = e2[0] * (q2 - (*v2)[1]) - e2[1] * (q1 - (*v2)[0]);
                        if (!INSIDE(hit->b1, pt->norm[2])) 
                                return (0);

                        hit->b2 = e3[0] * (q2 - (*v3)[1]) - e3[1] * (q1 - (*v3)[0]);
                        if (!INSIDE(hit->b2, pt->norm[2]))
                                return (0);

                        hit->b3 = e1[0] * (q2 - (*v1)[1]) - e1[1] * (q1 - (*v1)[0]);
                        if (!INSIDE(hit->b3, pt->norm[2])) 
                                return (0);
                        break;
        }

        IsectAdd(hit, tval, pe);

        return (1);
}

VOID    IntersectHuniformPrimlist(intersectPrim, hit, v, r, pid)
INT *intersectPrim;
IRECORD *hit;
VOXEL *v;
RAY     *r;
INT     pid;
{
        ELEMENT **pptr;                 /* Primitive element list ptr.       */
        OBJECT  *peParent;              /* Ptr to parent object.             */
        ELEMENT *pe;                    /* Primitive element ptr.            */
        IRECORD newhit[ISECT_MAX];      /* Hit recorder.                     */
        INT     hitcode,i;
        REAL    t_out;

        t_out = r->ri->t_out;
        hit[0].t = HUGE_REAL;
        pptr = (ELEMENT**)v->cell;

/*@;BEGIN(NEST1=Nest)@*/for (i = 0; i < v->numelements; i++)
        {
                pe       = pptr[i];
                peParent = pe->parent;
                hitcode  = (*peParent->procs->pe_intersect)(r, pe, newhit);
		hitcode = TriPeIntersect (r, pe, newhit);

                if (hitcode)
                        if (newhit[0].t < hit[0].t && newhit[0].t < t_out)
                                hit[0] = newhit[0];
        }

        if (hit[0].t < HUGE_REAL)
                *intersectPrim = TRUE;
        else
                *intersectPrim = FALSE;
}


/*int main()
{
	INT intersectPrim;
	IRECORD hit;
	VOXEL v;
	RAY   r;
	INT   pid;

	IntersectHuniformPrimlist(&intersectPrim, &hit, &v, &r, pid);

	return 0;
}*/
