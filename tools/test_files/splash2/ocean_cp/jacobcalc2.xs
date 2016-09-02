
Nests:Nest1,Nest2
Stmts:Stmt1

ScalarRepl:aref=t1b[iindex-1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1b[iindex+1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1d[iindex-1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1d[iindex] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1d[iindex+1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1a[iindex] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1e[iindex-1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1e[iindex] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
ScalarRepl:aref=t1e[iindex+1] dim=Nest2 target=Nest2 data_type="double" init=1 save=0 scalar_num=1
DistributeLoop: statement_to_dist=Stmt1 target=Nest2 outer_nest=Nest1 statement_to_split=Stmt1 data_type="double"

