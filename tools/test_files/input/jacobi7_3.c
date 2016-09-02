/*
	StencilProbe Heat Equation
	Implements 7pt stencil from Chombo's heattut example.
*/

#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))

void jacobi7_3(const int nx,const int ny, int nz, const double alpha,double* A0,const int timesteps,const double* B,const int ldb, double* Anext,const int ldc) 
{
  double fac;
  double *temp_ptr;
  int i, j, k, t;	
  fac = 6.0/(A0[0]*A0[0]);
  double *l0, *lnext;

  /*@;BEGIN(Nest1=Nest)@*/for (t = 0; t < timesteps; t++) {
    /*@;BEGIN(Nest2=Nest)@*/for (k = 1; k < nz - 1; k++) {
      /*@;BEGIN(Nest3=Nest)@*/for (j = 1; j < ny - 1; j++) {
	/*@;BEGIN(Nest4=Nest)@*/for (i = 1; i < nx - 1; i++) {
          if (t%2 == 0) { l0 = A0; lnext = Anext; }
          else {lnext = A0; l0 = Anext; }
	  lnext[Index3D (nx, ny, i, j, k)] = 
	    l0[Index3D (nx, ny, i, j, k + 1)] +
	    l0[Index3D (nx, ny, i, j, k - 1)] +
	    l0[Index3D (nx, ny, i, j + 1, k)] +
	    l0[Index3D (nx, ny, i, j - 1, k)] +
	    l0[Index3D (nx, ny, i + 1, j, k)] +
	    l0[Index3D (nx, ny, i - 1, j, k)]
	    -  l0[Index3D (nx, ny, i, j, k)] *fac ;
	}
      }
    }
  }
}

