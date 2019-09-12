      PROGRAM MG3XDEMO 
C
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C
C        'MGXDEMO' DEMONSTRATES THE CAPABILITIES OF A VERY SIMPLE MULTIGRID
C        SOLVER IN COMPUTING A THREE DIMENSIONAL POTENTIAL FIELD.  THIS IS
C        A SIMPLIFIED MULTIGRID SOLVER IN TWO IMPORTANT RESPECTS:
C
C                (1) IT SOLVES ONLY A CONSTANT COEFFICIENT EQUATION,
C                AND THAT ONLY ON A UNIFORM CUBICAL GRID,
C
C                (2) IT SOLVES ONLY A SINGLE EQUATION, REPRESENTING
C                A SCALAR FIELD RATHER THAN A VECTOR FIELD.
C
C        WE CHOSE IT FOR ITS PORTABILITY AND SIMPLICITY, AND EXPECT THAT A
C        SUPERCOMPUTER WHICH CAN RUN IT EFFECTIVELY WILL ALSO BE ABLE TO
C        RUN MORE COMPLEX MULTIGRID PROGRAMS AT LEAST AS WELL.
C
C              ERIC BARSZCZ                        PAUL FREDERICKSON
C                                                      RIACS
C        NASA AMES RESEARCH CENTER            NASA AMES RESEARCH CENTER
C
CCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCCC
C
      INTEGER LM, NM, NV, NR, NIT


      PARAMETER( LM=8 )
C      PARAMETER( NIT=40 )


      PARAMETER( NM=2+2**LM, NV=NM**3 )
      PARAMETER( NR = (8*(NM**3+NM**2+5*NM-23+7*LM))/7 )
C
      COMMON /X/ U, V, R, A, C, IR, MM
      REAL*8 U(NR),V(NV),R(NR),A(0:3),C(0:3)
      REAL*8 RNM2, RNMU, OLD2, OLDU
      REAL*8 XX
      INTEGER IR(LM), MM(LM)
      INTEGER IT, N
C
C
      A(0) = -8.0D0/3.0D0 
      A(1) =  0.0D0 
      A(2) =  1.0D0/6.0D0 
      A(3) =  1.0D0/12.0D0
C
      C(0) =  -3.0D0/8.0D0
      C(1) =  +1.0D0/32.0D0
      C(2) =  -1.0D0/64.0D0
      C(3) =   0.0D0

      READ *,LMI
      READ *,NIT
      READ *,NTIMES
C
      N  = 2 + 2**LMI


      WRITE(6,7)N-2,N-2,N-2,NIT
C
      CALL SETUP(LMI,IR,MM)
      XX = 314159265.D0
      DO 1000 MTIME=1,NTIMES
      CALL ZERO3(U,N,N,N)
      CALL ZRAN3(XX,V,N,N,N)

      CALL RESID(U,V,R,N,A)
      CALL NORM2U3(R,N,N,N,RNM2,RNMU,N,N,N)
           OLD2 = RNM2
           OLDU = RNMU
C
      DO 20 IT=1,NIT
        CALL MG3P(U,V,R,N,A,C,NV,NR,IR,MM,LMI)
        CALL RESID(U,V,R,N,A)
 20   CONTINUE
C
C
        CALL NORM2U3(R,N,N,N,RNM2,RNMU,N,N,N)
        WRITE(6,'(A40)')
        WRITE(6,'(A40)')' IT    L2-NORM(R)         UNIF-NORM(R)'
        WRITE(6,6) 0, OLD2, OLDU
        WRITE(6,6) NIT, RNM2, RNMU
      

C //@; BEGIN(end0=CODE.Label)
1000  CONTINUE
C
C

 6    FORMAT( I4, 2E19.12)
 7    FORMAT(/,' KERNEL B:  SOLVING A POISSON PROBLEM ON A ',I3,' BY ',
     > I3,' BY ',I3,' GRID,',/,' USING ',I1,' MULTIGRID ITERATIONS.',/)
C
      STOP

      END
*
******  MG3P   IMPLEMENTS A SIMPLE, CONSTANT COEFFICIENT VERSION OF THE
******        MG ALGORITHM FAPIN (FAST APPROXIMATE INVERSE)
*
      SUBROUTINE MG3P(U,V,R,N,A,C,NV,NR,IR,MM,LM)
C
      INTEGER N,NV,NR,LM
      REAL*8 U(NR),V(NV),R(NR)
      REAL*8 A(0:3),C(0:3)
      INTEGER IR(LM), MM(LM)
C
      INTEGER K, J
C
      DO 50 K= LM, 2, -1
      J=K-1
      CALL RPRJ3(R(IR(K)),MM(K),R(IR(J)),MM(J))
 50   CONTINUE
C
      K = 1
      CALL ZERO3(U(IR(K)),MM(K),MM(K),MM(K))
      CALL PSINV(R(IR(K)),U(IR(K)),MM(K),C)
      IF( LM .EQ. 2 )GO TO 200
      DO 100 K = 2, LM-1
      J = K-1
      CALL ZERO3(U(IR(K)),MM(K),MM(K),MM(K))
      CALL INTERP(U(IR(J)),MM(J),U(IR(K)),MM(K))
      CALL RESID(U(IR(K)),R(IR(K)),R(IR(K)),MM(K),A)
      CALL PSINV(R(IR(K)),U(IR(K)),MM(K),C)
 100  CONTINUE
 200  CONTINUE
      J = LM - 1
      K = LM
      CALL INTERP(U(IR(J)),MM(J),U,N)
      CALL RESID(U,V,R,N,A)
      CALL PSINV(R,U,N,C)
C
      RETURN
      END
*
****** PSINV APPLIES AN APPROXIMATE INVERSE AS SMOOTHER:  U = U + CR
*
*      THIS SIMPLE IMPLEMENTATION COSTS  27A + 4M PER RESULT, WHERE
*      A AND M DENOTE THE COSTS OF ADDITION AND MULTIPLICATION.  
*      BY USING SEVERAL TWO-DIMENSIONAL BUFFERS ONE CAN REDUCE THIS
*      COST TO  13A + 4M IN THE GENERAL CASE, OR  11A + 3M WHEN THE
*      COEFFICIENT C(3) IS ZERO.
*
      SUBROUTINE PSINV(R,U,N,C)
      INTEGER N
      REAL*8 U(N,N,N),R(N,N,N),C(0:3)
      INTEGER I3, I2, I1
C      WRITE(0,*) "SIZE", N
C
C //@; BEGIN(nest1=CODE.SingleLoop)
      DO 600 I3=2,N-1
      DO 600 I2=2,N-1
      DO 600 I1=2,N-1
 600  U(I1,I2,I3)=U(I1,I2,I3)
     >      +C(0)*( R(I1,  I2,  I3  ) )
     >      +C(1)*( R(I1-1,I2,  I3  ) + R(I1+1,I2,  I3  )
     >           +  R(I1,  I2-1,I3  ) + R(I1,  I2+1,I3  )
     >           +  R(I1,  I2,  I3-1) + R(I1,  I2,  I3+1) )
     >      +C(2)*( R(I1-1,I2-1,I3  ) + R(I1+1,I2-1,I3  )
     >           +  R(I1-1,I2+1,I3  ) + R(I1+1,I2+1,I3  )
     >           +  R(I1,  I2-1,I3-1) + R(I1,  I2+1,I3-1)
     >           +  R(I1,  I2-1,I3+1) + R(I1,  I2+1,I3+1)
     >           +  R(I1-1,I2,  I3-1) + R(I1-1,I2,  I3+1)
     >           +  R(I1+1,I2,  I3-1) + R(I1+1,I2,  I3+1) )
     >      +C(3)*( R(I1-1,I2-1,I3-1) + R(I1+1,I2-1,I3-1)
     >           +  R(I1-1,I2+1,I3-1) + R(I1+1,I2+1,I3-1)
     >           +  R(I1-1,I2-1,I3+1) + R(I1+1,I2-1,I3+1)
     >           +  R(I1-1,I2+1,I3+1) + R(I1+1,I2+1,I3+1) )
C
         CALL COMM3(U,N)
      WRITE (6,9000) (((U(I1,I2,I3), 
     1               I1=1,N,69), I2=1,N,69), I3=1,N,69)
9000  FORMAT (1X, E15.6)
C
      RETURN
      END
*
******* RESID COMPUTES THE RESIDUAL:  R = V - AU
*
*      THIS SIMPLE IMPLEMENTATION COSTS  27A + 4M PER RESULT, WHERE
*      A AND M DENOTE THE COSTS OF ADDITION (OR SUBTRACTION) AND 
*      MULTIPLICATION, RESPECTIVELY.  BY USING SEVERAL TWO-DIMENSIONAL 
*      BUFFERS ONE CAN REDUCE THIS COST TO  13A + 4M IN THE GENERAL 
*      CASE, OR  10A + 3M WHEN THE COEFFICIENT A(1) IS ZERO.
*
      SUBROUTINE RESID(U,V,R,N,A)
      INTEGER N
      REAL*8 U(N,N,N),V(N,N,N),R(N,N,N),A(0:3)
      INTEGER I3, I2, I1

C
C //@; BEGIN(nest2=CODE.SingleLoop)
      DO 600 I3=2,N-1
      DO 600 I2=2,N-1
      DO 600 I1=2,N-1
 600  R(I1,I2,I3)=V(I1,I2,I3)
     >      -A(0)*( U(I1,  I2,  I3  ) )
     >      -A(1)*( U(I1-1,I2,  I3  ) + U(I1+1,I2,  I3  )
     >                 +  U(I1,  I2-1,I3  ) + U(I1,  I2+1,I3  )
     >                 +  U(I1,  I2,  I3-1) + U(I1,  I2,  I3+1) )
     >      -A(2)*( U(I1-1,I2-1,I3  ) + U(I1+1,I2-1,I3  )
     >                 +  U(I1-1,I2+1,I3  ) + U(I1+1,I2+1,I3  )
     >                 +  U(I1,  I2-1,I3-1) + U(I1,  I2+1,I3-1)
     >                 +  U(I1,  I2-1,I3+1) + U(I1,  I2+1,I3+1)
     >                 +  U(I1-1,I2,  I3-1) + U(I1-1,I2,  I3+1)
     >                 +  U(I1+1,I2,  I3-1) + U(I1+1,I2,  I3+1) )
     >      -A(3)*( U(I1-1,I2-1,I3-1) + U(I1+1,I2-1,I3-1)
     >                 +  U(I1-1,I2+1,I3-1) + U(I1+1,I2+1,I3-1)
     >                 +  U(I1-1,I2-1,I3+1) + U(I1+1,I2-1,I3+1)
     >                 +  U(I1-1,I2+1,I3+1) + U(I1+1,I2+1,I3+1) )
C
         CALL COMM3(R,N)
C
      RETURN
      END
*
****** RPRJ3 PROJECTS ONTO THE NEXT COARSER GRID, 
****** USING A TRILINEAR FINITE ELEMENT PROJECTION:  S = R' = P R
*
*      THIS SIMPLE IMPLEMENTATION COSTS  27A + 4M PER RESULT, WHERE
*      A AND M DENOTE THE COSTS OF ADDITION AND MULTIPLICATION.  
*      BY USING SEVERAL TWO-DIMENSIONAL BUFFERS ONE CAN REDUCE THIS
*      COST TO  23A + 1M.  (NOTE, HOWEVER, THAT THE NUMBER OF RESULTS
*      IS ABOUT 1/8 THAT OF THE OTHER THREE OPERATORS.)
*
      SUBROUTINE RPRJ3(R,MK,S,MJ)
      INTEGER MK, MJ
      REAL*8 R(MK,MK,MK), S(MJ,MJ,MJ)
      INTEGER J3, J2, J1, I3, I2, I1
C
C //@; BEGIN(nest3=CODE.SingleLoop)
      DO 100 J3=2,MJ-1
        I3 = 2*J3-1
      DO 100 J2=2,MJ-1
        I2 = 2*J2-1
      DO 100 J1=2,MJ-1
        I1 = 2*J1-1
 100  S(J1,J2,J3) =
     >      0.5D0 * ( R(I1,  I2,  I3  ) )
     >   + 0.25D0 * ( R(I1-1,I2,  I3  ) + R(I1+1,I2,  I3  )
     >             +  R(I1,  I2-1,I3  ) + R(I1,  I2+1,I3  )
     >             +  R(I1,  I2,  I3-1) + R(I1,  I2,  I3+1) )
     >  + 0.125D0 * ( R(I1-1,I2-1,I3  ) + R(I1+1,I2-1,I3  )
     >             +  R(I1-1,I2+1,I3  ) + R(I1+1,I2+1,I3  )
     >             +  R(I1,  I2-1,I3-1) + R(I1,  I2+1,I3-1)
     >             +  R(I1,  I2-1,I3+1) + R(I1,  I2+1,I3+1)
     >             +  R(I1-1,I2,  I3-1) + R(I1-1,I2,  I3+1)
     >             +  R(I1+1,I2,  I3-1) + R(I1+1,I2,  I3+1) )
     > + 0.0625D0 * ( R(I1-1,I2-1,I3-1) + R(I1+1,I2-1,I3-1)
     >             +  R(I1-1,I2+1,I3-1) + R(I1+1,I2+1,I3-1)
     >             +  R(I1-1,I2-1,I3+1) + R(I1+1,I2-1,I3+1)
     >             +  R(I1-1,I2+1,I3+1) + R(I1+1,I2+1,I3+1) )
C
      CALL COMM3(S,MJ)
C
      RETURN
      END
*
****** INTERP ADDS THE TRILINEAR INTERPOLATION OF THE CORRECTION
****** FROM THE COARSER GRID TO THE CURRENT APPROXIMATION:  U = U + QU'
*
*      THIS SIMPLE IMPLEMENTATION COSTS  (27/8)A + (7/8)M PER RESULT,
*      WHERE A AND M DENOTE THE COSTS OF ADDITION AND MULTIPLICATION.  
*      BY USING SEVERAL TWO-DIMENSIONAL BUFFERS ONE CAN REDUCE THIS
*      COST TO  (15/8)A + (7/8)M.
*
      SUBROUTINE INTERP(Z,M,U,N)
      REAL*8 Z(M,M,M),U(N,N,N)
      INTEGER M, N
      INTEGER I3, I2, I1
C
C //@; BEGIN(nest4=CODE.LoopNestList)
      DO 400 I3=2,M-1
         DO 200 I2=2,M-1
            DO 100 I1=2,M-1
            U(2*I1-1,2*I2-1,2*I3-1)=U(2*I1-1,2*I2-1,2*I3-1)
     >      +Z(I1,I2,I3)
 100        CONTINUE
            DO 200 I1=2,M-1
            U(2*I1-2,2*I2-1,2*I3-1)=U(2*I1-2,2*I2-1,2*I3-1)
     >      +0.5D0*(Z(I1-1,I2,I3)+Z(I1,I2,I3))
 200     CONTINUE
         DO 400 I2=2,M-1
            DO 300 I1=2,M-1
            U(2*I1-1,2*I2-2,2*I3-1)=U(2*I1-1,2*I2-2,2*I3-1)
     >      +0.5D0*(Z(I1,I2-1,I3)+Z(I1,I2,I3))
 300        CONTINUE
               DO 400 I1=2,M-1
            U(2*I1-2,2*I2-2,2*I3-1)=U(2*I1-2,2*I2-2,2*I3-1)
     >      +0.25D0*(Z(I1-1,I2-1,I3)+Z(I1-1,I2,I3)
     >            +Z(I1,  I2-1,I3)+Z(I1,  I2,I3))
 400  CONTINUE
C
      DO 800 I3=2,M-1
         DO 600 I2=2,M-1
            DO 500 I1=2,M-1
            U(2*I1-1,2*I2-1,2*I3-2)=U(2*I1-1,2*I2-1,2*I3-2)
     >      +0.5D0*(Z(I1,I2,I3-1)+Z(I1,I2,I3))
 500        CONTINUE
            DO 600 I1=2,M-1
            U(2*I1-2,2*I2-1,2*I3-2)=U(2*I1-2,2*I2-1,2*I3-2)
     >      +0.25D0*(Z(I1-1,I2,I3-1)+Z(I1,I2,I3-1)
     >            +Z(I1-1,I2,I3  )+Z(I1,I2,I3  ))
 600     CONTINUE
         DO 800 I2=2,M-1
            DO 700 I1=2,M-1
            U(2*I1-1,2*I2-2,2*I3-2)=U(2*I1-1,2*I2-2,2*I3-2)
     >      +0.25D0*(Z(I1,I2-1,I3-1)+Z(I1,I2,I3-1)
     >            +Z(I1,I2-1,I3  )+Z(I1,I2,I3  ))
 700        CONTINUE
               DO 800 I1=2,M-1
            U(2*I1-2,2*I2-2,2*I3-2)=U(2*I1-2,2*I2-2,2*I3-2)
     >      +0.125D0*(Z(I1-1,I2-1,I3-1)+Z(I1-1,I2,I3-1)
     >             +Z(I1,  I2-1,I3-1)+Z(I1,  I2,I3-1)
     >             +Z(I1-1,I2-1,I3  )+Z(I1-1,I2,I3  )
     >             +Z(I1,  I2-1,I3  )+Z(I1,  I2,I3  ))
 800  CONTINUE
C
        CALL COMM3(U,N)
C
      RETURN 
      END
*
****** COMM3 COMMUNICATES ON ALL BORDERS OF AN ARRAY
*
      SUBROUTINE COMM3(U,N)
      INTEGER N
      REAL*8 U(N,N,N)
      INTEGER I3, I2, I1
C
      DO 100 I3=2,N-1
        DO 100 I2=2,N-1
          U(1,I2,I3) = U(N-1,I2,I3)
          U(N,I2,I3) = U( 2, I2,I3)
 100  CONTINUE
C
      DO 200 I3=2,N-1
        DO 200 I1=1,N
          U(I1,1,I3) = U(I1,N-1,I3)
          U(I1,N,I3) = U(I1, 2, I3)
 200  CONTINUE
      DO 300 I2=1,N
        DO 300 I1=1,N
          U(I1,I2,1) = U(I1,I2,N-1)
          U(I1,I2,N) = U(I1,I2, 2 )
 300  CONTINUE
C
      RETURN
      END
*
****** NORM2U3 EVALUATES APPROXIMATIONS TO THE L2 NORM AND THE
****** UNIFORM (OR L-INFINITY OR CHEBYSHEV) NORM, UNDER THE
****** ASSUMPTION THAT THE BOUNDARIES ARE PERIODIC OR ZERO.  ADD THE
****** BOUNDARIES IN WITH HALF WEIGHT (QUARTER WEIGHT ON THE EDGES
****** AND EIGTH WEIGHT AT THE CORNERS) FOR INHOMOGENEOUS BOUNDARIES.
*
      SUBROUTINE NORM2U3(R,N1,N2,N3,RNM2,RNMU,NX,NY,NZ)
      INTEGER N1, N2, N3, NX, NY, NZ
      REAL*8 RNM2, RNMU, R(N1,N2,N3)
      REAL*8 S, A
      INTEGER I3, I2, I1
C
      S=0.0D0
      RNMU = 0.0D0
      DO 100 I3=2,N3-1
         DO 100 I2=2,N2-1
            DO 100 I1=2,N1-1
               S=S+R(I1,I2,I3)**2
               A=ABS(R(I1,I2,I3))
               IF(A.GT.RNMU)RNMU=A
 100  CONTINUE
      RNM2=SQRT(S/FLOAT((NX-2)*(NY-2)*(NZ-2)))
C
      RETURN
      END
*
****** SETUP   MUST BE CALLED BEFORE MG3P
*
      SUBROUTINE SETUP(LM,IR,MM)
      INTEGER LM, IR(LM), MM(LM)
      INTEGER L, K
C
        MM(LM) = 2+2**LM
        DO 100 K = LM-1, 1, -1
          MM(K) = 1 + MM(K+1)/2
 100     CONTINUE
            L = LM
C
            IR(L)=1
            DO 200 K = L-1, 1, -1
            IR(K)=IR(K+1)+MM(K+1)**3
 200        CONTINUE
C
      RETURN
      END
*
***
*
      SUBROUTINE ZERO3(Z,NX,NY,NZ)
      INTEGER NX,NY,NZ
      REAL*8 Z(NX,NY,NZ)
      INTEGER I1, I2, I3
C
      DO 100 I3=1,NZ
      DO 100 I2=1,NY
      DO 100 I1=1,NX
 100  Z(I1,I2,I3)=0.0D0
C
      RETURN
      END
*
****** ZRAN3  LOADS +1 AT TEN RANDOMLY CHOSEN POINTS,
******        LOADS -1 AT A DIFFERENT TEN RANDOM POINTS,
******        AND ZERO ELSEWHERE.
*
      SUBROUTINE ZRAN3(X,Z,N1,N2,N3)
      INTEGER N1, N2, N3
      REAL*8 Z(N1,N2,N3)
      INTEGER M, I1, I2, I3
      REAL*8 X, A
      PARAMETER( M = 10,  A = 5.D0 ** 13 )
      INTEGER I, J1( M, 0:1 ), J2( M, 0:1 ), J3( M, 0:1 )
C
C
        READ(5,*)
	READ(5,9007)(J1(I,0),J2(I,0),J3(I,0),I=1,M)
        READ(5,*)
	READ(5,9007)(J1(I,1),J2(I,1),J3(I,1),I=1,M)
9007	FORMAT(5(2X,I3,2(1X,I3),1X))
C 
        WRITE(6,*)' NEGATIVE CHARGES AT'
	WRITE(6,7)(J1(I,0),J2(I,0),J3(I,0),I=1,M)
        WRITE(6,*)' POSITIVE CHARGES AT'
	WRITE(6,7)(J1(I,1),J2(I,1),J3(I,1),I=1,M)
 7	FORMAT(5(' (',I3,2(',',I3),')'))
C
      DO 400 I3=1,N3
      DO 400 I2=1,N2
      DO 400 I1=1,N1
	Z(I1,I2,I3) = 0.0D0
 400  CONTINUE
C
	DO 500 I=1,M
	  Z( J1(I,0), J2(I,0), J3(I,0) ) = -1.0D0
	  Z( J1(I,1), J2(I,1), J3(I,1) ) = +1.0D0
 500	CONTINUE
C
        CALL COMM3(Z,N1)
C
      RETURN 
      END
*
***** BUBBLE	DOES A BUBBLE SORT IN DIRECTION DIR
*
	SUBROUTINE BUBBLE( TEN, J1, J2, J3, M, IND )
	REAL*8 TEN( M, 0:1 )
        INTEGER M, IND, J1( M, 0:1 ), J2( M, 0:1 ), J3( M, 0:1 )
	REAL*8 DIR, TEMP
	INTEGER I, JXTEMP
C
	IF( IND .EQ. 1 )THEN
	  DIR = +1.0D0
	ELSE
	  DIR = -1.0D0
	ENDIF
C
	DO 100 I=1,M-1
	  IF( DIR*TEN(I,IND) .GT. DIR*TEN(I+1,IND) )THEN
	    TEMP = TEN( I+1, IND )
	    TEN( I+1, IND ) = TEN( I, IND )
	    TEN( I, IND ) = TEMP
C
	    JXTEMP	   = J1( I+1, IND )
	    J1( I+1, IND ) = J1( I,   IND )
	    J1( I,   IND ) = JXTEMP
C
	    JXTEMP	   = J2( I+1, IND )
	    J2( I+1, IND ) = J2( I,   IND )
	    J2( I,   IND ) = JXTEMP
C
	    JXTEMP	   = J3( I+1, IND )
	    J3( I+1, IND ) = J3( I,   IND )
	    J3( I,   IND ) = JXTEMP
C
	  ELSE 
	    RETURN
	  ENDIF
C
 100	CONTINUE
C
	RETURN
	END
