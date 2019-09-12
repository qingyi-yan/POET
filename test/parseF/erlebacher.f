      program testh
c...............................................................|
c
c   program used to study performance:  test host
c
c   code:  erlebacher
c          - calculation of variable derivatives 
c          - tri-diagonal solver
c          - sequential for HYPERCUBE target
c
c   Thomas M. Eidson
c   ICASE
c   March, 1991
c...............................................................|
c
      parameter (ioprt=6)
c
      common /grids/ dx,dy,dz
      common /times/ dt,dtx,dty,dtz
      double precision dt,dtx,dty,dtz
      include 'erle.h'

      call setgrid
      call dotest
C     call prntout

      call checksum(dux)
      call checksum(duy)
      call checksum(duz)

      stop 0
      end

c===============================================================|
      subroutine checksum(ar)
      include 'par.h'
      double precision ar(N,N,N)

      double precision sum 
      sum = 0.0
      do i = 1, N
         do j = 1,N 
            do k = 1,N 
              sum = sum + ar(k, j, i)
            enddo
         enddo
      enddo
      print *, sum
      end

c===============================================================|
      subroutine tridvpk(a,b,c,d,e,tot)

      include 'erle.h'
      double precision tot(N,N)
      double precision a(N),b(N),c(N),d(N),e(N)

c
c...............................................................|
c
c     perform forward substitution
c  //@; BEGIN(looplist1=CODE.LoopNestList)
      do 10 j=1,N  
      do 10 i=1,N
         duz(i,j,1) = duz(i,j,1)*b(1)
   10 continue

      do  k=2,N-1
      do  j=1,N
      do  i=1,N
         duz(i,j,k)=(duz(i,j,k)-a(k)*duz(i,j,k-1))*b(k)
      enddo
      enddo
      enddo

   20 continue
c
      do 30 j=1,N
      do 30 i=1,N
         tot(i,j) = 0.  
   30 continue
c
      do 40 k=1,N-1
      do 40 j=1,N
      do 40 i=1,N
            tot(i,j) = tot(i,j) + d(k)*duz(i,j,k)
   40 continue
c
      do 50 j=1,N
      do 50 i=1,N
         duz(i,j,N) = (duz(i,j,N) - tot(i,j))*b(N)
   50 continue
c
c     perform backward substitution
c
      do 60 j=1,N
      do 60 i=1,N
         duz(i,j,N-1)=duz(i,j,N-1) - e(N-1)*duz(i,j,N)
   60 continue
c
      do  k=N-2,1,-1
      do  j=1,N
      do  i=1,N
         duz(i,j,k) = duz(i,j,k) - c(k)*duz(i,j,k+1) - e(k)*duz(i,j,N)
      enddo
      enddo
      enddo

   70 continue
c
      return
      end
c===============================================================|
      subroutine tridvpj(a,b,c,d,e,tot)

      include 'erle.h'
        double precision tot(N,N)
        double precision a(N),b(N),c(N),d(N),e(N)

c
c...............................................................|
c
c     perform forward substitution
c
c  //@; BEGIN(looplist2=CODE.LoopNestList)
      do 10 k=1,N
      do 10 i=1,N
         duy(i,1,k) = duy(i,1,k)*b(1)
   10 continue
c
      do 20 k=1,N
      do 20 j=2,N-1
      do 20 i=1,N
         duy(i,j,k)=(duy(i,j,k)-a(j)*duy(i,j-1,k))*b(j)
   20 continue
c
      do 30 k=1,N
      do 30 i=1,N
         tot(i,k) = 0.
   30 continue
c
      do 40 k=1,N
      do 40 j=1,N-1
      do 40 i=1,N
         tot(i,k) = tot(i,k) + d(j)*duy(i,j,k)
   40 continue
c
      do 50 k=1,N
      do 50 i=1,N
         duy(i,N,k) = (duy(i,N,k) - tot(i,k))*b(N)
   50 continue
c
c     perform backward substitution
c
      do 60 k=1,N
      do 60 i=1,N
         duy(i,N-1,k)=duy(i,N-1,k) - e(N-1)*duy(i,N,k)
   60 continue
c
      do 70 k=1,N
      do 70 j=N-2,1,-1
      do 70 i=1,N
         duy(i,j,k) = duy(i,j,k) - c(j)*duy(i,j+1,k) - e(j)*duy(i,N,k)
   70 continue
c
      return
      end
c===============================================================|
      subroutine tridvpi(a,b,c,d,e,tot)

      include 'erle.h'
        double precision tot(N,N)
        double precision a(N),b(N),c(N),d(N),e(N)

c
c...............................................................|
c
c     perform forward substitution
c
c  //@; BEGIN(looplist3=CODE.LoopNestList)
      do 10 k=1,N
      do 10 j=1,N
         dux(1,j,k) = dux(1,j,k)*b(1)
   10 continue
c
      do 20 k=1,N
      do 20 j=1,N
      do 20 i=2,N-1
         dux(i,j,k)=(dux(i,j,k)-a(i)*dux(i-1,j,k))*b(i)
   20 continue
c
      do 30 k=1,N
      do 30 j=1,N
         tot(j,k) = 0.
   30 continue
c
      do 40 k=1,N
      do 40 j=1,N
      do 40 i=1,N-1 
         tot(j,k) = tot(j,k) + d(i)*dux(i,j,k)
   40 continue
c
      do 50 k=1,N
      do 50 j=1,N
         dux(N,j,k) = (dux(N,j,k) - tot(j,k))*b(N)
   50 continue
c
c     perform backward substitution
c
      do 60 k=1,N
      do 60 j=1,N
         dux(N-1,j,k)=dux(N-1,j,k) - e(N-1)*dux(N,j,k)
   60 continue
c
      do 70 k=1,N
      do 70 j=1,N
      do 70 i=N-2,1,-1
         dux(i,j,k) = dux(i,j,k) - c(i)*dux(i+1,j,k) - e(i)*dux(N,j,k)
   70 continue
c
      return
      end
c===============================================================|
      subroutine tridvpf(a,b,c,d,e)
c...............................................................|
c
c   routine:
c      factorization stage of vectorized tridiagonal solver
c      equations are periodic
c      all equations have the same coefficients
c
c...............................................................|
c
      include 'erle.h'
      double precision a(N),b(N),c(N),d(N),e(N)
c
c...............................................................|
c
c     generate first elements of LU
c
      b(1) = 1.0/b(1)
      c(1) = c(1)*b(1)
      e(1) = a(1)*b(1)
      d(1) = c(N)
c
c     generate n=2 to n=N-2 elements of LU
c
      do 10 k=2,N-2
         b(k) = b(k) - a(k)*c(k-1)
         b(k) = 1.0/b(k)
         c(k) = c(k)*b(k)               
         e(k) = -a(k)*e(k-1)*b(k)
         d(k) = -d(k-1)*c(k-1)
   10 continue
c
c     generate N-1 elements
c
      b(N-1) = b(N-1) - a(N-1)*c(N-2)
      b(N-1) = 1.0/b(N-1)
      e(N-1) = (c(N-1) - a(N-1)*e(N-2))*b(N-1)
      d(N-1) = a(N) - d(N-2)*c(N-2)
c
c     generate the n-th element
c
      tot = 0.
      do 20 k=1,N-1
         tot = tot + d(k)*e(k)
   20 continue
      b(N) = b(N) - tot
      b(N) = 1.0/b(N)
c
      return
      end

      subroutine prnt(ar)
      include 'erle.h'
      double precision ar(N,N,N)

c
c
      parameter (size = N)
      do i = 1, size 
	 do j = 1, size 
	    print *, "ROW ", i , " COL ", j
	    do k = 1, size 
	       print *, ar(i,j,k)
            enddo 
         enddo 
      enddo 
      end
c===============================================================|
      subroutine dz3d6p(dz)
c...............................................................|
c
c   routine:
c      computes the z-derivatives of u storing the result in ud
c      uses a 6th order Pade scheme (Periodic domain)
c      periodic in z (evenly spaced grid)
c      third index corresponds to z direction
c
c...............................................................|
c


      parameter (pi=3.1415926535898)
c
      include 'erle.h'
      double precision a(N),b(N),c(N),d(N),e(N)


c
c...............................................................|
c
      nij=N*N 
c
c  first derivative
c
         c13    = 1./3.
         c79dz  = 7./(9.*dz)
         c136dz = 1./(36.*dz)
c
c  set up the left hand side and factor the periodic matrix
c
         do 30 i=1,N
            a(i) = c13 
            b(i) = 1.
            c(i) = c13
   30    continue
         call tridvpf(a,b,c,d,e)
c
c  set up right hand side and do forward/backward substitution
c
   91    do 41 j=1,N
         do 41 i=1,N
            duz(i,j,1) = c79dz*(u(i,j,2) - u(i,j,N))
     1                 + c136dz*(u(i,j,3) - u(i,j,N-1))
            duz(i,j,2) = c79dz*(u(i,j,3) - u(i,j,1))
     1                 + c136dz*(u(i,j,4) - u(i,j,N))
   41    continue

   92  do 40 j=1,N
         do 40 i=1,N 
           duz(i,j,N-1) = c79dz*(u(i,j,N) - u(i,j,N-2))
     1                    + c136dz*(u(i,j,1) - u(i,j,N-3))
            duz(i,j,N)   = c79dz*(u(i,j,1) - u(i,j,N-1))
     1                    + c136dz*(u(i,j,2) - u(i,j,N-2))
   40    continue


         do 50 k=3,N-2
         do 50 j=1,N
         do 50 i=1,N
              duz(i,j,k) = c79dz*(u(i,j,k+1) - u(i,j,k-1))
     1                   + c136dz*(u(i,j,k+2) - u(i,j,k-2))
   50    continue
         call tridvpk(a,b,c,d,e,wrk)
c
      return
      end
c===============================================================|
      subroutine setgrid
c
      common /grids/ dx,dy,dz

      include 'erle.h'
c
c...............................................................|
c
c calculate boundary indices for data section on each node
c

c
c calculate grid
c
      pi=acos(-1.0)
      dx=2.*pi/N
      dy=2.*pi/N
      dz=2.*pi/N
c
      do 5 i=1,N
         x(i)=(i-1)*dx
    5 continue
c
      do 6 j=1,N
         y(j)=(j-1)*dy
    6 continue
c
      do 7 k=1,N
         z(k)=(k-1)*dz
    7 continue
c
      return
      end
c===============================================================|
      subroutine dotest

      common /grids/ dx,dy,dz
      common /times/ dt,dtx,dty,dtz
      double precision dt,dtx,dty,dtz

c...............................................................|
c
c*** generate data
c
      call genvar
c
c...............................................................|
c
c*** time derivative calculation
c
      call dx3d6p(dx)
      call dy3d6p(dy)
      call dz3d6p(dz)

      return
      end
c===============================================================|
      subroutine genvar
c
      common /grids/ dx,dy,dz
      include 'erle.h'

      do 10 kk=1,N
         do 10 jj=1,N
            do 10 ii=1,N
               u(ii,jj,kk)   =sin(x(ii))*cos(y(jj))*cos(3.*z(kk))
   10 continue
c
      return
      end
c===============================================================|
      subroutine dx3d6p(dx)
c...............................................................|
c
c   routine:
c      computes the x-derivatives of u storing the result in ud
c      uses a 6th order Pade scheme (Periodic domain)
c      periodic in x (evenly spaced grid)
c      first index corresponds to x direction
c
c...............................................................|
c
      parameter (pi=3.1415926535898)
c
      include 'erle.h'
        double precision a(N),b(N),c(N),d(N),e(N)

c...............................................................|
c
c  first derivative
c
         c13    = 1./3.
         c79dx  = 7./(9.*dx)
         c136dx = 1./(36.*dx)
c
c  set up the left hand side and factor the periodic matrix
c
         do 30 i=1,N
            a(i) = c13 
            b(i) = 1.
            c(i) = c13
   30    continue
         call tridvpf(a,b,c,d,e)
c
c  set up right hand side and do forward/backward substitution
c
         do 40 k=1,N
         do 40 j=1,N
            dux(1,j,k) = c79dx*(u(2,j,k) - u(N,j,k))
     &               + c136dx*(u(3,j,k) - u(N-1,j,k))
            dux(2,j,k) = c79dx*(u(3,j,k) - u(1,j,k))
     &               + c136dx*(u(4,j,k) - u(N,j,k))
   40    continue
c
         do 41 k=1,N
         do 41 j=1,N
            dux(N-1,j,k) = c79dx*(u(N,j,k) - u(N-2,j,k))
     &                     + c136dx*(u(1,j,k)    - u(N-3,j,k))
            dux(N,j,k) = c79dx*(u(1,j,k) - u(N-1,j,k))
     &                   + c136dx*(u(2,j,k) - u(N-2,j,k))
   41    continue
c
         do 50 k=1,N
         do 50 j=1,N
         do 50 i=3,N-2
              dux(i,j,k) = c79dx*(u(i+1,j,k) - u(i-1,j,k))
     &                 + c136dx*(u(i+2,j,k) - u(i-2,j,k))
   50    continue
         call tridvpi(a,b,c,d,e,wrk)
      return
      end
c===============================================================|
      subroutine dy3d6p(dy)
c...............................................................|
c
c   routine:
c      computes the y-derivatives of u storing the result in ud
c      uses a 6th order Pade scheme (Periodic domain)
c      periodic in y (evenly spaced grid)
c      second index corresponds to y direction
c
c...............................................................|
c

      parameter (pi=3.1415926535898)
c
      include 'erle.h'

        double precision a(N),b(N),c(N),d(N),e(N)
c...............................................................|
c
c  first derivative
c
         c13    = 1./3.
         c79dy  = 7./(9.*dy)
         c136dy = 1./(36.*dy)
c
c  set up the left hand side and factor the periodic matrix
c
         do 30 i=1,N
            a(i) = c13 
            b(i) = 1.
            c(i) = c13
  30     continue
         call tridvpf(a,b,c,d,e)
c
c  set up right hand side and do forward/backward substitution
c
         do 40 k=1,N
         do 40 i=1,N
            duy(i,1,k) = c79dy*(u(i,2,k) - u(i,N,k))
     1               + c136dy*(u(i,3,k) - u(i,N-1,k))
            duy(i,2,k) = c79dy*(u(i,3,k) - u(i,1,k))
     1               + c136dy*(u(i,4,k) - u(i,N,k))
  40     continue

         do 41 k=1,N
         do 41 i=1,N
            duy(i,N-1,k) = c79dy*(u(i,N,k)
     1                          - u(i,N-2,k))
     2                     + c136dy*(u(i,1,k) - u(i,N-3,k))
            duy(i,N,k) = c79dy*(u(i,1,k) - u(i,N-1,k))
     1                   + c136dy*(u(i,2,k) - u(i,N-2,k))
  41     continue
c
         do 50 k=1,N
         do 50 j=3,N-2
         do 50 i=1,N
              duy(i,j,k) = c79dy*(u(i,j+1,k) - u(i,j-1,k))
     1                 + c136dy*(u(i,j+2,k) - u(i,j-2,k))
  50     continue
         call tridvpj(a,b,c,d,e,wrk)
c
      return
      end
