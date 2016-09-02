Nests: nest1,nest2
ParallelizeLoop: target=nest1 private=i,j threads=16
BlockLoops: target=nest1 inner_loop=nest2 factor=32
UnrollJam: target=nest1 inner_loop=nest2 factor=4
ScalarRepl:  aref=X[i] data_type="double" dim=nest2 target=nest2 init=1 save=0
ScalarRepl:  aref=Y[(j*incY)] data_type="double" dim=nest1 target=nest1 init=1 save=0
UnrollLoop: target=nest2 factor=4
