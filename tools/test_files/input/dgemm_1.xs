Nests: Nest1, Nest2, Nest3, Nest4
PermuteLoops:inner_loop=Nest3 target=Nest2 order="3,1,2" 
FuseLoops:loop_to_fuse=Nest1 target=Nest2 
FuseLoops:loop_to_fuse=Nest1 target=Nest4 
ParallelizeLoop: target=Nest2 private=j,i,k factor=256 threads="MACRO"
BlockLoops: inner_loop=Nest3 target=Nest2  factor=32
UnrollJam: inner_loop=Nest3 target=Nest2 factor=4
ScalarRepl: target=Nest4 aref=c[j*n+i] dim=Nest2,Nest4  data_type="double" init=1 save=1
ScalarRepl: aref=a[k*n+i] dim=Nest4,Nest3  data_type="double" target=Nest3 init=1 save=0
UnrollLoop:  target=Nest3  factor=4
