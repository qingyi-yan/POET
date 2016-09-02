Nests: nest1,nest2
ParallelizeLoop: target=nest1 private=j,i
BlockLoops: target=nest1 inner_loop=nest2
UnrollJam: target=nest1 inner_loop=nest2
ScalarRepl:  aref=Y[i] data_type="double" dim=nest1 target=nest1[Nest.body] init=1 save=1
ScalarRepl:  aref=X[j] data_type="double" dim=nest2 target=nest2[Nest.body] init=1 save=0
UnrollLoop: target=nest2
