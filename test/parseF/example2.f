C  Needed Modifications:   
C  1)  parse "end if" and "end do" instead of "endif" and "enddo"
C        note * - endif is for Fortran 77 and "end if" for Fortran 90+
C  2)  honor Fortran 90/95 line continue token &
C  3)  statements start on any column (e.g. don't reserve columns 1 - 6)  
C  4)  parse "! comment" just after statement on same line  
C  5)  honor do while ( cond ) statement
C  6)  parse floating point number 0.D0 or 0.d0 ==> not supported
C     
C  Not as important, but would be nice   
C     
C  7)  parse print statements  
C  8)  parse read/write statements  
C     
C     
      subroutine update_data(i1, i2)

	  real(kind=dp) :: var1, var2, var3, var4, var5, var6, var7, var8, var9, var10

* //@; BEGIN(nest1=SingleLoop)

	  do i= 1, N, 2
	    do j= 1, M
		  m = d2 + arg1

		  result(j) = operand1(j) + operand2(j) / operand3(k) * &
		  operand4(k)

		  result(k) = operand4(j)  ! Fortran 90/95 comment

		  if ( arg2 .gt. 0. ) then
		  	result(j) = operand2(k)
		  else if ( arg3 .lt. 0. ) then
		  	result(j) = operand3(k)
		  else
		  	result(j) = operand4(k)
		  end if

		  do while(.not. converged)
		     result(j) = operand4(j)  ! Fortran 90/95 comment
		     if (result(j) .gt. 6) then converged = .true. endif
		  end do

C		  print *, 'error in data'
C		  write(50, *) 'step = ', j
	    end do
	  end do

	  end subroutine update_data
