Nests: nest1,nest2
ParallelizeLoop: target=nest1 private=i,j
BlockLoops: target=nest1 inner_loop=nest2
UnrollJam: target=nest1 inner_loop=nest2
ScalarRepl:  aref=X[i] data_type="double" dim=nest2 target=nest2[Nest.body] init=1 save=0
ScalarRepl:  aref=Y[(j*incY)] data_type="double" dim=nest1 target=nest1[Nest.body] init=1 save=0
UnrollLoop: target=nest2
