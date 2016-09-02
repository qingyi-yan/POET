
Stmts: Stmt1,Stmt2
Funcs: Func1

RedundancyElimination:target=Stmt1 type=1 redundant_branch_flag=0
RedundancyElimination:target=Stmt2 type=1 redundant_branch_flag=1
ScalarRepl:aref=((Local)[ProcessId].dr)[0] dim="" target=Func1 data_type="real" init=0 save=0
ScalarRepl:aref=((Local)[ProcessId].dr)[1] dim="" target=Func1 data_type="real" init=0 save=0
ScalarRepl:aref=((Local)[ProcessId].dr)[2] dim="" target=Func1 data_type="real" init=0 save=0
