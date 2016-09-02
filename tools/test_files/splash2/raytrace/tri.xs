
Stmts:Stmt1,Stmt2,Stmt3,Stmt4,Stmt5,Stmt6,Stmt7,Stmt8,Stmt9,Stmt10,Stmt11,Stmt12,Stmt13,Stmt14,Stmt15,Stmt16,Stmt17,Stmt18,Stmt19,Stmt20,Stmt21,Stmt22,Stmt23,Stmt24,Stmt25,Stmt26
Funcs:Func1

ScalarRepl:aref=(*v1)[0] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt18,Stmt24
ScalarRepl:aref=(*v1)[1] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt12,Stmt24
ScalarRepl:aref=(*v1)[2] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt12,Stmt18
ScalarRepl:aref=(*v2)[0] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt16,Stmt22
ScalarRepl:aref=(*v2)[1] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt10,Stmt22
ScalarRepl:aref=(*v2)[2] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt10,Stmt16
ScalarRepl:aref=(*v3)[0] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt16,Stmt22
ScalarRepl:aref=(*v3)[1] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt10,Stmt22
ScalarRepl:aref=(*v3)[2] dim="" target=Func1 data_type="REAL" init=1 save=0 scalar_num=1 init_loc=Stmt10,Stmt16
RedundancyElimination:target=Stmt1 type=4 used_place=Stmt20,Stmt26
RedundancyElimination:target=Stmt2 type=4 used_place=Stmt14,Stmt26
RedundancyElimination:target=Stmt3 type=4 used_place=Stmt14,Stmt20
RedundancyElimination:target=Stmt4 type=4 used_place=Stmt16,Stmt22
RedundancyElimination:target=Stmt5 type=4 used_place=Stmt10,Stmt22
RedundancyElimination:target=Stmt6 type=4 used_place=Stmt10,Stmt16
RedundancyElimination:target=Stmt7 type=4 used_place=Stmt18,Stmt24
RedundancyElimination:target=Stmt8 type=4 used_place=Stmt12,Stmt24
RedundancyElimination:target=Stmt9 type=4 used_place=Stmt12,Stmt18
