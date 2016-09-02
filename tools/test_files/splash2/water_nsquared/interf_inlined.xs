
Nests:Nest2,Nest3,Nest4,Nest5,Nest6,Nest7,Nest11,Nest12,Nest13
Stmts:Stmt1,Stmt2,Stmt3,Stmt4,Stmt5,Stmt6,Stmt7,Stmt8,Stmt9,Stmt10,Stmt11,Stmt12,Stmt13,Stmt14,Stmt15,Stmt16,Stmt17,Stmt18,Stmt19,Stmt20,Stmt21,Stmt22,Stmt23

RedundancyElimination:target=Stmt2 type=4 used_place=""
RedundancyElimination:target=Stmt3 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt4 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt5 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt6 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt7 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt9 type=4 used_place=""
RedundancyElimination:target=Stmt10 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt11 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt12 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt13 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt14 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt16 type=4 used_place=Stmt22 erase_flag=0
RedundancyElimination:target=Stmt17 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt18 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt19 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt20 type=4 used_place=Stmt22
RedundancyElimination:target=Stmt21 type=4 used_place=Stmt22
FuseLoops:loop_to_fuse=Nest11,Nest12 target=Nest13 reserve_target=1
RedundancyElimination:target=Nest13 type=4 used_place=Stmt22 index_start=9
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[0] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt1
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[1] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt22
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[2] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt1
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[0] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt8
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[1] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt22
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[2] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt8
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[0] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt15
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[1] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt22
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[2] dim=Nest3 target=Nest3 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt15
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[0] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[2] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[0] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[2] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[0] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[2] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((VAR)[mol].VM)[XDIR] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((VAR)[mol].VM)[YDIR] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
ScalarRepl:aref=((VAR)[mol].VM)[ZDIR] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest3
RedundancyElimination:target=Nest2 type=6 expression=NMOL%2==0 data_type="int"
StrengthReduction:target=Stmt23 type=2 minus_result="NMOL1"

