Nests: nest1,nest3,nest2
ParallelizeLoop: target=nest1 private=l,i,j
BlockLoops: target=nest1 inner_loop=nest2
UnrollJam: target=nest1 inner_loop=nest2
ScalarRepl:  aref=C[((j*ldc)+i)] data_type="double" dim=nest1,nest3 target=nest3[Nest.body] init=1 save=1
ScalarRepl:  aref=A[((l*lda)+i)] data_type="double" dim=nest2,nest3 target=nest3[Nest.body] init=1 save=0
ScalarRepl:  aref=B[((j*ldb)+l)] data_type="double" dim=nest1,nest2 target=nest2[Nest.body] init=1 save=0
