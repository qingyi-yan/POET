*
****** COMM3 COMMUNICATES ON ALL BORDERS OF AN ARRAY
*
C     SUBROUTINE COMM3(U,N)
      INTEGER N, LMI
      REAL*8 U(N,N,N)
      INTEGER I3, I2, I1
C

	  N = 2 + 2**LMI

      DO 100 I3=2,N-1
        DO 100 I2=2,N-1
          U(1,I2,I3) = U(N-1,I2,I3)
          U(N,I2,I3) = U( 2, I2,I3)
 100  CONTINUE
 
*    //@; BEGIN(nest2=SingleLoop)

      DO 200 I3=2,N-1  
        DO 200 I1=1,N
          if( N .eq. LMI .and. LMI .eq. I2 ) then
            U(I1,1,I3) = U(I1,N-1,I3)
            U(I1,N,I3) = U(I1, 2, I3)
          endif
 200  CONTINUE

      DO 300 I2=1,N
        DO 300 I1=1,N
          U(I1,I2,1) = U(I1,I2,N-1)
          U(I1,I2,N) = U(I1,I2, 2 )
 300  CONTINUE

* //@; BEGIN(nest4=SingleLoop)
      DO I3=1,N
        DO I2=1,N
          DO I1=1,N
              U(I1,I2,I3) = U(I1,I2,N-1)
              U(I1,I2,I3) = U(I1,I2, 2 )
	      call foo(N)
            enddo
         enddo
      enddo

      RETURN
      END
