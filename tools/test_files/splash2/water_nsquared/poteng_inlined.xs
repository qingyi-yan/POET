
Nests:Nest8,Nest9,Nest10,Nest11,Nest12,Nest1_1,Nest1_2,Nest1_3
Stmts:Stmt1,Stmt2,Stmt3,Stmt4,Stmt5,Stmt6,Stmt7,Stmt8,Stmt9,Stmt10,Stmt11,Stmt12,Stmt13,Stmt14,Stmt15,Stmt16,Stmt17,Stmt18,Stmt19,Stmt20,Stmt21,Stmt22

RedundancyElimination:target=Stmt3 type=4 used_place=""
RedundancyElimination:target=Stmt4 type=4 used_place=Nest12
RedundancyElimination:target=Stmt5 type=4 used_place=Nest12
RedundancyElimination:target=Stmt6 type=4 used_place=Nest12
RedundancyElimination:target=Stmt7 type=4 used_place=Nest12
RedundancyElimination:target=Stmt8 type=4 used_place=Nest12
RedundancyElimination:target=Stmt10 type=4 used_place=""
RedundancyElimination:target=Stmt11 type=4 used_place=Nest12
RedundancyElimination:target=Stmt12 type=4 used_place=Nest12
RedundancyElimination:target=Stmt13 type=4 used_place=Nest12
RedundancyElimination:target=Stmt14 type=4 used_place=Nest12
RedundancyElimination:target=Stmt15 type=4 used_place=Nest12
RedundancyElimination:target=Stmt17 type=4 used_place=Nest12 erase_flag=0
RedundancyElimination:target=Stmt18 type=4 used_place=Nest12
RedundancyElimination:target=Stmt19 type=4 used_place=Nest12
RedundancyElimination:target=Stmt20 type=4 used_place=Nest12
RedundancyElimination:target=Stmt21 type=4 used_place=Nest12
RedundancyElimination:target=Stmt22 type=4 used_place=Nest12
FuseLoops:loop_to_fuse=Nest1_1,Nest1_2 target=Nest1_3 reserve_target=1
RedundancyElimination:target=Nest1_3 type=4 used_place=Nest12 index_start=9
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[0] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt2
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[1] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest12
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[XDIR])[2] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt2
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[0] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt9
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[1] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest12
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[YDIR])[2] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt9
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[0] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt16
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[1] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest12
ScalarRepl:aref=((((VAR)[comp].F)[DISP])[ZDIR])[2] dim=Nest9 target=Nest9 data_type="double" init=1 save=0 scalar_num=1 init_loc=Stmt16
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[0] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[1] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[XDIR])[2] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[0] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[1] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[YDIR])[2] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[0] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[1] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((((VAR)[mol].F)[DISP])[ZDIR])[2] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((VAR)[mol].VM)[XDIR] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((VAR)[mol].VM)[YDIR] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
ScalarRepl:aref=((VAR)[mol].VM)[ZDIR] dim=Nest8 target=Nest8 data_type="double" init=1 save=0 scalar_num=1 init_loc=Nest9
RedundancyElimination:target=Nest8 type=6 expression=NMOL%2==0 data_type="int"
StrengthReduction:target=Stmt1 type=2 minus_result="NMOL1"

