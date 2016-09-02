/*
	StencilProbe Heat Equation
	Implements 7pt stencil from Chombo's heattut example.
*/

#define Index3D(_nx,_ny,_i,_j,_k) ((_i)+_nx*((_j)+_ny*(_k)))

void jacobi7(const int nx,const int ny, int nz, const double alpha,double* A0,const int timesteps,const double* B,const int ldb, double* Anext,const int ldc) 
{
  double fac;
  double *temp_ptr;
  int i, j, k, t;	
  fac = 6.0/(A0[0]*A0[0]);

  /*@;BEGIN(Nest1=Nest)@*/for (t = 0; t < timesteps; t++) {
    /*@;BEGIN(Nest2=Nest)@*/for (k = 1; k < nz - 1; k++) {
      /*@;BEGIN(Nest3=Nest)@*/for (j = 1; j < ny - 1; j++) {
	/*@;BEGIN(Nest4=Nest)@*/for (i = 1; i < nx - 1; i++) {
	  Anext[Index3D (nx, ny, i, j, k)] = 
	    A0[Index3D (nx, ny, i, j, k + 1)] +
	    A0[Index3D (nx, ny, i, j, k - 1)] +
	    A0[Index3D (nx, ny, i, j + 1, k)] +
	    A0[Index3D (nx, ny, i, j - 1, k)] +
	    A0[Index3D (nx, ny, i + 1, j, k)] +
	    A0[Index3D (nx, ny, i - 1, j, k)]
	    -  A0[Index3D (nx, ny, i, j, k)] *fac ;
	}
      }
    }
    temp_ptr = A0;
    A0 = Anext;
    Anext = temp_ptr;
  }
}

