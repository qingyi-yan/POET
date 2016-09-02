      subroutine chlskyfac(a, NMAX)
      integer NMAX
      double precision a(NMAX,NMAX)
      double precision dsqrt, abs
      integer i,j,k


      do k = 1, NMAX
         a(k,k) = dsqrt( abs(a(k,k)) )
         do i = k+1, NMAX
            a(i,k) = a(i,k) * 1.0d0 / a(k,k)
         enddo
         do j = k+1, NMAX
            do i = j, NMAX
               a(i,j) = a(i,j) - a(i,k) * a(j,k)
            enddo
         enddo
      enddo

      end

