Nests: nest1,nest3,nest2
ParallelizeLoop: target=nest2 model="VEC" reduction=C[j*ldc+i] private=A[l+lda*i],B[j*ldb+l] reduction_op="+" scope=nest3

