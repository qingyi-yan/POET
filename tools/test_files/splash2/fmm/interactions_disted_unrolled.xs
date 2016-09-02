
Nests:Nest1_1,Nest1_2,Nest2,Nest3,Nest4,Nest5
Stmts:Stmt1,Stmt2,Stmt3,Stmt4,Stmt5

ScalarRepl:aref=z0_pow_minus_n[k] dim=Nest1_1 target=Nest1_1 data_type="complex" init=0 save=1
RedundancyElimination:target=Stmt2 type=1 redundant_branch_flag=1 else_branch=Stmt3
RedundancyElimination:target=Stmt4 type=1 redundant_branch_flag=0 else_branch=Stmt5

